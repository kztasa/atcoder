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
using ll = long long; using dd = double;
using Pll = pair<ll, ll>;
using    vll = vector<   ll>; using   vdd = vector< dd>;
using   vvll = vector<  vll>; using  vvdd = vector<vdd>;
using  vvvll = vector< vvll>; using vvvdd = vector<vvdd>;
using vvvvll = vector<vvvll>;
using  vchar = vector< char>;
using vvchar = vector<vchar>;
using mint = modint998244353;
using mint2 = modint1000000007;
using  vmint = vector< mint>; using  vmint2 = vector< mint2>;
using vvmint = vector<vmint>; using vvmint2 = vector<vmint2>;

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
	ll t = A % B; if (t < 0) { t += B; } return t;
}

string zfill(int n, const int width)
{
	stringstream ss;
	ss << setw(width) << setfill('0') << n;
	return ss.str();
}

//1+2+3+…+N
ll OnetoN_sum(ll N) {
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
std::map<T, ll> factorize(T n) {
	std::map<T, ll> factor_map;
	for (T i = 2; i * i <= n; i++) {
		while (!(n % i)) {
			factor_map[i]++; n /= i;
		}
	}
	if (n > 1) factor_map[n]++;
	return factor_map;
}

template<typename T = int>
vector<long long> divisor(T n) {
	vector<long long> ret;
	for (long long i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			ret.push_back(i);
			if (i * i != n) ret.push_back(n / i);
		}
	}
	sort(ret.begin(), ret.end()); // 昇順に並べる
	return ret;
}

template<typename T = int>
bool isp(T num) {
	if (num < 2) return false;
	else if (num == 2) return true;
	else if (num % 2 == 0) return false;
	double sqrtNum = sqrt(num);
	for (int i = 3; i <= sqrtNum; i += 2) {
		if (num % i == 0) {
			return false;
		}
	}
	return true;
}

