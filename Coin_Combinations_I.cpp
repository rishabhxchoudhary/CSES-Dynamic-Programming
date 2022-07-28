#include<bits/stdc++.h>
using namespace std;
 
// Code Shortners
typedef long long ll;
#define all(a) (a).begin(), (a).end()
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
    sort(coins,coins+n);
    ll dp[x+1]={0};
    for(ll i=0;i<x+1;i++) dp[i]=0;
    dp[0]=1;
    for(ll i=1;i<x+1;i++){
        for(ll j=0;j<n;j++){
            if (coins[j]>i) break;
            dp[i]=(dp[i]+dp[i-coins[j]])%mod;
        }
    }
    cout<<dp[x]<<endl;
    return 0;
}