#include <bits/stdc++.h>

using namespace std;

// #define endl '\n'
#define INF 1e9
#define vi vector<long long int>
#define ll long long int
#define all(x) x.begin(), x.end()

const ll MOD = 1000000000000000009;
const ll mod = 1000000007;
// namespace Template
// {
bool isPrime(ll n)
{
	if (n <= 1)
		return 0;
	if (n <= 3)
		return 1;
	if (n % 2 == 0 || n % 3 == 0)
		return 0;
	for (ll i = 5; i * i <= n; i += 6)
	{
		if (n % i == 0 || n % (i + 2) == 0)
			return 0;
	}
	return 1;
}

vi eratosthenes(ll n)
{
	// int N = 1e6;
	vector<bool> snt(n, true);
	vi prime;
	snt[0] = false;
	snt[1] = false;
	for (int i = 2; i * i <= n; i++)
	{
		if (snt[i])
		{
			for (int j = i * i; j <= n; j += i)
				snt[j] = false;
		}
	}
	for (int i = 2; i <= n; i++)
	{
		if (snt[i] == true)
		{
			prime.push_back(i);
		}
	}
	return prime;
}

pair<ll, ll> factor(ll n)
{
	ll s = 0;
	while ((n & 1) == 0)
	{
		s++;
		n >>= 1;
	}
	return {s, n};
}
ll pow(ll a, ll d, ll n)
{
	ll r = 1;
	a = a % n;
	while (d > 0)
	{
		if (d & 1)
			r = (r * a) % n;
		d >>= 1;
		a = (a * a) % n;
	}
	return r;
}
bool test_a(ll s, ll d, ll n, ll a)
{
	if (n == a)
		return true;
	ll p = pow(a, d, n);
	if (p == 1)
		return true;
	for (; s > 0; s--)
	{
		if (p == n - 1)
			return true;
		p = p * p % n;
	}
	return false;
}
bool miller(ll n)
{
	if (n < 2)
		return false;
	if ((n & 1) == 0)
		return n == 2;
	ll s, d;
	tie(s, d) = factor(n - 1);

	if (n < 1373653)
	{
		return test_a(s, d, n, 2) && test_a(s, d, n, 3);
	}
	else if (n < 4759123141)
	{
		return test_a(s, d, n, 2) && test_a(s, d, n, 7) && test_a(s, d, n, 61);
	}
	else
	{
		return test_a(s, d, n, 2) && test_a(s, d, n, 3) && test_a(s, d, n, 5) && test_a(s, d, n, 7) && test_a(s, d, n, 11) && test_a(s, d, n, 13) && test_a(s, d, n, 17) && test_a(s, d, n, 19) && test_a(s, d, n, 23);
	}
}

ll reflective(ll l, ll r, ll s)
{
	long double i = 1;
	long long int ans = 0;
	long double LL = INT64_MIN;
	long double rr = INT64_MAX;
	while (r > i)
	{
		i *= s;
		LL = ceil(l / i);
		rr = floor(r / i);
		ans += rr - LL + 1;
	}
	return ans;
}

ll add_modulo(ll a, ll b, ll m) { return ((a + b) % m + m) % m; }
ll multiply_modulo(ll a, ll b, ll m)
{
	ll res = 0;
	for (a %= m, b %= m; b > 0; a = add_modulo(a, a, m), b >>= 1)
		if (b & 1)
			res = add_modulo(res, a, m);
	return res;
}
ll power_modulo(ll p, ll n, ll m)
{
	ll ans = 1LL;
	for (p %= m; n > 0; p = multiply_modulo(p, p, m), n >>= 1)
	{
		if (n & 1)
			ans = multiply_modulo(ans, p, m);
		// p = p*p % m;
	}
	return ans;
}

void least_prime_factor()
{
	int lpf[100001] = {0};
	lpf[1] = 1;
	for (int i = 2; i * i <= 100000; i++)
	{
		if (!lpf[i])
		{
			for (int j = i * i; j <= 100000; j += i)
				if (!lpf[j])
					lpf[j] = i;
		}
	}
	for (int i = 2; i <= 100000; i++)
	{
		if (!lpf[i])
			lpf[i] = i;
	}
}

ll phi_euler(ll n)
{
	ll res = n;
	for (ll i = 2; i * i <= n; ++i)
	{
		if (n % i == 0)
		{
			while (n % i == 0)
				n /= i;
			res -= res / i;
		}
	}
	if (n > 1)
		res -= res / n;
	return res;
}

