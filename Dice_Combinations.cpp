#include<iostream>
#include<vector>
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
    ll n;
    cin>>n;
    vector<ll>dp(n+1,0);
    dp[0]=1;
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=6;j++){
            if (j>i) break;
            dp[i]= (dp[i]+dp[i-j])%mod;
        }
    }
    cout<< dp[n]<<endl;
    return 0;
}