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


ll n,m,a[MAX][MAX];
ll d[MAX][MAX];
vii adj[1000005];
queue<ll> h;

signed main(){
    faster();
    
    cin>>n>>m;
    for(ll i = 1;i<=n;i++){
        for(ll j = 1;j<=m;j++){
            cin>>a[i][j];
            adj[i * j].push_back({i,j});
        }
    }
    h.push(a[1][1]);
    memset(d,0,sizeof d);
    d[1][1] = 1;
    while(!h.empty()){
        ll u = h.front();
        h.pop();
        for(auto v : adj[u]){
            if(v.X == n && v.Y == m)return cout<<"yes",0;
            if(!d[v.X][v.Y]){
                h.push(a[v.X][v.Y]);
                d[v.X][v.Y] = 1;
            }
        }
    }
    cout<<"no";
    #ifndef LOCAL_DEFINE
        cerr << "\nTime elapsed: " << fixed << setprecision(9) << (double)clock() / CLOCKS_PER_SEC << "s.";
    #endif
    return 0;
}