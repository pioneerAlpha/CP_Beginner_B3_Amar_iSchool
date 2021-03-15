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
    string a , b;
    cin>>a>>b;
    if(a == b) cout<<a<<endl;
    else cout<<"1\n";
    return 0;
}
