#include<bits/stdc++.h>
#define N ((int)2e5 + 5)
#define MAXL ((ll)1e18 + 5)
#define MAX ((int)2e9 + 5)
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define endl "\n"
#define ll long long

using namespace std;

vector < int > vec[N];

int col[N] , vis[N] , v[N] , u[N];

void dfs(int n , int c)
{
    vis[n] = 1;
    col[n] = c;
    for(int a:vec[n]){
        if(!vis[a]) dfs(a,!c);
    }
}

int main()
{
    fastio;
    int n;
    cin>>n;
    for(int i = 1 ; i<=n ; i++){
        int a , b;
        cin>>a>>b;
        vec[b].push_back(a);
        vec[a].push_back(b);
        u[i] = a;
        v[i] = b;
    }
    for(int i = 1 ; i <= n+n ; i += 2){
        vec[i].push_back(i+1);
        vec[i+1].push_back(i);
    }
    for(int i = 1 ; i <= n+n ; i++){
        if(!vis[i]) dfs(i,0);
    }
    for(int i = 1 ; i<=n ; i++){
        cout<<col[u[i]]+1<<" "<<col[v[i]]+1<<endl;
    }
    return 0;
}
