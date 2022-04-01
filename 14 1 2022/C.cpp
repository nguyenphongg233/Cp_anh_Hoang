#include <bits/stdc++.h>

#define ll long long
#define X first
#define Y second

#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<ll>
#define ii pair<ll, ll>
#define vii vector<pair<ll, ll>>

#define FOR(i, a, b) for (ll i = a; i <= b; i++)
#define FOD(i, a, b) for (ll i = a; i >= b; i--)

const long long  MAX = 105;
const long long  INF = 20000000000000000;

// Nguyễn Phongg :)) sample template 
using namespace std;

ll n;
bool cmp(ii a, ii b) {
	return a.Y < b.Y;
}
signed main() {
	cin >> n;
	vii a(n + 1);
	vi f(n + 1);
	f[0] = 0;
	FOR(i, 1, n)cin >> a[i].X >> a[i].Y;
	sort(a.begin()+1, a.end(),cmp);
	FOR(i, 1, n) {
		ll q = 0;
		FOD(j, i - 1, 0)if (a[i].X >= a[j].Y) {
			q = j;
			break;
		}
		f[i] = max(f[i - 1], f[q] + 1);
	}
	cout << f[n];
}