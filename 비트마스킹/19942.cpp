#include<bits/stdc++.h>
using namespace std;
const int INF=987654321;
int n,mp,mf,ms,mv,p,f,s,v,c,ret=INF;
struct A{
	int mp,mf,ms,mv,cost;
}a[16];
map<int, vector<vector<int>>>mp_ret;
int main(){
	cin>>n;
	cin>>mp>>mf>>ms>>mv;
	for(int i=0;i<n;i++){
		cin>>a[i].mp>>a[i].mf>>a[i].ms>>a[i].mv>>a[i].cost;
	}
	
	for(int i=0;i<(1<<n);i++){
		vector<int> vec;
		p=f=s=v=c=0;
		for(int j=0;j<n;j++){
			if(i&(1<<j)){
				vec.push_back(j+1);
				p+=a[j].mp;
				f+=a[j].mf;
				s+=a[j].ms;
				v+=a[j].mv;
				c+=a[j].cost;
			}
		}
		if(p>=mp&&f>=mf&&s>=ms&&v>=mv){
			if(ret>=c){
				ret=c;
				mp_ret[ret].push_back(vec);
			}
		}
	}
	if(ret==INF)cout<<-1;
	else{
		sort(mp_ret[ret].begin(),mp_ret[ret].end());
		cout<<ret<<"\n";
		for(int i:mp_ret[ret][0]){
			cout<< i <<" ";
		}
	}
	

	
}
