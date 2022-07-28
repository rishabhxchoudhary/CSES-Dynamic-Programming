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
    for(ll i=0;i<x+1;i++) {dp[i]=0;}
    dp[0]=1;
    for(ll i=1;i<n+1;i++){
        for(ll j=0;j<x+1;j++){
            if(j>=coins[i-1]){
                dp[j]+=dp[j-coins[i-1]];
                dp[j]%=mod;
            }
        }
    }
    cout<<dp[x]<<endl;
    return 0;
}