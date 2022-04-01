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

ll l1,l2,l3,c1,c2,c3,n,s,t,f[MAX],a[MAX],value = 0;

signed main(){
       faster();
       cin >> l1 >> l2 >> l3 >> c1 >> c2 >> c3;
	   cin >> n >> s >> t;
	   a[1] = 0;
	   if (s > t) swap(s,t);
	   for (int i = 2;i<=n;i++) cin >> a[i];
	   for (int i = s + 1;i<=t;i++) {
	   f[i] = 1e18;
		 for (int j = i - 1;j>=s;j--) {
			 int distance = a[i] - a[j];
			 if (distance > l3) break;
			 if (distance > l2) value = c3;
			 else if (distance > l1) value = c2;
			 else value = c1;
			 f[i] = min(f[i],f[j] + value);
		}
	   }
	   cout << f[t];
       return 0;
}