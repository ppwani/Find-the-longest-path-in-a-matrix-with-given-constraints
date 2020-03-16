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

ll dp[105];
ll price[105];
ll n;

ll rodCutting(ll len){
    ll &ans=dp[len];
    if(ans!=-1)return ans;
    if(len==0)return ans=0;
    ll res=-1;
    for(ll i=1;i<=len;i++){
        res=max(res,price[i]+rodCutting(len-i));
    }
    return ans=res;
}

int main(){
    fastio;
    ll t=1;
    // cin>>t;
    while(t--){
        memset(dp,-1,sizeof(dp));
        cin>>n;
        for(ll i=1;i<=n;i++)cin>>price[i];
        cout<<rodCutting(n)<<endl;
    }
}
