#include<bits/stdc++.h>

#define ll long long
#define vi vector<ll>

#define X first
#define Y second

const long long MAX = 1e5 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e18;
using namespace std;

struct Edge{
    int v,a,b,d;
};

vector<Edge> g[MAX];

signed main(){

    int n,m,s,tr;

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>s>>tr;

    for(int i = 0,u,v,a,b,d;i< m;i++){
        cin>>u>>v>>a>>b>>d;
        g[u].push_back({v,a,b,d});
        g[v].push_back({u,a,b,d});

    }
    
    priority_queue<pair<ll,int>> h;

    vector<ll> t(n + 1,INF);
    t[s] = 0;
    h.push({0,s});

    while(!h.empty()){
        int u = h.top().Y;
        ll f = -h.top().X;
        h.pop();
        if(u == tr)return cout<<f,0;
        if(t[u] == f){
            for(auto e : g[u]){
                int v = e.v;
                int a = e.a;
                int b = e.b;
                int d = e.d;
                int x = t[u] % (a + b);
                ll cp = 0;
                if(x + d <= a)cp = t[u] + d;
                else cp = t[u] + (a + b - x) + d;
                if(d <= a && cp < t[v]){
                    t[v] = cp;
                    h.push({-t[v],v});
                }
            }
        }
    }
    cout<<-1;
}