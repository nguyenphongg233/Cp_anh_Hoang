#include<bits/stdc++.h>

#define ll long long
#define ld long double

#define X first
#define Y second

#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<ll>
#define ii pair<ll, ll>
#define vii vector<pair<ll, ll>>

#define FOR(i, a, b) for (ll i = a; i <= b; i++)
#define FOD(i, a, b) for (ll i = a; i >= b; i--)

const double pi = 1.00 * acos(-1.00);
const long long  MAX = 100005;
const long long  INF = 361700864190383365;
const long long mod = 1e9 + 7;

// Nguyễn Phongg :))
using namespace std;


ll n, f[5005][5005];
string s, t;

signed main(){
    faster();
    cin >> n >> s;
    t = s;
    reverse(t.begin(), t.end());
    s = " " + s;
    t = " " + t;
    f[0][0] = 0;
    FOR(i,1,n){
        FOR(j,1,n){
            if(s[i] == t[j]) f[i][j] = max(f[i-1][j-1] + 1, 1ll);
            else f[i][j] = max(f[i-1][j], f[i][j-1]);
        }
    }
    cout << n - f[n][n];
    return 0;
}