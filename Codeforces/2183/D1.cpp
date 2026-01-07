/*
D1. Tree Coloring (Easy Version)
Author: Dan Shan
Date: 2026-01-07

Contest upsolve
Theory:
1. BFS to count number of nodes in each layer
2. Set answer as the max among those values
3. If they all share a parents add a move
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
        int n, w = 0;
        cin >> n;
        vector<vector<int>> adj(n+1);
        vector<int> c(n, 0), v(n+1, 0); // c: nodes at each depth
        for(int i = 1; i < n; ++i){
            int ai, bi;
            cin >> ai >> bi;
            adj[ai].emplace_back(bi);
            adj[bi].emplace_back(ai);
        }
        queue<int> qi, qd;
        qi.emplace(1); qd.emplace(0);
        c[0] = 1; v[1] = 1;
        while(qi.size()){
            int ai = qi.front(), di = qd.front();
            qi.pop(); qd.pop();
            for(auto x: adj[ai]){
                if(!v[x]){
                    v[x] = 1; ++c[di + 1];
                    qi.emplace(x); qd.emplace(di + 1);
                }
            }
        }
        for(int i = 0; i < n; ++i){
            if(!c[i]) break; // depth not reached
            w = max(w, c[i]);
        }
        for(int i = 1; i <= n; ++i){
            if(adj[i].size() - (i != 1) == w){ // subtract 1 if not node 1 (to exclude parent)
                ++w; break;
            }
        }
        cout << w << "\n";
    }
}
