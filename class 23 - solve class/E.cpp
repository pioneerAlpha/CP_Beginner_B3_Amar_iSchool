#include<bits/stdc++.h>
#define N ((int)1e6 + 5)
#define MOD ((int)1e9 + 7)
#define ll long long
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define MAX ((int)1e6 + 5)
#define endl "\n"

using namespace std;

int cnt[N];

int main()
{
    fastio;
    for(int i = 1 ; i<N ; i++){
        for(int j = i ; j<N ; j += i) cnt[j]++;
    }
    int t;
    cin>>t;
    while(t--){
        int a, b;
        cin>>a>>b;
        int g = __gcd(a,b);
        cout<<cnt[g]<<endl;
    }
    return 0;
}
