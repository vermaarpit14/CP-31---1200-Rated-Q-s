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
        int n, q;
        cin>>n>>q;
        vector<int> a(n+1), pre(n+1, 0), pmax(n+1, 0);
        rep(i, 0, n) cin>>a[i];
        a[n] = INF;
        rep(i, 1, n+1) pre[i] = pre[i-1]+a[i-1];
        pmax[0] = a[0];
        rep(i, 1, n+1) pmax[i] = max(pmax[i-1], a[i]);
        while(q--){
            int k, ans=0;
            cin>>k;
            int low=0, high=n;
            while(low <= high){
                int mid = low + (high-low)/2;
                if(pmax[mid] <= k){
                    low = mid+1;
                } else {
                    ans = pre[mid];
                    high = mid-1;
                }
            }
            cout<<ans<<" ";
        }
        cout<<"\n";
    }
    return 0;
}