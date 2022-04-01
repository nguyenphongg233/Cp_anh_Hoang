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

ll n,m,a[MAX][MAX],dp[MAX][MAX][MAX],res = 0;
 
signed main(){
       faster();
       cin>>m>>n;
       FOR(i,1,m)FOR(j,1,n)cin>>a[i][j];
       FOR(i,0,m)FOR(j,0,n)FOR(z,1,m)dp[i][j][z] = -INF;
       dp[0][0][0] = 0;
       FOR(i,1,m)FOR(j,1,n)FOR(z,1,i)
             dp[i][j][z] = max(dp[i][j-1][z],dp[i-1][j-1][z-1] + a[i][j]);
       cout<<dp[m][n][m];
       return 0;
}
/*signed main() {
    faster();
    cin >> m >> n;
    for(int i=1;i<=m;++i) {
        for(int j=1;j<=n;++j) {
            cin >> a[i][j];
        }
    }
    for(int i=0;i<=m;++i) {
        for(int j=0;j<=n;++j) {
            for(int k=1;k<=m;++k) {
                dp[i][j][k] = -INF;
            }
        }
    }
    dp[0][0][0] = 0;
    
    for(int i=1;i<=m;++i) {
        for(int j=1;j<=n;++j) {
            for(int k=1;k <= i;++k) {
                dp[i][j][k] = max(dp[i][j-1][k], dp[i-1][j-1][k-1] + a[i][j]);
            }
        }
    }
    
    cout << dp[m][n][m];
}*/