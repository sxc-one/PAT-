#include<bits/stdc++.h>
using namespace std;
map<string,set<int> >title,author,keyword,publish,year;
void query(map<string,set<int> >& mp,string& str){
	if(mp.count(str)==0) printf("Not Found\n");
	else{
		for(auto it=mp[str].begin();it!=mp[str].end();it++){
			printf("%07d\n",*it);
		}
	}
}
int main(){
	int n,m;
	scanf("%d",&n);
	string str;
	for(int i=0;i<n;i++){
		int id;
		scanf("%d",&id);
		getchar();
		
		getline(cin,str);
		title[str].insert(id);
		getline(cin,str);
		author[str].insert(id);
		while(cin>>str){
			keyword[str].insert(id);
			char c=getchar();
			if(c=='\n') break;
		}
		getline(cin,str);
		publish[str].insert(id);
		getline(cin,str);
		year[str].insert(id);
	}
	scanf("%d",&m);
	for(int i=0;i<m;i++){
		int type;
		scanf("%d: ",&type);
		getline(cin,str);
		cout<<type<<": "<<str<<endl;
		if(type==1) query(title,str);
		else if(type==2) query(author,str);
		else if(type==3) query(keyword,str);
		else if(type==4) query(publish,str);
		else query(year,str);
	}
	return 0;
}
