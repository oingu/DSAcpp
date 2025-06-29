#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 100005;
vector<pair<int, int>> adj[MAXN];
long long f[MAXN];
int subtree_size[MAXN];
int n;

void dfs1(int u, int parent) {
    subtree_size[u] = 1;
    f[u] = 0;
    for (auto &edge : adj[u]) {
        int v = edge.first, w = edge.second;
        if (v == parent) continue;
        dfs1(v, u);
        subtree_size[u] += subtree_size[v];
        f[u] += f[v] + 1LL * subtree_size[v] * w;
    }
}

void dfs2(int u, int parent) {
    for (auto &edge : adj[u]) {
        int v = edge.first, w = edge.second;
        if (v == parent) continue;
        f[v] = f[u] + 1LL * (n - 2 * subtree_size[v]) * w;
        dfs2(v, u);
    }
}

int main() {
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    dfs1(1, 0);
    dfs2(1, 0);
    long long res = 0;
    for (int i = 1; i <= n; ++i) {
        res = max(res, f[i]);
    }
    cout << res << endl;
    return 0;
}
