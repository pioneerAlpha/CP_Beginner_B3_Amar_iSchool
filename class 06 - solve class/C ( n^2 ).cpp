#include<bits/stdc++.h>
#define N ((int)1e5 + 5)
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define endl "\n"

using namespace std;

int cnt[105], vis[105] , arr[105];

int main()
{
    fastio;
    int t , caseno = 1;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i = 1 ; i<=n+n ; i++) cin>>arr[i];
        memset(cnt,0,sizeof cnt);
        memset(vis,0,sizeof vis);
        for(int i = 1 ; i<=n+n ; i++){
            vis[arr[i]] = !vis[arr[i]];
            if(!vis[arr[i]]) continue;
            for(int j = i-1 ; j>0 ; j--){
                if(vis[arr[j]]){
                    cnt[arr[j]]++;
                    break;
                }
            }
        }
        cout<<"Case "<<caseno++<<":\n";
        for(int i = 1 ; i <= n ; i++) cout<<i<<" -> "<<cnt[i]<<endl;
    }
    return 0;
}
