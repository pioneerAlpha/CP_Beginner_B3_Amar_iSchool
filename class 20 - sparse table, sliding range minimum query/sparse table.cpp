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

int arr[N] , tab[22][N] , aux[N];

void sparse(int n)
{
    for(int i = 1 ; i<=n ; i++) tab[i][0] = arr[i];
    for(int j = 1 ; j<20 ; j++){
        for(int i = 1 ; i<=n ; i++){
            tab[i][j] = tab[i][j-1];
            int too = i + (1<<(j-1));
            if(too <= n) tab[i][j] = min(tab[i][j] , tab[too][j-1]);
        }
    } /// O (n * logn)
    aux[1] = 0;
    for(int i = 2 ; i<=n ; i++) aux[i] = aux[i/2] + 1;
}

int query(int l , int r)
{
    int len = r - l + 1;
    int i = aux[len]; /// 2^i <= len
    int ans = tab[l][i];
    int too = r - (1<<i) + 1;
    ans = min(ans , tab[too][i]);
    return ans;
}

int main()
{
    int n , q;
    cin>>n>>q;
    for(int i = 1 ; i<=n ; i++) cin>>arr[i];
    sparse(n);
    while(q--){
        int l , r;
        cin>>l>>r;
        cout<<query(l,r)<<endl;
    }
}
