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


pair < int , int > arr[N];

/// {1,2} < {2,1} ; {1,1} < {1,2}

/// {1,2} > {2,1} ; {1,1} < {1,2} ; {1,2} < {2,2}

/// my definition:
/// a < b if a.second < b.second

bool cmp(pair < int , int > a , pair < int , int > b) /// returns true if a < b;
{
    if(a.second < b.second) return true;
    return false;
}

int main()
{
//    fastio;
    int n;
    cin>>n;
    for(int i = 1 ; i<=n ; i++) cin>>arr[i].first>>arr[i].second;
    sort(arr+1,arr+n+1,cmp);
    for(int i = 1 ; i<=n ; i++) cout<<arr[i].first << " " << arr[i].second << endl;
    return 0;
}





