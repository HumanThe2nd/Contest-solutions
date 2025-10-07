/*
Codeforces Round 1056 (Div. 2), problem: (C) The Ancient Wizards' Capes - Upsolve
Try both wizards as the 1st a dn check validity
Referenced codeforce code by: @jiangly
Author: Dan Shan
Date: 2025-10-07

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
        int n, c = 0;
        cin >> n;
        vector<int> a(n);
        for(auto &x: a) cin >> x;

        for(int x = 0; x < 2; ++x){ // try left and right for 1st wizard
            int ci = a[0] + x - 1, f = 1;

            vector<int> p(n + 1);
            for(int i = 0; i < n; ++i){
                p[i+1] = i + 1 - p[i] + ci - a[i];
            }

            if(p[n] != ci) f = 0;
            
            for(int i = 0; i < n; ++i){
                if(p[i + 1] < p[i] || p[i+1] > p[i] + 1){
                    f = 0; break;
                }
            }
            if(f) ++c; // possible
        }
        cout << c << "\n";
    }
}
