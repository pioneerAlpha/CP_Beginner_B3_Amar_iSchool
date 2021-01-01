/// contest: graph intro
#include<bits/stdc++.h>
#define N ((int)1e5 + 5)
#define MAXL ((ll)1e18 + 5)
#define MAX ((int)2e9 + 5)
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define endl "\n"
#define ll long long

using namespace std;



string str[25] , ans , dir , tmp[25];

int n , m;

int dxx[] = {0,0,1,-1};
int dyy[] = {1,-1,0,0};

bool vis[25][25];

char dfs(pair < int , int > cur , pair < int , int > des)
{
    if(cur == des) return '0';
    int x = cur.first , y = cur.second;
    vis[x][y] = 1;
    for(int i = 0 ; i<4 ; i++){
        int a = x + dxx[i] , b = y + dyy[i];
        if(min(a,b) < 0 || a >= n || b >= m || vis[a][b] || str[a][b] == '0') continue;
        if(dfs({a,b},des) != '#') return dir[i];
    }
    return '#';
}

int idx(char c)
{
    for(int i = 0 ; i<4 ; i++){
        if(dir[i] == c) return i;
    }
}

void follow(int too)
{

    for(int i = 0 ; i<n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(tmp[i][j] == '1') tmp[i][j] = '2';
        }
    }

    for(int i = 0 ; i<n ; i++){
        for(int j = 0 ; j<m ; j++){
            if(str[i][j] == '1'){
                int x = i + dxx[too] , y = j + dyy[too];
                if(min(x , y) < 0 || x >= n || y >= m || str[x][y] == '0') tmp[i][j] = '1';
            }
        }
    }

    if(too == 0) too = 1;
    else if(too == 1) too = 0;
    else if(too == 2) too = 3;
    else too = 2;

    for(int i = 0 ; i<n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(tmp[i][j] == '0') continue;
            int x  = i + dxx[too] , y = j + dyy[too];
            if(min(x, y ) < 0 || x >= n || y >= m) continue;
            if(str[x][y] == '1') tmp[i][j] = '1';
        }
    }

    for(int i = 0 ; i<n ; i++) str[i] = tmp[i];
}

pair < int , int > pos(pair < int , int > cur , int too)
{
    int x = cur.first , y = cur.second ,a , b;
    a = x + dxx[too] , b = y + dyy[too];
    if(min(a,b) < 0 || a >= n || b >= m || str[a][b] == '0') return {x,y};
    return {a,b};
}

void bug(char c)
{
    cout<<c<<endl;
    for(int i = 0 ; i<n ; i++) cout<<str[i]<<endl;
}

int main()
{
    dir = "RLDU";
//    //cout<<(int)((1LL<<31)-1);
    fastio;
    int t , caseno = 1;
    t = 1;
    while(t--){
        int cur = 0;
        cin>>n>>m;
        for(int i = 0 ; i<n ; i++){
            cin>>str[i];
            tmp[i] = str[i];
        }
        ans = "";
        while(1){
            pair < int , int > from = {-1,-1} , too = {-1,-1};
            bool flag = 1;
            for(int i = 0 ; i<n && flag; i++){
                for(int j = 0 ; j < m && flag; j++){
                    if(str[i][j] == '1'){
                        if(from.first == -1) from = {i,j};
                        else{
                            too = {i,j};
                            flag = 0;
//                            cout<<"start "<<from.first<<" "<<from.second<<" "<<too.first<<" "<<too.second<<endl;
                            while(from != too){
//                                cout<<from.first<<" "<<from.second<<" "<<too.first<<" "<<too.second<<endl;
//                                getchar();
                                memset(vis,0,sizeof vis);
                                char c = dfs(from, too);
                                ans += c;
                                int idd = idx(c);
                                follow(idd);
                                from = pos(from,idd) , too = pos(too,idd) ;
//                                bug(c);
                            }
                            break;
                        }
                    }
                }
            }
            if(flag) break;
        }
        cout<<ans<<endl;
    }
    return 0;
}
