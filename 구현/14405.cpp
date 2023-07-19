#include<bits/stdc++.h>
using namespace std;
string s,s1,a[3]={"pi","ka","chu"};
int main(){
	cin>>s;
	while(s.substr(0,2)=="pi"||s.substr(0,2)=="ka"||s.substr(0,3)=="chu"){
		if((s.substr(0,2)=="pi")||s.substr(0,2)=="ka"){
			s.erase(0,2);
		}
		else if(s.substr(0,3)=="chu"){
			s.erase(0,3);
		}
	}
	if(s.size()==0){
		cout<<"YES";
	}else cout<<"NO";
}
