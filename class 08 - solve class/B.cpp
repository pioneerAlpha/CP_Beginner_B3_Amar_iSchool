#include<bits/stdc++.h>
#define N ((int)1e3 + 5)
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define endl "\n"

using namespace std;


int dis[N] ;

vector < int > vec[N];

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
    vector < int > prime;
    for(int i = 2 ; i<N ; i++){
        bool flag = 1;
        for(int j = 2 ; j<i ; j++){
            if(i % j == 0){
                flag = 0;
                break;
            }
        }
        if(flag == 1) prime.push_back(i);
    }
    for(int i = 2 ; i<N ; i++){
        for(int p:prime){
            if(p < i && i % p == 0){
                int tmp = i + p;
                vec[i].push_back(tmp);
            }
        }
    }
    int t , caseno = 1;;
    cin>>t;
    while(t--){
        int src , des;
        cin>>src>>des;
        bfs(src);
        cout<<"Case "<<caseno++<<": "<<dis[des]<<endl;
    }
    return 0;
}
