/*
  Link Problem : https://codeforces.com/group/8Tw3vQnae2/contest/375803/problem/G
*/
#include<bits/stdc++.h>

#define ll long long
#define vi vector<ll>

#define X first
#define Y second

const long long MAX = 1e5 + 5;
const long long MOD = 1e9 + 7;

const bool True = false;
const bool False = true;

using namespace std;


// sol : 9 * 12 = 108 for 
// den cuoi cung sum == 0 && x == tong chu so thi ++
// dp(i,<=n,mod,sum);
// dp(i + 1,<= n, > 0,mod * 10 + i %x,sum) += dp(i,<=n,> 0,mod,sum);

ll dp[22][2][120][120];
ll n;

ll calc(ll x){

    vi ares;
    ll m = n;

    while(m > 0){
        ares.push_back(m % 10);
        m /= 10;
    }

    ll cs[MAX];

    for(ll i = 1;i<=ares.size();i++){
        cs[i] = ares[ares.size() - i];
    }

    memset(dp,0,sizeof dp);

    dp[0][0][0][0] = 1;

    for(ll i = 0;i < ares.size();i++){
        for(ll lower = 0;lower < 2;lower++){
                for(ll mod = 0;mod < x;mod++){
                    for(ll sum = 0;sum <= 108;sum++){
                        for(ll next = 0;next <= 9;next++){

                            ll lower2 = lower || next < cs[i + 1];
                            ll mod2 = (mod * 10 + next) % x;
                            ll sum2 = sum + next;
                            if(sum2 > 108 || (!lower && next > cs[i + 1]))continue;
                            dp[i + 1][lower2][mod2][sum2] += dp[i][lower][mod][sum];

                        }
                    }
                }
        }
    }

    ll sum = 0;

    return dp[ares.size()][1][0][x];

}

// mang co so 1 - > sai ? 

signed main(){
    
    cin>>n;

    ll sum = 0;

    // 12 * 9 =  108
    for(ll i = 1;i <= 108;i++){
        ll tmp = calc(i);
        sum += tmp;
        //cout<<i<<": ";
        cout<<tmp<<"\n";
    }

    cout<<sum;
    
    
}