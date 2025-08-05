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
        string a, b;
        cin>>a>>b;
        bool ans = true;
        int c1_0=0, c1_1=0, c2_0=0, c2_1=0;
        rep(i, 0, n){
            if(a[i] == '0') c1_0 += 1;
            if(a[i] == '1') c1_1 += 1;
            if(b[i] == '0') c2_0 += 1;
            if(b[i] == '1') c2_1 += 1;
            if(!((c1_0==c2_0 && c1_1==c2_1) || (c1_0==c2_1 && c1_1==c2_0))){
                ans = false;
                break;
            }
        }
        cout<<(ans ? "YES" : "NO")<<"\n";
    }
    return 0;
}