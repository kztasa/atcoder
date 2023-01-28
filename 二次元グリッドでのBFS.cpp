//二次元グリッドでのBFS
vector<ll> dx = { 1,0,-1,0 }, dy = { 0,1,0,-1 };
vector<ll> bfs(vector<string> s) {
    ll h = s.size(), w = s[0].size();
    vector<vector<ll>> G(h * w);
    rep(i, h) {
        rep(j, w) {
            if (s[i][j] == '#') {
                continue;
            }
            rep(k, 4) {
                if (i + dx[k] < 0 || i + dx[k] >= h || j + dy[k] < 0 || j + dy[k] >= w) {
                    continue;
                }
                if (s[i + dx[k]][j + dy[k]] != '#') {
                    G[i * w + j].pub((i + dx[k]) * w + j + dy[k]);
                }
            }
        }
    }
    vector<ll> dist(h * w, -1);
    queue<ll> que;
    dist[0] = 1;
    que.push(0);
    while (!que.empty()) {
        int v = que.front();
        que.pop();
        for (int nv : G[v]) {
            if (dist[nv] != -1) continue;
            dist[nv] = dist[v] + 1;
            que.push(nv);
        }
    }
    return dist;
}
