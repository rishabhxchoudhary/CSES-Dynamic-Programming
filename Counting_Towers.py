import sys
# from functools import lru_cache
# @lru_cache(maxsize=None)

def _input():
    return sys.stdin.readline().strip()

N=int(1e6+5)
mod = 1000000007

dp=[[0,0] for _ in range(N)]
dp[0][0]=1
dp[0][1]=1
for i in range(1,N):
    dp[i][0]=((2*dp[i-1][0])%mod + dp[i-1][1])%mod
    dp[i][1] = (dp[i-1][0]+(4*dp[i-1][1])%mod) %mod

n=int(_input())
for _ in range(n):
    k = int(_input())
    print((dp[k-1][0]+dp[k-1][1])%mod)