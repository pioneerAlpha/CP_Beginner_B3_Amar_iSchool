#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define endl "\n"
#define ll long long
#define N ((int)(1e5 + 5))

using namespace std;

ll arr[N] , cnt[N];

int main()
{
    fastio;
    int t;
    t = 1;
    while(t--){
        int n , q;
        cin>>n>>q;
        for(int i = 1 ; i<=n ; i++){
            cin>>arr[i];
            cnt[arr[i]]++;
        }
        ll ans = 0;
        for(int i = 1 ; i<=n ; i++){
            cnt[arr[i]]--;
            int b = arr[i];
            int c = q ^ b;
            if(c < N ) ans += cnt[c];
        }
        cout<<ans<<endl;
    }
    return 0;
}
