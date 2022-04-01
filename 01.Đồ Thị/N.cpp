/*
  Link Problem : https://codeforces.com/group/8Tw3vQnae2/contest/371845/problem/N
*/
#include<bits/stdc++.h>

#define ll long long
#define vi vector<ll>

#define X first
#define Y second

const long long MAX = 2e5 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9;

using namespace std;


int n,m,k;

struct Edge{
    int u,v,w;
};

bool cmp(const Edge&a,const Edge&b){
        return a.w < b.w;
}

signed main(){
    
    cin>>n>>m>>k;

    
    vector<Edge> h(m + 1);

    for(ll i = 1,u,v,w;i<=m;i++)cin>>h[i].u>>h[i].v>>h[i].w;

    sort(h.begin() + 1,h.end(),cmp);

    set<int> node;

    ll p = min(k,500);
    vector<vector<pair<int,int>>> adj(n + 1);
    //cout<<"\n";
    for(ll i = 1;i<=p;i++){

        //cout<<h[i].u<<" "<<h[i].v<<" "<<h[i].w<<"\n";
        node.insert(h[i].u);
        node.insert(h[i].v);
        adj[h[i].u].push_back({h[i].v,h[i].w});
        adj[h[i].v].push_back({h[i].u,h[i].w});
    }
    
    vector<pair<pair<int,int>,int>> dist;

    vector<int> noodle(node.begin(),node.end());
    
    ll r = noodle.size();

    //cout<<"\n";

    for(ll i = 0;i<r;i++){
        ll u = noodle[i];

        //deque<pair<int,int>> h;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> h;
        ll step[MAX];

        for(ll j = 0;j<r;j++)step[noodle[j]] = INF;

        step[u] = 0;
        h.push({step[u],u});

        while(!h.empty()){
            ll v = h.top().Y;
            h.pop();

            for(auto e : adj[v]){
                if(step[e.X] > step[v] + e.Y){
                    step[e.X] = step[v] + e.Y;
                    h.push({step[e.X],e.X});
                }
            }
        }

        for(ll j = 0;j<r;j++)if(i != j)dist.push_back({{step[noodle[j]],noodle[i]},noodle[j]});

    }

    sort(dist.begin(),dist.end());
    /*for(auto x : dist){
        cout<<x.X.X<<' '<<x.X.Y<<" "<<x.Y<<"\n";
    }*/

    cout<<dist[k * 2 - 1].X.X;
}