vector<ll>g[N];
bool vis[N];


valid dfs(int vertex){
	// take action on vertex after entering the vertex
	vis[vertex]=true;
	for(int child : g[vertex]){
		if(vis[child]) continue;
		//take action on child before entering the child node
		dfs(child);
		//take action on child after exiting the child

	}
	//take action on the vertex before exiting the vertex
}
// O(V+E)