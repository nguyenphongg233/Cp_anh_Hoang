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
const long long  MAX = 100;
const long long  INF = 1e9 + 6;
const long long mod = 1e9 + 7;

// Nguyễn Phongg :))
using namespace std;

ll n,m,a[MAX][MAX],dd[MAX][MAX],dp[MAX][MAX];

ll getbit(ll n,ll i){
    return (n>>i)&1;
}
ll tx(ll u ,ll mask){
    if(mask==(1<<n - 1))return a[u][0];
    if(dd[u][mask] == 1)return dp[u][mask];
    dd[u][mask] = 1;
    dp[u][mask] = INF;
    FOR(i,1,n-1){
          if(getbit(mask,i)==0)dp[u][mask] = max(dp[u][mask],a[u][i] + tx(i,mask & (1<<i)));
    }
    return dp[u][mask];
}
signed main(){
       faster();
       cin>>n>>m;
       FOR(i,1,m){
           ll u,v,c;
           cin>>u>>v>>c;
           a[--u][--v] = c;
       }
       cout<<tx(0,1<<n - 1);
       return 0;
}