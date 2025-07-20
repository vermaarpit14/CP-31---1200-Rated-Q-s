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
        vector<vector<int>> grid(n, vector<int>(n, 0));
        for (int i = 0; i < n; ++i)
        {
            string s;
            cin >> s;
            for (int j = 0; j < n; ++j)
            {
                grid[i][j] = s[j] - '0';
            }
        }
        int operations = 0;
        for (int i = 0; i < (n + 1) / 2; ++i)
        {
            for (int j = 0; j < n / 2; ++j)
            {
                int x1 = i, y1 = j;
                int x2 = j, y2 = n - 1 - i;
                int x3 = n - 1 - i, y3 = n - 1 - j;
                int x4 = n - 1 - j, y4 = i;
                int sum = grid[x1][y1] + grid[x2][y2] + grid[x3][y3] + grid[x4][y4];
                operations += min(sum, 4 - sum);
            }
        }
        cout << operations << "\n";
    }
    return 0;
}