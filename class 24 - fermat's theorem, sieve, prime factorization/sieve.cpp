#include<bits/stdc++.h>
#define MAX ((int)2e9 + 5)
#define MAXL ((ll)1e16 + 5)
#define pi acos(-1)
#define MOD ((int)1e9 + 7)
#define N ((int)1e7 + 5)
#define eps (1e-8)
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define endl "\n"
#define ll long long
//#define int ll


using namespace std;



//fast io
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);

vector < int > prime;
bool vis[N]; /// N = 1e7

void sieve(int n){
    prime.clear();
    for(int i = 1 ; i<=n; i++) vis[i] = 0;
    for(int i = 3 ; i*i <= n ; i += 2){
        if(vis[i] == 0){
            for(int j = i*i ; j <= n ; j += (i<<1)){
                vis[j] = 1;
            }
        }
    }
    prime.push_back(2);
    for(int i = 3 ; i<=n ; i += 2){
        if(vis[i] == 0) prime.push_back(i);
    }
}


int main()
{
    ///

    fastio;
    sieve(N-5);
    return 0;

}
