#include<bits/stdc++.h>
#define N ((int)1e2 + 5)
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define endl "\n"

using namespace std;

int dis[2][N];


vector < int > vec[N];

void bfs(int idx , int src)
{
    memset(dis[idx],-1,sizeof dis[idx]);
//    memset(dis,-1,sizeof dis);
    dis[idx][src] = 0;
    queue < int > que;
    que.push(src);
    while(!que.empty()){
        int a = que.front();
        que.pop();
        for(int b:vec[a]){
            if(dis[idx][b] == -1){
                dis[idx][b] = dis[idx][a] + 1;
                que.push(b);
            }
        }
    }

    /// O (n + m)
}



int main()
{
    fastio;
    int t , caseno = 1;
    cin>>t;
    while(t--){
        int n , m;
        cin>>n>>m;
        for(int i = 1 ; i<=n ; i++) vec[i].clear();
        while(m--){
            int a , b;
            cin>>a>>b;
            a++;
            b++;
            vec[b].push_back(a);
            vec[a].push_back(b);
        }
        int src , des;
        cin>>src>>des;
        src++;
        des++;
        bfs(0,src);
        bfs(1,des);
        int ans = 0;
        for(int i = 1 ; i<=n ; i++){
            if(i != src && i != des){
                ans = max(ans , dis[0][i] + dis[1][i]);
            }
        }

        cout<<"Case "<<caseno++<<": "<<ans<<endl;
    }

    return 0;
}
