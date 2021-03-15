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
    int t , caseno = 1;
    cin>>t;
    while(t--){
        ll w;
        cin>>w;
        ll m = 1;
        while(w % 2 == 0){
            m *= 2;
            w /= 2;
        }
        ll n = w;
        cout<<"Case "<<caseno++<<": "<<n<<" "<<m<<endl;
    }
    return 0;
}
