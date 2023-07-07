#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> v;
map<int,int> mp,mp_first;
int n,c,num;;
bool cmp(pair<int,int> a, pair<int,int> b){
	if(a.first==b.first){
		return mp_first[a.second]>mp_first[b.second];
	}
	
	return a.first>b.first;
}
int main(){
	cin>>n>>c;
	for(int i=0;i<n;i++){
		cin>>num;
		mp[num]++;
		if(mp_first[num]==0) mp_first[num]=i;
	}
	for(auto it : mp){
		v.push_back({it.second,it.first});
	}
	sort(v.begin(),v.end(),cmp);
	for(auto i:v){
		for(int j=0;j<i.first;j++){
			cout<<i.second<<" ";
		}
	}
}
