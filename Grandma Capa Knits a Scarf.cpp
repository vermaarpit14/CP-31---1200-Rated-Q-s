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

int f(char ch, string s, int n){
    int i=0, j=n-1;
    while(i <= j){
        if(s[i] == s[j]){
            i += 1;
            j -= 1;
        } else if(s[i] == ch){
            n -= 1;
            i += 1;
        } else if(s[j] == ch){
            n -= 1;
            j -= 1;
        } else {
            return -1;
        }
    }
    return n;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //code here
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        string s; cin>>s;
        int mx = -1;
        for(int i=0 ; i<26 ; i++){
            char ch = (char)(i+97);
            int x = f(ch, s, n);
            if(x != -1)
                mx = max(mx, x);
        }
        cout<<(mx == -1 ? -1 : n-mx)<<"\n";
    }
    return 0;
}