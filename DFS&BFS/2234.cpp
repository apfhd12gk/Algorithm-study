#include<bits/stdc++.h>
using namespace std;
int dy[]={0,-1,0,1};
int dx[]={-1,0,1,0};
int n,m,a[54][54],visited[54][54],sizeR[3504];
int ret1,ret2,ret3,cnt;
void dfs(int y, int x){
	visited[y][x]=ret1;
	for(int i=0;i<4;i++){
		int ny=y+dy[i];
		int nx=x+dx[i];
		if(ny<0||nx<0||ny>=n||nx>=m)continue;
		if(a[y][x]&(1<<i))continue;
		if(!visited[ny][nx]){
			cnt++;
			dfs(ny,nx);
		}
	}
	return;
}
int main(){
	cin>>m>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>a[i][j];
		}
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(!visited[i][j]){
				ret1++;
				cnt=1;
				dfs(i,j);
				sizeR[ret1]=cnt;
				ret2=max(ret2,cnt);
			}
		}
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
		
			if(i+1<n){
				int a=visited[i][j];
				int b=visited[i+1][j];
				if(a!=b){
					ret3=max(ret3,sizeR[a]+sizeR[b]);
				}
			}
			if(j+1<m){
				int a=visited[i][j];
				int b=visited[i][j+1];
				if(a!=b){
					ret3=max(ret3,sizeR[a]+sizeR[b]);
				}
			}
		}
	}
	
	
	cout<<ret1<<"\n"<<ret2<<"\n"<<ret3;
}
