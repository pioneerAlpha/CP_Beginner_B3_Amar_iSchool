#include<bits/stdc++.h>
#define ll long long
#define N ((int)(2e5 + 5))
#define MAX ((int)2e9 + 5)
#define MOD ((int)(1e9 + 7))
#define endl "\n"
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL);


using namespace std;

// fastio
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);



int main()
{
    set < int > sss;
    fastio;
    sss.insert(5);  /// log
    sss.insert(5);
    sss.insert(-5);
    sss.insert(0);
    cout<<sss.size()<<endl;

    set < int > :: iterator it;

    sss.erase(0);

    for(it = sss.begin(); it != sss.end() ; it++)
    {
        cout<<*it<<endl;
    }

    return 0;
}
