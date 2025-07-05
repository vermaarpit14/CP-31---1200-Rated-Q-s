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
        vector<pair<int, int>> a(n), b(n), c(n);
        rep(i, 0, n){
            int x; cin>>x;
            a[i] = {x, i};
        }
        rep(i, 0, n){
            int x; cin>>x;
            b[i] = {x, i};
        }
        rep(i, 0, n){
            int x; cin>>x;
            c[i] = {x, i};
        }
        sort(all(a));
        sort(all(b));
        sort(all(c));
        int ans = 0;
        for(int i=n-3 ; i<n ; i++){
            for(int j=n-3 ; j<n ; j++){
                for(int k=n-3 ; k<n ; k++){
                    if ((a[i].second != b[j].second) && (b[j].second != c[k].second) && (a[i].second != c[k].second))
                    ans = max(ans, a[i].first+b[j].first+c[k].first);
                }
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}