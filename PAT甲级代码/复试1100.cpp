#include<bits/stdc++.h>
using namespace std;
string gewei[13]={"tret","jan","feb","mar","apr","may","jun","jly","aug","sep","oct","nov","dec"};
string shiwei[13]={"tret","tam","hel","maa","huh","tou","kes","hei","elo","syy","lok","mer","jou"};
string numtostr[170];
map<string,int>strtonum;
void init(){
	for(int i=0;i<13;i++){
		numtostr[i]=gewei[i];
		strtonum[gewei[i]]=i;
		numtostr[i*13]=shiwei[i];
		strtonum[shiwei[i]]=i*13;
	}
	for(int i=1;i<13;i++){
		for(int j=1;j<13;j++){
			numtostr[i*13+j]=shiwei[i]+" "+gewei[j];
			strtonum[shiwei[i]+" "+gewei[j]]=i*13+j;
		}
	}
}
int main(){
	init();
	int n;
	scanf("%d",&n);
	getchar();
	for(int i=0;i<n;i++){
		string str;
		getline(cin,str);
		if(str[0]>='0'&&str[0]<='9'){
			int num=0;
			for(int j=0;j<str.length();j++){
				num=num*10+str[j]-'0';
			}
			cout<<numtostr[num]<<endl;
		}else{
			cout<<strtonum[str]<<endl;
		}
	}
	return 0;
}
