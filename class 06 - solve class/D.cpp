#include<bits/stdc++.h>
#define N ((int)1e5 + 5)
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define endl "\n"

using namespace std;


bool vis[105][105];

int dirx[] = {0,0,1,-1};
int diry[] = {1,-1,0,0};

int arr[105][105] , ans[105][105];

int main()
{
    fastio;
    int t;
    cin>>t;
    while(t--){
        int n , m;
        cin>>n>>m;
        memset(vis,0,sizeof vis);
        for(int i = 1 ; i<=n ; i++){
            for(int j = 1 ; j <= m ; j++) cin>>arr[i][j];
        }
        priority_queue < pair < int , pair < int , int > > >  pqq;
        for(int i = 1 ; i<=n ; i++){
            ans[i][1] = arr[i][1];
            pqq.push({-ans[i][1],{i,1}});
            vis[i][1] = 1;
            if(m > 1){
                ans[i][m] = arr[i][m];
                vis[i][m] = 1;
                pqq.push({-ans[i][m],{i,m}});
            }
        }

        for(int j = 2 ; j<m ; j++){
            ans[1][j] = arr[1][j];
            vis[1][j] = 1;
            pqq.push({-ans[1][j],{1,j}});
            if(n > 1){
                ans[n][j] = arr[n][j];
                vis[n][j] = 1;
                pqq.push({-ans[n][j],{n,j}});
            }
        }

        for(int i = 0 ; i<=n+1 ; i++) vis[i][0] = vis[i][m+1] = 1;
        for(int i = 0 ; i<=m+1 ; i++) vis[0][i] = vis[n+1][i] = 1;

        while(!pqq.empty()){
            pair < int , int > p = pqq.top().second;
            pqq.pop();
            int row = p.first , col = p.second;
            for(int i = 0 ; i<4 ; i++){
                int x = row + dirx[i] , y = col + diry[i];
                if(!vis[x][y]){
                    vis[x][y] = 1;
                    ans[x][y] = max(arr[x][y] , ans[row][col]);
                    pqq.push({-ans[x][y],{x,y}});
                }
            }
        }
        int anss = 0;
        for(int i = 1 ; i<=n ; i++){
            for(int j = 1 ; j<=m ; j++) anss += ans[i][j] - arr[i][j];
        }
        cout<<anss<<endl;
    }
    return 0;
}
