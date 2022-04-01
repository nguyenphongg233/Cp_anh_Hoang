#include<bits/stdc++.h>

#define ll long long
#define ld long double

#define X first
#define Y second

#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<ll>
#define ii pair<ll, ll>
#define vii vector<pair<ll, ll>>

const double pi = 1.00 * acos(-1.00);
const long long  MAX = 1005;
const long long  INF = 1e9;
const long long mod = 1e9 + 7;

const int dx[] = {0,0,-1,1};
const int dy[] = {1,-1,0,0};

// 🥇 🐘

using namespace std;

ll n,k,a[MAX],dp[MAX][16];
bool d[MAX][16];

ll cacl(ll x,ll y){
    if(x > n)return 0;
    if(d[x][y])return dp[x][y];
    d[x][y] = 1;
    dp[x][y] = 0;
    for(ll t = x+1;t <= n;t++){
        if(a[x] < a[t])dp[x][y] = max(dp[x][y],cacl(t,y) + 1);
        else if(y > 0) dp[x][y] = max(dp[x][y],cacl(t,y-1) + 1);
    }
    return dp[x][y];
}
signed main(){
    faster();
    cin>>n>>k;
    for(ll i = 1;i<=n;i++)cin>>a[i];
    a[0] = -INF;
    cout<<n - cacl(0,k);
    return 0;
}