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
        int n, last=-1;
        cin>>n;
        vector<int> a(n);
        map<int, int> mp;
        rep(i, 0, n) {
            cin>>a[i];
            mp[a[i]] += 1;
        }
        int cnt = 0;
        sort(all(a));
        a.erase(unique(all(a)), a.end());
        for(int i=0 ; i<a.size() ; i++){
            cnt += max(mp[a[i]] - mp[a[i]-1], 0LL);
        }
        cout<<cnt<<"\n";
    }
    return 0;
}