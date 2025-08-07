#pragma once

#include "ImageApplication.h"

namespace NTNUAIP {

	using System::Char;
	using System::Byte;
	using System::UInt16;
	using System::UInt32;
	using System::Exception;
	using System::ArgumentException;
	using System::IO::Stream;
	using System::IO::BinaryReader;
	using System::IO::EndOfStreamException;
	using System::Drawing::Bitmap;
	using System::Drawing::Color;

	enum class NetpbmType {
		P1, P2, P3, P4, P5, P6
	};

	ref class NetpbmHeader {
	private:
		NetpbmType _type;
		int _width, _height, _maxval;
	public:
		NetpbmHeader(NetpbmType type, int width, int height, int maxval) : _type(type), _width(width), _height(height), _maxval(maxval) {
			if (_width <= 0) {
				ArgumentException^ ae = gcnew ArgumentException("Width must greater than 0");
				throw ae;
			}
			if (_height <= 0) {
				ArgumentException^ ae = gcnew ArgumentException("Height must greater than 0");
				throw ae;
			}
			if (_maxval <= 0) {
				ArgumentException^ ae = gcnew ArgumentException("Maxval must greater than 0");
				throw ae;
			}
		}
		property NetpbmType Type {
			NetpbmType get() {
				return _type;
			}
		}
		property int Width {
			int get() {
				return _width;
			}
		}
		property int Height {
			int get() {
				return _height;
			}
		}
		property int Maxval {
			int get() {
				return _maxval;
			}
		}
	};
		
