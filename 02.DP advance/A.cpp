/*
  Link Problem : https://codeforces.com/group/8Tw3vQnae2/contest/375803/problem/A
*/
#include<bits/stdc++.h>

#define ll int
#define vi vector<ll>

#define X first
#define Y second

const long long MAX = 1e2 + 5;
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
 
// bignum

ll n;
string gt[MAX];
ll a[MAX];

// truy van 1 - > 
void findpos(ll a[]){

    bool check[MAX];

    memset(check,1,sizeof check);

    string ans = "0";

    // voi moi vi tri i -> ktra xem con nhung so nao nho hon no 
    // thi so hoac vi co the dat dc o do la (n - i) ! * so so thoa man 


    for(ll i = 1;i<=n;i++){
        ll t = 0;

        check[a[i]] = 0;

        for(ll j = a[i] - 1;j >= 1;j--){
            t += check[j];
        }

        ans = sum(ans,multi(gt[n - i],t));

        // ans += gt[n - i] * t

    }

    cout<<sum(ans,"1");


}

// truy van 2 ->
void makeitdone(string s){
    ll d[MAX];

    memset(d,1,sizeof d);


    ll i = n - 1;

    while(1){
        ll t = chia(s,gt[i]);

        bool candiv = True;
        string s_ = multi(gt[i],t);

        while(s_[0] == '0')s_.erase(0,1);

        if(s_.empty()) s_ = "0";
        if(s_ == s)candiv = true;

        string mod_ = tru(s,s_);

        if(!candiv)t++;
        else{
            for(ll i = 1;i <= n;i++){
                if(d[i] & t == 1){
                    cout<<i<<" ";
                    d[i] = 0;
                    break;
                }else if(d[i])t--;
            }
            break;
        }

        for(ll i = 1;i<=n;i++){
            if(d[i] & t == 1){
                cout<<i<<" ";
                d[i] = True;
                break;
            }else if(d[i])t--;
        }

        s = mod_;
        i--;
    }




    for(ll i = n;i >= 1;i--){
        if(d[i])cout<<i<<" ";
    }
}


signed main(){
    
    cin>>n;

    gt[1] = "1";
    gt[0] = "0";

    for(ll i = 2;i<=n;i++){
        gt[i] = multi(gt[i - 1],i);
    }

    cout<<gt[n]<<"\n";

    ll choose;

    while(cin>>choose){
        if(choose == 1){
            
            for(ll i = 1;i<=n;i++)cin>>a[i];

            findpos(a);
        }else{
            string x;
            cin>>x;

            makeitdone(x);
        }

        cout<<"\n";
    }
    
    
}