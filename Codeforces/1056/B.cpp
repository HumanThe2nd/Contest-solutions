/*
B - Abraham's Great Escape
Theory: # of trapped cells can't equal 1 (need 2+ to create a loop)
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
        long long n, k;
        cin >> n >> k;
        if(k == n * n - 1){
            cout << "NO\n";
            continue;
        } cout << "YES\n";
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                int ai = n * i + j;
                if(ai < k) cout << "U"; // first k cells all exit directly upward
                else{
                    if(j == n - 1 ){
                        if(ai == k) cout <<  "D"; // push down if possible
                        else cout << "L"; // bounce left
                    }
                    else cout << "R"; // bounce right
                }
            } cout << "\n";
        }
    }
}
