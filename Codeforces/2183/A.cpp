/*
A. Binary Array Game
Author: Dan Shan
Date: 2026-01-07
 
Alice need 1 a corner 1 to win
Otherwise: Bob wins
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
        int n;
        cin >> n;
        int a[n];
        for(int i = 0; i < n; ++i) cin >> a[i];
        if(a[0] == 1 || a[n-1] == 1) puts("Alice");
        else puts("Bob");
    }
}
