#include<bits/stdc++.h>
#define ll long long
#define N ((int)(1e4 + 5))
#define MAX ((int)2e9 + 5)
#define MAXL ((ll)1e18 + 5)
#define MOD ((int)(1e9 + 3))
#define endl "\n"
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL);


using namespace std;

// fastio
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);

vector < pair < int , int > > edg[N] , ext[N];


int vis[15][N], dis[15][N];

int main()
{
    fastio;

    int t, caseno = 1;

    cin>>t;
    while(t--)
    {
        int n, m, k, d;
        cin>>n>>m>>k>>d;
        for(int i = 0 ; i<n ; i++) edg[i].clear() , ext[i].clear();
        while(m--)
        {
            int u, v, w;
            cin>>u>>v>>w;
            edg[u].push_back({v,w});
        }
        while(k--)
        {
            int u, v, w;
            cin>>u>>v>>w;
            ext[u].push_back({v,w});
        }

        for(int i = 0 ; i<n ; i++)
        {
            for(int j = 0 ; j<=d ; j++) dis[j][i] = MAX , vis[j][i] = 0;
        }
        dis[0][0] = 0;
        priority_queue < pair < int, pair < int, int > > > pqq;
        pqq.push({0,{0,0}});
        while(!pqq.empty())
        {
            pair < int, int > p = pqq.top().second;
            pqq.pop();
            int a = p.second, cnt = p.first;
            if(vis[cnt][a]) continue;
            vis[cnt][a] = 1;
            for(auto p:edg[a])
            {
                int b = p.first, w = p.second;
                w = dis[cnt][a] + w;
                if(w < dis[cnt][b])
                {
                    dis[cnt][b] = w;
                    pqq.push({-dis[cnt][b], {cnt,b}});
                }
            }
            if(cnt == d) continue;
            for(auto p:ext[a])
            {
                int b = p.first, w = p.second;
                w = dis[cnt][a] + w;
                if(w < dis[cnt+1][b])
                {
                    dis[cnt+1][b] = w;
                    pqq.push({-dis[cnt+1][b], {cnt+1,b}});
                }
            }
        }

        int ans = MAX;
        for(int i = 0 ; i<=d ; i++) ans = min(ans, dis[i][n-1]);
        cout<<"Case "<<caseno++<<": ";
        if(ans == MAX ) cout<<"Impossible\n";
        else cout<<ans<<endl;
    }

    return 0;
}
