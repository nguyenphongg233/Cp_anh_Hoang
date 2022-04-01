#include<bits/stdc++.h>

#define ll long long
#define X first
#define Y second

const long long MAX = 1e3 + 5;
const long long mod = 1e9 + 7;

using namespace std;


int n,m,a,b;
vector<int> e[MAX];
int step[MAX][MAX];

signed main(){
    
    cin>>n>>m>>a>>b;

    for(ll i = 1;i<=m;i++){
        ll u,v;
        cin>>u>>v;
        e[u].push_back(v);
    }
    
    queue<pair<int,int>> h;
    h.push({a,b});
    step[a][b] = 1;

    while(!h.empty()){
        int u1 = h.front().X;
        int u2 = h.front().Y;
        h.pop();
        if(u1 == u2)return cout<<step[u1][u2] - 1,0;
        for(auto x1 : e[u1]){
            for(auto y1 : e[u2]){
                if(step[x1][y1] == 0){
                    h.push({x1,y1});
                    step[x1][y1] = step[u1][u2] + 1;
                }
            }
        }
    }
    
}