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
        stack < int > stt;
        stt.push(0);
        for(int i = 1 ; i<=n+n ; i++){
            vis[arr[i]] = !vis[arr[i]];
            if(vis[arr[i]]){
                int a = stt.top();
                cnt[a]++;
                stt.push(arr[i]);
            }
            else stt.pop();
        }
        cout<<"Case "<<caseno++<<":\n";
        for(int i = 1 ; i <= n ; i++) cout<<i<<" -> "<<cnt[i]<<endl;
    }
    return 0;
}
