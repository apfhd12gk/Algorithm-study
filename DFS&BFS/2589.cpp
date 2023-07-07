#include<bits/stdc++.h>
using namespace std;
int a[54][54],visited[54][54],n,mx,m,cnt;
int dy[]={-1,0,1,0};
int dx[]={0,1,0,-1};
string s;
int bfs(int y,int x){
	
	visited[y][x]=1;
	queue<pair<int,int>> q;
	q.push({y,x});
	while(q.size()){
		tie(y,x)=q.front(); q.pop();
		for(int i=0;i<4;i++){
			int ny=y+dy[i];
			int nx=x+dx[i];
			if(ny<0||nx<0||ny>=n||nx>=m||a[ny][nx]==0)continue;
			if(visited[ny][nx])continue;
			visited[ny][nx]=visited[y][x]+1;
			q.push({ny,nx});
			
		}
		mx=max(mx,visited[y][x]);
	}
	
	return mx;
	
}
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>s;
		for(int j=0;j<m;j++){
			if(s[j]=='W'){
				a[i][j]=0;
			}
			else if(s[j]=='L'){
				a[i][j]=1;
			}
		}
	}
	
	for(int i=0;i<n;i++){
		
		for(int j=0;j<m;j++){
			
			if(a[i][j]==1){
				
				fill(&visited[0][0],&visited[0][0]+54*54,0);
//				cnt=max(cnt,bfs(i,j));
				bfs(i,j);
				
			}
		}
	}
	cout<<mx-1;
}
