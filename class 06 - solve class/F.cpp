#include<bits/stdc++.h>
#define N ((int)1e5 + 5)
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define endl "\n"

using namespace std;

vector < int > vec[N];
vector < pair < int , int > > ans; /// to store the final edges

int par[N] , lev[N] , vis[N] , chl[N] , cnt[N]; /// cnt[i] = 1 if odd number of edges go out from i, cnt[i] = 0 otherwise
/// par[i] = parent of node i in the dfs tree
/// chl[i] = count of child of node i in the dfs tree

void dfs(int n , int pre)
{
    par[n] = pre;
    vis[n] = 1;
    lev[n] = lev[pre] + 1;
    for(int a:vec[n]){
        if(a != pre){
            if(vis[a] && lev[a] < lev[n]){ /// this is a back edge.
                    /// vis[a] == 1 is enough to check the back edge but every edge is counted twice. that's why  lev[a] < lev[n] condition is important
                cnt[a] = !cnt[a];
                ans.push_back({a,n});  /// giving the direction from a to n; so cnt[a] changes
            }
            else if(!vis[a]){
                chl[n]++;
                dfs(a,n);
            }
        }
    }
}

int main()
{
    fastio;
    int n , m;
    cin>>n>>m;
    if(m&1){
        cout<<"-1\n";
        return 0;
    }
    while(m--){
        int a , b;
        cin>>a>>b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }

    dfs(1,0);

    queue < int > que;

    for(int i = 1 ; i<=n ; i++){
        if(chl[i] == 0){
            que.push(i);
        }
    }

    while(!que.empty()){
        int a = que.front();
        que.pop();

        int p = par[a];

        if(p == 0) continue;

        if(cnt[a]){
            ans.push_back({a,p});
        }
        else{
            cnt[p] = !cnt[p];
            ans.push_back({p,a});
        }

        chl[p]--;
        if(chl[p] == 0) que.push(p);
    }

    for(auto p:ans) cout<<p.first<<" "<<p.second<<endl;

    return 0;
}
