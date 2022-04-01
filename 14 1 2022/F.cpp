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

ll n, m;
ll f[MAX];
ii a[MAX];
signed main() {
	cin >> n >> m;
	ll maxx = 0;
    FOR(i,1,n)cin>>a[i].X;
    FOR(i,1,n)cin>>a[i].Y;
	FOR(i, 1, n) {
		ll u = a[i].X;
        ll v = a[i].Y;
		FOD(j, m, u)f[j] = max(f[j], f[j - u] + v), maxx = max(maxx, f[j]);
	}
	cout << maxx;
}