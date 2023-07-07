#include<bits/stdc++.h>
using namespace std;
int R,C,num,ret,dy[]={-1,0,1,0},dx[]={0,1,0,-1};
int visited[30];
char a[24][24];
string s;
void dfs(int y, int x, int cnt){
	ret=max(ret,cnt);
	for(int i=0;i<4;i++){
		int ny=y+dy[i];
		int nx=x+dx[i];
		int next=a[ny][nx]-'A';
		if(ny<0||nx<0||ny>=R||nx>=C)continue;
		if(!visited[next]){
			visited[next]=1;
			dfs(ny,nx,cnt+1);
			visited[next]=0;
		}
		
	}
	return;
}
int main(){
	cin>>R>>C;
	for(int i=0;i<R;i++){
		cin>>s;
		for(int j=0;j<C;j++){
			a[i][j]=s[j];
		}
	}
		
	num=a[0][0]-'A';
	visited[num]=1;
	dfs(0,0,1);
	
	
	cout<<ret;
}
