#include<bits/stdc++.h>

#define ll long long

const long long MAX = 505 * 2;
const long long mod = 1e9 + 7;

using namespace std;

int w,h,x1,y12,x2,y2;
int e[MAX][MAX][6];

int convert(char c){
    if(c == 'n')return 0;
    if(c == 'b')return 1;
    return 2;
}

struct State{
    int x,y,c;
};

int dx[] = {-1,0,1,1,0,-1};
int dy[] = {1,1,0,-1,-1,0};

int step[MAX][MAX][3];
void bfs(){
    queue<State> q;
    q.push({x1,y12,0ll});
    while(!q.empty()){
        State u = q.front();
        q.pop();
        if(u.x == x2 && u.y == y2){
            cout<<step[x2][y2][u.c];
            return;
        }
        for(int i = 0;i<6;i++){
            State v = {u.x + dx[i],u.y + dy[i],e[u.x][u.y][i]};
            if(v.c != 0 && v.c != u.c && v.x >= 0 && v.x <= h && v.y >= 0 && v.y <= w){
                if(step[v.x][v.y][v.c] == 0){
                    q.push(v);
                    step[v.x][v.y][v.c] = step[u.x][u.y][u.c] + 1;
                }
            }
        }
    }
}
signed main(){
    
    cin>>w>>h;
    cin>>x1>>y12>>x2>>y2;
    int tmp = y12;
    y12 = x1;
    x1 = tmp;
    tmp = y2;
    y2 = x2;
    x2 = tmp;
    for(int i = 0;i <= 2*h ;i++){
        string s;
        cin>>s;
        int x = i/2;
        if(i % 2 == 0){
            for(int y = 0;y < w;y++){
                e[x][y][1] = e[x][y + 1][4] = convert(s[y]);
            }
        }else{
            for(int j = 0;j <= 2 * w ;j ++){
                if(j % 2 == 0){
                    e[x][j/2][2] = e[x + 1][j/2][5] = convert(s[j]);
                }else{
                    e[x][j/2 + 1][3] = e[x + 1][j /2][0] = convert(s[j]);
                }
            }
        }
    }
    
    bfs();
    
}