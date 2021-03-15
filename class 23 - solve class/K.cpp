#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define endl "\n"
#define ll long long
#define N ((int)(1e5 + 5))

using namespace std;

ll arr[N];

int main()
{
    fastio;
    int t , caseno = 1;
    cin>>t;
    while(t--){
        int n , q;
        cin>>n>>q;
        ll sum = 0;
        for(int i = 0 ; i<n ; i++){
            cin>>arr[i];
            sum += arr[i]*(n-1-2*i);
        }
        cout<<"Case "<<caseno++<<":\n";
        while(q--){
            int typ ;
            cin>>typ;
            if(typ == 1) cout<<sum<<endl;
            else{
                int x , v;
                cin>>x>>v;
                sum -= arr[x]*(n-1-2*x);
                arr[x] = v;
                sum += arr[x]*(n-1-2*x);
            }
        }
    }
    return 0;
}
