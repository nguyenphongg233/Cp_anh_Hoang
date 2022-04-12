/*
  Link Problem : https://codeforces.com/group/8Tw3vQnae2/contest/375803/problem/G
*/
#include<bits/stdc++.h>

#define ll long long
#define vi vector<ll>

#define X first
#define Y second

const long long MAX = 1e5 + 5;
const long long mod2 = 1e9 + 7;

const bool True = false;
const bool False = true;

using namespace std;


ll dp[33][110][110][2];
ll n,x;
string s;
// dp(i,mod,sum, <= n)

ll calc(ll i,ll sum,ll mod,ll lower){
    if(i == s.size())
        if(mod == 0 && sum == x)return 1;
        else return 0;
    
    if(dp[i][sum][mod][lower] != -1)return dp[i][sum][mod][lower];

    ll nextdigit = lower ? 9 : s[i] - '0';
    ll res = 0;

    for(ll next = 0;next <= nextdigit;next++){
        ll lower2 = lower || next < s[i] - '0';
        res += calc(i + 1,sum + next,(mod * 10 + next) % x,lower2);
    } 

    return dp[i][sum][mod][lower] = res;
}

signed main(){
    
    
    ll n;
    cin>>n;

    s = to_string(n);



    ll sum = 0;

    for(ll i = 1;i < 109;i++){
        memset(dp,-1,sizeof dp);
        x = i;
        sum += calc(0,0,0,0);
    }

    cout<<sum;
    
}