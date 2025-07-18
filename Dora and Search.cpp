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
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        rep(i, 0, n) cin>>a[i];
        int mn=1, mx=n, l=0, r=n-1;
        bool ans = false;
        while(l < r){
            bool f = true;
            if(a[l]==mn){
                mn += 1;
                l += 1;
                f = false;
            }
            if(a[r]==mn){
                mn += 1;
                r -= 1;
                f = false;
            }
            if(a[l]==mx){
                mx -= 1;
                l += 1;
                f = false;
            }
            if(a[r]==mx){
                mx -= 1;
                r -= 1;
                f = false;
            }
            if(f){
                ans = true;
                break;
            }
        }
        if(ans)
            cout << l + 1 << " " << r + 1 << "\n";
        else
            cout << -1 << "\n";
    }
    return 0;
}