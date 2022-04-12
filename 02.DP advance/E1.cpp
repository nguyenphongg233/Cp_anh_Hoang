/*
  Link Problem : https://codeforces.com/group/8Tw3vQnae2/contest/375803/problem/E
*/
#include<bits/stdc++.h>

#define ll long long
#define vi vector<ll>
#define FOR(i,a,b) for(ll i = a;i <= b;i++)

#define X first
#define Y second

const long long MAX = 1e5 + 5;
const long long mod = 1e9 + 7;

const bool True = false;
const bool False = true;

using namespace std;

ll n;
string a,b;
ll cs[MAX];
ll dp[22][2][2][3][3][3][3][3][3][3][3][3][3];

// f(i,<= n, > 0,0,1,2,3,4,5,6,7,8,9)
ll predigit = 0;

ll calc(ll i,bool lower,bool pos,ll s0,ll s1,ll s2,ll s3,ll s4,ll s5,ll s6,ll s7,ll s8,ll s9){

    if(i == n)return 1;

    if(dp[i][lower][pos][s0][s1][s2][s3][s4][s5][s6][s7][s8][s9] != -1)return dp[i][lower][pos][s0][s1][s2][s3][s4][s5][s6][s7][s8][s9];

    if(i > 0 && !pos){
      if(!predigit)s0--;
      else pos = 1;

    }
    ll canput = (!lower) ? 9 : cs[i];
    ll sum = 0;
    

    for(ll next = 0;next <= canput;next++){
       ll s00 = s0,s01=s1,s02=s2,s03=s3,s04=s4,s05=s5,s06=s6,s07=s7,s08=s8,s09=s9;
       if(next == 0)s00++,predigit = 0;
       else if(next == 1)s01++,predigit = 1;
       else if(next == 2)s02++,predigit = 2;
       else if(next == 3)s03++,predigit = 3;
       else if(next == 4)s04++,predigit = 4;
       else if(next == 5)s05++,predigit = 5;
       else if(next == 6)s06++,predigit = 6;
       else if(next == 7)s07++,predigit = 7;
       else if(next == 8)s08++,predigit = 8;
       else if(next == 9)s09++,predigit = 9;




      if(s00 > 2 || s01 > 2|| s02 > 2|| s03 > 2|| s04 > 2|| s05 > 2|| s06 > 2|| s07 > 2|| s08 > 2|| s09 > 2)continue;

      sum += calc(i + 1,lower & (next == canput),pos,s00,s01,s02,s03,s04,s05,s06,s07,s08,s09);

    }

    return dp[i][lower][pos][s0][s1][s2][s3][s4][s5][s6][s7][s8][s9] = sum;
    
}

signed main(){
    
    ll l,r;
    cin>>l>>r;

    memset(dp,-1,sizeof dp);
    string a = to_string(l - 1);
    ll n = a.size();
    for(ll i = 0;i < a.size();i++)cs[i] = a[i] - '0';

    ll x = calc(0,1,0,0,0,0,0,0,0,0,0,0,0);

    memset(dp,-1,sizeof dp);
    memset(cs,0,sizeof cs);

    string b = to_string(r);
    n = b.size();
    for(ll i = 0;i < b.size();i++)cs[i] = b[i] - '0';

    ll y = calc(0,1,0,0,0,0,0,0,0,0,0,0,0);

    cout<<y - x;
}