struct edge { ll to; ll cost; };
vll dijkstra(vector<vector<edge>> graph, ll n, ll start, int64_t INF) {
	priority_queue< Pll, vector<Pll>, greater<Pll> > que;
	vll dst(n, INF);
	dst[start] = 0;
	que.push({ 0, start });
	while (que.size()) {
		ll d = que.top().first;
		ll u = que.top().second;
		que.pop();
		if (dst[u] < d) continue;
		for (ll i = 0; i < graph[u].size(); ++i) {
			ll v = graph[u][i].to;
			ll cost = graph[u][i].cost;
			if (dst[v] > d + cost) {
				dst[v] = d + cost;
				que.push({ dst[v], v });
			}
		}
	}
	return dst;
}
