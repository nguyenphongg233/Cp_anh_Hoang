#include<bits/stdc++.h>

#define ll int
#define vi vector<ll>

#define X first
#define Y second

const long long MAX = 3e3 + 5;
const long long N = 15;
const long long mod = 1e9 + 7;
const long long INF = 1e9;

using namespace std;


ll n,m;

ll adj[MAX][N][4];
/*
       0
       |
       |
3 <--- . ---> 1
       |
       |
       2

*/

ll dx[] = {-1,0,1,0};
ll dy[] = {0,1,0,-1};

// di chuyen theo huong 3 , 2 , 1

signed main(){
    
    cin>>n>>m;


    for(ll i = 0;i<=n + 5;i++){
        for(ll j = 0;j<=m + 6;j++){
            for(ll z = 0;z <=4;z++){
                adj[i][j][z] = INF;
            }
        }
    }
    for(ll j = 1;j<=m;j++){
        adj[1][j][1] = adj[1][j][3] = INF;
        cin>>adj[1][j][2];
        adj[2][j][0] = adj[1][j][2];
    }
    
    for(ll i = 2;i<=n;i++){
        for(ll j = 1;j< m;j++){
            cin>>adj[i][j][1];
            adj[i][j + 1][3] = adj[i][j][1];
        }
        for(ll j = 1;j<=m;j++){
            cin>>adj[i][j][2];
            adj[i + 1][j][0] = adj[i][j][2];
        }
    }

    for(ll j = 1;j<m;j++){
        cin>>adj[n + 1][j][1];
        adj[n + 1][j + 1][3] = adj[n + 1][j][1];
    }

    /*for(ll i = 1;i<=n + 1;i++){
        for(ll j = 1;j<=m;j++){
            cout<<"("<<i<<","<<j<<") : "<<" = {"<<adj[i][j][0]<<","<<adj[i][j][1]<<","<<adj[i][j][2]<<","<<adj[i][j][3]<<"}  ";
        }
        cout<<"\n";
    }*/

    // str = 1 j ( j : 1 - > m) 
    // ed = n m 

    deque<pair<ll,ll>> h;

    ll step[MAX][N];

    for(ll i = 0;i<=n + 5;i++){
        for(ll j = 0;j<=m + 5;j++){
            step[i][j] = INF;
        }
    }
    for(ll i = 1;i<=m;i++){
        step[1][i] = 0;
        h.push_back({1,i});
    }


    while(!h.empty()){
        ll i = h.front().X;
        ll j = h.front().Y;

        h.pop_front();

        for(ll z = 0;z<=3;z++){
            ll x = i + dx[z];
            ll y = j + dy[z];

            if(x < 1 || x > n + 1 || y < 1 || y > m)continue;
            if(step[x][y] > step[i][j] + adj[i][j][z]){
                step[x][y] = step[i][j] + adj[i][j][z];
                h.push_back({x,y});
            }
        }
    }

    cout<<step[n + 1][m];
}