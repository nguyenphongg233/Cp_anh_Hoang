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
const long long  MAX = 1005;
const long long  INF = 1e18;
const long long mod = 1e9 + 7;


//  code là cái gì ?

using namespace std;

ll step[MAX][MAX][5];


struct State{
    ll x,y,h;
};


ll dx[] = {-1,0,1,0,0};
ll dy[] = {0,1,0,-1,0};
/*







*/

bool check(ll x,ll y,ll n,ll m,char a[MAX][MAX]){
    if(x >= 0 && x < n && y >= 0 && y < m && a[x][y] != '*')return true;
    return false;
}

void bfs(ll sx,ll sy,ll tx,ll ty,char a[MAX][MAX],ll n,ll m){

    queue<State> q;

    q.push({sx,sy,4});

    memset(step,-1,sizeof step);
    step[sx][sy][4] = 0;

    while(!q.empty()){
        State u = q.front();

        ll x = u.x;
        ll y = u.y;
        ll h = u.h;

        //cout<<x<<" "<<y<<" "<<h<<" \n";

        if(x == tx && y == ty && h == 4){
            cout<<step[x][y][h];
            return;
        }
        q.pop();

        for(ll k = 0;k < 4;k++){

            ll x1,y1,h1;

            x1 = x + dx[k];
            y1 = y + dy[k];
            if(h == 4)h1 = k;
            // hcv dung 
            else {
                if(k % 2 != h%2) h1 = h;
                else{
                    if(k == h){
                        x1 = x + 2*dx[k];
                        y1 = y + 2*dy[k];
                        // chuyen trang thai 
                        // h cung huong voi k
                        // di chuyen thg dung 
                    }
                    h1 = 4;
                }
            }
            ll x2 = x1 + dx[h1];
            ll y2 = y1 + dy[h1];
            if(k == h)x2 = x2,y2 = y1;
            //swap(x1,x2);
            //swap(y1,y2);
            if(check(x1,y1,n,m,a) && check(x2,y2,n,m,a)){
                //cout<<x1 + 1<<" "<<y1 + 1<<" "<<x2 + 1<<" "<<y2 + 1<<" "<<h1<<'\n';
                if(step[x1][y1][h1] == -1){
                    q.push({x1,y1,h1});
                    step[x1][y1][h1] = step[x][y][h] + 1;
                }
            }
        }
    }

    cout<<-1;


}


signed main(){
    faster();
    
    ll t;
    cin>>t;

    while(t--){
        char a[MAX][MAX];

        ll n,m;
        cin>>n>>m;

        for(ll i = 0;i<n;i++){
            for(ll j = 0;j<m;j++){
                cin>>a[i][j];
            }
        }

        ll sx,sy,tx,ty;
        cin>>sx>>sy>>tx>>ty;
        sx--;
        sy--;
        tx--;
        ty--;

        bfs(sx,sy,tx,ty,a,n,m);
        cout<<"\n";
    }
    
    
    
    #ifndef LOCAL_DEFINE
        cerr << "\nTime elapsed: " << fixed << setprecision(9) << (double)clock() / CLOCKS_PER_SEC << "s.";
    #endif
    return 0;
}

/*1  
4 4
. . . . 
. . . .
. . . .
. . . .
2 2
4 4*/