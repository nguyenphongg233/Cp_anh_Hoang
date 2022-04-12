/*
  Link Problem : https://codeforces.com/group/8Tw3vQnae2/contest/375803/problem/E
*/
#include<bits/stdc++.h>

#define ll long long
#define vi vector<ll>

#define X first
#define Y second
#define FOR(i,a,b) for(ll i = a;i <= b;i++)

const long long MAX = 1e5 + 5;
const long long mod = 1e9 + 7;

const bool True = false;
const bool False = true;

using namespace std;


ll calc(ll x){

    string s = to_string(x);
    ll cs[MAX];
    for(ll i = 1;i <= s.size();i++){
        cs[i] = s[i - 1] - '0';
    }

    //dp(i,lower,> 0,0,1,2,3,4,5,6,7,8,9)

    ll dp[25][2][2][3][3][3][3][3][3][3][3][3][3];

    dp[0][1][0][0][0][0][0][0][0][0][0][0][0] = 1;
    for(ll i = 0;i<s.size();i++){
        for(ll lower = 0;lower < 2;lower++){
            for(ll pos = 0;pos < 2;pos++){
            for(ll next = 0;next < 10;next++){
                if(!lower && next > cs[i + 1])continue;
                ll lower2 = lower || next < cs[i + 1];
                ll pos2 = pos || next > 0;
                FOR(s0,0,2)FOR(s1,0,2)FOR(s2,0,2)FOR(s3,0,2)FOR(s4,0,2)FOR(s5,0,2)FOR(s6,0,2)FOR(s7,0,2)FOR(s8,0,2)FOR(s9,0,2){

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




                    if(s00 > 2 || s01 > 2|| s02 > 2|| s03 > 2|| s04 > 2|| s05 > 2|| s06 > 2|| s07 > 2|| s08 > 2|| s09 > 2)continue;
                    dp[i + 1][lower2][pos2][s00][s01][s02][s03][s04][s05][s06][s07][s08][s09] += dp[i][lower][pos][s0][s1][s2][s3][s4][s5][s6][s7][s8][s9];
                }
            }
            }
        }
    }


    ll sum = 0;

    FOR(s0,0,2)FOR(s1,0,2)FOR(s2,0,2)FOR(s3,0,2)FOR(s4,0,2)FOR(s5,0,2)FOR(s6,0,2)FOR(s7,0,2)FOR(s8,0,2)FOR(s9,0,2){
        sum += dp[s.size()][1][1][s0][s1][s2][s3][s4][s5][s6][s7][s8][s9];
    }


    return sum;
}

signed main(){
    
    
    ll a,b;

    cin>>a>>b;

    cout<<calc(b + 1) - calc(a);
    
}