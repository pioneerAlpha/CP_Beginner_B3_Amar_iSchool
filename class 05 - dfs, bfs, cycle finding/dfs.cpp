#include<bits/stdc++.h>
#define N ((int)1e5 + 5)
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define endl "\n"

using namespace std;

vector < int > edg[N]; /// edg[i] =

bool vis[N];


void dfs(int n)
{
    vis[n] = 1;
//    for(int i = 0; i<edg[n].size() ; i++){
//        int b = edg[n][i];
//    }
    for(int b:edg[n]){
        if(!vis[b]) dfs(b);
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
    dfs(1);
    /// O (m + n)
}