template <template <typename...> class _Tr, typename... _Args>
std::ostream &operator<<(std::ostream &os, _Tr<_Args...> a)
{
	// os << "[";
	// auto s = a.begin();
	// auto e = a.end();
	// e--;
	// for (auto it = s; it != a.end(); it++)
	// {
	// 	cout << *it << (it == e ? "" : ", ");
	// }
	// os << "]";
	// return os;

	for (auto e : a)
	{
		os << e << " ";
	}
	// cout << endl;
	return os;
}
template <typename _Tp1, typename _Tp2>
std::ostream &operator<<(std::ostream &os, pair<_Tp1, _Tp2> a)
{
	os << a.first << " " << a.second << " ";
	// os << "[" << a.first << ", " << a.second << "]";
	return os;
}

template <typename _Tp>
std::istream &operator>>(std::istream &is, vector<_Tp> &a)
{
	for (_Tp &t : a)
	{
		is >> t;
	}
	return is;
}
template <typename _Tp1, typename _Tp2>
std::istream &operator>>(std::istream &is, pair<_Tp1, _Tp2> &a)
{
	is >> a.first >> a.second;
	return is;
}

template <typename _Tp>
_Tp mulmod(_Tp a, _Tp b, _Tp p)
{
	a %= p;
	b %= p;
	_Tp q = (_Tp)((long double)a * b / p);
	_Tp r = a * b - q * p;
	while (r < 0)
		r += p;
	while (r >= p)
		r -= p;
	return r;
}
template <typename _Tp>
_Tp powmod(_Tp n, _Tp k, _Tp p)
{
	_Tp r = 1;
	for (; k; k >>= 1)
	{
		if (k & 1)
			r = mulmod(r, n, p);
		n = mulmod(n, n, p);
	}
	return r;
}
template <typename _Tp>
int rabin(_Tp n)
{
	if (n == 2)
		return 1;
	if (n < 2 || !(n & 1))
		return 0;
	const _Tp p[9] = {2, 3, 5, 7, 11, 13, 17, 19, 23};
	_Tp a, d = n - 1, mx = 4;
	int i, r, s = 0;
	while (!(d & 1))
	{
		++s;
		d >>= 1;
	}
	for (i = 0; i < mx; i++)
	{
		if (n == p[i])
			return 1;
		if (!(n % p[i]))
			return 0;
		a = powmod(p[i], d, n);
		if (a != 1)
		{
			for (r = 0; r < s && a != n - 1; r++)
				a = mulmod(a, a, n);
			if (r == s)
				return 0;
		}
	}
	return 1;
}
template <typename _Tp>
inline _Tp f(_Tp a, _Tp b, _Tp n)
{
	return (mulmod(a, a, n) + b) % n;
}
template <typename _Tp>
void factorize(_Tp n, vector<_Tp> &facs)
{
	if (n == 1)
	{
		return;
	}
	if (rabin(n))
	{
		facs.push_back(n);
		return;
	}
	if (n == 4)
	{
		facs.push_back(2);
		facs.push_back(2);
		return;
	}
	while (1)
	{
		_Tp a = rand() & 63, x = 2, y = 2;
		while (1)
		{
			x = f(x, a, n), y = f(f(y, a, n), a, n);
			if (x == y)
				break;
			_Tp p = __gcd(n, y <= x ? x - y : y - x);
			if (p > 1)
			{
				factorize(p, facs), factorize(n / p, facs);
				return;
			}
		}
	}
}
template <typename _Tp>
vector<_Tp> get_divisor(_Tp n)
{
	vector<_Tp> arr;
	factorize(n, arr);
	map<_Tp, int> prime;
	for (_Tp i : arr)
		prime[i]++;
	vector<_Tp> res(1, 1);
	for (auto it : prime)
	{
		int k = res.size();
		_Tp val = 1;
		for (int i = 0; i < it.second; ++i)
		{
			val *= it.first;
			for (int j = 0; j < k; ++j)
			{
				res.push_back(res[j] * val);
			}
		}
	}
	return res;
}
// }

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// freopen("input.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);

	int n;
	cin >> n;
	vector<vector<int>> a(n, vector<int>(n - 1));
	int t = 2;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			a[i][j] = t++;
		}
	}
	cout << n * (n - 1) + 1 << endl;

	for (int i = 0; i < n; i++)
	{
		cout << 1 << " ";
		cout << a[i] << endl;
	}

	for (int i = 0; i < n - 1; i++)
	{

		for (int j = 0; j < n - 1; j++)
		{
			int d = j;
			cout << a[0][i] << " ";
			for (int k = 1; k < n; k++)
			{
				cout << a[k][d] << " ";
				d = (d + i) % (n - 1);
			}
			cout << endl;
		}
	}

	return 0;
}
