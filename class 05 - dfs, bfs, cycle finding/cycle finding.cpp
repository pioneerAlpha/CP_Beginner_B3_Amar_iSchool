#include<bits/stdc++.h>
#define N ((int)1e5 + 5)
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define endl "\n"

using namespace std;

vector < int > edg[N]; /// edg[i] =

bool vis[N] , mark[N];

int lev[N] , par[N];

void cyc(int from , int too)
{
    while(from != too){
        mark[from] = 1;
        from = par[from];
    }
    mark[too] = 1;
}

void dfs(int n, int p)
{
    par[n] = p;
    vis[n] = 1;
    lev[n] = lev[p] + 1;
//    for(int i = 0; i<edg[n].size() ; i++){
//        int b = edg[n][i];
//    }
    for(int b:edg[n]){
        if(vis[b]){
            if(b != p && lev[b] < lev[n]) cyc(n,b);
        }
        else dfs(b,n);
    }
}

int main()
{
    fastio;
    int n , m;
    cin>>n>>m;
    while(m--){
        int a , b;
        cin>>a>>b;
        edg[a].push_back(b);
        edg[b].push_back(a);
    }
    lev[0] = 0;
    dfs(1,0);

    /// O (m)
}
