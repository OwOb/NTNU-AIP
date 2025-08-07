#pragma once

// #include <cmath>

namespace NTNUAIP {

	using System::Math;
	using System::Random;

	ref class MyRandom : public System::Random
	{
	private:
		static constexpr double PI = Math::PI;
		static constexpr double TAU = 2.0 * Math::PI;

	public:
		// get random variables with a Gaussian distribution
		array<double>^ NormalRandomVariables(int length, double mean, double sigma) {
			array<double>^ data = gcnew array<double>(length);
			for (int i = 1; i < length; i += 2) {
				// Box-Muller transform 
				double r = this->NextDouble(), t = this->NextDouble();
				r = Math::Sqrt(-2.0 * Math::Log(r));
				t *= TAU;
				double z1 = sigma * Math::Sin(t) * r, z2 = sigma * Math::Cos(t) * r;
				// calculate value
				data[i - 1] = z1 + mean;
				data[i] = z2 + mean;
			}
			// length is odd do more one time
			if (length % 2 == 0) {
				// Box-Muller transform 
				double r = this->NextDouble(), t = this->NextDouble();
				double z = sigma * Math::Sin(TAU * t) * Math::Sqrt(-2.0 * Math::Log(r));
				// calculate value
				data[length - 1] = z + mean;
			}
			return data;
		}

		// get random variables with a Bernoulli distribution
		array<bool>^ BernoulliRandomVariables(int length, double probability) {
			array<bool>^ data = gcnew array<bool>(length);
			for (int i = 1; i < length; ++i) {
				data[i] = (this->NextDouble() < probability);
			}
			return data;
		}
	};
}