#include<bits/stdc++.h>

#define ll int
#define ld long double

#define X first
#define Y second

#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define getbit(x,n) ((x >> n) & 1);
#define turnoff(x,n) (x & ~(1 << n));
#define turnon(x,n) (x | (1<<n))

#define vi vector<ll>
#define ii pair<ll, ll>
#define vii vector<pair<ll, ll>>
#define matrix vector<vi>

const double pi = 1.00 * acos(-1.00);
const long long  MAX = 81;
const long long  INF = 1e18;
const long long mod = 1e9 + 7;

const int dx[] = {0,0,-1,1};
const int dy[] = {1,-1,0,0};

//  code là cái gì ?

using namespace std;


ll n,m;
char a[MAX][MAX];
ll step[MAX][MAX][MAX][MAX];

struct State{
    ll xs,ys,xm,ym;
};

ll check[MAX][MAX];
ll dd[MAX][MAX];
ll kt[MAX][MAX][4];

signed main(){
    faster();
    
    cin>>n>>m;

    ii str,mid,end;
    for(ll i = 1;i<=n;i++){
        for(ll j = 1;j<=m;j++){
            cin>>a[i][j];
            if(a[i][j] == '*')str = {i,j};
            if(a[i][j] == '$')mid = {i,j};
            if(a[i][j] == '@')end = {i,j};
        }
    }

    step[str.X][str.Y][mid.X][mid.Y] = 1;
    deque<State> g;
    g.push_back({str.X,str.Y,mid.X,mid.Y});

    while(!g.empty()){
        State u = g.front();
        g.pop_front();

        ll x = u.xs;
        ll y = u.ys;
        ll xi = u.xm;
        ll yi = u.ym;

        //cout<<x<<" "<<y<<" "<<xi<<" "<<yi<<" : "<<step[x][y][xi][yi]<<"\n";

        if(a[xi][yi] == '@')return cout<<step[x][y][xi][yi] - 1,0;

        ll sum = 0;
        for(ll i = 0;i < 4;i++){
            ll xz = x + dx[i];
            ll yz = y + dy[i];                                              
            if(xz < 1 || xz > n || yz < 1 || yz > m || a[xz][yz] == '#' )continue;
            sum += dd[xz][yz];
        }

        if(check[xi][yi] == sum)continue;


        for(ll i = 0;i < 4;i++){
            ll xz = x + dx[i];
            ll yz = y + dy[i];                                              
            if(xz < 1 || xz > n || yz < 1 || yz > m || a[xz][yz] == '#' )continue;
            if(dd[xz][yz]){
                if(xz == xi && yz == yi){
                   ll xxz = xi + dx[i];
                   ll yyz = yi + dy[i];
                   if(xxz < 1 || xxz > n ||yyz < 1 || yyz > m || a[xxz][yyz] == '#')continue;
                   if(dd[xxz][yyz] && !kt[x][y][i]){
                       check[x][y]++;
                       kt[x][y][i] = 1;
                       if(!step[xz][yz][xxz][yyz]){
                          step[xz][yz][xxz][yyz] = step[x][y][xi][yi] + 1;
                          g.push_back({xz,yz,xxz,yyz});
                       }
                   }
            }else if(!step[xz][yz][xi][yi]){
                step[xz][yz][xi][yi] = step[x][y][xi][yi] + 1;
                g.push_back({xz,yz,xi,yi});
            }
        }

        
    }
    }
    
    cout<<-1;
    
    #ifndef LOCAL_DEFINE
        cerr << "\nTime elapsed: " << fixed << setprecision(9) << (double)clock() / CLOCKS_PER_SEC << "s.";
    #endif
    return 0;
}