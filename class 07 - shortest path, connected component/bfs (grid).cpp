#include<bits/stdc++.h>
#define N ((int)1e3 + 5)
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define endl "\n"

using namespace std;

int dis[N][N];

int dxx[] = {0,0,1,-1};
int dyy[] = {1,-1,0,0};

void bfs(int srcx , int srcy)
{
    memset(dis,-1,sizeof dis);
    dis[srcx][srcy] = 0;
    queue < pair < int , int > > que;
    que.push({srcx,srcy});
    while(!que.empty()){
        int a = que.front().first , b = que.front().second;
        que.pop();
        for(int i = 0 ; i<4 ; i++){
            int x = a + dxx[i] , y = b + dyy[i];
            if(min(x , y) <= 0 || x > n || y > m || dis[x][y] != -1) continue;
            dis[x][y] = dis[a][b] + 1;
            que.push({x,y});
        }
    }

    /// O (n + m)
}

int main()
{
    fastio;
    return 0;
}
