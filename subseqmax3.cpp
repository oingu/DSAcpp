//cho dãy số nguyên a1 a2 an hãy tìm đoạn con ai ai+1... aj sao cho a[i]^3 + ... + a[j]^3 max

#include <bits/stdc++.h>
using namespace std;

int a[10001];
int n;
int sum1 = 0;
int sum2 = INT_MIN;

int main(){
    a[0] = 0;
    cin >> n;
    int tmp;
    for(int i = 1; i <= n; i++){
        cin >> tmp;
        a[i] = tmp * tmp * tmp;
    }
    int p = 1, q = 1;
    for(int i = 1; i <= n; i++){
        sum1 += a[i];
        if(sum1 < 0){
            sum1 = 0;
            p = i;
            q = i;
        }
        if(sum2 < sum1){
            sum2 = sum1;
            q = i;
        } 
    }
    cout << p << ' ' << q << ' ' << sum2;
    return 0;
}
