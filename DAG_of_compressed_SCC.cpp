#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back

ll n,m;
vector<ll>v[100005];
bool vis[100005]={0},onstack[100005]={0};
ll ids[100005],low[100005];
ll idct=0,ind=0;
ll mp[100005]={0};
stack<ll>st;

void dfs(ll at){
    vis[at]=1;
    st.push(at);
    onstack[at]=1;
    ids[at]=low[at]=++idct;
    for(ll to:v[at]){
        if(!vis[to]){
            dfs(to);
            low[at]=min(low[at],low[to]);
        }
        if(onstack[to])low[at]=min(low[at],ids[to]);
    }
    if(ids[at]==low[at]){
        while(!st.empty() && st.top()!=at){
            mp[st.top()]=ind;
            onstack[st.top()]=0;
            st.pop();
        }
        if(!st.empty()){
            mp[st.top()]=ind;
            onstack[st.top()]=0;
            st.pop();
        }
        ind++;
    }
}

vector<ll>dag[100005];
bool vis2[100005]={0};

void dfs2(ll at){
    vis2[at]=1;
    for(ll to:v[at]){
        if(mp[to]!=mp[at]){
            dag[mp[at]].pb(mp[to]);
        }
        if(!vis2[to])dfs2(to);
    }
}

vector<ll>topv;
bool vistop[100005]={0};

void topSortDFS(ll at){
    vistop[at]=1;
    for(ll to:dag[at]){
        if(!vistop[to])topSortDFS(to);
    }
    topv.pb(at);
}

int main(){
    cin>>n>>m;
    for(ll i=0;i<m;i++){
        ll a,b;
        cin>>a>>b;
        v[a].pb(b);
    }
    for(ll i=1;i<=n;i++){
        if(!vis[i])dfs(i);
    }
    if(ind==1){
        // There is only one node in DAG
        // cout<<0;
        return 0;
    }
    for(ll i=1;i<=n;i++){
        if(!vis2[i])dfs2(i);
    }
    for(ll i=0;i<ind;i++){
        if(!vistop[i])topSortDFS(i);
    }
    reverse(topv.begin(),topv.end());
    cout<<"Toplogical Sorting of DAG of SCC (where all SCC are compressed into one node)\n";
    for(ll a:topv)cout<<a<<" ";
    return 0;
}