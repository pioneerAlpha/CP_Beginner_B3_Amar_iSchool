#include<bits/stdc++.h>
#define pi acos(-1)
#define MOD ((int)1e9 + 7)
#define N ((int)2e2 + 9)
#define eps (1e-8)
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define endl "\n"


typedef long long ll;
typedef unsigned long long ull;

/*fast io
ios_base::sync_with_stdio(false);
cin.tie(NULL);
*/



int main(){
    int n;
    vector < int > vec; /// prime factorize in root(n)
    int ans = n;
    for(int a:vec){
        ans /= a;
        ans *= a-1;
    }
    cout<<ans<<endl;
}

