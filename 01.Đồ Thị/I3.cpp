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

const int dx[] = {1,0,0,-1};
const int dy[] = {0,1,-1,0};

//  code là cái gì ?

using namespace std;

ll m,n;
ii str,mid,ed;
char c;
ll u,v,x,y,pu,pv,px,py;
ll dd[MAX][MAX],res = -1;
ll step[MAX][MAX][MAX][MAX];
ll kt[MAX][MAX][4];
ll check[MAX][MAX];


struct State{
    ll u,v,x,y;
};



signed main(){
    faster();
    
    cin>>n>>m;

    for(ll i = 1;i<=n;i++){
        for(ll j = 1;j<=m;j++){
            cin>> c;
            if(c != '#')dd[i][j] = 1;
            if(c == '*')str = {i,j};
            if(c == '$')mid = {i,j};
            if(c == '@')ed = {i,j};
        }
    }
    

    deque<State> g;

    g.push_back({str.X,str.Y,mid.X,mid.Y});
    step[str.X][str.Y][mid.X][mid.Y] = 0;
    while(!g.empty()){
        State t = g.front();
        g.pop_front();

        ll u = t.u;
        ll v = t.v;
        ll x = t.x;
        ll y = t.y;

        //cout<<u<<" "<<v<<" "<<x<<" "<<y<<"\n";
        ll sum = 0;
        for(ll i = 0;i < 4;i++){
            ll x_ = x + dx[i];
            ll y_ = y + dy[i];
            sum += dd[x_][y_];
        }
        if(sum == check[x][y])continue;


        for(ll i = 0;i < 4;i++){
            ll lu = u + dx[i];
            ll lv = v + dy[i];
            if(lu < 1 || lu > n || lv < 1 || lv > m )continue;
            if(dd[lu][lv]){
                if(lu == x && lv == y){
                    ll lx = x + dx[i];
                    ll ly = y + dy[i];
                    if(lx < 1 || lx > n || ly < 1 || ly > m)continue;
                    if(dd[lx][ly] && !kt[x][y][i]){
                        check[x][y]++;
                        kt[x][y][i] = 1;
                        step[x][y][lx][ly] = step[u][v][x][y] + 1;
                        g.push_back({x,y,lx,ly});
                        if(lx == ed.X && ly == ed.Y)return cout<<step[x][y][lx][ly],0;
                    }
                }else if(!step[lu][lv][x][y]){
                    step[lu][lv][x][y] = step[u][v][x][y] + 1;
                    g.push_back({lu,lv,x,y});
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