#include<bits/stdc++.h>
#define N ((int)2e5 + 5)
#define MAXL ((ll)1e18 + 5)
#define MAX ((int)2e9 + 5)
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define endl "\n"
#define ll long long

using namespace std;

vector < int > vec[N] , ans[2];

int vis[N];

void dfs(int n , int c)
{
    vis[n] = 1;
    ans[c].push_back(n);
    c = !c;
    for(int a:vec[n]){
        if(!vis[a]) dfs(a,c);
    }
}

int main()
{
    fastio;
    int t;
    cin>>t;
    while(t--){
        int n , m;
        cin>>n>>m;
        ans[0].clear();
        ans[1].clear();
        for(int i = 1 ; i <= n ; i++) vec[i].clear() , vis[i] = 0;
        while(m--){
            int a , b;
            cin>>a>>b;
            vec[b].push_back(a);
            vec[a].push_back(b);
        }
        dfs(1,0);
        int idx = 0;
        if(ans[1].size() < ans[0].size()) idx = 1;
        cout<<ans[idx].size()<<endl;
        for(int a:ans[idx]) cout<<a<<" ";
        cout<<endl;
    }
    return 0;
}
