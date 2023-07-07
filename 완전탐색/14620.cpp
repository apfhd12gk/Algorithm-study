#include<bits/stdc++.h>
using namespace std; 
const int INF = 987654321;
int n,a[20][20],visited[20][20],ret=INF;
int dy[]={-1,0,1,0};
int dx[]={0,1,0,-1};

bool check(int y,int x){
	if(visited[y][x]) return false;
	for(int i=0;i<4;i++){
		int ny=y+dy[i];
		int nx=x+dx[i];
		if(ny<0||nx<0||ny>=n||nx>=n||visited[ny][nx]){
			return false;
		}
	}
	return true;
}
int setflower(int y,int x){
	visited[y][x]=1;
	int money=a[y][x];
	for(int i=0;i<4;i++){
		int ny=y+dy[i];
		int nx=x+dx[i];
		visited[ny][nx]=1;
		money+=a[ny][nx];
	}
	return money;
}
void eraseflower(int y, int x){
	visited[y][x]=0;
	for(int i=0;i<4;i++){
		int ny=y+dy[i];
		int nx=x+dx[i];
		visited[ny][nx]=0;
	}
	return;
}
void go(int cnt, int hap){
	if(cnt==3){
		ret=min(ret,hap);
		return;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(check(i,j)){
				go(cnt+1,hap+setflower(i,j));
				eraseflower(i,j);
			}
		}
	}
	return;
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>a[i][j];
		}
	}
	
	go(0,0);
	cout<<ret;
	
}
