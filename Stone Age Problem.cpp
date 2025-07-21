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

int globalValue = 0, globalChange = -1, currTime = 0;

int getValue(int i, vector<int> &timeStamp, vector<int> &a){
    if(timeStamp[i-1] > globalChange)
    return a[i-1];
    else
    return globalValue;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //code here
    int n, q, sum=0;
    cin>>n>>q;
    vector<int> a(n), timeStamp(n, 0);
    rep(i, 0, n){
        cin>>a[i];
        sum += a[i];
    }
    while(q--){
        int t; cin>>t;
        if(t == 1){
            int i, x;
            cin>>i>>x;
            sum += (x-getValue(i, timeStamp, a));
            a[i-1] = x;
            timeStamp[i-1] = currTime;
        } else {
            int x; cin>>x;
            sum = n*x;
            globalValue = x;
            globalChange = currTime;
        }
        currTime += 1;
        cout<<sum<<"\n";
    }
    return 0;
}