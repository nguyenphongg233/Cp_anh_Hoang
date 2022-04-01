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

ll n;
ll a[MAX],dp[MAX][MAX];

ll cacl(ll x,ll y){
    if(dp[x][y])return dp[x][y];
    if(y < x)return dp[x][y] = 1;
    if(y - x == 1)return 0;
    //ll score = a[x + 1] * a[x] * a[y] + cacl(x,x+1) + cacl(x+1,y);
    ll score = INF;
    for(ll i = x+1;i<y;i++){
        score = min(score,a[x] * a[y] * a[i] + cacl(x,i)+ cacl(i,y));
        //cout<<a[x] * a[y] * a[i] + cacl(x,i)+ cacl(i,y)<<" ";
    }
    return dp[x][y] = score;
}
signed main(){
    faster();
    cin>>n;
    for(ll i = 1;i<=n;i++)cin>>a[i];
    cout<<cacl(1,n);
    return 0;
}