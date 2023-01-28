/// オイラーツアー（自分で作ったやつ　order[i]：iを何番目に通過したか)
vector<ll> ET(vector<vector<ll>> G, ll root) {
    int n = G.size();
    vector<ll> order(n);
    int cur = 0;
    function<void(int, int)> dfs = [&](int v, int p) {
        order[v] = cur;
        cur++;
        for (auto nv : G[v]) {
            if (nv == p) continue;
            dfs(nv, v);
        }
    };
    dfs(root, -1);
    return order;
}


/// オイラーツアー
vector<vector<ll>> G;
vector<ll> order;　//orderに行きがけ順に頂点を入れていく　上のやつとは対になる存在
vector<ll> par;

void dfs(ll crr, ll pre) {
    order.push_back(crr);
    for (int nxt : G[crr])if (nxt != pre) {
        par[nxt] = crr;
        dfs(nxt, crr);
    }
}