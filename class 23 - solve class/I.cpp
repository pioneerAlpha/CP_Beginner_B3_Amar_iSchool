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
   // fastio;
    int t , caseno = 1;
    cin>>t;
    while(t--){
        int n , m;
        cin>>n>>m;
        int seg = n/(2*m);
        ll sum = 1LL*m*m;
        sum = sum*seg;
        cout<<"Case "<<caseno++<<": "<<sum<<endl;
    }
    return 0;
}
