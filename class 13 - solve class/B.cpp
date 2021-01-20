#include<bits/stdc++.h>
#define N ((int)2e5 + 5)
#define MAXL ((ll)1e18 + 5)
#define MAX ((int)2e9 + 5)
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define endl "\n"
#define ll long long
#define err (1e-9)

using namespace std;


ll zero(int n) /// count of trailing zeros in n!
{
    ll div = 5;
    ll ans = 0;
    while(div <= n){
        ans += n/div;
        div *= 5;
    }
    return ans;
}

int main()
{
    fastio;
    int t , caseno = 1;
    cin>>t;
    while(t--){
        int q;
        cin>>q;
        int lef = 0 , rig = 5*q;
        while(lef < rig){
            int mid = (lef + rig)/2;
            ll zer = zero(mid);
            if(zer >= q) rig = mid;
            else lef = mid + 1;
        }
        cout<<"Case "<<caseno++<<": ";
        if(zero(lef) == q) cout<<lef<<endl;
        else cout<<"impossible\n";

        /// O ( 32 * 13 )
    }
    return 0;
}
