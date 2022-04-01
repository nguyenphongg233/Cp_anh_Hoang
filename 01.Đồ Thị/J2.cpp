#include<bits/stdc++.h>

#define ll long long

const long long MAX = 1e5 + 5;
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
    for(ll i = 0;i <= t;i++){
        
        if(i == 0){
            for(auto x : adj[1]){
                cnt[x] = a[x];
            }
            count3[1]++;
            cnt[1] = -1;
        }else{
            bool dream[MAX];
            memset(dream,0,sizeof dream);
            vector<ll> whyrte;
            for(ll j = 1;j<=d;j++){
                if(cnt[j] > 0 )cnt[j]--;
                if(cnt[j] == 0 && !dream[j])dream[j] = 1,whyrte.push_back(j);
            }
            //if(i == 6)cout<<whyrte[0]<<" ";
            for(auto e : whyrte){
                count3[e]++;
                cnt[e]--;
                for(auto x : adj[e]){
                    if(!dream[x] && cnt[x] == -1){
                        cnt[x] = a[x];

                    }
                }
            }
        }
        //for(ll j = 1;j<=d;j++)cout<<count3[j]<<","<<cnt[j]<<" ";
        //cout<<'\n';
    }

    for(ll i = 1;i<=d;i++){
        cout<<count3[i]<<"\n";
    }
    
    
}