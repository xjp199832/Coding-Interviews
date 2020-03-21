//实现函数double Power(double base, int exponent)，求base的exponent次方。不得使用库函数，同时不需要考虑大数问题。

class Solution {
private:
	bool catchException;
public:
	double myPow(double x, int n) {
		catchException = false;
		if (x - 0.0 < 0.1 && n < 0)
		{
			catchException = true;
			return 0.0;
		}

		unsigned int absExp = (unsigned int)n;
		if (n < 0)
			absExp = (unsigned int)(-n);

		double result = powerWithUnsignedExp(x, absExp);

		if (n < 0)
			return 1.0 / result;
		return result;
	}

	double powerWithUnsignedExp(double x, unsigned int absExp)
	{
		if (absExp == 0)
			return 1;
		if (absExp == 1)
			return x;

		double result = powerWithUnsignedExp(x, absExp >> 1);
		result *= result;
		if (absExp & 1 == 1)
			result *= x;
		return result;
	}
};