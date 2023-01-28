vector<ll> seen;
vector<vector<ll>> G;
vector<ll> depth;//dfs木における深さ
vector<ll> par;//dfs木の親

vector<ll> subtree_size;//部分木サイズ

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

    // 帰りがけ時に、部分木サイズを求める
    subtree_size[v] = 1; // 自分自身
    for (auto c : G[v]) {
        if (c == par[v]) continue;
        subtree_size[v] += subtree_size[c]; // 子のサイズを加える
    }
    return;
}


//部分木のサイズを求める(例の根は1)
int main() {
    ll N;  cin >> N;
    G.resize(N);
    depth.resize(N);
    par.resize(N);
    subtree_size.resize(N);
    rep(i, N-1) {
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

    //部分木サイズ
    rep(i, N) {
        cout << subtree_size[i] << " ";
    }
    cout << endl;

}