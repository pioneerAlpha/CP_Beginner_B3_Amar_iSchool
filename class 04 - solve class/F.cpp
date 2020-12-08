#include<bits/stdc++.h>

using namespace std;



int main()
{
    int n;
    cin>>n;
    int ans = 0;
    for(int i = 0 ; n>0 ; i++){
        if(n&(1<<i)){
            n -= 1<<i;
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
