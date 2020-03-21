//一只青蛙一次可以跳上1级台阶，也可以跳上2级台阶。求该青蛙跳上一个 n 级的台阶总共有多少种跳法。
//
//答案需要取模 1e9 + 7（1000000007），如计算初始结果为：1000000008，请返回 1。


//思路：1层台阶有1种跳法，2层台阶有2种跳法，n层台阶有f(n)层跳法，n层中的先跳1层后面还有f(n-1)种跳法，如果n层中一开始跳2层，后面还有f(n-2)种跳法，所以f(n)=f(n-1)+f(n-2)，由此可以看出这是一个斐波那契问题
class Solution {
public:
    int numWays(int n) {
		if (n == 0)
			return 1;
		if (n == 1)
			return 1;

		long long numWays0 = 0;
		long long numWays1 = 1;

		int result = -1;
		long long numWaysN = 0;
		for (int i = 2; i <= n; i++)
		{
			numWaysN = (numWays0 + numWays1) % 1000000007;
			numWays0 = numWays1;
			numWays1 = numWaysN;
		}
		return numWaysN;
    }
};