	ref class Netpbm
	{
	public:
		static bool CheckSignature(Stream^ stream) {
			try {
				GetNetpbmType(stream);
				stream->Position -= 2;
				return true;
			}
			catch (ArgumentException^) {
				return false;
			}
		}

		static Bitmap^ ToBitmap(Stream^ stream) {
			// header
			NetpbmHeader^ header = ReadHeader(stream);
			// raster
			Bitmap^ img = CreateBitmap(header, stream);
			return img;
		}

	private:
		static Bitmap^ CreateBitmap(NetpbmHeader^ header, Stream^ stream) {
			ArgumentException^ ae = gcnew ArgumentException("Invaid type");
			switch (header->Type) {
			case NetpbmType::P1:
				return CreateBitmapWithP1(header, stream);
			case NetpbmType::P2:
				return CreateBitmapWithP2(header, stream);
			case NetpbmType::P3:
				return CreateBitmapWithP3(header, stream);
			case NetpbmType::P4:
				return CreateBitmapWithP4(header, stream);
			case NetpbmType::P5:
				return CreateBitmapWithP5(header, stream);
			case NetpbmType::P6:
				return CreateBitmapWithP6(header, stream);
			default:
				throw ae;
			}
		}

		static Bitmap^ CreateBitmapWithP1(NetpbmHeader^ header, Stream^ stream) {
			array<Byte>^ raw = gcnew array<Byte>(header->Width * header->Height * 4);
			const int A = ImageApplication::A, R = ImageApplication::R, G = ImageApplication::G, B = ImageApplication::B;
			// read raster
			for (int offset = 0; offset < raw->Length; offset += 4) {
				SkipWhitespacesAndComments(stream);
				int colorch = stream->ReadByte();
				Byte color;
				if (colorch == '0') {
					color = ImageApplication::WHITE;
				}
				else if (colorch == '1') {
					color = ImageApplication::BLACK;
				}
				else {
					ArgumentException^ ae = gcnew ArgumentException("Invaid pixel value");
					throw ae;
				}
				raw[offset + R] = raw[offset + G] = raw[offset + B] = color;
				raw[offset + A] = ImageApplication::WHITE;
			}
			return ImageApplication::FromRaw(raw, header->Width, header->Height);
		}
		static Bitmap^ CreateBitmapWithP2(NetpbmHeader^ header, Stream^ stream) {
			array<Byte>^ raw = gcnew array<Byte>(header->Width * header->Height * 4);
			const int A = ImageApplication::A, R = ImageApplication::R, G = ImageApplication::G, B = ImageApplication::B;
			// initialize gray palette
			array<Byte>^ graypalette = gcnew array<Byte>(header->Maxval + 1);
			for (int i = 0; i <= header->Maxval; i++) {
				graypalette[i] = (Byte)(i * 255 / header->Maxval);
			}
			// read raster
			for (int offset = 0; offset < raw->Length; offset += 4) {
				SkipWhitespacesAndComments(stream);
				int colorval = ReadUInt16(stream);
				if (colorval > header->Maxval) {
					ArgumentException^ ae = gcnew ArgumentException("Invaid pixel value");
					throw ae;
				}
				raw[offset + R] = raw[offset + G] = raw[offset + B] = graypalette[colorval];
				raw[offset + A] = ImageApplication::WHITE;
			}
			return ImageApplication::FromRaw(raw, header->Width, header->Height);
		}
		static Bitmap^ CreateBitmapWithP3(NetpbmHeader^ header, Stream^ stream) {
			array<Byte>^ raw = gcnew array<Byte>(header->Width * header->Height * 4);
			array<int>^ rgb = { ImageApplication::R, ImageApplication::G, ImageApplication::B };
			const int A = ImageApplication::A;
			// initialize color palette
			array<Byte>^ colorpalette = gcnew array<Byte>(header->Maxval + 1);
			for (int i = 0; i <= header->Maxval; i++) {
				colorpalette[i] = (Byte)(i * 255 / header->Maxval);
			}
			// read raster
			for (int offset = 0; offset < raw->Length; offset += 4) {
				for (int k = 0; k < rgb->Length; ++k) {
					SkipWhitespacesAndComments(stream);
					int colorval = ReadUInt16(stream);
					if (colorval > header->Maxval) {
						ArgumentException^ ae = gcnew ArgumentException("Invaid pixel value");
						throw ae;
					}
					raw[offset + rgb[k]] = colorpalette[colorval];
				}
				raw[offset + A] = ImageApplication::WHITE;
			}
			return ImageApplication::FromRaw(raw, header->Width, header->Height);
		}
		static Bitmap^ CreateBitmapWithP4(NetpbmHeader^ header, Stream^ stream) {
			array<Byte>^ raw = gcnew array<Byte>(header->Width * header->Height * 4);
			const int A = ImageApplication::A, R = ImageApplication::R, G = ImageApplication::G, B = ImageApplication::B;
			// read raster
			const int rowlength = (header->Width + 7) >> 3;
			array<Byte>^ data = gcnew array<Byte>(rowlength * header->Height);
			stream->Read(data, 0, data->Length);
			for (int offset = 0, h = 0; h < header->Height; ++h) {
				for (int w = 0; w < header->Width; ) {
					int pixel8 = (int)data[h * rowlength + (w >> 3)];
					for (int k = 0; k < 8 && w < header->Width; ++k, ++w, offset += 4) {
						Byte color = (pixel8 & (1 << k) ? ImageApplication::BLACK : ImageApplication::WHITE);
						raw[offset + R] = raw[offset + G] = raw[offset + B] = color;
						raw[offset + A] = ImageApplication::WHITE;
					}
				}
			}
			return ImageApplication::FromRaw(raw, header->Width, header->Height);
		}
		static Bitmap^ CreateBitmapWithP5(NetpbmHeader^ header, Stream^ stream) {
			array<Byte>^ raw = gcnew array<Byte>(header->Width * header->Height * 4);
			const int A = ImageApplication::A, R = ImageApplication::R, G = ImageApplication::G, B = ImageApplication::B;
			// initialize gray palette
			array<Byte>^ graypalette = gcnew array<Byte>(header->Maxval + 1);
			for (int i = 0; i <= header->Maxval; i++) {
				graypalette[i] = (Byte)(i * 255 / header->Maxval);
			}
			// read raster
			const int pp = (header->Maxval <= Byte::MaxValue ? 1 : 2);
			array<Byte>^ data = gcnew array<Byte>(header->Width * header->Height * pp);
			stream->Read(data, 0, data->Length);
			for (int i = 0, offset = 0; offset < raw->Length; i += pp, offset += 4) {
				int colorval = (int)data[i];
				if (pp == 2) {
					colorval = colorval << 8 | data[i + 1];
				}
				if (colorval > header->Maxval) {
					ArgumentException^ ae = gcnew ArgumentException("Invaid pixel value");
					throw ae;
				}
				raw[offset + R] = raw[offset + G] = raw[offset + B] = graypalette[colorval];
				raw[offset + A] = ImageApplication::WHITE;
			}
			return ImageApplication::FromRaw(raw, header->Width, header->Height);
		}
		static Bitmap^ CreateBitmapWithP6(NetpbmHeader^ header, Stream^ stream) {
			array<Byte>^ raw = gcnew array<Byte>(header->Width * header->Height * 4);
			array<int>^ rgb = { ImageApplication::R, ImageApplication::G, ImageApplication::B };
			const int A = ImageApplication::A;
			// initialize color palette
			array<Byte>^ colorpalette = gcnew array<Byte>(header->Maxval + 1);
			for (int i = 0; i <= header->Maxval; i++) {
				colorpalette[i] = (Byte)(i * 255 / header->Maxval);
			}
			// read raster
			const int pp = (header->Maxval <= Byte::MaxValue ? 1 : 2);
			array<Byte>^ data = gcnew array<Byte>(header->Width * header->Height * pp * 3);
			stream->Read(data, 0, data->Length);
			for (int i = 0, offset = 0; offset < raw->Length; offset += 4) {
				for (int k = 0; k < rgb->Length; i += pp, ++k) {
					int colorval = (int)data[i];
					if (pp == 2) {
						colorval = colorval << 8 | data[i + 1];
					}
					if (colorval > header->Maxval) {
						ArgumentException^ ae = gcnew ArgumentException("Invaid pixel value");
						throw ae;
					}
					raw[offset + rgb[k]] = colorpalette[colorval];
				}
				raw[offset + A] = ImageApplication::WHITE;
			}
			return ImageApplication::FromRaw(raw, header->Width, header->Height);
		}

	private:
		static NetpbmHeader^ ReadHeader(Stream^ stream) {
			// magic number
			NetpbmType type = GetNetpbmType(stream);
			// whitespaces
			SkipWhitespacesAndComments(stream);
			// width
			int width = (int)ReadUInt16(stream);
			// whitespaces
			SkipWhitespacesAndComments(stream);
			// height
			int height = (int)ReadUInt16(stream);

			int maxval = 1;
			if (type == NetpbmType::P2 || type == NetpbmType::P3 || type == NetpbmType::P5 || type == NetpbmType::P6) {
				// whitespaces
				SkipWhitespacesAndComments(stream);
				// maxval
				maxval = (int)ReadUInt16(stream);
			}
			// single whitespace
			int ws = stream->ReadByte();
			if (!Char::IsWhiteSpace(ws)) {
				ArgumentException^ ae = gcnew ArgumentException("Unexpected code in ReadHeader()");
				throw ae;
			}
			// make header
			return gcnew NetpbmHeader(type, width, height, maxval);
		}

	private:
		static NetpbmType GetNetpbmType(Stream^ stream) {
			int magicNumber = stream->ReadByte();
			magicNumber = magicNumber << 8 | stream->ReadByte();
			switch (magicNumber) {
				case 0x5031:
					return NetpbmType::P1;
				case 0x5032:
					return NetpbmType::P2;
				case 0x5033:
					return NetpbmType::P3;
				case 0x5034:
					return NetpbmType::P4;
				case 0x5035:
					return NetpbmType::P5;
				case 0x5036:
					return NetpbmType::P6;
				default:
					ArgumentException^ ae = gcnew ArgumentException("Invalid magic number");
					throw ae;
			}
		}

	private:
		static System::Void SkipWhitespaces(Stream^ stream) {
			int next;
			do {
				next = stream->ReadByte();
				// end of stream
				if (next == -1) {
					return;
				}
			} while (Char::IsWhiteSpace(next));
			// put the byte back to the stream
			stream->Position -= 1;
		}
		static System::Void SkipWhitespacesAndComments(Stream^ stream) {
			while (1) {
				int next = stream->ReadByte();
				// end of stream
				if (next == -1) {
					return;
				}
				// whitespace
				if (Char::IsWhiteSpace(next)) {
					continue;
				}
				// comment
				if (next == '#') {
					// ignore one line
					do {
						next = stream->ReadByte();
						// end of stream
						if (next == -1) {
							return;
						}
					} while (next != '\n');
					continue;
				}
				// otherwise
				stream->Position -= 1;
				return;
			}
		}
		static UInt16 ReadUInt16(Stream^ stream) {
			UInt32 val = 0;
			int digit = 0;
			int next;
			do {
				next = stream->ReadByte();
				// end of stream
				if (next == -1) {
					if (digit == 0) {
						EndOfStreamException^ eos = gcnew EndOfStreamException("Unexpected end of input stream");
						throw eos;
					}
					return val;
				}
				// not digits
				if (next < '0' || '9' < next) {
					if (digit == 0) {
						ArgumentException^ ae = gcnew ArgumentException("Unexpected code in ReadUInt()");
						throw ae;
					}
					stream->Position -= 1;
					return val;
				}
				// digits
				val = val * 10 + (next - '0');
				if (val > UInt16::MaxValue) {
					ArgumentException^ ae = gcnew ArgumentException("ReadUInt16(): number is too large");
					throw ae;
				}
				++digit;
			} while (1);
		}
			
	};
}
