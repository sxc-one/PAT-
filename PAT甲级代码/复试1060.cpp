#include<bits/stdc++.h>
using namespace std;
const int maxn=110;
int n;
string deal(string str,int &e){
	while(str[0]=='0'&&str.length()>0){
		str.erase(str.begin());
	}
	if(str[0]=='.'){
		str.erase(str.begin());
		while(str.length()>0&&str[0]=='0'){
			e--;
			str.erase(str.begin());
		}
	}else{
		for(int i=0;i<str.length();i++){
			if(str[i]!='.') e++;
			else{
				str.erase(str.begin()+i);
				break;
			}
		}
	}
	if(str.length()==0) e=0;
	while(str.length()<n){
		str+='0';
	}
	while(str.length()>n){
		str.erase(str.end()-1);
	}
	return str;
}
int main(){
	int e1=0,e2=0;
	string s1,s2,s3,s4;
	cin>>n>>s1>>s2;
	s3=deal(s1,e1);
	s4=deal(s2,e2);
	if(s3==s4&&e1==e2){
		cout<<"YES 0."<<s3<<"*10^"<<e1;
	}else{
		cout<<"NO 0."<<s3<<"*10^"<<e1<<" 0."<<s4<<"*10^"<<e2;
	}
	return 0;
}
