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
const long long  MAX = 5005;
const long long  INF = 1e18;
const long long mod = 1e9 + 7;
 
const int dx[] = {0,0,-1,1};
const int dy[] = {1,-1,0,0};

const bool True = false;
const bool False = true;

//  code là cái gì ?
 
using namespace std;
 
 
ll n,k;
 
ll cost[MAX],dist[MAX];
vi adj[MAX];
ll step[MAX];
 
struct State{
    ll step;
    ll index;
};

struct cmp{
    bool operator()(const State &a,const State &b){
        return a.step < b.step;
    }
};
 
vi own[MAX];
 
vi bfs(ll id,ll d){
    vi a;
 
    queue<ii> h;
    h.push({id,d});
    bool check[MAX];
    while(!h.empty()){
        ii u = h.front();
        h.pop();
        if(u.Y == 0)continue;
        for(auto e : adj[u.X]){
            if(!check[e])h.push({e,u.Y - 1});
            check[e] = 1;
        }
    }
    for(ll i = 1;i<=n;i++)if(check[i] && i != id)a.push_back(i);
    return a;
}
signed main(){
    faster();
    
    cin>>n>>k;
 
    for(ll i = 1;i <= n; i++)cin>>cost[i]>>dist[i];
    
    for(ll i = 1,u,v;i <= k; i++){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    //queue<State> q;
    priority_queue<State,vector<State>,cmp> q;
    q.push({0,1});
 
    for(ll i = 1;i<=n;i++)step[i] = INF,own[i] = bfs(i,dist[i]);
    step[1] = 0;

    while(!q.empty()){
        State u = q.top();
        q.pop();

        //cout<<u.index<<" ";

        for(auto e : own[u.index]){
            if(step[e] > step[u.index] + cost[u.index]){
                step[e] = step[u.index] + cost[u.index];
                q.push({step[e],e});
            }
        }
    }

    cout<<step[n];
    #ifndef LOCAL_DEFINE
        cerr << "\nTime elapsed: " << fixed << setprecision(9) << (double)clock() / CLOCKS_PER_SEC << "s.";
    #endif
    return 0;
}