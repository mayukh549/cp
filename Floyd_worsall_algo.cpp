// impt concept k-1 are calculated and we have to include kth node

int Dist[N][N]
void floyd_worsall(){
	fr(i,N,0){
		fr(j,n,0){
			if(i==j)dist[i][j]=0;
			else dist[i][j]==INF;
		}
	}
	int n,m;
	cin>>n>>m;
	fr(i,m,0){
		int x,y,wt;
		cin>>x>>y>>wt;
		dist[x][y]=wt;
	}
	// vll del_order(n);
	// fr(i,n,0){
	// 	cin>>del_order[i];
	// }
	// reverse(del_order.begin(),del_order.end())
	fr(k1,n,0){
		//int k = del_order[k1]
		fr(i,n+1,1){
			fr(j,n+1,1){
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);

			}
		}
	}
	fr(i,n+1,1){
		fr(j,n+1,1){
			if(dist[i][j]==INF){
				// no path exists
				cout<<100000<<" ";
				continue;
			}
			cout<<dist[i][j]<<" ";	
		}
		cout<<endl;
	}

}

//-ve weight can be ahndled by it 
// -ve weighted cycles are not handled(as you will go on spinning on that cycles)
// O(n^3) n ==vertices
