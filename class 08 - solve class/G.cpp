#include<bits/stdc++.h>
#define N ((int)1e3 + 5)
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define endl "\n"

using namespace std;

int dis[N][N];

int dxx[] = {1 , 0 , 0 , -1};
int dyy[] = {0 , -1 , 1 , 0};

int n , m;


/// D: {1,0} , L :{0,-1} , R: {0,1} , U:{-1,0}

string str[N] , dir;

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

string ans;

void fun(int x , int y , int rem)
{
    if(rem == 0) return;
    for(int i = 0 ; i<4 ; i++){
        int a = x + dxx[i] , b = y + dyy[i];
        if(min(a, b ) < 0 || a >= n || b >= m || str[a][b] == '*') continue;
        if(dis[a][b] <= rem-1){
            ans += dir[i];
            fun(a,b,rem-1);
            return;
        }
    }
}

int main()
{
    dir = "DLRU";
    fastio;
    int k;
    cin>>n>>m>>k;
    if(k & 1){
        cout<<"IMPOSSIBLE\n";
        return 0;
    }
    for(int i = 0 ; i<n ; i++){
        cin>>str[i];
    }
    for(int i = 0 ; i<n ; i++){
        for(int j = 0 ; j<m ; j++){
            if(str[i][j] == 'X'){
                bfs(i,j);
                bool flag = 0;
                for(int ii = 0 ; ii < 4 ; ii++){
                    int a = i + dxx[ii] , b = j + dyy[ii];
                    if(min(a, b) < 0 || a >= n || b >= m) continue;
                    if(str[a][b] == '.') flag = 1;
                }
                if(!flag){
                    cout<<"IMPOSSIBLE\n";
                    return 0;
                }
                fun(i,j,k);
                cout<<ans<<endl;
                return 0;
            }
        }
    }

//    cout<<ans<<endl;

//    return 0;
}
