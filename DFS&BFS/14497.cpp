#include<bits/stdc++.h>
using namespace std;
#define y1 AAA
char a[304][304];
int visited[304][304];
int n,m,y,x,x1,y1,x2,y2,cnt;
int dy[]={-1,0,1,0};
int dx[]={0,1,0,-1};
string s;

int main(){
	cin>>n>>m;
	cin>>y1>>x1>>y2>>x2;
	y1--;y2--;x1--;x2--;
	for(int i=0;i<n;i++){
		cin>>s;
		for(int j=0;j<m;j++){
			a[i][j]=s[j];
		}
	}
	
	queue<pair<int,int>> q;
	visited[y1][x1]=1;
	q.push({y1,x1});
	while(a[y2][x2] != '0'){
		cnt++;
		queue<pair<int,int>> temp;
		while(q.size()){
			tie(y,x)=q.front(); q.pop();
			for(int i=0;i<4;i++){
				int ny=y+dy[i];
				int nx=x+dx[i];
				if(ny<0||nx<0||ny>=n||nx>=m||visited[ny][nx])continue;
				visited[ny][nx]=1;
				if(a[ny][nx]!='0'){
					a[ny][nx]='0';
					temp.push({ny,nx});
				}
				else q.push({ny,nx});
			}
		}
		q=temp;
	}
	
	
	cout<<cnt;
}
