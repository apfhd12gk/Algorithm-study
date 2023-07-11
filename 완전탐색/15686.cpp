#include<bits/stdc++.h>
using namespace std;
int n,m,a[54][54],visited[54][54],result=987654321;
vector<vector<int>> seq;
vector<pair<int,int>> chickenList,cityList;
void combi(int start, vector<int> v){
	if(v.size()==m){
		seq.push_back(v);
		return;
	}
	for(int i=start;i<chickenList.size();i++){
		v.push_back(i);
		combi(i+1,v);
		v.pop_back();
	}
	return;
}
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>a[i][j];
			if(a[i][j]==1) cityList.push_back({i,j});
			if(a[i][j]==2) chickenList.push_back({i,j});
		}
	}
	vector<int> v;
	combi(0,v);
	for(vector<int> cList : seq){
		int ret=0;
		for(pair<int,int> _city:cityList){
			int _min=987654321;
			for(int ch : cList){
				int _dist=abs(_city.first-chickenList[ch].first)+abs(_city.second-chickenList[ch].second);
				_min=min(_min,_dist);
			}
			ret+=_min;
			
			
		}
		result=min(result,ret);
	}
	cout<<result;
}
