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

pair<ii,ll> d[MAX];
ll dp[MAX],n,ans = 0;

bool check(ll a,ll b,ll x,ll y){
    if((a >=x && b >=y) || (a >= y && b >= x) )return true;
    else return false;
}
signed main(){
       faster();
       cin>>n;
       FOR(i,1,n){
           ll a, b, c, x, y, z; cin >> a >> b >> c;
           x = max(a, max(b,c)); z = min(a, min(b, c)); y = (a+b+c)-(x+z);
           d[i].X.X = x,d[i].X.Y=y,d[i].Y=z;
       }
       sort(d+1,d+1+n);
       dp[n] = d[n].Y;
       FOD(i,n-1,1){
           dp[i] = d[i].Y;
           FOD(j,n,i+1){
               if(check(d[j].X.X,d[j].X.Y,d[i].X.X,d[i].X.Y))dp[i] = max(dp[i],dp[j] + d[i].Y);
           }
           ans = max(ans,dp[i]);
       }
       //FOR(i,1,n)cout<<dp[i]<<" ";
       cout<<ans;
       return 0;
}