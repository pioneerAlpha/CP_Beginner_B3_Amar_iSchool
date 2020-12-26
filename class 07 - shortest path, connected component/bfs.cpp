#include<bits/stdc++.h>
#define N ((int)1e5 + 5)
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define endl "\n"

using namespace std;

int dis[N];



void bfs(int src)
{
    memset(dis,-1,sizeof dis);
    dis[src] = 0;
    queue < int > que;
    que.push(src);
    while(!que.empty()){
        int a = que.front();
        que.pop();
        for(int b:vec[a]){
            if(dis[b] == -1){
                dis[b] = dis[a] + 1;
                que.push(b);
            }
        }
    }

    /// O (n + m)
}

int main()
{
    fastio;

    return 0;
}
