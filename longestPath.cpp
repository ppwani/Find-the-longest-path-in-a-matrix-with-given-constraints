#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define getMat(x, n, m, val) vector<vector<ll>> x(n, vector<ll> (m, val))
#define setp fixed<<setprecision // use it as cout<<setp(number of fractional digits in x)<<x;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
ll M=1000000000+7;
 
ll power(ll x,ll n)
{
    ll result=1;
    while(n>0)
    {
        if(n % 2 ==1)
            result=(result * x)%M;
        x=(x*x)%M;
        n=n/2;
    }
    return result;
}

ll dp[105][105];
ll a[105][105];
ll n;

ll longestPath(ll i,ll j){
    if(i<0 || j<0 || i>=n || j>=n)return 0;
    ll& res=dp[i][j];
    if(res!=-1)return res;
    if(i+1<n && a[i+1][j]==a[i][j]+1)res=max(res,1+longestPath(i+1,j));
    if(i-1>=0 && a[i-1][j]==a[i][j]+1)res=max(res,1+longestPath(i-1,j));
    if(j+1<n && a[i][j+1]==a[i][j]+1)res=max(res,1+longestPath(i,j+1));
    if(j-1>=0 && a[i][j-1]==a[i][j]+1)res=max(res,1+longestPath(i,j-1));
    return max(1LL,res);
}

int main(){
    fastio;
    ll t=1;
    // cin>>t;
    while(t--){
        memset(dp,-1,sizeof(dp));
        cin>>n;
        ll ans=-1;
        for(ll i=0;i<n;i++){
            for(ll j=0;j<n;j++){
                cin>>a[i][j];
            }
        }
        for(ll i=0;i<n;i++){
            for(ll j=0;j<n;j++){
                cout<<longestPath(i,j)<<" ";
                ans=max(ans,longestPath(i,j));
            }
            cout<<endl;
        }
        cout<<ans<<endl;
    }
}
