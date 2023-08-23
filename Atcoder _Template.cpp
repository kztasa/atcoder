#include <bits/stdc++.h> 
#include <atcoder/all>

#define pub push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i, n) rep2(i, 0, n)
#define rep2(i, m, n) for (ll i = m; i < (n); i++)
#define per(i, b) per2(i, 0, b)
#define per2(i, a, b) for (ll i = int(b) - 1; i >= int(a); i--)
#define all(c) (c).begin(), (c).end()

using namespace std;
using namespace atcoder;

using ll = long long;
using dd = double;
using Pll = pair<ll, ll>;
using    vll = vector<   ll>;
using   vvll = vector<  vll>; 
using  vvvll = vector< vvll>; 
using vvvvll = vector<vvvll>;
using    vdd = vector<   dd>;
using   vvdd = vector<  vdd>;
using  vvvdd = vector< vvdd>;
using  vchar = vector< char>;
using vvchar = vector<vchar>;
using  vbool = vector< bool>;
using vvbool = vector<vbool>;

using    mint = modint998244353;
using   mint2 = modint1000000007;
using   vmint = vector<  mint>;
using  vvmint = vector< vmint>;
using  vmint2 = vector< mint2>; 
using vvmint2 = vector<vmint2>;

constexpr long long INF = (1LL << 60);
constexpr double EPS = 1e-9;
constexpr double PI = 3.141592653589;

//////////////////////////////////////////////////////////

template <typename T>
bool chmax(T& a, const T& b) {
	if (a < b) {
		a = b;  // aをbで更新
		return true;
	}
	return false;
}

template <typename T>
bool chmin(T& a, const T& b) {
	if (a > b) {
		a = b;  // aをbで更新
		return true;
	}
	return false;
}

ll rem(ll A, ll B) {
	ll t = A % B;
	if (t < 0) {
		t += B;
	}
	return t;
}

string zfill(int n, const int width)
{
	stringstream ss;
	ss << setw(width) << setfill('0') << n;
	return ss.str();
}

//1+2+3+…+N
ll cumlative_sum(ll N) {
	return (N * (N + 1)) / 2;
}

template<typename T>
void outvec(vector<T> A) {
	ll N = A.size();
	rep(i, N) { cout << A[i] << " "; }
	cout << endl;
	return;
}
template<typename T>
void outvec(vector<vector<T>> A) {
	ll N = A.size();
	rep(i, N) { outvec(A[i]); }
	return;
}

ll max(int x, ll y) { return max((ll)x, y); }
ll max(ll x, int y) { return max(x, (ll)y); }
int min(int x, ll y) { return min((ll)x, y); }
int min(ll x, int y) { return min(x, (ll)y); }

template<typename T = int>
map<T, ll> factorize(T n) {
	map<T, ll> factor_map;
	for (T i = 2; i * i <= n; i++) {
		while (!(n % i)) {
			factor_map[i]++; n /= i;
		}
	}
	if (n > 1) {
		factor_map[n]++;
	}
	return factor_map;
}

template<typename T = int>
vll divisor(T n) {
	vll ret;
	for (ll i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			ret.push_back(i);
			if (i * i != n) ret.push_back(n / i);
		}
	}
	sort(all(ret)); // 昇順に並べる
	return ret;
}

vvll div2(ll N) {
	vvll isprime(N + 1);
	for (ll p = 1; p <= N; ++p) {
		for (ll q = p; q <= N; q += p) {
			isprime[q].eb(p);
		}
	}
	return isprime;
}

template<typename T = int>
bool isp(T num) {
	if (num < 2) {
		return false;
	}
	else if (num == 2) {
		return true;
	}
	else if (num % 2 == 0) {
		return false;
	}
	dd sqrtNum = sqrt(num);
	for (int i = 3; i <= sqrtNum; i += 2) {
		if (num % i == 0) {
			return false;
		}
	}
	return true;
}

