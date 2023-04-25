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

//全点対距離(N^2)
vvll BFS2(vvll G) {
	vvll dist(G.size(), vll(G.size(),-1));
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
