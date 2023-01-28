vector<ll> seen;
vector<vector<ll>> G;
vector<ll> depth;//dfs木における深さ
vector<ll> par;//dfs木の親

void dfs(int v) {
    seen[v] = true;
    for (auto nv : G[v]) {
        if (seen[nv]) {
            continue;
        }
        par[nv] = v;
        depth[nv] = depth[v] + 1;
        dfs(nv); // d を 1 増やして子ノードへ
    }
    return;
}


//N頂点M辺のグラフからDFS木を構成する(例の根は1)
int main() {
    ll N, M; cin >> N >> M;
    G.resize(N);
    depth.resize(N);
    par.resize(N);
    rep(i, M) {
        ll u, v; cin >> u >> v;
        //デクリメントする
        u--; v--;
        G[u].pub(v);
        G[v].pub(u);
    }
    seen.resize(N,false);
    
    
    depth[0] = 0;
    dfs(0);
    
    //深さ
    rep(i, N) {
        cout << depth[i]+1 << " ";
    }
    cout << endl;

    //親
    rep(i, N) {
        cout << par[i]+1 << " ";
    }
    cout << endl;

}