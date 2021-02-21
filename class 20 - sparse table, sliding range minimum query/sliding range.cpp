#include<bits/stdc++.h>
#define MAX ((int)2e9 + 5)
#define MAXL ((ll)1e16 + 5)
#define pi acos(-1)
#define MOD ((int)1e8 + 7)
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


int sub[N] , arr[N];

int main()
{
    int n , k;
    cin>>n>>k;
    for(int i = 1 ; i<=n ; i++) cin>>arr[i];
    deque < pair < int , int > > deq;
    for(int i = 1 ; i <= k ; i++){
        while(!deq.empty()){
            pair < int , int > p = deq.back();
            if(p.first >= arr[i]) deq.pop_back();
            else break;
        }
        deq.push_back({arr[i],i});
    }
    sub[1] = deq.front().first;
    for(int i = k + 1 ; i <= n ; i++){
        if(!dep.empty()){
            if( i - deq.front().second >= k ) deq.pop_front();
        }

        while(!deq.empty()){
            pair < int , int > p = deq.back();
            if(p.first >= arr[i]) deq.pop_back();
            else break;
        }
        deq.push_back({arr[i],i});
        sub[i - k + 1] = deq.front().first;
    }

    /// O ( n )

    int q;
    cin>>q;
    while(q--){
        int l;
        cin>>l;
        cout<<sub[l]<<endl;
    }
    /// O ( q )
    return 0;
}
