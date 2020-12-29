#include<bits/stdc++.h>
#define N ((int)1e3 + 5)
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define endl "\n"

using namespace std;

int dis[25][25];

int dxx[] = {1 , 0 , 0 , -1};
int dyy[] = {0 , -1 , 1 , 0};

int n , m;


string str[25] ;

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
            if(min(x , y) < 0 || x >= n || y >= m || dis[x][y] != -1 || str[x][y] == '*') continue;
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

    cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i = 0 ; i<n ; i++) cin>>str[i];
        for(int i = 0 ; i<n ; i++){
            for(int j = 0; j < m ; j++){
                if(str[i][j] == 'h') bfs(i,j);
            }
        }

        int ans = 0;
        for(int i = 0 ; i<n ; i++){
            for(int j = 0 ; j<m ; j++){
                if(str[i][j] >= 'a' && str[i][j] <= 'c') ans = max(ans , dis[i][j]);
            }
        }
        cout<<"Case "<<caseno++<<": "<<ans<<endl;
    }

    return 0;
}
