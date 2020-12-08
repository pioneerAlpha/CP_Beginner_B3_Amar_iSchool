#include<bits/stdc++.h>

using namespace std;

int ang[20];

int main()
{
    int n ;
    cin>>n;
    for(int i = 0 ; i<n ; i++) cin>>ang[i];
    for(int mask = 0 ; mask < (1<<n) ; mask++){
        int sum = 0;
        for(int i = 0 ; i<n ; i++){
            if( mask & (1<<i) ) sum += ang[i];
            else sum -= ang[i];
        }
        if(sum % 360 == 0){
            cout<<"YES\n";
            return 0;
        }
    }
    cout<<"NO\n";
    return 0;
}
