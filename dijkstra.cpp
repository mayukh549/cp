void dijkstra(ll source){
	vll vis(N,0);
	vll dist(N,INF);
	set<pair<ll,ll>>st;
	st.insert({0,source});
	dist[source]=0;
	while(st.size()>0){
		auto node = *(st.begin());
		int v = node.S;
		int dist = node.F;
		if(vis[v]) continue;
		vis[v]=1;
		for(auto child : g[v]){
			ll child_v=child.F;
			ll wt = child.S;
			if(dist[v]+wt<dist[child_v]){
				dist[child_v]=dist[v]+wt;
				st.insert({dist[child_v],child_v});
			}

		}
	}
}
//vector<pair<ll,ll>>g[N];
//g[v[0]].pb({v[1],v[0]});