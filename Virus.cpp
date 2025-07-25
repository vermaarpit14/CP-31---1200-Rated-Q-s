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
        int n, m;
        cin>>n>>m;
        vector<int> a(m);
        for(int i=0 ; i<m ; i++){
            cin>>a[i];
        }
        sort(all(a));
        vector<int> gaps(m);
        gaps[0] = (n-a[m-1]+a[0]-1);
        for(int i=1 ; i<m ; i++){
            gaps[i] = (a[i]-a[i-1]-1);
        }
        sort(rall(gaps));
        int daysPassed=0, saved=0;
        for(int i=0 ; i<m ; i++){
            gaps[i] = gaps[i] - 2*daysPassed;
            if(gaps[i] > 0){
                saved += 1;
            }
            gaps[i] -= 2;
            daysPassed += 1;
            if(gaps[i] > 0){
                saved += gaps[i];
                daysPassed += 1;
            }
        }
        cout<<n-saved<<"\n";
    }
    return 0;
}