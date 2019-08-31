'''
动态规划， 台阶数量从1到n的不同走法数量的数列满足斐波那契数列。
'''
class Solution:
    def climbStairs(self, n: int) -> int:
        fib = [1 for _ in range(n+1)]
        for i in range(2, n+1):
            fib[i] = fib[i-1] + fib[i-2]
        return fib[n]