#include<iostream>
#include<vector>
using namespace std;

// Code Shortners
typedef long long ll;
#define all(a) (a).begin(), (a).end()
#define endl '\n'
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int mod = 1000000007;

// Code
int main()
{
    fast;
    int n,m;
    cin>>n>>m;
    vector<int> x(n+1);
    for(int i=1;i<n+1;i++) cin>>x[i];
    vector< vector<int> > dp(n+1, vector<int> (m+1,0));
    if (x[1]==0) for(int i=0;i<m+1;i++) dp[1][i]=1;
    else dp[1][x[1]]=1;
    for(int i=2;i<n+1;i++){
        int x0 = x[i];
        if (x0==0){
            for(int j=1;j<m+1;j++){
                for(int k : {j-1,j,j+1}){
                    if (k>=1 && k<=m) dp[i][j] = (dp[i][j]+dp[i-1][k])%mod;
                }
            }
        }
        else{
            for(int k : {x0-1,x0,x0+1}){
                if (k>=1 && k<=m) dp[i][x0] = (dp[i][x0]+dp[i-1][k])%mod;
            }
        }
    }

    int ans=0;
    for(int i=1;i<m+1;i++){
        ans=(ans+dp[n][i])%mod;
    }
    cout<<ans<<endl;
    
    return 0;
}