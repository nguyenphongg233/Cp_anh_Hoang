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

/*ll n,x,y;
ii a[MAX];
ll dp[MAX];

signed main(){
    faster();
    cin>>n;
    for(ll i = 1;i<=n;i++){
        cin>>x>>y;
        a[i] = {x-y,x+y};
    }
    ll maxx = 0;
    sort(a+1,a+1+n);
    dp[1] = 1;
    for(ll i = 1;i<=n;i++){
        dp[i] = 1;
        for(ll j = i-1;j>=1;j--){
            if(a[i].X >= a[j].Y || (a[i].X == a[j].X && a[i].Y >= a[j].Y))dp[i] = max(dp[i],dp[j] + 1);
        }
        maxx = max(maxx,dp[i]);
    }
    for(ll i = 1;i<=n;i++)cout<<dp[i]<<" ";
    cout<<n - maxx;
    return 0;
}*/

ll n;
ii a[MAX];
ll dp[MAX][MAX];
bool d[MAX][MAX];
ll cacl(ll x,ll y){
   if(d[x][y])return dp[x][y];
   if(x >= y)return 0;
   d[x][y] = 1;
   ll res = 0;
   for(ll i = 1;i<=n;i++){
       if(a[i].X == x && a[i].Y == y)res++;
   }
   dp[x][y] = 0;
   for(ll i = x+1;i<y;i++){
       dp[x][y] = max(dp[x][y],cacl(x,i) + cacl(i,y));
   }
   return dp[x][y] + res;
}

signed main(){
    cin>>n;
    ll minx = INF,maxx = -INF;
    for(ll i = 1;i<=n;i++){
        ll x,y;
        cin>>x>>y;
        minx = min(minx,x-y+100);
        maxx = max(maxx,x+y+100);
        a[i] = {x-y + 100,x+y+100};
    }
    cout<<n - cacl(minx,maxx);
}