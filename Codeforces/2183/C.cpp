/*
C. War Strategy
Author: Dan Shan
Date: 2026-01-07
 
Simulate optimal process until completion or budget m exhausted
Closest 2 bases use 1 move each. 
The rest alternate between 2 and 1 moves each. (1 moves are capped at the closer edge)

Demo
1 0 0 0 0 0 0
2 0 0 0 0 0 0
3 0 0 0 0 0 0
4 0 0 0 0 0 0
1 4 0 0 0 0 0
1 1 3 0 0 0 0
2 1 1 2 0 0 0
3 1 1 1 1 0 0
 
0 0 0 1 0 0 0
0 0 0 2 0 0 0
0 0 0 3 0 0 0
0 0 3 1 0 0 0
0 2 1 2 0 0 0
1 1 1 3 0 0 0
1 1 1 1 3 0 0
1 1 1 2 1 2 0
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
        int n, m, k, res = 1;
        cin >> n >> m >> k;
        int l = k - 1, r = k + 1, cst = 2, f = min(n - k, k - 1) - 1;
        if(l > 0){ // 1st moves cost 1
            --m; --l; ++res;
        }
        if(m && r <= n){
            --m; ++r; ++res;
        }
        while(res < n){
            if(l < 1 && r > n) break; // completion
            if(k - l < r - k || r > n){ // moving left cheaper
                if(m < cst) break; // insufficient budget
                ++res; --l; // move a soldier left
                m -= cst;
            }
            else{
                if(m < cst) break;
                ++res; ++r; // move a soldier right
                m -= cst;
            }
            if(cst == 2 && f > 0) cst = 1, --f;
            else cst = 2;
        }
        printf("%d\n", res);
    }
}
