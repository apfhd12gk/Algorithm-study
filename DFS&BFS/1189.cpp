#include<bits/stdc++.h>
using namespace std;
int visited[7][7],R,C,K,ret;
int dy[]={-1,0,1,0};
int dx[]={0,1,0,-1};
string s;
char a[7][7];
void go(int y,int x,int cnt){
	if(cnt==K&&y==0&&x==C-1){
		ret++;
		return;
	}
	for(int i=0;i<4;i++){
		int ny=y+dy[i];
		int nx=x+dx[i];
		if(ny<0||nx<0||ny>=R||nx>=C||visited[ny][nx])continue;
		if(a[ny][nx]=='.'){
			visited[ny][nx]=1;
			go(ny,nx,cnt+1);
			visited[ny][nx]=0;
		}
	}
	return;
}
int main(){
	cin>>R>>C>>K;
	for(int i=0;i<R;i++){
		cin>>s;
		for(int j=0;j<C;j++){
			a[i][j]=s[j];
			if(a[i][j]=='T'){
				visited[i][j]=1;
			}
		}
	}
	visited[R-1][0]=1;
	go(R-1,0,1);
	cout<<ret;
}
