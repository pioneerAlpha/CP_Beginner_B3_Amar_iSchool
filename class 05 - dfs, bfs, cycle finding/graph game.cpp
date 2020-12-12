problem link: https://csacademy.com/contest/archive/task/graph-game
#include<bits/stdc++.h>
#define N ((int)1e5 + 5)
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define endl "\n"

using namespace std;


int deg[N];


int main()
{
    fastio;

    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        cin>>n>>m;
        for(int i = 1 ; i<=n ; i++) deg[i] = 0;
        while(m--)
        {
            int a, b;
            cin>>a>>b;
            deg[a]++;
            deg[b]++;
        }

        int cnt = 0;
        for(int i = 1 ; i<=n ; i++) if(!(deg[i]&1)) cnt++;
        cout<<(cnt&1)<<endl;
    }
    return 0;
}
