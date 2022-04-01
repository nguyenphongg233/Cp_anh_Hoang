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
const long long  MAX = 105;
const long long  INF = 1e9;
const long long mod = 1e9 + 7;

const int dx[] = {0,0,-1,1};
const int dy[] = {1,-1,0,0};

// 🥇 🐘

using namespace std;

ll n,dp[MAX][MAX],a[MAX];

signed main(){
    faster();
    cin>>n;
    for(ll i = 1;i<=n;i++)cin>>a[i];
    memset(dp,0,sizeof dp);
    for(ll i = 1;i<=n;i++){
       for(ll j = 0;j<=100;j++){
           dp[i][j] = INF;
           for(ll g = 0;g < j;g++){
               dp[i][j] = min(abs(a[i] - j) + dp[i-1][g],dp[i][j]);
           }
       }
    }
    ll ans = INF;
    for(ll i = 1;i<=100;i++)ans = min(ans,dp[n][i]);
    cout<<ans;
    return 0;
}