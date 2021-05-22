#include<bits/stdc++.h>
#define N ((int)1e6 + 9)
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

int aux[N] , arr[N];

void mergsort(int arr[] , int L , int R)
{
    if(L == R) return;
    int mid = (L + R)>>1;
    mergsort(arr,L,mid);
    mergsort(arr,mid+1,R);
    int i = L , j = mid+1 , k = L;
    while(i <= mid && j <= R){
        if(arr[i] < arr[j]){
            aux[k++] = arr[i++];
        }
        else{
            aux[k++] = arr[j++];
        }
    }
    while(i <= mid){
        aux[k++] = arr[i++];
    }
    while(j <= R){
        aux[k++] = arr[j++];
    }
    for(int i = L ; i <= R ; i++) arr[i] = aux[i];
}


int main()
{
//    fastio;
    int n;
    cin>>n;
    for(int i = 1 ; i<=n ; i++) cin>>arr[i];
    mergsort(arr,1,n);
    for(int i = 1 ; i<=n ; i++) cout<<arr[i]<<" ";
    return 0;
}





