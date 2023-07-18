

vector<ll>g[N];
depth[N];
height[N];
void dfs(int vertex , int p =0){
	for(int child : g[vertex]){
		if(child == p) continue;
		depth[child]=depth[vertex]+1;
		dfs(child,vertex);
		height[vertex]=max(height[vertex],height[child]+1);
	}
}