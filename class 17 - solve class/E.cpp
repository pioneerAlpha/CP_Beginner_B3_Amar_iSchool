#include<bits/stdc++.h>
#define MAX ((int)2e9 + 5)
#define MAXL ((ll)1e16 + 5)
#define pi acos(-1)
#define MOD ((int)1e9 + 7)
#define N ((int)2e3 + 5)
#define eps (1e-8)
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define endl "\n"
#define ll long long
//#define int ll


using namespace std;



/*fast io
ios_base::sync_with_stdio(false);
cin.tie(NULL);
*/

vector < pair < int , int > > comp;

int dpp[N][1005] , vis[N] , col[N] , tot[3];

vector < int > vec[N];

bool dfs(int n , int c)
{
    vis[n] = 1;
    col[n] = c;
    tot[c]++;
    c = !c;
    for(int a:vec[n]){
        if(vis[a]){
            if(col[a] != c) return 0;
        }
        else if(dfs(a,c) == 0) return 0;
    }
    return 1;
}

int call(int idx , int rem)
{
    if(rem < 0) return 0;
    if(idx >= comp.size()){
        if(rem == 0) return 1;
        return 0;
    }
    if(dpp[idx][rem] != -1) return dpp[idx][rem];
    int ans = call(idx + 1 , rem - comp[idx].first) | call(idx + 1 , rem - comp[idx].second);
    return dpp[idx][rem] = ans;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {

        int b , c , m;
        cin>>b>>c>>m;
        int n = b + c;
        for(int i = 1 ; i<=n ; i++) vec[i].clear();
        comp.clear();
        while(m--){
            int u , v;
            cin>>u>>v;
            vec[u].push_back(v);
            vec[v].push_back(u);
        }
        memset(vis,0,sizeof vis);
        bool flag = 0;
        for(int i = 1 ; i<=n ; i++){
            if(!vis[i]){
                tot[0] = tot[1] = 0;
                if(dfs(i,0) == 0){
                    flag = 1;
                    break;
                }
                comp.push_back({tot[0],tot[1]});
            }
        }
        if(!flag){
            memset(dpp,-1,sizeof dpp);
            if(call(0,b) == 0) flag = 1;
        }
        if(flag) cout<<"no\n";
        else cout<<"yes\n";
    }
    return 0;
}

