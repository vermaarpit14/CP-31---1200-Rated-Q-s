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

bool cmp(pair<int, int> a, pair<int, int> b){
    return (a.second-a.first) > (b.second-b.first);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //code here
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<pair<int, int>> a(n);
        rep(i, 0, n) cin>>a[i].first;
        rep(i, 0, n) cin>>a[i].second;
        sort(all(a), cmp);
        int i=0, j=n-1, cnt=0;
        while(i < n){
            int d1 = a[i].second-a[i].first;
            int d2 = a[j].second-a[j].first;
            while(i<j && d1+d2 < 0){
                j -= 1;
                d2 = a[j].second-a[j].first;
            }
            if(i>=j) break;
            cnt += 1;
            i += 1;
            j -= 1;
        }
        cout<<cnt<<"\n";
    }
    return 0;
}