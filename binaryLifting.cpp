// code to find LCA using 2 types of binary lifting
// i.e. LCA() and LCA2()
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define getMat(x, n, m, val) vector<vector<ll>> x(n, vector<ll> (m, val))

ll c=0;
ll in[100005],out[100005];
ll lvl[100005]={0};

// dfs() is the preprocessing function 
// i.e. for finding the N.logN array of binary lifted parents
// it also stores the level of each node with level(root=1)=0
// it also stores in and out time of each node
void dfs(vector<ll>v[],vector<vector<ll>>&P,ll src, ll par,ll lg){
    in[src]=c++;
    P[src][0]=par;
    for(ll i=1;i<=lg;i++){
        P[src][i]=P[P[src][i-1]][i-1];
    }
    for(ll to:v[src]){
        if(to!=par){
            lvl[to]=lvl[src]+1;
            dfs(v,P,to,src,lg);
        }
    }
    out[src]=++c;
}

bool isAncestor(ll a,ll b){
    return in[a]<=in[b] && out[a]>=out[b];
}

// LCA() only binary lifts 'a' until 'a' is not the ancestor of 'b'
// repeatedly
ll LCA(ll a,ll b,ll lg,vector<vector<ll>>&P){
    if(isAncestor(a,b))return a;
    if(isAncestor(b,a))return b;
    for(ll i=lg;i>=0;i--){
        if(!isAncestor(P[a][i],b)){
            a=P[a][i];
        }
    }
    return P[a][0];
}

// walk() to make lvl of 'a' and 'b' same
// here lvl[a] > lvl[b]
// so we binary lift 'a' upto lvl[b]
ll walk(ll a,ll b,ll lg,vector<vector<ll>>&P){
    ll k=lvl[a]-lvl[b];
    for(ll i=0;i<=lg;i++){
        if((1<<i)&k){
            a=P[a][i];
        }
    }
    return a;
}

// LCA2() first matches lvl[a] and lvl[b]
// and then binary lift 'a' and 'b' together
ll LCA2(ll a,ll b,ll lg,vector<vector<ll>>&P){
    if(lvl[a]<lvl[b])swap(a,b);
    if(lvl[a]!=lvl[b])a=walk(a,b,lg,P);
    if(a==b)return a;
    for(ll i=lg;i>=0;i--){
        if(P[a][i]!=P[b][i]){
            a=P[a][i];
            b=P[b][i];
        }
    }
    return P[a][0];
}

void solve(){
    cout<<"Enter number of nodes in tree\n";
    ll n;
    cin>>n;
    vector<ll>v[n+1];
    cout<<"Enter edges in tree\n";
    for(ll i=0;i<n-1;i++){
        ll a,b;
        cin>>a>>b;
        v[a].pb(b);
        v[b].pb(a);
    }
    ll lg=log2(n)+1;
    getMat(P,n+1,lg+1,-1);
    dfs(v,P,1,1,lg);
    cout<<endl<<endl;
    cout<<"The N.logN array for storing parents is as follows\n\n";
    for(ll i=1;i<=n;i++){
        cout<<i<<" "<<lvl[i]<<endl;
        for(ll j=0;j<=lg;j++){
            cout<<P[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl<<endl;
    cout<<"Enter number of queries\n";
    ll q;
    cin>>q;
    while(q--){
        cout<<"Enter 2 nodes to find LCA\n";
        ll a,b;
        cin>>a>>b;
        cout<<"LCA of "<<a<<" and "<<b<<" is ";
        cout<<LCA2(a,b,lg,P)<<endl<<endl;
    }
}

int main() {
    ll t=1;
    // cin>>t;
    while(t--){
        solve();
    }
	return 0;
}

/*
7
1 2
1 3
2 4
2 5
4 6
5 7
*/
