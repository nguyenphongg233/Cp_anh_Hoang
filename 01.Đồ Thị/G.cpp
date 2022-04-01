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
const long long  MAX = 305;
const long long  INF = 1e18;
const long long mod = 1e9 + 7;

const int dx[] = {0,0,-1,1};
const int dy[] = {1,-1,0,0};

//  code là cái gì ?

using namespace std;

ll n,m,k;
char a[MAX][MAX];
string s;
ll dist[MAX][MAX][MAX];

struct s1mp{
    ll disc,next,row,col;
};

queue<s1mp> h;
signed main(){
    faster();
    
    cin>>n>>m>>k>>s;
    s = " " + s;
    memset(dist,-1,sizeof dist);
    for(ll i = 1;i<=n;i++){
        for(ll j = 1;j<=m;j++){
            cin>>a[i][j];
            if(a[i][j] == s[1]){
                dist[i][j][1] = 1;
                h.push({0,1,i,j});
            }
        }
    }
    
    while(!h.empty()){
        ll discc = h.front().disc;
        ll nextt = h.front().next;
        ll nr = h.front().row;
        ll mr = h.front().col;
        h.pop();
        //if(nextt == k)continue;
        for(ll i = 0;i<=3;i++){
            ll x = nr + dx[i];
            ll y = mr + dy[i];
            if(x < 1 || x > n || y < 1 || y > m)continue;
            ll nec = (a[x][y] == s[nextt + 1]) ? (nextt + 1) : nextt;
            if(dist[x][y][nec] != -1)continue;
            dist[x][y][nec] = dist[nr][mr][nextt] + 1;
            h.push({dist[x][y][nec],nec,x,y});
        }
    }
    
    ll ans = INF;

    for(ll i = 1;i<=n;i++){
        for(ll j = 1;j<=m;j++){
            ans = min(ans,dist[i][j][k]);
        }
    }
    cout<<ans;
    #ifndef LOCAL_DEFINE
        cerr << "\nTime elapsed: " << fixed << setprecision(9) << (double)clock() / CLOCKS_PER_SEC << "s.";
    #endif
    return 0;
}