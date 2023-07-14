#include<bits/stdc++.h>
using namespace std;
int num,n,S;
string s;
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s;
		if(s=="add"){
			cin>>num;
			S|=(1<<(num-1));
		}
		if(s=="remove"){
			cin>>num;
			S&=~(1<<(num-1));
		}
		if(s=="check"){
			cin>>num;
			if(S&(1<<(num-1))){
				cout<<"1\n";
			}else{cout<<"0\n";}
			
		}
		if(s=="toggle"){
			cin>>num;
			S^=(1<<(num-1));
		}
		if(s=="all"){
			S=(1<<20)-1;
		}
		if(s=="empty"){
			S&=0;
		}
	}
}
