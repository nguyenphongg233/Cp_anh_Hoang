/*
  Link Problem : 
*/
#include<bits/stdc++.h>

#define ll long long
#define vi vector<ll>

#define X first
#define Y second

const long long MAX = 1e5 + 5;
const long long mod = 1e9 + 7;

const bool True = false;
const bool False = true;

using namespace std;




string dp[115][215];
int a[215];
int n,tv;
string s;
string ans;
 
 
bool ss(string a, string b) {
	while (a.size() < b.size()) a = '0' + a;
	while (a.size() > b.size()) b = '0' + b;
	if (a < b) return false;
	return true;
}
 
string sum(string a,string b) {
	string c = "";
	int res = 0, mem = 0;
	while (a.size() < b.size()) a = "0" + a;
	while (a.size() > b.size()) b = "0" + b;
	for (int i = a.size() - 1;i>=0;i--) {
		res = a[i] + b[i] - 96 + mem;
		mem = res / 10;
		c = char(res%10 + 48) + c;
	}
	if (mem != 0) c = "1" + c;
	return c;
}
 
string tru(string a, string b) {
    while (a.size() > b.size()) b = "0" + b;
    while (a.size() < b.size()) a = "0" + a;
    int s;
    string c = "";
    int mem = 0;
    for (int i=a.size()-1; i>=0; i--) {
        s = a[i] - b[i] - mem;
        if (s < 0) {
            s += 10;
            mem = 1;
        }
        else mem = 0;
        c = char(s+48) + c;
    }
    while ((c.size() > 1) && c[0] == '0') c.erase(0, 1);
    return c;
}
 
string multi(string a,int k) {
	string c = "";
	int mem = 0,s;
	for (int i = a.size() - 1;i>=0;i--) {
		s = (a[i] - 48) * k + mem;
		mem = s/10;
		c = char(s%10 + 48) + c;
	}
	string tmp;
	if (mem > 0) tmp = to_string(mem);
	else tmp = "";
	c = tmp + c;
	return c;
}
 
int chia(string a, string b){
    int ans = 0;
    while(ss(a,b)){
        a = tru(a,b);
        ans++;
    }
    return ans;
}
 
signed main(){

    cin >> n;
    dp[0][2*n+1] = "1";
    dp[1][2*n] = "1";
    for(int i = 2*n-1; i >= 1; i--){
        for(int j = 0; j <= n; j++){
            dp[j][i] = "0";
            if(j > 0) dp[j][i] = sum(dp[j][i], dp[j-1][i+1]);
            dp[j][i] = sum(dp[j][i], dp[j+1][i+1]);
        }
    }
    cout << dp[1][2] << endl;
    while(cin >> tv){
        if(tv == 1){
            ans = "1";
            for(int i = 1; i <= 2*n+1; i++)cin >> a[i];
            for(int i = 1; i <= 2*n+1; i++)
                if(a[i] > a[i-1])if(a[i-1] > 0)ans = sum(ans, dp[a[i-1]-1][i]);
            
            cout << ans << "\n";
        }
        else{
            cin >> s;
            s = tru(s, "1");
            int t = 0;
            cout << 0 << " ";
            for(int i = 2; i <= 2*n; i++){
                if(t == 0){
                    t = 1;
                    cout << 1 << " ";
                }
                else if(t == n){
                    cout << n-1 << " ";
                    t = n-1;
                }
                else{
                     if(ss(s, dp[t-1][i])){
                        s = tru(s, dp[t-1][i]);
                        cout << t+1 << " ";
                        t+=1;
                     }else{
                        cout << t-1 << " ";
                        t-=1;
                     }
                }
            }
            cout << 0 << " " << '\n';
        }
    }
    return 0;
}