
class Solution:
    def winnerSquareGame(self, n: int) -> bool:
        dp = [-1] * (n + 1)
        return self.solve(n, dp)

    def solve(self, n: int, dp: list) -> bool:
        if n == 0:
            return False

        if dp[n] != -1:
            return dp[n]

        for i in range(1, int(n ** 0.5) + 1):
            sq = i * i

            if not self.solve(n - sq, dp):
                dp[n] = True
                return True

        dp[n] = False
        return False
