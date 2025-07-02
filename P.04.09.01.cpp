// Traveling Salesman Problem (TSP) using DP with bitmasking
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> c(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> c[i][j];

    int N = 1 << n;
    vector<vector<int>> dp(N, vector<int>(n, INT_MAX));
    dp[1][0] = 0; // Start at city 0 (city 1 in problem)

    for (int mask = 1; mask < N; ++mask) {
        for (int u = 0; u < n; ++u) {
            if (!(mask & (1 << u)) || dp[mask][u] == INT_MAX) continue;
            for (int v = 0; v < n; ++v) {
                if (mask & (1 << v)) continue;
                int nextMask = mask | (1 << v);
                if (dp[nextMask][v] > dp[mask][u] + c[u][v]) {
                    dp[nextMask][v] = dp[mask][u] + c[u][v];
                }
            }
        }
    }

    int res = INT_MAX;
    for (int u = 1; u < n; ++u) {
        if (dp[N-1][u] < INT_MAX && c[u][0] < INT_MAX) {
            res = min(res, dp[N-1][u] + c[u][0]);
        }
    }
    cout << res << endl;
    return 0;
}
