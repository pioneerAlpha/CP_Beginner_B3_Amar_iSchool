#include<bits/stdc++.h>
#define pi acos(-1)
#define MOD ((int)1e9 + 7)
#define N ((int)2e2 + 9)
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

string str ;

bool vis[30];

vector < string > vec;

void backtrack(int rem)
{
    if(rem == 0){
        vec.push_back(str);
        return;
    }
    for(int i = 0 ; i<26 ; i++){
        if(vis[i]){
            vis[i] = 0;
            str += 'a' + i;
            backtrack(rem-1);
            vis[i] = 1;
            str.pop_back();
        }
    }
}


int main()
{
    /// problem: given a string of distinct characters, print all of its permutations
    /*
    input: acb
    output:
    abc
    acb
    bac
    bca
    cab
    cba
    */
    string str;
    cin>>str; /// string of distinct characters from a to z
    for(int i = 0 ; i<str.size(); i++){
        vis[str[i]-'a'] = 1;
    }
    backtrack(str.size());
    for(auto p:vec) cout<<p<<endl;
    return 0;
}

