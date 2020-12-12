problem link: https://csacademy.com/contest/archive/task/simple-paths
#include<bits/stdc++.h>
#define N ((int)1e3 + 5)
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define endl "\n"

using namespace std;

vector < int > edg[N]; /// edg[i] =

int nxt[N];

bool vis[N];

bool dfs(int n, int des)
{
    if( n == des ) return 1;
    vis[n] = 1;
//    for(int i = 0; i<edg[n].size() ; i++){
//        int b = edg[n][i];
//    }
    for(int b:edg[n]){
        if(!vis[b]){
            if(dfs(b,des) == 1){
                nxt[n] = b;
                return 1;
            }
        }
    }
    return 0;
}

bool newdfs(int n , int des , bool path) /// path = 0 if on previous path
{
    if(n == des){
        if(path == 0) return 0;
        else return 1;
    }
    vis[n] = 1;
    for(int b:edg[n]){
        if(vis[b] == 0 && nxt[n] != b){
            if(newdfs(b,des,1) == 1) return 1;
        }
    }

    int b = nxt[n];
    if(b != -1 && vis[b] == 0){
        if(newdfs(b,des,path) == 1) return 1;
    }

    return 0;

}

int main()
{
    fastio;
    int n , m , q;
    cin>>n>>m>>q;
    while(m--){
        int a , b;
        cin>>a>>b;
        edg[a].push_back(b);
        edg[b].push_back(a);
    }

    while(q--){
        int x , y;
        cin>>x>>y;
        memset(vis,0,sizeof vis);
        memset(nxt,-1,sizeof nxt);
        int ans;
        if(dfs(x,y) == 0) ans = 0;
        else{
            memset(vis,0,sizeof vis);
            if(newdfs(x,y,0) == 1) ans = 0;
            else ans = 1;
        }
        cout<<ans<<endl;
    }
    return 0;
}
