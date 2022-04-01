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

ll a,b,c;
ll step[MAX][MAX];

// do binh 1 - > 2
// do binh 2 - > 1
// do day binh 1 = may
// do day binh 2 = may
// do het nuoc binh 1
// do het nuoc binh 2

ii poor(ll x,ll y,ll base){
   // do tu x -> y;
   ii ans;

   if(x + y < base)ans = {0,x + y};
   else ans = {x - base + y,base};

   return ans;

}

signed main(){
    faster();
    
    cin>>a>>b>>c;

    queue<ii> h;
    step[0][b] = 1;
    step[a][0] = 1;
    step[a][b] = 1;
    h.push({0,b});
    h.push({a,0});
    h.push({a,b});
    while(!h.empty()){
        ll x = h.front().X;
        ll y = h.front().Y;
        if(x == c || y == c)return cout<<step[x][y],0;
        h.pop();
        // do binh 1 - > 2
        ii u = poor(x,y,b);
        if(!step[u.X][u.Y]){
            step[u.X][u.Y] = step[x][y] + 1;
            h.push(u);
        }
        u = poor(y,x,a);
        // do binh 2 - > 1
        if(!step[u.Y][u.X]){
            step[u.Y][u.X] = step[x][y] + 1;
            h.push({u.Y,u.X});
        }
        // do day binh 1 = may
        if(!step[a][y]){
            step[a][y] = step[x][y] + 1;
            h.push({a,y});
        }
        // do day binh 2 = may
        if(!step[x][b]){
            step[x][b] = step[x][y] + 1;
            h.push({x,b});
        }
        if(!step[x][0]){
            step[x][0] = step[x][y] + 1;
            h.push({x,0});
        }
        // do het nuoc binh 2
        if(!step[0][y]){
            step[0][y] = step[x][y] + 1;
            h.push({0,y});
        }
    }
    
    cout<<-1;
    
    #ifndef LOCAL_DEFINE
        cerr << "\nTime elapsed: " << fixed << setprecision(9) << (double)clock() / CLOCKS_PER_SEC << "s.";
    #endif
    return 0;
}