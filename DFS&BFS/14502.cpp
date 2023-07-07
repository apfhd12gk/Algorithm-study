#include<bits/stdc++.h>
using namespace std;
int dy[]={-1,0,1,0};
int dx[]={0,1,0,-1};
int n,m,a[80][80],visited[80][80];
int ret=-987654321;
vector<pair<int,int>> wallList,virusList;
void dfs(int y, int x){
	for(int i=0;i<4;i++){
		int ny=y+dy[i];
		int nx=x+dx[i];
		if(ny<0||nx<0||ny>=n||nx>=m)continue;
		if(!visited[ny][nx]&&a[ny][nx]==0){
			visited[ny][nx]=1;
			dfs(ny,nx);
		}
	}
} 

int solve(){
	fill(&visited[0][0],&visited[0][0]+80*80,0);
	for(pair<int,int> p : virusList){
		visited[p.first][p.second]=1;
		dfs(p.first,p.second);
	}
	
	int cnt=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(a[i][j]==0&&visited[i][j]==0) cnt++;
		}
	}
	return cnt;
}

int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>a[i][j];
			if(a[i][j]==0)wallList.push_back({i,j});
			if(a[i][j]==2)virusList.push_back({i,j});
		}
	}
	
	for(int i=0;i<wallList.size();i++){
		for(int j=0;j<i;j++){
			for(int k=0;k<j;k++){
				a[wallList[i].first][wallList[i].second]=1;
				a[wallList[j].first][wallList[j].second]=1;
				a[wallList[k].first][wallList[k].second]=1;
				ret=max(ret,solve());
				a[wallList[i].first][wallList[i].second]=0;
				a[wallList[j].first][wallList[j].second]=0;
				a[wallList[k].first][wallList[k].second]=0;
			}
		}
	}
	cout<<ret;
}
