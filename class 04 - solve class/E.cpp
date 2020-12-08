#include<bits/stdc++.h>

using namespace std;

int mask[1005];

int main()
{
    int n , m  , k , ans = 0;
    cin>>n>>m>>k;
    m++;
    for(int i = 1 ; i<=m ; i++){
        cin>>mask[i];
    }
    for(int i = 1 ; i<m ; i++){
        int tmp = mask[i]^mask[m];
        int cnt = __builtin_popcount(tmp);
        if(cnt <= k) ans++;
    }
    cout<<ans<<endl;
    return 0;
}
