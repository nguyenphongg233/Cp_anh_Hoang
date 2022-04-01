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
const long long  MAX = 100005;
const long long  INF = 1e9;
const long long mod = 1e9 + 7;

const int dx[] = {0,0,-1,1};
const int dy[] = {1,-1,0,0};

// a.k.a 1 Dam Wrong Answer

using namespace std;

/*ll v,p,a[MAX],dp[MAX][N][2];


signed main(){
    faster();
    cin>>v>>p;
    for(ll i = 1;i<=v;i++)cin>>a[i];
    dp[1][1][1] = 0;
    dp[1][1][0] = INF;
    // 1 co dat
    // 0 khong dat 
    for(ll i = 1;i<=v;i++){
        for(ll j = 1;j<=p;j++){
            for(ll z = i-1;z>=1;z--){
            if(i<j)dp[i][j][1] = dp[i][j][0] = 0;
            else {
                dp[i][j][0] = min(dp[z][j - 1][1],dp[i][j][0]);
                dp[i][j][1] = min(dp[z][j][1]  + a[i] - a[z],dp[i][j][1]);
            }
            }
        }
    }
    for(ll i = 1;i<=v;i++){
        for(ll j = 1;j<=p;j++)cout<<dp[i][j][1]<<" ";
        cout<<"\n";
    }
    cout<<min(dp[v][p][1],dp[v][p][0]);
    return 0;
}*/

const int N = 105;

ll n,m,a[MAX],dp[N][MAX];

signed main(){
    cin>>n>>m;
    for(ll i = 1;i<=n;i++)cin>>a[i];
    for(ll i = 1;i<=n;i++){
        dp[1][i] = dp[0][i] = 0;
        for(ll j = 1;j<i;j++)dp[1][i] += abs(a[i] - a[j]);
    }
    for(ll i = 2;i<=m;i++){
        for(ll j = i;j<=n;j++){
            dp[i][j] = INF;
            for(ll u = i-1;u<j;u++){
                ll sum = dp[i-1][u];
                for(ll v = u+1;v<j;v++){
                    sum += min(abs(a[v] - a[j]),abs(a[v] - a[u]));
                }
                dp[i][j] = min(dp[i][j],sum);
            }
        }
    }
    ll ans = INF;
    for(ll i = m;i<=n;i++){
        for(ll j = i+1;j<=n;j++){
            dp[m][i] += abs(a[j] - a[i]);
        }
        ans = min(ans,dp[m][i]);
    }
    cout<<ans;
}