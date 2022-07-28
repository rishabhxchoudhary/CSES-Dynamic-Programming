#include<bits/stdc++.h>
using namespace std;

// Code Shortners
typedef long long ll;
#define endl '\n'
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
const ll mod = 1000000007;
 
// Code
int main()
{
    fast;
    ll n,x;
    cin>>n>>x;
    ll coins[n];
    for(ll i=0;i<n;i++) cin>>coins[i];
    ll dp[x+1];
    for(ll i=0;i<x+1;i++) dp[i]=INT_MAX;
    dp[0]=0;
    for(ll i=1;i<x+1;i++){
        for(ll j=0;j<n;j++){
            ll c=coins[j];
            if (c>i) continue;
            dp[i] = min(dp[i],1+dp[i-c]);
        }
    }
    if (dp[x]==INT_MAX){
        cout<<-1<<endl;
    }
    else cout<<dp[x]<<endl;
    return 0;
}