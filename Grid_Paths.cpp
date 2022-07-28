// Header Files and namespaces
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define endl '\n'
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const ll mod = 1000000007;

int main()
{
    fast;
    ll n; cin>>n;
    ll arr[n][n];
    for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++){
            arr[i][j]=-1;
        }
    }
    for(ll i=0;i<n;i++){
        char s[n];
        for(int k=0;k<n;k++){
            cin>>s[k];
        }
        for(ll j=0;j<n;j++){
            if (s[j]=='*'){
                arr[i][j]=0;
            }
        }
    }
    for(ll i=0;i<n;i++){
        if(arr[0][i]==-1) arr[0][i]=1;
        if(arr[i][0]==-1) arr[i][0]=1;
        if(i>0){
            if (arr[0][i-1]==0) arr[0][i]=0;
            if (arr[i-1][0]==0) arr[i][0]=0;
        }
    }
    for(ll i=1;i<n;i++){
        for(ll j=1;j<n;j++){
            if (arr[i][j]==-1){
                arr[i][j] = (arr[i-1][j]+arr[i][j-1])%mod;
            }
        }
    }
    cout<<arr[n-1][n-1]<<endl;
    return 0;
}