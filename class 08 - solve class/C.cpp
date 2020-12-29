#include<bits/stdc++.h>
#define N ((int)5e2 + 5)
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define endl "\n"

using namespace std;

int dis[N][N];

int dxx[] = {1 , 0 , 0 , -1};
int dyy[] = {0 , -1 , 1 , 0};

int n , m;


string str[N] ;

void bfs(int srcx , int srcy)
{
    memset(dis,-1,sizeof dis);
    dis[srcx][srcy] = 0;
    queue < pair < int , int > > que;
    que.push({srcx,srcy});
    while(!que.empty()){
        int a = que.front().first , b = que.front().second;
        que.pop();
        int val = str[a][b] - '0';
        for(int i = 0 ; i<4 ; i++){
            int x = a + dxx[i]*val , y = b + dyy[i]*val;
            if(min(x , y) < 0 || x >= n || y >= m || dis[x][y] != -1) continue;
            dis[x][y] = dis[a][b] + 1;
            que.push({x,y});
        }
    }

    /// O (n + m)
}



int main()
{

    fastio;

    int t , caseno = 1;

    t = 1;
    while(t--){
        cin>>n>>m;
        for(int i = 0 ; i<n ; i++) cin>>str[i];
        bfs(0,0);

        cout<<dis[n-1][m-1]<<endl;
    }

    return 0;
}
