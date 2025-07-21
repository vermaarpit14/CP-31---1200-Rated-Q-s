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
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; ++i)
        {
            prefix[i + 1] = prefix[i] + a[i];
        }

        int total_packs = 0;
        int days_passed = 0;
        for (int i = n; i >= 1; --i)
        {
            int sum = prefix[i] + days_passed * i;
            if (sum <= x)
            {
                int remaining = x - sum;
                int max_possible_days = remaining / i + 1;
                total_packs += max_possible_days * i;
                days_passed += max_possible_days;
            }
        }
        cout << total_packs << "\n";
    }
    return 0;
}