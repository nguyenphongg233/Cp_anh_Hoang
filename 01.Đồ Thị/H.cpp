#include<bits/stdc++.h>

#define ll long long
#define X first
#define Y second

const long long MAX = 105;
const long long mod = 1e9 + 7;

using namespace std;

ll n,m,k;

char a[MAX][MAX];

ll step[MAX][MAX][MAX];
pair<ll,ll> nextpos[MAX];

struct State{
    ll pos,row,col;
};

queue<State> h;

ll dx[] = {0,0,-1,1};
ll dy[] = {-1,1,0,0};

signed main(){
    
    cin>>n>>m>>k;

    memset(step,0,sizeof step);

    for(ll i = 1;i<=n;i++){
        for(ll j = 1;j<=m;j++){
            cin>>a[i][j];
            if(a[i][j] == 'F')nextpos[k + 1] = {i,j};
            if(a[i][j] == 'S'){
                step[i][j][0] = 1;
                h.push({0,i,j});
            }
        }
    }
    
    for(ll i = 1;i<=k;i++){
        cin>>nextpos[i].X>>nextpos[i].Y;
    }

    while(!h.empty()){
        ll row = h.front().row;
        ll col = h.front().col;
        ll pos = h.front().pos;

        //cout<<row<<" "<<col<<" "<<pos<<"\n";
        h.pop();

        if(pos == k && row == nextpos[k + 1].X && col == nextpos[k + 1].Y)return cout<<step[row][col][pos] - 1,0;

        for(ll i = 0;i<4;i++){
            ll x = row + dx[i];
            ll y = col + dy[i];
            if(x < 1 || x > n || y < 1 || y > m || a[x][y] == '#')continue;
            ll d = 0;
            if(pos != k){
            // 1 o co the tham toi da 3 o ke canh 
                for(ll qw = 1;qw <= 3;qw ++){
                if(pos + d + 1 <= k + 1){
                   for(ll z = 0;z < 4;z ++){
                      ll zx = x + dx[z];
                      ll zy = y + dy[z];
                      if(zx < 1 || zx > n || zy < 1 || zy > m)continue;
                      if(a[zx][zy] == '#' && zx == nextpos[pos + d + 1].X && zy == nextpos[pos + d + 1].Y){
                         d++;
                         break;
                      }   
                   }
                    }
                }
            }
            if(!step[x][y][pos + d]){
                step[x][y][pos + d] = step[row][col][pos] + 1;
                h.push({pos + d,x,y});
            }
        }
    }

    cout<<-1;

}