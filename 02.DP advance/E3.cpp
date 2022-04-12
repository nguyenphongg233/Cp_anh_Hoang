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


ll l,r,pg = 0;
ll dp[22][2][2][3][3][3][3][3][3][3][3][3][3];

ll calc(string s,ll i,bool lower,bool pos,ll s0,ll s1,ll s2,ll s3,ll s4,ll s5,ll s6,ll s7,ll s8,ll s9){
    if(i == s.size())return 1;
    if(dp[i][lower][pos][s0][s1][s2][s3][s4][s5][s6][s7][s8][s9] != -1)return dp[i][lower][pos][s0][s1][s2][s3][s4][s5][s6][s7][s8][s9];

    if(i > 0 && !pos){
      if(!pg)s0--;
      else pos = 1;
    }

    ll canput = lower ? s[i] - '0' : 9;
    ll sum = 0;

    for(ll next = 0;next <= canput;next++){
        ll s00 = s0,s01=s1,s02=s2,s03=s3,s04=s4,s05=s5,s06=s6,s07=s7,s08=s8,s09=s9;
        if(next == 0)s00++;
       else if(next == 1)s01++;
       else if(next == 2)s02++;
       else if(next == 3)s03++;
       else if(next == 4)s04++;
       else if(next == 5)s05++;
       else if(next == 6)s06++;
       else if(next == 7)s07++;
       else if(next == 8)s08++;
       else if(next == 9)s09++;

       pg = next;
       ll lower2 = lower & (next == canput);
       if(s00 > 2 || s01 > 2|| s02 > 2|| s03 > 2|| s04 > 2|| s05 > 2|| s06 > 2|| s07 > 2|| s08 > 2|| s09 > 2)continue;
       sum += calc(s,i + 1,lower2,pos,s00,s01,s02,s03,s04,s05,s06,s07,s08,s09);

    }

    return dp[i][lower][pos][s0][s1][s2][s3][s4][s5][s6][s7][s8][s9] = sum;
}

signed main(){
    
    cin >> l >> r;
	l--;
	string a = to_string(r);
	string b = to_string(l);
	memset(dp, -1, sizeof(dp));
	ll x = calc(a, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	memset(dp, -1, sizeof(dp));
	ll y = calc(b, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
 
	cout << x - y;
    
    
    
}