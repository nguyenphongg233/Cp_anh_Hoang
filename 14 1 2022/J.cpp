#include<bits/stdc++.h>

#define ll long long
#define ld long double

#define X first
#define Y second

#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<ll>
#define ii pair<ll, ll>
#define vii vector<pair<ll, ll>>

#define FOR(i, a, b) for (ll i = a; i <= b; i++)
#define FOD(i, a, b) for (ll i = a; i >= b; i--)

const double pi = 1.00 * acos(-1.00);
const long long  MAX = 100005;
const long long  INF = 1e18;
const long long mod = 1e9 + 7;

// Author : NguyenPhongg
// Date : 22 1 2022
// NT --> NH --> NU 

using namespace std;

ll n,k,a[MAX],dp[MAX][15];
bool d[MAX][15];
ll cacl(ll i,ll t){
    if(i==n) return dp[i][t] = 1;
    if(d[i][t])return dp[i][t];
    d[i][t] = 1;
    FOR(j,i+1,n){
        if(a[j] <= a[i] && t < k)dp[i][t] = max(dp[i][t],cacl(j,t + 1) + 1);
        else dp[i][t] = max(dp[i][t],dp[j][t] + 1);
    }
    return dp[i][t];
}
signed main(){
    faster();
    cin>>n>>k;
    FOR(i,1,n)cin>>a[i];
    ll res = 0;
    FOD(i,n,1)FOR(j,0,k)res = max(res,cacl(i,j));
    cout<< n - res;
    return 0;
}