template<typename T = int>
vbool Era(ll N) {
	vbool isprime(N + 1, true);
	isprime[0] = isprime[1] = false;
	for (ll p = 2; p <= N; ++p) {
		if (!isprime[p]) continue;
		for (ll q = p * 2; q <= N; q += p) {
			isprime[q] = false;
		}
	}
	return isprime;
}

const int MAX = 510000;
const int MOD = 1020202009;
long long fac[MAX], finv[MAX], inv[MAX];

void COMinit() {
	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
	for (int i = 2; i < MAX; i++) {
		fac[i] = fac[i - 1] * i % MOD;
		inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
		finv[i] = finv[i - 1] * inv[i] % MOD;
	}
}

ll COM(ll n, ll k) {
	if (n < k) return 0;
	if (n < 0 || k < 0) return 0;
	return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

ll LIS(const vll& v) {
	vector<ll> dp;
	for (const auto& elem : v) {
		auto it = lower_bound(all(dp), elem);
		if (it == dp.end()) {
			dp.push_back(elem);
		}
		else {
			*it = elem;
		}
	}
	return dp.size();
}

vll Cumlative_Sum_of_Vector(vll A) {
	ll n = A.size();
	vll S(n + 1);
	S[0] = 0;
	rep(i, n) {
		S[i + 1] = S[i] + A[i];
	}
	return S;
}

bool Isin(ll a, ll b, ll H, ll W) {
	if (a >= 0 && a < H && b >= 0 && b < W) {
		return true;
	}
	else {
		return false;
	}
}

vll BFS(vvll G, ll start) {
	queue<ll> que;
	vll dist(G.size(), -1);
	dist[start] = 0;
	que.push(start);
	while (!que.empty()) {
		ll v = que.front();
		que.pop();
		for (auto nv : G[v]) {
			if (dist[nv] != -1) {
				continue;
			}
			dist[nv] = dist[v] + 1;
			que.push(nv);
		}
	}
	return dist;
}

vvll BFS2(vvll G) {
	vvll dist(G.size(), vll(G.size(), -1));
	rep(i, G.size()) {
		queue<ll> que;
		dist[i][i] = 0;
		que.push(i);
		while (!que.empty()) {
			ll v = que.front();
			que.pop();
			for (auto nv : G[v]) {
				if (dist[i][nv] != -1) {
					continue;
				}
				dist[i][nv] = dist[i][v] + 1;
				que.push(nv);
			}
		}
	}
	return dist;
}
/////////////////////////////////////////////////////

char SMALL(char a) {
	if (a - 'a' < 26 && a - 'a' >= 0) {
		return a;
	}
	else {
		return char(a + 32);
	}
}
char LARGE(char a) {
	if (a - 'A' < 26) {
		return a;
	}
	else {
		return char(a - 32);
	}
}

vll topological_sort(vvll G) {
	ll n = G.size();
	vll indeg(n);
	for (int i = 0; i < n; i++) {
		for (auto j : G[i]) {
			indeg[j]++;
		}
	}
	vll res;
	queue<ll> que;
	for (int i = 0; i < n; i++) {
		if (indeg[i] == 0) {
			que.push(i);
		}
	}
	while (!que.empty()) {
		ll v = que.front();
		que.pop();
		res.push_back(v);
		for (auto nv : G[v]) {
			indeg[nv]--;
			if (indeg[nv] == 0) {
				que.push(nv);
			}
		}
	}
	return res;
}

//N未満でNと互いに素な数の個数
vll totient(int n) {
	vbool prime(n + 1, true);
	vll ans(n + 1);
	for (int i = 2; i <= n; i++) {
		ans[i] = i;
	}
	if (n >= 0) prime[0] = false;
	if (n >= 1) prime[1] = false;
	for (int i = 2; i <= n; i++) {
		if (!prime[i]) {
			continue;
		}
		ans[i] *= i - 1;
		ans[i] /= i;
		for (int j = i + i; j <= n; j += i) {
			prime[j] = false;
			ans[j] *= i - 1;
			ans[j] /= i;
		}
	}
	return ans;
}

int main(void)
{
	//cout << fixed << setprecision(10);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	
}

