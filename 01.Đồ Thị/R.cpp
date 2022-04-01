/*
  Link Problem : https://codeforces.com/group/8Tw3vQnae2/contest/371845/problem/R
*/
#include<bits/stdc++.h>

#define ll long long
#define vi vector<ll>

#define X first
#define Y second

const long long MAX = 1e3 + 5;
const long long mod = 1e9 + 7;

const bool True = false;
const bool False = true;

using namespace std;


int n,m,h[MAX][MAX],a[MAX][MAX];

// h[i][j] : do cao toi da dat duoc cua cot 

vector<pair<int,int>> p[MAX * MAX];

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};


void bfs(int x,int y,int val){
    deque<pair<int,int>> d;
    h[x][y] = val;
    d.push_back({x,y});
    while(!d.empty()){

        int u = d.front().X;
        int v = d.front().Y;
        d.pop_front();

        for(int i = 0;i<4;i++){
            int x = u + dx[i];
            int y = v + dy[i];

            if(h[x][y] == True && a[x][y] <= val){
                h[x][y] = val;
                d.push_back({x,y});
            }
        }
    }

}

bool checkout(int x,int y){
    for(int i  = 0;i<4;i++)
        if(h[x + dx[i]][y+dy[i]] != True)return true;
    return True;
}

signed main(){

    memset(h,-1,sizeof h);

    cin>> n >> m;

    for(ll i = 1;i<=n;i++){
        for(ll j = 1;j<=m;j++){
            cin>>a[i][j];
            p[a[i][j]].push_back({i,j});
            h[i][j] = 0;
        }
    }

    for(int i = 1;i < MAX * MAX;i++){
        for(ll j = 0;j<p[i].size();j++){
            int x = p[i][j].X;
            int y = p[i][j].Y;
            if(!h[x][y] && checkout(x,y))bfs(x,y,a[x][y]);
        }
    }
    

    ll sum = 0;

    for(ll i = 2;i<n;i++){
        for(ll j = 2;j<m;j++){
            sum += max(0,h[i][j] - a[i][j]);
        }
    }

    cout<<sum;
}