#include<bits/stdc++.h>

#define ll long long

const long long MAX = 1e6 + 5;
const long long mod = 1e9 + 7;

using namespace std;

// [i][j][z][k]
// i : luong nc binh dang co nc 
// j : binh dang co nc
// z : binh tiep theo
// k : het hoac day

int n[3],a[3],b[3],sum = 0;


bool check(int x[]){
    int y[] = {x[0],x[1],x[2]};
    sort(y ,y + 3);
    return (y[0] == b[0] && y[1] == b[1] && y[2] == b[2]);
}


struct State{
    int v,i1,i2,f;
};

int step[MAX][3][3][2];

State poor(int x[] , int i, int j){
    int y[] = {x[0],x[1],x[2]};
    State s;
    s.v = x[3 - i - j];
    s.i1 = 3 - i - j;
    if(y[i] + y[j] >= n[j]){
        y[i] = y[i] + y[j] - n[j];
        y[j] = n[j];
        s.i2 = j;
        s.f = 1;
    }else{
        y[j] += y[i];
        y[i] = 0;
        s.i2= i;
        s.f = 0;
    }
    return s;
}

void convert(State s,int x[]){
    x[s.i1] = s.v;
    x[s.i2] = (s.f == 1) ? n[s.i2] : 0;
    x[3 - s.i1 - s.i2] = sum - x[s.i1] - x[s.i2];
}

void bfs(){
    queue<State> q;
    for(int i = 0;i<3;i++){
        for(ll j = 0;j < 3;j++){
            if(i != j){
                State s = poor(a,i,j);
                q.push(s);
                step[s.v][s.i1][s.i2][s.f] = 1;
            }
        }
    }
    
    while(!q.empty()){
        State s = q.front();
        q.pop();
        int x[3];
        convert(s,x);
        if(check(x)){
            cout<<step[s.v][s.i1][s.i2][s.f];
            return;
        }
        for(int i = 0;i<3;i++){
            for(int j = 0;j<3;j++){
                if(i != j){
                    State _s = poor(x,i,j);
                    if(!step[_s.v][_s.i1][_s.i2][_s.f]){
                        step[_s.v][_s.i1][_s.i2][_s.f] = step[s.v][s.i1][s.i2][s.f] + 1;
                        q.push(_s);
                    }
                }
            }
        }
    }
    cout<<-1;
}
signed main(){
    
    cin>>n[0]>>n[1]>>n[2]>>a[0]>>a[1]>>a[2]>>b[0]>>b[1]>>b[2];
    sort(b , b + 3);
    sum = a[0] + a[1] + a[2];
    if(check(a))return cout<<0,0;
    
    bfs();
}