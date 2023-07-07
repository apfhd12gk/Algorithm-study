#include<bits/stdc++.h>
using namespace std;
int n,t,A,B,sumA,sumB;
#define prev aa
string s,prev;
string print(int a){
	string d = "00"+to_string(a/60);
	string e = "00"+to_string(a%60);
	return d.substr(d.size()-2,2)+":"+e.substr(e.size()-2,2);
}
int changeInt(string s){
	return atoi(s.substr(0,2).c_str())*60+atoi(s.substr(s.size()-2,2).c_str());
}
int go(string s){
	return changeInt(s)-changeInt(prev);
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>t>>s;
		
		if(A>B) sumA+=go(s);
		else if (B>A) sumB+=go(s);
		if(t==1) A++;
		if(t==2) B++;
		prev=s;
	}
	if(A>B) sumA+=go("48:00");
	else if(B>A) sumB+=go("48:00");
	cout<<print(sumA)<<"\n"<<print(sumB);
}
