//structに変更したい

vector<vector<Pll>> G;
vector<bool> seen;
void dfs(ll v, ll dist, Pll& ans) {
	seen[v] = true;
	if (dist > ans.second) {
		ans = { v,dist };
	}
	for (auto a : G[v]) {
		if (seen[a.fi]) { continue; }
		dfs(a.fi, dist + a.second, ans);
	}
	return;
}

int main() {
	//cout << fixed << setprecision(10);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll N; cin >> N;
	G.resize(N);
	seen.resize(N, false);
	rep(i, N - 1) {
		ll a, b, c; cin >> a >> b >> c;
		a--; b--;
		G[a].pub({ b,c });
		G[b].pub({ a,c });
	}
	Pll ans = { 0,0 };
	dfs(0, 0, ans);
	ll u = ans.first;
	ans = { 0,0 };
	rep(i, 2 * N) {
		seen[i] = false;
	}
	dfs(u, 0, ans);
	cout << u << " " << ans.first << endl;//’[“_
	cout << ans.second << endl;//diamiter
}
