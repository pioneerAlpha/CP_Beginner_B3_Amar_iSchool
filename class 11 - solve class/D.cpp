#include<bits/stdc++.h>
#define N ((int)1e5 + 5)
#define MAXL ((ll)1e18 + 5)
#define MAX ((int)2e9 + 5)
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define endl "\n"
#define ll long long

using namespace std;

vector < pair < int , int > > vec[N];

vector < int > ans[2];

int col[N] , vis[N];

bool dfs(int n , int c)
{
    vis[n] = 1;
    ans[c].push_back(n);
    col[n] = c;
    for(auto p:vec[n]){
        int a = p.first , b = p.second;
        b = b^c;
        if(!vis[a]){
            if(!dfs(a,b)) return 0;
        }
        else{
            if(col[a] != b) return 0;
        }
    }
    return 1;
}

int main()
{
    fastio;
    int n , m ;
    cin>>n>>m;
    while(m--){
        int a , b , edg;
        string col;
        cin>>a>>b>>col;
        if(col[0] == 'R') edg = 1;
        else edg = 0;
        vec[a].push_back({b,edg});
        vec[b].push_back({a,edg});
    }
    bool flag = 1;
    vector < int > taken[2];
    for(int i = 1 ; i<=n ; i++){
        if(!vis[i]){
            ans[0].clear();
            ans[1].clear();
            if(!dfs(i,0)){
                flag = 0;
                break;
            }
            else{
                bool idx = 1;
                if(ans[0].size()<ans[1].size()) idx = 0;
                for(int a:ans[idx]) taken[0].push_back(a);
            }
        }
    }

    for(int i = 1 ; i<=n ; i++){
        for(int j = 0 ; j<vec[i].size() ; j++){
            vec[i][j].second = !vec[i][j].second;
        }
    }

    memset(vis,0,sizeof vis);

    bool tmp = 1;

    for(int i = 1 ; i<=n ; i++){
        if(!vis[i]){
            ans[0].clear();
            ans[1].clear();
            if(!dfs(i,0)){
                tmp = 0;
                break;
            }
            else{
                bool idx = 1;
                if(ans[0].size()<ans[1].size()) idx = 0;
                for(int a:ans[idx]) taken[1].push_back(a);
            }
        }
    }
    int idx = -1;
    if(flag && tmp){
        if(taken[0].size() < taken[1].size()) idx = 0;
        else idx = 1;
    }
    else if(flag) idx = 0;
    else if(tmp) idx = 1;

    if(idx != -1){
        cout<<taken[idx].size()<<endl;
        for(int a:taken[idx]) cout<<a<<" ";
        cout<<endl;
    }
    else cout<<"-1\n";

    return 0;
}
