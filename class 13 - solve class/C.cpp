#include<bits/stdc++.h>
#define N ((int)2e5 + 5)
#define MAXL ((ll)1e18 + 5)
#define MAX ((int)2e9 + 5)
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define endl "\n"
#define ll long long
#define err (1e-9)

using namespace std;



int main()
{
    fastio;
    int t , caseno = 1;
    cin>>t;
    while(t--){
        double ab , ac , bc , rat;
        cin>>ab>>ac>>bc>>rat;
        rat /= 1 + rat;
//        cout<<rat<<endl;
        int iter = 0;
        double lef = 0 , rig = ab;
        while((rig - lef) > err && iter < 100){
            double mid = (lef + rig)/2;
            double val = mid/ab;
            val *= val;
            if(val < rat) lef = mid;
            else rig = mid;
//            cout<<mid<<" "<<val<<endl;
//            getchar();
            iter++;
        }
        cout<<"Case "<<caseno++<<": ";
        cout<<setprecision(15)<<fixed;
        cout<<lef<<endl;
//        else cout<<"impossible\n";

        /// O ( 32 * 13 )
    }
    return 0;
}
