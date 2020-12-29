#include<bits/stdc++.h>
#define N ((int)2e3 + 5)
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define endl "\n"

using namespace std;

int dis[N][N];

int dxx[] = {1 , 0 , 0 , -1};
int dyy[] = {0 , -1 , 1 , 0};

int n , m;

void bfs(vector < pair < int , int > > vec)
{
    memset(dis,-1,sizeof dis);
    queue < pair < int , int > > que;
    for(auto p:vec){
        que.push(p);
        dis[p.first][p.second] = 0;
    }
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

    freopen ("input.txt","r",stdin);
    freopen ("output.txt","w",stdout);
    fastio;

    int t , caseno = 1;

    t = 1;
    while(t--){
        int k;
        cin>>n>>m>>k;
        vector < pair < int , int > > src;
        while(k--){
            int a , b;
            cin>>a>>b;
            src.push_back({a,b});
        }
        bfs(src);
        int mxx = -1 , ansi , ansj;
        for(int i = 1 ; i<=n ; i++){
            for(int j = 1 ; j<=m ; j++){
                if(dis[i][j] > mxx){
                    mxx = dis[i][j];
                    ansi = i;
                    ansj = j;
                }
            }
        }
        cout<<ansi<<" "<<ansj<<endl;
    }

    return 0;
}
