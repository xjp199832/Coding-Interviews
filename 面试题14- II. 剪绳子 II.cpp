//给你一根长度为 n 的绳子，请把绳子剪成整数长度的 m 段（m、n都是整数，n > 1并且m > 1），每段绳子的长度记为 k[0], k[1]...k[m] 。请问 k[0] * k[1] *...* k[m] 可能的最大乘积是多少？例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。
//
//答案需要取模 1e9 + 7（1000000007），如计算初始结果为：1000000008，请返回 1。
#include <cmath>
#include <iostream>
using namespace std;

class Solution {
	const int p = 1000000007;
public:
	long cuttingRope(int n) {
		if (n < 2)
			return 0;
		if (n == 2)
			return 1;
		if (n == 3)
			return 2;

		int numOf3 = n / 3;
		if (n - numOf3 * 3 == 1)
			numOf3--;

		int numOf2 = (n - numOf3 * 3) / 2;

		return quickGetRem(3, numOf3) * (int)(pow(2, numOf2)) % p;
	}

	long quickGetRem(long x, int numOf3)
	{
		int rem = 1;
		for (; numOf3 > 0; numOf3 /= 2)
		{
			if (numOf3 % 2 == 1) rem = (rem * x) % p;
			x = (x * x) % p;
		}
		return rem;
	}
};