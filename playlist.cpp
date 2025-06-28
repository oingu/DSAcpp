#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int p = 0, q = 0;
    int res = 0;
    for(int i = 0; i < n; i++){
        q = i;
        for(int j = 0; j < i; j++){
            if(a[i] == a[j]) p = j;
            res = max(res, q - p + 1);
        }
    }
    cout << res << endl;
    return 0;
}