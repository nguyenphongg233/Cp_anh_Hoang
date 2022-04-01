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
const long long  INF = 361700864190383365;
const long long mod = 1e9 + 7;

// Nguyễn Phongg :))
using namespace std;

ll n,l,w[MAX];
float v[MAX],p,dp[MAX];

signed main(){
       faster();
       cin>>n>>p>>l;
       FOR(i,1,n)cin>>w[i]>>v[i];
       dp[1] = l/v[1];
       dp[0] = 0;
       FOR(i,2,n){
           dp[i] = dp[i-1] + l/v[i];
           ll j = i-1;
           ll sum = w[i];
           float minx = v[i];
           while(sum<=p && j>=0){
               dp[i] = min(dp[i],dp[j] + l/minx);
               minx = min(minx,v[j]);
               sum += w[j];
               j--;
           }
       }
       //FOR(i,1,n)cout<<dp[i]<<" ";
       cout<<setprecision(6)<<fixed<<dp[n];
       return 0;
}