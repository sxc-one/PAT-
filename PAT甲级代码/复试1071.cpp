#include<bits/stdc++.h>
using namespace std;
const int maxn=1100000;
map<string,int>num; 
int main(){
	string str;
	getline(cin,str);
	int i=0;
	while(i<str.length()){
		string word;
		while((str[i]>='0'&&str[i]<='9'||str[i]>='a'&&str[i]<='z'||str[i]>='A'&&str[i]<='Z')&&i<str.length()){
			if(str[i]>='A'&&str[i]<='Z'){
				str[i]+=32;
			}
			word+=str[i];
			i++;
		}
		if(word!=""){
			if(num.count(word)){
				num[word]++;
			}else num[word]=1;
		}
		while(!(str[i]>='0'&&str[i]<='9'||str[i]>='a'&&str[i]<='z'||str[i]>='A'&&str[i]<='Z')&&i<str.length()){
				i++;
			}
		}
	string ans;
	int max=0;
	for(auto it=num.begin();it!=num.end();it++){
		if(it->second>max){
			max=it->second;
			ans=it->first;
		}
	}
	cout<<ans<<" "<<max<<endl;
	return 0;
} 
