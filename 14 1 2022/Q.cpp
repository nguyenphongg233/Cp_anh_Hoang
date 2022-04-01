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

string s;
ll n,dp[MAX][2];

signed main(){
       faster();
       cin>>s;
       n = s.size();
       s = " " + s;
       dp[0][1] = dp[0][0] = 0;
       // dp[i][1] : bo nho chinh 
       // dp[i][0] : bo nho phu
       dp[1][0] = dp[1][1] = 2;
       FOR(i,2,n){
           if(s[i]==s[i-1]){
               dp[i][0] = min(dp[i-1][0] + 2 ,dp[i-1][1] + 2);
               dp[i][1] = min(dp[i-1][1] + 1 ,dp[i-1][0] + 2);
           }else{
               dp[i][0] = dp[i][1] = min(dp[i-1][0],dp[i-1][1]) + 2;
               FOD(j,i-2,1)if(s[i]==s[j]){
                   dp[i][1] = min(dp[i][1],dp[j][1] + 1 + (i-j-1)*2);
                   break;
               }
           }   
       }
       //FOR(i,1,n)cout<<dp[i][1]<<","<<dp[i][0]<<"\n";
       cout<<min(dp[n][1],dp[n][0]);
       return 0;
}