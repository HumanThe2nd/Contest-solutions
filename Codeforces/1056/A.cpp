/*
A - El fucho
Author: Dan Shan
Date: 2025-10-05
 
*/
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        long long n, n2 = 0, c = 1;
        cin >> n;
        while(n > 1 || n2 > 1){
            c += (n2 >> 1);
            n2 -= (n2 >> 1);
            n2 += (n >> 1);
            c += (n >> 1);
            n -= (n >> 1);
        }
        cout << c << "\n";
    }
}
