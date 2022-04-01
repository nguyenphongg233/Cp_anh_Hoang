#include<bits/stdc++.h>

#define ll long long

const long long MAX = 1e3 + 5;
const long long mod = 1e9 + 7;

using namespace std;


ll d,t,f;
ll a[MAX];
ll cnt[MAX];
vector<ll> adj[MAX];
ll count3[MAX];

signed main(){
    
    cin>>d;

    for(ll i = 1;i<=d;i++)cin>>a[i];

    memset(cnt,-1,sizeof cnt);

    cin>>f;

    for(ll i = 1;i<=f;i++){
        ll u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }

    cin>>t;
    for(ll i = 1;i <= t;i++){
        if(i == 1){
            for(auto e : adj[i]){
                cnt[e] = a[e];
            }
            cnt[i] = -1;
            count3[i]++;
        }else{
            vector<ll> record;
            bool d2[MAX];
            for(ll j = 1;j<=d;j++){
                if(cnt[j] > 0)cnt[j]--;
                if(cnt[j] == 0)record.push_back(j),cnt[j]--,d2[j] = 1;
            }
            for(auto e : record){
                count3[e]++;
                for(auto x : adj[e]){
                    if(cnt[x] < 0 && !d2[x]){
                        cnt[x] = a[x];
                    }
                }
            }
        }
        for(ll j = 1;j<=d;j++)cout<<count3[j]<<","<<cnt[j]<<" ";
        cout<<'\n';
    }

    for(ll i = 1;i<=d;i++){
        if(i == 1)cout<<count3[i] + 1<<'\n';
        else cout<<count3[i]<<"\n";
    }
    
    
}