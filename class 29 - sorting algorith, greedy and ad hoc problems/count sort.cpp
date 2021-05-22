#include<bits/stdc++.h>
#define N ((int)1e6 + 9)
#define MAX ((int)2e9 + 9)
#define eps (1e-8)
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define endl "\n"


using namespace std;

typedef long long ll;
typedef unsigned long long ull;

/*fast io
ios_base::sync_with_stdio(false);
cin.tie(NULL);
*/

int cnt[N] , arr[N];

void countsort(int arr[] , int n)
{
    int mnn = MAX , mxx = -MAX;
    for(int i = 1 ; i<=n ; i++) mnn = min(arr[i] , mnn) , mxx = max(mxx , arr[i]);
    int rng = mxx - mnn;
    for(int i = 0 ; i <= rng ; i++) cnt[i] = 0;
    for(int i = 1 ; i<=n ; i++){
        int a = arr[i] - mnn;
        cnt[a]++;
    }
    int cur = 1;
    for(int i = 0 ; i<=rng ; i++){
        while(cnt[i]--){
            arr[cur++] = i + mnn;
        }
    }
}


int main()
{
//    fastio;
    int n;
    cin>>n;
    for(int i = 1 ; i<=n ; i++) cin>>arr[i];
    countsort(arr,n);
    for(int i = 1 ; i<=n ; i++) cout<<arr[i]<<" ";
    return 0;
}





