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

/// to declare vector: vector < data type > name;
/// to insert an element: name.push_back(element);
/// to erase an element: name.erase( name.begin() + index ); /// O ( size )
/// to erase a subsegment: name.erase( name.begin() + starting index , name.begin() + ending index + 1 ); /// O ( size )

int dpp[(1<<20) + 2] , n , arr[22];

int call(int mask)
{
    if(mask == 0) return 0;
    if( dpp[mask] != -1 ) return dpp[mask];
    int ans = MAX , sum = 0;
    for(int i = 0 ; i<n ; i++){
        if(mask & (1<<i)) sum += arr[i];
    }
    for(int i = 0 ; i<n ; i++){
        if( mask & (1<<i) ){
            int maskn = mask , sumn = sum;
            for(int j = 0 ; j<3 ; j++){
                int k = i + j;
                if(k == n) k = 0;
                if(maskn & (1<<k)){
                    maskn ^= 1<<k;
                    sumn -= arr[k];
                }
            }
            ans = min(ans , call(maskn) + sumn);
        }
    }
    return dpp[mask] = ans;
}

int main()
{
    int t;
    t = 1;
    while(t--){
        cin>>n;
        for(int i = 0 ; i<n ; i++) cin>>arr[i];
        memset(dpp,-1,sizeof dpp);
        cout<<call((1<<n) - 1 )<<endl;
    }
    return 0;
}
