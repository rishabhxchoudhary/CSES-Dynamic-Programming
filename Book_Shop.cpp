#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define endl '\n'
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int mod = 1000000007;

int main()
{
    fast;
    int n,x; cin>>n>>x;
    vector<int> prices(n+1),pages(n+1);
    prices[0]=0; pages[0]=0;
    for(int i=1;i<n+1;i++) cin>>prices[i];
    for(int i=1;i<n+1;i++) cin>>pages[i];
    vector< vector<int> > dp(n+1,vector<int>(x+1,0));
    for(int i=1;i<n+1;i++){
        for(int j=0;j<x+1;j++){
            dp[i][j]=dp[i-1][j];
            if(j-prices[i]>=0){
                dp[i][j] = max ( dp[i][j], dp[i-1][j-prices[i]]+pages[i] );
            }
        }
    }
    cout<<dp[n][x];
}
