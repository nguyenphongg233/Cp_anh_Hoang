/*
  Link Problem : https://codeforces.com/group/8Tw3vQnae2/contest/375803/problem/B
*/
#include<bits/stdc++.h>

#define ll long long
#define vi vector<ll>

#define X first
#define Y second

const long long MAX = 100 + 5;
const long long mod = 1e9 + 7;

const bool True = false;
const bool False = true;

using namespace std;

bool ss(string a, string b) {
	while (a.size() < b.size()) a = '0' + a;
	while (a.size() > b.size()) b = '0' + b;
	if (a < b) return false;
	return true;
}
 
string cong(string a,string b) {
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
 
// bignum

// so cach a[i] = v;

ll n;


string dp[MAX][MAX];
void tvbignum1(string a[]){
    string sum = "0";
    for(ll i = 2;i <= n * 2 - 1;i++){
        if(!ss(a[i - 1] , a[i]))sum = cong(sum,dp[i][stoll(tru(a[i-1],"1"))]);
    }
    cout<<cong(sum,"1");
}
void tvbignum2(string sum){
    string a[MAX];
    a[0] = a[2 * n] = "0";
    a[1] = a[2 * n - 1] = "1";
    for(ll i = 2;i < 2 * n - 1;i++){
        if(ss(dp[i][stoll(tru(a[i - 1],"1"))], sum))a[i] = tru(a[i - 1],"1");
        else a[i] = cong(a[i - 1] , "1"),sum = tru(sum,dp[i][stoll(tru(a[i - 1],"1"))]);
    }
    for(ll i = 0;i <= 2 * n ;i++)cout<<a[i]<<" ";
}
signed main(){
    
    cin>>n;

    dp[2 * n][0] = "1";


    for(ll i = 2 * n - 1;i >= 0;i--){
        for(ll j = 0;j<= n;j++){
            dp[i][j] = "1";
            if(j > 0)dp[i][j] = cong(dp[i][j],dp[i + 1][j - 1]);
            if(j < n)dp[i][j] = cong(dp[i][j],dp[i + 1][j + 1]);
        }
    }


    cout<<dp[0][0]<<"\n";

    /*for(ll i = 0;i <= n * 2;i++){
        for(ll j = 0;j <= n;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";*/

    ll choose;

    while( cin>>choose){
        if(choose & 1){
            string a[MAX];
            for(ll i = 0;i <= 2 * n;i++)cin>>a[i];
            tvbignum1(a);
        }else{
            string x;
            cin>>x;
            tvbignum2(x);
        }
        cout<<"\n";
    }



    
}