#include<bits/stdc++.h>

#define ll long long
#define ld long double

#define X first
#define Y second

#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ce(x) cerr << #x << " = " << x << endl
#define len(x) x.size();

#define getbit(x,n) ((x >> n) & 1);
#define turnoff(x,n) (x & ~(1 << n));
#define turnon(x,n) (x | (1<<n))

#define vi vector<ll>
#define ii pair<ll, ll>
#define vii vector<pair<ll, ll>>
#define matrix vector<vi>

const double pi = 1.00 * acos(-1.00);
const long long  MAX = 1005;
const long long  INF = 1e18;
const long long mod = 1e9 + 7;

const int dx[] = {0,0,-1,1};
const int dy[] = {1,-1,0,0};

//  code là cái gì ?

using namespace std;

ll n,m;
string a[MAX];
vii e[MAX][MAX];
bool visited[MAX][MAX];

void solve(ll x,ll y){

    vii q;
    q.push_back({x,y});

    visited[x][y] = 1;
    ll cur = 0;
    while (cur < q.size()) {
        ll x = q[cur].X;
        ll y = q[cur].Y;
        cur++;
        for (auto p : e[x][y]) {
            ll x_ = p.X;
            ll y_ = p.Y;
            if (visited[x_][y_] == 0) {
                q.push_back({x_, y_});
                visited[x_][y_] = 1;
            }
        }
    }
    char best_c = 0;
    ll best_cost = 1e9;
    for (char c = '0'; c <= '9'; c++) {
        ll cost = 0;
        for (auto p : q) {
            cost += abs(a[p.X][p.Y] - c);
        }
        if (cost < best_cost) {
            best_cost = cost;
            best_c = c;
        }
    }
    for (auto p : q) {
        a[p.X][p.Y] = best_c;
    }

}
signed main(){
    faster();
    
    cin>>n>>m;

    for(ll i = 0;i<n;i++)cin>>a[i];

    for(ll j = 0;j< m;j++){
        for(ll i = 0;i< n;i++){
            if(a[i][j] != '.'){
                ll k = i + 1;
                while(a[k][j] != '.' && k < n)k++;
                ll l = i,r = k - 1;
                while(l <= r){
                    e[l][j].push_back({r,j});
                    e[r][j].push_back({l,j});
                    l++,r--;
                }
                i = k;
            }
        }
    }
    
    for(ll i = 0;i<n;i++){
        for(ll j = 0;j<m;j++){
                if(a[i][j] != '.'){
                ll k = j + 1;
                while(a[i][k] != '.' && k < m)k++;
                ll l = j,r = k - 1;
                while(l <= r){
                    e[i][l].push_back({i,r});
                    e[i][r].push_back({i,l});
                    l++,r--;
                }
                j = k;
            }
        }
    }

    for(ll i = 0;i<n;i++){
        for(ll j = 0;j<m;j++){
            if(!visited[i][j] && a[i][j] != '.')solve(i,j);
        }
    }

    for(ll i = 0;i<n;i++){
        for(ll j = 0;j<m;j++)cout<<a[i][j];
        cout<<'\n';
    }
    #ifndef LOCAL_DEFINE
        cerr << "\nTime elapsed: " << fixed << setprecision(9) << (double)clock() / CLOCKS_PER_SEC << "s.";
    #endif
    return 0;
}