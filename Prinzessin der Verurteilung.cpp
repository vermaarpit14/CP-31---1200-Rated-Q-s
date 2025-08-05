/************************************************************************************/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((int)(x).size())
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define per(i, a, b) for (int i = (b) - 1; i >= (a); --i)
#define each(x, a) for (auto &x : a)

const int INF = 1e18;
const int MOD = 1e9 + 7;

vector<bool> sieve(int n) {
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= n; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i)
                isPrime[j] = false;
        }
    }
    return isPrime;
}
/************************************************************************************/

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //code here
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        string s;
        cin>>s;
        vector<string> allPossible;
        rep(i, 0, 26) allPossible.pb(string(1, (char)(i+97)));
        rep(i, 0, 26){
            rep(j, 0, 26) allPossible.pb(string(1, (char)(i + 97)) + (char)(j + 97));
        }
        rep(i, 0, 26){
            rep(j, 0, 26){
                rep(k, 0, 26) allPossible.pb(string(1, (char)(i + 97)) + (char)(j + 97) + (char)(k + 97));
            }
        }

        each(x, allPossible){
            int m = x.length();
            bool ans = false;
            rep(i, 0, n){
                if (((m == 1) && (s[i] == x[0])) || ((m == 2) && (s[i] == x[0] && s[i + 1] == x[1])) || ((m == 3) && (s[i] == x[0] && s[i + 1] == x[1] && s[i + 2] == x[2]))){
                    ans = true;
                    break;
                }
            }
            if(!ans){
                cout<<x<<"\n";
                break;
            }
        }
    }
    return 0;
}