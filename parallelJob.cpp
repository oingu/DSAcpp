#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// longest job first
int main() {
    int n;
    cin >> n;
    vector<int> d(n);
    for (int i = 0; i < n; ++i) cin >> d[i];
    sort(d.rbegin(), d.rend()); // Sort durations descending xếp giảm dần
    int T = 0;
    for (int i = 0; i < n; ++i) {
        T = max(T, d[i] + i); // 1 thời điểm có thể bđầu 1 việc mới chạy song song với 
                                //những cái cũ nên phải +i là số job đã chạy trước đó
    }
    cout << T << endl;
    return 0;
}