#include<bits/stdc++.h>
#define MAX ((int)2e9 + 5)
#define MAXL ((ll)1e16 + 5)
#define pi acos(-1)
#define MOD ((int)1e9 + 7)
#define N ((int)1e5 + 5)
#define eps (1e-8)
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define endl "\n"
#define ll long long
//#define int ll


using namespace std;



/*fast io
ios_base::sync_with_stdio(false);
cin.tie(NULL);
*/


int dpp[(1<<15) + 2] , n , arr[16] ;

string dam[16];

int call(int mask) /// 2^n
{
    if(mask == 0) return 0;
    if(dpp[mask] != -1) return dpp[mask];
    int ans = MAX;
    for(int i = 0; i < n ;i++){
        if(mask & (1<<i)){
            for(int j = 0 ; j<n ; j++){
                if(mask & (1<<j)) continue;
                int tmp = call(mask ^ (1<<i));
                int dmg = (dam[j][i] - '0');
                if(dmg > 0){
                    int shot = (arr[i] + dmg - 1) / dmg;
                    tmp += shot;
                    ans = min(ans , tmp);
                }
            }
            ans = min(ans , call(mask ^ (1<<i)) + arr[i]);
        }
    }
    /// O(n*n)
    return dpp[mask] = ans;
}

/// O (n * n * 2^n );

int main()
{
    int t , caseno = 1;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i = 0 ; i<n ; i++) cin>>arr[i];
        for(int i = 0 ; i<n ; i++){
            cin>>dam[i];
        }
        memset(dpp,-1,sizeof dpp);
        cout<<"Case "<<caseno++<<": "<<call((1<<n) - 1)<<endl;
    }
    return 0;
}
