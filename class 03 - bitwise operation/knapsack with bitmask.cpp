#include<bits/stdc++.h>
#define ll long long
#define N ((int)(2e5 + 5))
#define MAX ((int)2e9 + 5)
#define MOD ((int)(1e9 + 7))
#define endl "\n"
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL);


using namespace std;

// fastio
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);





int main()
{
    int n , val[22] , vol[22] , cap;
    cin>>n>>cap; /// sub set = 2 to the power n
    for(int i = 0 ; i<n ; i++) cin>>val[i]>>vol[i];
    int ans = 0;
    for(int mask = 0 ; mask < (1<<n) ; mask++){
        int pro = 0 , sum = 0;
        for(int i = 0 ; i<n ; i++){
            if(mask & (1<<i)){
                pro += val[i];
                sum += vol[i];
            }
        }

        if(sum <= cap) ans = max(ans , pro);
    }
    cout<<ans<<endl;

    for(int mask = 0 ; mask < (1<<n) ; mask++){
        int pro = 0 , sum = 0;
        for(int i = 0 ; i<n ; i++){
            if(mask & (1<<i)){
                pro += val[i];
                sum += vol[i];
            }
        }

        if(sum <= cap && ans == pro){
            for(int i = 0 ; i<n ; i++)
                if(mask & (1<<i)) cout<<i<<" ";
            cout<<endl;
            break;
        }
    }

    /// O (n*2^n)
    return 0;
}
