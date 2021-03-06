#pragma GCC diagnostic ignored "-Wunused-parameter"
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

#define INP "solve"
#define OUT "solve"

const long long INF_LL = 8e18;
const int INF = 1e9 + 100;
const int MOD = 1e9 + 7;
//const int Base = 311;9
const long double EPS = 1e-10;
const int BLOCK = 1000;
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};
mt19937 rnd(chrono::system_clock::now().time_since_epoch().count());

void open_file() {
    #ifdef THEMIS
        freopen(INP ".inp","r",stdin);
        freopen(OUT ".out","w",stdout);
    #endif // THEMIS
}

const int maxN = 1e3 + 100;

void sol(){
    int n, m;
    cin >> n >> m;
    vector<pair<int, int> > a(m);
    for (int i = 0; i < m; i++) {
        cin >> a[i].first >> a[i].second;
        a[i].first--; a[i].second--;
    }

    vector<int> ok(n, 0);
    auto check = [&](vector<int> &val) {
        int num = 0;
        for (int i = 0; i < m; i++) {
            num += val[a[i].first] == 1 && val[a[i].second] == 0;
        }
        return num >= m / 4 + 1;
    };

    vector<int> val(n);
    while (true) {
        for (int i = 0; i < n; i++) val[i] = rnd() % 2;
        if (check(val)) {
            vector<int> ans;
            for (int i = 0; i < m; i++) {
                if (val[a[i].first] == 1 && val[a[i].second] == 0) ans.push_back(i);
            }
            cout << (int)ans.size() << '\n';
            for (int x : ans) cout << x + 1 << ' ';
            cout << '\n';
            return;
        }
    }
}


void solve() {
    clock_t begin = clock();
    int T;
    cin >> T;
    //T = 1;
    int TestCase = 0;
    while (T--) {
        TestCase += 1;
        //cout << "Case #" << TestCase << ":" << ' ';
        //cout << "Test " << TestCase << ": ";
        sol();
    }
    clock_t end = clock();
    cerr << "Time: " << fixed << setprecision(10) << (double)(end - begin) / (double)CLOCKS_PER_SEC << '\n';
}

int main(int argc,char *argv[]) {
    ///srand(time(nullptr));
    ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    open_file();
    solve();
}