#include<bits/stdc++.h>

#define ll unsigned long long
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

ll n,p,a[MAX],dp[MAX];

signed main(){
       faster();
       cin>>n>>p;
       FOR(i,1,n)cin>>a[i];
       dp[0] = a[0] = 0;
       FOR(i,1,n){
           dp[i] = INF;
           FOR(j,0,i-1)dp[i] = min(dp[i],dp[j] + (a[i] - a[j] - p)*(a[i] - a[j] - p));
       }
       cout<<dp[n];
       return 0;
}