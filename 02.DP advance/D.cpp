#include<bits/stdc++.h>

#define ll long long
#define X first
#define Y second

#define vi vector<ll>
#define ii pair<ll,ll>

const long long MAX = 1e2 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9;

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


ll l,d;
string k;
string dp[MAX][2][MAX][MAX];
// stt,(1/0),tong,bac
string f(ll i,bool c,ll si,ll b){
    if(i == l){
       if(b == d && si == 0)return dp[i][c][si][b] = "1";
       else return dp[i][c][si][b] = "0";
    }

    if(dp[i][c][si][b].size())return dp[i][c][si][b];

    string sum = "0";

    sum = cong(sum,f(i + 1,0,si + 1,max(b,si + 1)));

    if(si > 0)sum = cong(sum,f(i + 1,1,si - 1,max(b,si - 1)));

    
    return dp[i][c][si][b] = sum;
}





signed main(){
    
    cin>>l>>d>>k;

    cout<<f(0,0,0,0)<<"\n";


    ll si = 0,b = 0;
    for(ll i = 1;i <= l;i++){


        if(dp[i][1][si - 1][b].size() == 0)dp[i][1][si - 1][b] = "0";

        if(ss(dp[i][1][si - 1][b],k))cout<<')',si--;
        else cout<<'(',k = tru(k,dp[i][1][si - 1][b]),si++,b = max(b,si);
        
    }
}