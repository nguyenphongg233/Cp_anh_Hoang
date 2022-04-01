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
const long long  INF = 1e18;
const long long mod = 1e9 + 7;

// a.k.a 1 Dam Wrong Answer

using namespace std;


ll n,m,x,y;
pair<pair<ll,ll>,ll> pad[100005];    
ll dp[10005][2];

bool check(ll x,ll HPI,ll LPJ,ll RPJ,ll HPJ){
    if(x<=RPJ&&x>=LPJ&&HPI-HPJ<=m&&HPI-HPJ>=0)return true;
    else return false;
}
signed main(){
    ll LPI,LPJ,RPI,RPJ,HPI,HPJ,sum;
    cin >> n >> x >> y >> m;
    FOR(i,1,n){
        cin >> pad[i].X.Y >> pad[i].Y >> pad[i].X.X;
    }
    sort(pad+1,pad+1+n);
    FOR(i,1,n){
        LPI = pad[i].X.Y;
        RPI = pad[i].Y;
        HPI = pad[i].X.X;
        sum = 0;
        FOD(j,i-1,0){
            LPJ = pad[j].X.Y;
            RPJ = pad[j].Y;
            HPJ = pad[j].X.X;
            if(j==0){
                if(HPI<=m)dp[i][1] = HPI;
                else dp[i][1] = 1e9;
            }
            else{
                if(check(RPI,HPI,LPJ,RPJ,HPJ)){
                    dp[i][1] = min(dp[j][0]+RPI-LPJ,dp[j][1]+RPJ-RPI)+HPI-HPJ;
                    break;
                }
            }
        }
        FOD(j,i-1,0){
            LPJ = pad[j].X.Y;
            RPJ = pad[j].Y;
            HPJ = pad[j].X.X;
            if(j==0){
                if(HPI<=m)dp[i][0] = HPI;
                else dp[i][0] = 1e9;
            }
            else{
                if(check(LPI,HPI,LPJ,RPJ,HPJ)){
                    dp[i][0] = min(dp[j][0]+LPI-LPJ,dp[j][1]+RPJ-LPI)+HPI-HPJ;
                    break;
                }
            }
        }
    }
    FOD(j,n,1){
        LPJ = pad[j].X.Y;
        RPJ = pad[j].Y;
        HPJ = pad[j].X.X;
        if(check(x,y,LPJ,RPJ,HPJ)){
            cout << min(dp[j][0]+x-LPJ,dp[j][1]+RPJ-x)+y-HPJ;
            break;
        }
    }
    return 0;
}