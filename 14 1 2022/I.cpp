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
const long long  MAX = 105;
const long long  INF = 361700864190383365;
const long long mod = 1e9 + 7;

// Nguyễn Phongg :))
using namespace std;

ll n,m,dp[MAX][MAX];
ll a[MAX],b[MAX];

signed main(){
       faster();
       cin>>n>>m;
       FOR(i,1,n)cin>>a[i];
       FOR(j,1,m)cin>>b[j];
       dp[0][0] = 0;
       FOR(i,1,n)FOR(j,1,m)if(a[i]==b[j])dp[i][j] = max(dp[i][j],dp[i-1][j-1] + 1);
       else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
       cout<<dp[n][m];
       return 0;
}