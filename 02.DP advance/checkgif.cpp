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




signed main(){
    
    
    ll a[MAX];
    ll b[MAX];
    
    for(ll i = 1;i<=108;i++)cin>>a[i];
    for(ll i = 1;i<=108;i++)cin>>b[i];

    for(ll i = 1;i<=108;i++){
        cout<<i <<" "<<a[i]<<" "<<b[i]<<" "<<(a[i] == b[i])<<"\n";
    }
    
}