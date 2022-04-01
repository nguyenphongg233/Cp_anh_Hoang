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
const long long  MAX = 305;
const long long  INF = 1e9;
const long long mod = 1e9 + 7;

const int dx[] = {0,0,-1,1};
const int dy[] = {1,-1,0,0};

// 🥇 🐘

using namespace std;

ll n,x,y;
ll cir[MAX][MAX];
ll dp[MAX][MAX]; 
bool d[MAX][MAX];

ll cacl(ll x,ll y){
    if(d[x][y])return dp[x][y];
    if(x >= y)return dp[x][y] = 0;
    d[x][y] = 1;
    ll res = 0;
    for(ll i = x + 1;i<y;i++)res = max(res,cacl(x,i) + cacl(i,y));
    return dp[x][y] = res + cir[x][y];
}

signed main(){
    faster();
    cin>>n;
    for(ll i = 1;i<=n;i++){
        cin>>x>>y;
        cir[x-y+100][x+y+100]++;
    }
    cout<<n - cacl(0,300);
    return 0;
}