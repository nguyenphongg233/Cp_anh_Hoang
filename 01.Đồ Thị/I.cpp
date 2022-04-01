#include<bits/stdc++.h>

#define ll long long
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
const long long  MAX = 85;
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

// tim duong di ngan nhat tren moi cap diem
ll bfs(ii str,ii mid,char a[MAX][MAX]){
    deque<ii> d;

    d.push_back(str);
    ll sleep[MAX][MAX];
    bool visited[MAX][MAX];
    sleep[str.X][str.Y] = 1;

    while(!d.empty()){
        ii u = d.front();
        d.pop_front();

        ll x = u.X;
        ll y = u.Y;

        if(x == mid.X && y == mid.Y)return sleep[x][y] - 1;
        for(ll i = 0;i<4;i++){
            ll xi = x + dx[i];
            ll yi = y + dy[i];

            if(xi < 1 || xi > n || yi < 1 || yi > m || a[xi][yi] == '#' ||a[xi][yi] == '@'|| visited[xi][yi])continue;
               visited[xi][yi] = 1;
               sleep[xi][yi] = sleep[x][y] + 1;
               d.push_back({xi,yi});
        }
            
    }
    return -1;
}
// kong bug


bool check(ll x,ll y){
    return (x >= 1 && x <= n && y >= 1 && y <= n && a[x][y] != '#');
}
signed main(){
    faster();
    
    cin>>n>>m;

    memset(step,0,sizeof step);
    ii str,mid,end;
    for(ll i = 1;i<=n;i++){
        for(ll j = 1;j<=m;j++){
            cin>>a[i][j];
            if(a[i][j] == '*')str = {i,j};
            if(a[i][j] == '$')mid = {i,j};
            if(a[i][j] == '@')end = {i,j};
        }
    }

    // tim duong di tu xe -> kien hang
    //a[1][4] = '#';
    //cout<<bfs({2,4},{1,5},a);
    ll sleep[MAX][MAX];
    bool visited[MAX][MAX];

    sleep[str.X][str.Y] = 1;

    deque<ii> d;
    deque<State> g;

    d.push_back(str);

    while(!d.empty()){
        ii u = d.front();
        d.pop_front();

        ll x = u.X;
        ll y = u.Y;

        for(ll i = 0;i<4;i++){
            ll xi = x + dx[i];
            ll yi = y + dy[i];

            if(xi < 1 || xi > n || yi < 1 || yi > m || a[xi][yi] == '#'|| visited[xi][yi])continue;
            if(a[xi][yi] == '$'){
                step[x][y][xi][yi] = sleep[x][y] - 1;
                g.push_back({x,y,xi,yi});
            }else{
               visited[xi][yi] = 1;
               sleep[xi][yi] = sleep[x][y] + 1;
               d.push_back({xi,yi});
            }
            
        }
    }
    // bfs loang 
    // clear k bug 

    while(!g.empty()){

        State u = g.front();
        g.pop_front();

        ll x = u.xs;
        ll y = u.ys;
        ll xi = u.xm;
        ll yi = u.ym;

        cout<<x<<" "<<y<<" "<<xi<<" "<<yi<<" : "<<step[x][y][xi][yi]<<"\n";
        if(xi == end.X && yi == end.Y)return cout<<step[x][y][xi][yi],0;
        ll no1 = xi - x;
        ll no2 = yi - y;

        x = xi;
        y = yi;

        xi += no1;
        yi += no2;

        if(check(x,y) && check(xi,yi) && step[x][y][xi][yi] == 0){
            step[x][y][xi][yi] = step[u.xs][u.ys][u.xm][u.ym] + 1;
            g.push_back({x,y,xi,yi});

        }
        x = u.xs;
        y = u.ys;
        xi = u.xm;
        yi = u.ym;

        for(ll i = 0;i<4;i++){
            ll xz = xi + dx[i];
            ll yz = yi + dy[i];
            if(check(xz,yz)){
                a[xi][yi] = '#';
                ll p = bfs({x,y},{xz,yz},a);
                a[xi][yi] = '.';
                if(p < 1)continue;
                if(x == 2 && y == 4 && xz == 1 && yz == 5)cout<<"\n"<<p<<"\n";
                if(!step[xz][yz][xi][yi]){
                   step[xz][yz][xi][yi] = step[x][y][xi][yi] + p;
                   g.push_back({xz,yz,xi,yi});
                }
            }
        }
    }
    
    
    #ifndef LOCAL_DEFINE
        cerr << "\nTime elapsed: " << fixed << setprecision(9) << (double)clock() / CLOCKS_PER_SEC << "s.";
    #endif
    return 0;
}