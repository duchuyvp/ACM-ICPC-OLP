#pragma GCC diagnostic ignored "-Wunused-parameter"
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

#define INP "OB"
#define OUT "OB"

const long long INF_LL = 1e17;
const int INF = 1e9 + 100;
const int MOD = 1e9 + 7;
const int Base = 30;
const double EPS = 1e-9;
const int BLOCK = 1000;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

void open_file() {
    #ifdef THEMIS
        freopen(INP ".inp","r",stdin);
        freopen(OUT ".out","w",stdout);
    #endif // THEMIS
}

const int maxN = 5e5 + 10;

void sol() {
    string s;
    cin >> s;
    int n = (int)s.size();
    int a = 0, b = 0;
    for (int i = 0; i < n; i += 2) {
        int old_a = a, old_b = b;
        if (s[i] == 'A') {
            int c = s[i + 1] - '0';
            a += c;
        }
        if (s[i] == 'B') {
            int c = s[i + 1] - '0';
            b += c;
        }
        if (a >= 11 && (b < 10 || a - b >= 2)) {
            cout << "A";
            return;
        }
        if (b >= 11 && (a < 10 || b - a >= 2)) {
            cout << "B";
            return;
        }
    }
}

void solve() {
    int T;
    ///cin >> T;
    T = 1;
    int TestCase = 0;
    while (T--) {
        TestCase += 1;
        //cout << "Case #" << TestCase << ":" << ' ';
        ///cout << "Case #" << TestCase << '\n';
        sol();
    }
}
int main(int argc,char *argv[]) {
    //srand(time(nullptr));
    ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    open_file();
    solve();
}