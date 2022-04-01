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
const long long  MAX = 20005;
const long long  INF = 1e18;
const long long mod = 1e9 + 7;

// a.k.a 1 Dam Wrong Answer

using namespace std;

ll n,x,y,m;
ll dp[MAX][2];
pair<ll,ii> a[MAX];
ll x1,x2,h;

bool c(ll x,ll y,ll x1,ll x2,ll y2){
    if(x1 <= x && x<= x2 && y - y2 >=0 && y- y2 <= m)return true;
    else return false;
}
signed main(){
    faster();
    cin>>n>>x>>y>>m;
    FOR(i,1,n)cin>>a[i].Y.X>>a[i].Y.Y>>a[i].X;
    sort(a+1,a+1+n);
    FOR(i,1,n){
        ll x1 = a[i].Y.X,x2 = a[i].Y.Y,y1 = a[i].X;
        ll sum = 0;
        FOD(j,i-1,0){
            ll x11 = a[i].Y.X,x12 = a[i].Y.Y,y2 = a[i].X;
            if(j==0){
                if(y1 <= m)dp[i][1] = y1;
                else dp[i][1] = 1e9;
            }
            else {
                if(c(x2,y1,x11,x12,y2)){
                    dp[i][1] = min(dp[j][0] + x2 - x11,dp[j][1] + x12 - x2) + y1 - y2;
                    break;
                }
            }
        }
        FOD(j,i-1,0){
            ll x11 = a[i].Y.X,x12 = a[i].Y.Y,y2 = a[i].X;
            if(j==0){
                if(y1 <= m)dp[i][0] = y1;
                else dp[i][0] = 1e9;
            }
            else {
                if(c(x1,y1,x11,x12,y2)){
                    dp[i][0] = min(dp[j][0] + x1 - x11,dp[j][1] + x12 - x1) + y1 - y2;
                    break;
                }
            }
        }
    }
    FOD(i,n,1){
        ll x1 = a[i].Y.X ,x2 = a[i].Y.Y,y1 = a[i].X;
        if(c(x,y,x1,x2,y1)){
            cout<<min(dp[i][0] + x - x1,dp[i][1] + x2 - x) + y - y1;
            return 0;
        }
    }
}