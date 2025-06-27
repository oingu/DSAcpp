#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int MAXN = 100005;
int n, m;
vector<int> a;
vector<int> st;

void build(int id, int l, int r) {
    if (l == r) {
        st[id] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    st[id] = max(st[id * 2], st[id * 2 + 1]);
}

void update(int id, int l, int r, int pos, int val) {
    if (l == r) {
        st[id] = val;
        return;
    }
    int mid = (l + r) / 2;
    if (pos <= mid) update(id * 2, l, mid, pos, val);
    else update(id * 2 + 1, mid + 1, r, pos, val);
    st[id] = max(st[id * 2], st[id * 2 + 1]);
}

int getMax(int id, int l, int r, int u, int v) {
    if (v < l || r < u) return -1e9;
    if (u <= l && r <= v) return st[id];
    int mid = (l + r) / 2;
    return max(getMax(id * 2, l, mid, u, v), getMax(id * 2 + 1, mid + 1, r, u, v));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    a.resize(n + 1);
    st.resize(4 * n + 5);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    build(1, 1, n);
    cin >> m;
    string cmd;
    for (int i = 0; i < m; ++i) {
        cin >> cmd;
        if (cmd == "update") {
            int idx, val;
            cin >> idx >> val;
            update(1, 1, n, idx, val);
        } else if (cmd == "get-max") {
            int l, r;
            cin >> l >> r;
            cout << getMax(1, 1, n, l, r) << '\n';
        }
    }
    return 0;
}