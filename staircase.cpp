/*
number of ways to reach top of staircase with at most k jumps using jumps of size 1 or 2
e.g. if n=3(number of staircases) then for k=2, number of ways will be 2, which are 1+2 and 2+1
     if n=4 and k=3, then number of ways will be 4, which are 1+1+2, 1+2+1, 2+1+1 and 2+2('cause we need "atmost" k steps)
*/

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

ll dp[1005][1005];
ll n;

ll k;
ll staircase(ll i,ll steps){
    if(i<0 || steps<0)return 0;
    ll &res=dp[i][steps];
    if(res!=-1)return res;
    if(steps<=0 && i>0)return res=0;
    if(steps>=0 && i==0)return res=1;
    return res=staircase(i-1,steps-1)+staircase(i-2,steps-1);
}



int main(){
    fastio;
    ll t=1;
    // cin>>t;
    while(t--){
        cin>>n>>k;
        for(int i=0;i<=n;i++)
            for(int j=0;j<=k;j++)
                dp[i][j]=-1;
        cout<<staircase(n,k)<<endl;
        for(ll i=0;i<=n;i++){
            for(ll j=0;j<=k;j++){
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        cout<<endl;
        ll dp2[n+1][k+1]={0};
        for(ll i=0;i<=n;i++){
            for(ll j=0;j<=k;j++){
                dp2[i][j]=0;
            }
        }
        for(ll i=0;i<=k;i++)dp2[0][i]=1;
        ll ans=0;
        for(ll i=1;i<=n;i++){
            for(ll steps=1;steps<=k;steps++){
                if(i==1)dp2[i][steps]=dp2[i-1][steps-1];
                else dp2[i][steps]=dp2[i-1][steps-1]+dp2[i-2][steps-1];
            }
        }
        cout<<dp2[n][k]<<endl;
        for(ll i=0;i<=n;i++){
            for(ll j=0;j<=k;j++){
                cout<<dp2[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}
