void reset(){
	fr(i,n,0){
		fr(j,m,0){
			vis[i][j]=0;
			lev[i][j]=INF;
		}

	}
}
ll val[N][N];
ll vis[N][N];
ll lev[N][N];
ll n,m;
ll bfs(){
	ll mx =0;
	fr(i,n,0){
		fr(j,m,0){
			mx = max(mx,val[i][j]);
		}

	}
	queue<pair<ll,ll>>q;
	fr(i,n,0){
		fr(j,m,0){
			if(mx = val[i][j]){
				q.push({i,j});
				lev[i][j]=0;
				vis[i][j]=1;
			}
		}
	}
	ll ans =0;
	while(!q.empty){
		auto v = q.front();
		ll  v_x = v.first;
		ll v_y = v.second;
		q.pop();
		for(auto movement : movements){
			ll child_x = movement.first+v_x;
			ll child_y = movement.S +v_y;
			if(!isvalid(child_x,child_y)) continue;
			if(vis[child_x][child_y]) continue;
			q.push({child_x,child_y});
			lev[child_x][child_y]=lev[v_x][v_y]+1;
			vis[child_x][child_y]=1;
			ans = max(ans,level[child_x][child_y]);

		}
	}
	return ans;
	
}