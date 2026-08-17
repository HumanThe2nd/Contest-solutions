/*
USACO 2025 February Contest, Gold
Problem 2. The Best Subsequence
Author: Dan Shan
Created: August 9
Finished: August 16

Observation: optimal to only take 1s until 0s are needed for length -> modular arithmetic

setup:
- coordinate compress the relevant coords (l and r + 1 for queries/updates)
- Create 2 prefix arrays, one for binary and another for numerical
- binary: multiply the number in each chain by it's length, numerical: 2 ^ (n + 1 - last_digit) - 2 ^ (n + 1 - current_digit)

offline process queries:
- binary search index to stop taking only 1s (between l and r inclusive)
- use modular arithemtic with mod powers to compute the leading chain of 1s + suffix (using the psa)

Cool problem, but why is it so long...
*/
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll mod = 1e9 + 7;
ll mpow(ll b, int p){
    ll res = 1;
    for(int i = 0; (1LL << i) <= p; ++i){
        if(p & (1LL << i)) res = res * b % mod;
        b = b * b % mod;
    }
    return res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, q;
    cin >> n >> m >> q;
    map<int, int> mp;
    vector<int> ql(q), qr(q), qk(q), e;
    while(m--){ // difference array of 1s
        int l, r;
        cin >> l >> r;
        mp[l] ^= 1;
        mp[r + 1] ^= 1;
    }
    for(int i = 0; i < q; ++i){ // mark queried coords
        cin >> ql[i] >> qr[i] >> qk[i];
        mp[ql[i]] += 2;
        mp[qr[i] + 1] += 2;
    }
    e.emplace_back(0);
    for(auto x: mp) e.emplace_back(x.first);
    e.emplace_back(n + 1);
    vector<ll> val(e.size(), 0), psa(e.size(), 0), pre(e.size(), 0); // psa: binary, pre: numerical
    for(auto x: mp){
        val[lower_bound(e.begin(), e.end(), x.first) - e.begin()] ^= (x.second & 1);
    }
    for(int i = 1; i < e.size(); ++i){ // build regular and psa
        val[i] ^= val[i - 1];
        psa[i] = (psa[i - 1] + val[i - 1] * (e[i] - e[i - 1]));
        pre[i] = (pre[i - 1] + val[i - 1] * (mpow(2, n + 1 - e[i - 1]) - mpow(2, n + 1 - e[i]))) % mod;

    }
    for(int i = 0; i < q; ++i){ // process queries
        int l = ql[i], r = qr[i], k = qk[i];
        int L = lower_bound(e.begin(), e.end(), l) - e.begin(),
            R = lower_bound(e.begin(), e.end(), r + 1) - e.begin();
        l = L; // store original start
        if (psa[R] - psa[L] >= k) {
            cout << mpow(2, k) - 1 << '\n';
            continue;
        }
        int lo = 0, hi = e.size();
        while(lo + 1 < hi){
            int mid = (lo + hi) >> 1;
            if(psa[mid] - psa[l] + r - e[mid] >= k) lo = mid; // valid -> try better
            else hi = mid; // invalid -> crop less
        }
        int ind = psa[lo] + r - psa[l] - k;
        ll front = (mpow(2, k) - mpow(2, k - (psa[lo] - psa[l])) + mod) % mod;
        ll prei = (pre[lo] + val[lo] * (mpow(2, n + 1 - e[lo]) - mpow(2, n + 1 - ind)) + mod) % mod;
        ll back = (mpow((mod + 1) >> 1, n - r) * (pre[R] - prei) % mod + mod) % mod;
        cout << (front + mod + back) % mod << "\n";
    }
}

