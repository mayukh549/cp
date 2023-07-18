

ll even_ct[N];
vll g[N];
ll subtree_sum[N];
void dfs(int vertex ,int p=0){
	if(vertex%2==0){
		even_ct[vertex]++;
	}
	subtree_sum[vertex]++;
	for(int child : g[vertex]){
		if(child==par){
			continue;
		}
		dfs(child,vertex);
		subtree_sum[vertex]+=subtree_sum[child];
		even_ct[vertex]+=even_ct[child];

	}
}