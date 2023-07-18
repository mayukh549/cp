


void dfs(i,j,vll m){
	if(i<0 || j<0) continue;
	if(i>=n || j >=m) continue;
	dfs(i-1,j);
	dfs(i+1,j);
	dfs(i,j-1);
	dfs(i,j+1);

}