template<typename T = int>
vector<bool> Era(ll N) {
	vector<bool> isprime(N + 1, true);
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
const int MOD = 998244353;
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

long long COM(int n, int k) {
	if (n < k) return 0;
	if (n < 0 || k < 0) return 0;
	return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

ll LIS(const std::vector<ll>& v) {
	std::vector<ll> dp;
	for (const auto& elem : v) {
		auto it = std::lower_bound(dp.begin(), dp.end(), elem);
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

vvll B = {
	{1,2,3,4,5},
	{2,3,4,5,6},
	{3,4,5,6,7},
	{4,5,6,7,8},
	{5,6,7,8,9},
	{6,7,8,9,10},
	{7,8,9,10,11},
	{8,9,10,11,12},
	{9,10,11,12,13},
	{1,10,11,12,13},
	{1,2,11,12,13},
	{1,2,3,12,13},
	{1,2,3,4,13}
};
bool IsRoyal(vector<pair<ll, char>> P) {
	vll a = { 1,10,11,12,13 };
	rep(i, 5) {
		if (P[i].first != a[i]) {
			return false;
		}
	}
	rep(i, 4) {
		if (P[i].second != P[i + 1].second) {
			return false;
		}
	}
	return true;
}
bool IsStraightFlush(vector<pair<ll, char>> P) {
	rep(i, B.size()) {
		bool ok = true;
		rep(j, 5) {
			if (B[i][j] != P[j].first) {
				ok = false;
			}
		}
		rep(j, 4) {
			if (P[j].second != P[j + 1].second) {
				ok = false;
			}
		}
		if (ok) {
			return true;
		}
	}
	return false;
}
bool IsFour(vector<pair<ll, char>> P) {
	vll cnt(13);
	rep(i, 5) {
		cnt[P[i].first - 1]++;
		if (cnt[P[i].first - 1] == 4) {
			return true;
		}
	}
	return false;
}
bool IsFullHouse(vector<pair<ll, char>> P) {
	if (P[0].fi == P[1].first && P[1].first == P[2].first && P[3].first == P[4].fi) {
		return true;
	}
	if (P[0].fi == P[1].first && P[2].first == P[3].first && P[3].first == P[4].fi) {
		return true;
	}
	return false;
}
bool IsFlush(vector<pair<ll, char>> P) {
	rep(i, 4) {
		if (P[i].second != P[i + 1].second) {
			return false;
		}
	}
	return true;
}
bool IsStraight(vector<pair<ll, char>> P) {
	rep(i, B.size()) {
		bool ok = true;
		rep(j, 5) {
			if (B[i][j] != P[j].first) {
				ok = false;
			}
		}
		if (ok) {
			return true;
		}
	}
	return false;

}
bool IsThree(vector<pair<ll, char>> P) {
	vll cnt(13);
	rep(i, 5) {
		cnt[P[i].first - 1]++;
		if (cnt[P[i].first - 1] == 3) {
			return true;
		}
	}
	return false;
}
bool IsTwopair(vector<pair<ll, char>> P) {
	if (P[0].fi == P[1].first && P[3].first == P[4].fi) {
		return true;
	}
	if (P[0].fi == P[1].first && P[2].first == P[3].first) {
		return true;
	}
	if (P[1].first == P[2].first && P[3].first == P[4].fi) {
		return true;
	}
	return false;
}
bool IsOnepair(vector<pair<ll, char>> P) {
	rep(i, 4) {
		if (P[i].first == P[i + 1].fi) {
			return true;
		}
	}
	return false;
}

int main() {
	cout << fixed << setprecision(10);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	rep(Z, 1000) {
		//input
		vector<pair<ll, char>> P1, P2;
		rep(i, 5) {
			string s; cin >> s;
			pair<ll, char> a;
			a.second = s[1];
			if (s[0] == 'T') {
				a.first = 10;
			}
			else if (s[0] == 'J') {
				a.first = 11;
			}
			else if (s[0] == 'Q') {
				a.first = 12;
			}
			else if (s[0] == 'K') {
				a.first = 13;
			}
			else if (s[0] == 'A') {
				a.first = 1;
			}
			else {
				a.first = s[0] - '0';
			}
			P1.pub(a);
		}
		rep(i, 5) {
			string s; cin >> s;
			pair<ll, char> a;
			a.second = s[1];
			if (s[0] == 'T') {
				a.first = 10;
			}
			else if (s[0] == 'J') {
				a.first = 11;
			}
			else if (s[0] == 'Q') {
				a.first = 12;
			}
			else if (s[0] == 'K') {
				a.first = 13;
			}
			else if (s[0] == 'A') {
				a.first = 1;
			}
			else {
				a.first = s[0] - '0';
			}
			P2.pub(a);
		}
		sort(all(P1));
		sort(all(P2));
		//役判定
		Pll yaku = { 1,1 };
		if (IsRoyal(P1)) { chmax(yaku.first, 10ll); }
		if (IsStraightFlush(P1)) { chmax(yaku.first, 9ll); }
		if (IsFour(P1)) { chmax( yaku.first,8ll ); }
		if (IsFullHouse(P1)) { chmax(yaku.first, 7ll); }
		if (IsFlush(P1)) { chmax(yaku.first, 6ll); }
		if (IsStraight(P1)) { chmax(yaku.first, 5ll); }
		if (IsThree(P1)) { chmax(yaku.first, 4ll); }
		if (IsTwopair(P1)) { chmax(yaku.first, 3ll); }
		if (IsOnepair(P1)) { chmax(yaku.first, 2ll); }

		if (IsRoyal(P2)) { chmax(yaku.second, 10ll); }
		if (IsStraightFlush(P2)) { chmax(yaku.second, 9ll); }
		if (IsFour(P2)) { chmax(yaku.second, 8ll); }
		if (IsFullHouse(P2)) { chmax(yaku.second, 7ll); }
		if (IsFlush(P2)) { chmax(yaku.second, 6ll); }
		if (IsStraight(P2)) { chmax(yaku.second, 5ll); }
		if (IsThree(P2)) { chmax(yaku.second, 4ll); }
		if (IsTwopair(P2)) { chmax(yaku.second, 3ll); }
		if (IsOnepair(P2)) { chmax(yaku.second, 2ll); }

		//勝敗判定
	}
}
