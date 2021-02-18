/// problem link: https://codeforces.com/contest/1490/problem/B

#include<bits/stdc++.h>
#define MAX ((int)2e9 + 5)
#define MAXL ((ll)1e16 + 5)
#define pi acos(-1)
#define MOD ((int)1e8 + 7)
#define N ((int)2e5 + 5)
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

int arr[N] ;

int main()
{
//    fastio;
    int t , caseno = 1;
    cin>>t;
    while(t--)
    {
        int n , cnt[4];
        cin>>n;
        memset(cnt,0,sizeof cnt);
        for(int i = 1 ; i<=n; i++){
            int a;
            cin>>a;
            cnt[a % 3]++;
        }

        /// operation 1: 0--, 1++;
        /// operation 2: 1--, 2++;
        /// operation 3: 2--, 0++;
        /// so if i-- then  (i+1)++
        /// and if i++ then (i-1)--;
        int ans = 0;
        while(1){
            int inc = 0, dec = 0;
            for(int i = 0 ; i<3 ; i++){
//                cout<<cnt[i]<<" ";
                if(cnt[i] > n/3) dec++;
                else if(cnt[i] < n/3) inc++;
            }
//            cout<<endl;
//            getchar();
            if(inc == 1){
                for(int i = 0 ; i<3 ; i++){
                    if(cnt[i] < n/3){
                        int tmp = n/3 - cnt[i];
                        cnt[i] += tmp;
                        int j = i - 1;
                        if(j < 0) j = 2;
                        cnt[j] -= tmp;
                        ans += tmp;
                        break;
                    }
                }
            }
            else if(dec == 1){
                for(int i = 0 ; i<3 ; i++){
                    if(cnt[i] > n/3){
                        int tmp = cnt[i] - n/3;
                        cnt[i] -= tmp;
                        int j = i + 1;
                        if(j > 2) j = 0;
                        cnt[j] += tmp;
                        ans += tmp;
                        break;
                    }
                }
            }
            else break;
        }
        cout<<ans<<endl;
    }
    return 0;
}
