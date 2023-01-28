//木gを根rから遠ざかる辺のみからなる根付き木に変換したものを返す
//構成はBFS木

vector<vector<ll>> con(vector<vector<ll>> g, ll r = 0) {
    ll N = g.size();
    vector<vector<ll>> rg(N);
    vector<ll> v(N);
    v[r] = 1;
    queue<ll> que;
    que.emplace(r);
    while (!que.empty()) {
        auto p = que.front();
        que.pop();
        for (auto to : g[p]) {
            if (v[to] == 0) {
                v[to] = 1;
                que.emplace(to);
                rg[p].emplace_back(to);
                rg[to].emplace_back(p);
            }
        }
    }
    return rg;
}