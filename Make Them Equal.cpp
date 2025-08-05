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
        char c;
        cin>>n>>c;
        string s;
        cin>>s;
        bool f = true;
        for(int i=0 ; i<n ; i++){
            if(s[i] != c){
                f = false;
                break;
            }
        }
        if(f){
            cout<<0<<"\n";
        } else {
            if(s[n-1] == c)
            cout<<1<<"\n"<<n<<"\n";
            else{
                bool found = false;
                for(int i=2 ; i<=n ; i++){
                    bool valid = true;
                    for(int j=i ; j<=n ; j+=i){
                        if(s[j-1] != c){
                            valid = false;
                            break;
                        }
                    }
                    if(valid){
                        cout<<1<<"\n"<<i<<"\n";
                        found = true;
                        break;
                    }
                }
                if(!found){
                    cout<<2<<"\n"<<n-1<<" "<<n<<"\n";
                }
            }
        }
    }
    return 0;
}