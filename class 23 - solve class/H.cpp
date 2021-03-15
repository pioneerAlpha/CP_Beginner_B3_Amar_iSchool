#include<bits/stdc++.h>
#define N ((int)1e6 + 5)
#define mod ((int)1e9 + 7)
#define ll long long
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define MAX ((int)1e6 + 5)
#define endl "\n"

using namespace std;


int main()
{
//    fastio;
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll a = sqrt(n) - 10;
        if(a < 0) a = 0;
        bool flag = 1;
        while(1){
            if(a*a == n){
                flag = 0;
                break;
            }
            else if(a*a > n) break;
            a++;
        }

        if(flag) cout<<"NO\n";
        else cout<<"YES\n";

    }
    return 0;
}
