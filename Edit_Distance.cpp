// Header Files and namespaces
#include<iostream>
#include<vector>
#include<string>
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
    string a,b;
    cin>>a>>b;
    int na = a.length();
    int nb = b.length();
    vector < vector<int> > dp(na+1,vector<int>(nb+1,1e9));
    dp[0][0]=0;
    for(int i=0;i<na+1;i++){
        for(int j=0;j<nb+1;j++){
            if (i>0) dp[i][j]=min(dp[i][j],1+dp[i-1][j]);
            if (j>0) dp[i][j]=min(dp[i][j],1+dp[i][j-1]);
            if (j>0 and i>0){
                if (a[i-1]==b[j-1]) dp[i][j]=min(dp[i][j],dp[i-1][j-1]);
                else{
                    dp[i][j]=min(dp[i][j],1+dp[i-1][j-1]);
                }
            }
            // cout<<dp[i][j]<<" ";
        }
        // cout<<endl;
    }

    cout<<dp[na][nb]<<endl;

    return 0;
}