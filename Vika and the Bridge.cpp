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
        int n, k;
        cin>>n>>k;
        vector<int> c(n);
        rep(i, 0, n) cin>>c[i];
        vector<int> a[k+1];
        for(int i=1 ; i<=k ; i++) a[i].push_back(0);
        for(int i=0 ; i<n ; i++) a[c[i]].push_back(i+1);
        for(int i=1 ; i<=k ; i++) a[i].push_back(n+1);
        priority_queue<int> pq[k+1];
        int ans = INT_MAX;
        for(int i=1 ; i<=k ; i++){
            for(int j=0 ; j<a[i].size()-1 ; j++){
                pq[i].push(a[i][j+1]-a[i][j]-1);
            }
            int mx = pq[i].top();
            pq[i].pop();
            pq[i].push(mx/2);
            if(mx&1)
            pq[i].push(mx/2);
            else
            pq[i].push(mx/2-1);
            ans = min(ans, pq[i].top());
        }
        cout<<ans<<"\n";
    }
    return 0;
}