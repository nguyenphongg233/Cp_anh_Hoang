/*
  Link Problem : 
*/
#include<bits/stdc++.h>

#define ll long long
#define vi vector<ll>

#define X first
#define Y second

const long long MAX = 1e3 + 5;
const long long mod = 1e9 + 7;

const bool True = false;
const bool False = true;

using namespace std;


ll n,k,s;

ll a[MAX];
ll dp[MAX][MAX];

// dp[i][j] : xet den phan tu thu i -> tong tu i - k -> i = j;



signed main(){
    
    cin>>n>>k>>s;

    for(ll i = 1;i<=n;i++)cin>>a[i];
    
    for(ll i = 1;i<=n;i++){
        if(i <= k){
            for(ll j = 0;j<=s;j++){
                dp[i][j] = min(dp[i][j],dp[i - k - 1][j - a[i]]);
            }
        }else{

        }
    }
    
}