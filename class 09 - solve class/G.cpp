/// contest: graph intro
#include<bits/stdc++.h>
#define N ((int)1e5 + 5)
#define MAXL ((ll)1e18 + 5)
#define MAX ((int)2e9 + 5)
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define endl "\n"
#define ll long long

using namespace std;


vector < int > vec[N], tree[N] , edg[N];

int par[N] , vis[N] , lev[N] , deg[N] , cnt[N];

void dfs(int n , int p)
{
    par[n] = p;
    vis[n] = 1;
    lev[n] = lev[p] + 1;
    for(int a:vec[n]){
        if(vis[a] && a != p && lev[a] < lev[n]){
            cnt[n]++;
            edg[n].push_back(a);
        }
        if(!vis[a]){
            dfs(a,n);
            tree[n].push_back(a);
            deg[n]++;
        }
    }
}

struct boom{
    int u , v , w;
};

int main()
{
//    //cout<<(int)((1LL<<31)-1);
    fastio;
    int t , caseno = 1;
    t = 1;
    while(t--){
        int n , m;
        cin>>n>>m;
        while(m--){
            int a , b;
            cin>>a>>b;
            vec[a].push_back(b);
            vec[b].push_back(a);
        }
        dfs(1,0);
        vector < boom > ans;
        for(int i = 1 ; i <= n ; i++){
            while(edg[i].size() > 1){
                int a = edg[i].back();
                edg[i].pop_back();
                int b = edg[i].back();
                edg[i].pop_back();
                ans.push_back({a,i,b});
            }
        }
        priority_queue < pair < int , int > > leaf;
        memset(vis,0,sizeof vis);
        for(int i = 1 ; i<=n ; i++) if(deg[i] == 0) leaf.push({lev[i],i});
        vis[1] = 1;
        while(!leaf.empty()){
            int a = leaf.top().second;
            leaf.pop();
            if(vis[a]){
                continue;
            }
            vis[a] = 1;
            if(cnt[a]%2 == 1){
                int b = edg[a].back();
                ans.push_back({par[a],a,b});
            }
            else{
                int b = -1 , p = par[a];
                while(tree[p].size() > 0){
                    b = tree[p].back();
                    tree[p].pop_back();
                    if(vis[b]) b = -1;
                    else break;
                }
                if(b != -1){
                    ans.push_back({b,p,a});
                    deg[p]--;
                    vis[b] = 1;
                }
                else{
                    if(cnt[p]%2 == 1){
                        cnt[p]--;
                        int b = edg[p].back();
                        edg[p].pop_back();
                        ans.push_back({a,p,b});
                    }
                    else if(par[p] != 0){
                        ans.push_back({a,p,par[p]});
                        vis[p] = 1;
                        deg[par[p]]--;
                    }
                }
            }

            deg[par[a]]--;
            if(deg[par[a]] == 0) leaf.push({lev[par[a]] , par[a]});
        }
        cout<<ans.size()<<endl;
        for(auto p:ans) cout<<p.u<<" "<<p.v<<" "<<p.w<<endl;
    }
    return 0;
}
