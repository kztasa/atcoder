// 素集合データ構造
struct UnionFind
{
  /* 略 */
};

// 頂点a, bをつなぐコストcostの（無向）辺
struct Edge
{
  int a, b, cost;

  // コストの大小で順序定義
  bool operator<(const Edge& o) const {
    return cost < o.cost;
  }
};

// 頂点数と辺集合の組として定義したグラフ
struct Graph
{
  int n;  // 頂点数
  vector<Edge> es;  // 辺集合

  // クラスカル法で無向最小全域木のコストの和を計算する
  // グラフが非連結のときは最小全域森のコストの和となる
  ll kruskal() {
    // コストが小さい順にソート
    sort(es.begin(), es.end());

    UnionFind uf(n);
    int min_cost = 0;

    rep(ei, es.size()) {
      Edge& e = es[ei];
      if (!uf.same(e.a, e.b)) {
        // 辺を追加しても閉路ができないなら、その辺を採用する
        min_cost += e.cost;
        uf.unite(e.a, e.b);
      }
    }

    return min_cost;
  }
};

// 標準入力からグラフを読み込む
Graph input_graph() {
  Graph g;
  int m;
  cin >> g.n >> m;
  rep(i, m) {
    Edge e;
    cin >> e.a >> e.b >> e.cost;
    g.es.push_back(e);
  }
  return g;
}


int main()
{
  Graph g = input_graph();
  cout << "最小全域木のコスト: " << g.kruskal() << endl;
  return 0;
}