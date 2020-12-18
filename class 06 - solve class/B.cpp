#include<bits/stdc++.h>
#define N ((int)1e5 + 5)
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define endl "\n"

using namespace std;


string str[45];

bool vis[45][45][12];

int dirx[] = {0,0,1,-1};
int diry[] = {1,-1,0,0};

void dfs(int row , int col , int cnt)
{
    if(cnt > 10) return;
    if(vis[row][col][cnt] == 1) return;
    vis[row][col][cnt] = 1;
    for(int i = 0 ; i<4 ; i++){
        int x = row + dirx[i] , y = col + diry[i];
        if(str[x][y] == '#') continue;
        if(str[x][y] == 's') dfs(x,y,cnt+1);
        else dfs(x,y,cnt);
    }
}

int main()
{
    fastio;
    int n , m , cap;
    cin>>n>>m>>cap;
    for(int i = 1 ; i<=n ; i++){
        cin>>str[i];
        str[i] += "##";
        for(int j = m ; j>0 ; j--) str[i][j] = str[i][j-1];
        str[i][0] = '#';
    }
    for(int i = 0 ; i<m+2 ; i++){
        str[0] += "#";
        str[n+1] += "#";
    }

    for(int i = 1 ; i<=n ; i++){
        for(int j = 1 ; j<=m ; j++){
            if(str[i][j] == 'x'){
                dfs(i,j,0);
                break;
            }
        }
    }

    for(int i = 1 ; i<=n ; i++){
        for(int j = 1 ; j<=m ; j++){
            if(str[i][j] == '@'){
                for(int cnt = 0 ; cnt <= j/2 ; cnt++){
                    if(vis[i][j][cnt] == 1){
                        cout<<"SUCCESS\n";
                        return 0;
                    }
                }
            }
        }
    }

    cout<<"IMPOSSIBLE\n";

    return 0;
}
