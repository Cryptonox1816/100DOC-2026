class Solution:
    def tsp(self, cost):
        n = len(cost)
        INF = float('inf')
        
        # Fix 1: dp[mask][city] - correct dimensions
        dp = [[INF] * n for _ in range(1 << n)]
        dp[1][0] = 0  # mask=1 (city 0 visited), ending at city 0
        
        full_mask = (1 << n) - 1
        
        # Fix 2: Proper iteration order (smaller masks first)
        for mask in range(1 << n):
            for u in range(n):
                if (mask & (1 << u)) == 0 or dp[mask][u] == INF:
                    continue
                for v in range(n):
                    if mask & (1 << v):
                        continue  # already visited
                    next_mask = mask | (1 << v)
                    dp[next_mask][v] = min(dp[next_mask][v], dp[mask][u] + cost[u][v])
        
        # Find minimum cost to return to city 0
        ans = INF
        for u in range(1, n):
            if dp[full_mask][u] != INF:
                ans = min(ans, dp[full_mask][u] + cost[u][0])
        
        return int(ans) if ans != INF else -1