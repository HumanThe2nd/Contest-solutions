/*
B. Yet Another MEX Problem
Author: Dan Shan
Date: 2026-01-07
 
Order doesn't matter, find mex of entire array (if it only had k-1 elements)
Prune all excessive elements
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
        int n, k;
        cin >> n >> k;
        int a[n], res = 0;
        vector<int> v(n+1, 0);
        for(int i = 0; i < n; ++i) cin >> a[i], v[a[i]] = 1;
        for(res = 0; res < k-1; ++res){
            if(!v[res]) break;
        }
        printf("%d\n",res);
    }
}
