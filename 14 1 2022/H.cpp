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

ll n,q = 0,t,a[MAX],dp[MAX];

signed main(){
       faster();
       cin>>n;
       FOR(i,1,n)cin>>a[i],q+=a[i];
       t = q/2;
       memset(dp,0,sizeof(dp));
       FOR(i,1,t){
              dp[i] = INF;
              FOR(j,1,n){
                     if(i>=a[j] && j>dp[i-a[j]]){
                            dp[i] = j;
                            break;
                     }
              }
       }
       ll sum = 0,d[MAX];
       while(dp[t]>n)t--;
       while(t>0){
            d[dp[t]] = 1;
            sum+=a[dp[t]];
            t-=a[dp[t]];
       }
       cout<<abs(q - sum - sum);
       return 0;
}