#include<bits/stdc++.h>
#define N ((int)1e5 + 5)
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define endl "\n"

using namespace std;

vector < int > edg[N]; /// edg[i] =

bool vis[N];

int lev[N];

void bfs(int src , int n)
{
    for(int i = 1 ; i<=n ; i++) vis[i] = 0;

    queue < int > que;
    vis[src] = 1;
    lev[src] = 1;
    que.push(src);

    while(!que.empty()){
        int a = que.front();
        que.pop();

        for(int i = 0 ; i<edg[a].size() ; i++){
            int b = edg[a][i];
            if(vis[b] == 0){
                que.push(b);
                vis[b] = 1;
                lev[b] = lev[a] + 1;
            }
        }
    }

    /// O (n + m);

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

    bfs(1,n);

}
