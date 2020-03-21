//给你一根长度为 n 的绳子，请把绳子剪成整数长度的 m 段（m、n都是整数，n > 1并且m > 1），每段绳子的长度记为 k[0], k[1]...k[m] 。请问 k[0] * k[1] *...* k[m] 可能的最大乘积是多少？例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。

class Solution {
public:
	int cuttingRope(int n) {
		if (n < 2)
			return 0;
		if (n == 2)
			return 1;
		if (n == 3)
			return 2;

		long* result = new long[n + 1];
		result[0] = 0;
		result[1] = 1;
		result[2] = 2;
		result[3] = 3;

		long max = 0;
		for (int i = 4; i <= n; i++)
		{
			max = 0;
			for (int j = 1; j <= i / 2; j++)
			{
				int tmp = result[j] * result[i - j];
				if (tmp > max)
					max = tmp;
				result[i] = max;
			}
		}

		max = result[n];
		delete[] result;

		return max;
	}
};