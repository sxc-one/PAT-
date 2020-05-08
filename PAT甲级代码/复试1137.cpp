#include<bits/stdc++.h>
using namespace std;
const int maxn=30100;
struct Stu{
	int id,gp=-1,gm=-1,gf=-1,g=-1;
}stu[maxn];
int p,m,n,id=0;
map<string,int>strtoint;
map<int,string>inttostr;
bool cmp(Stu a,Stu b){
	if(a.g!=b.g) return a.g>b.g;
	else return inttostr[a.id]<inttostr[b.id];
}
int getid(string str){
	if(strtoint.count(str)==0){
		strtoint[str]=id;
		inttostr[id]=str;
		return id++;
	}else return strtoint[str];
}
int main(){
	scanf("%d%d%d",&p,&m,&n);
	string str;
	int data;
	for(int i=0;i<p;i++){
		cin>>str>>data;
		int ID=getid(str);
		stu[ID].gp=data;
		stu[ID].id=ID;
	}
	for(int i=0;i<m;i++){
		cin>>str>>data;
		int ID=getid(str);
		stu[ID].gm=data;
		stu[ID].id=ID;
	}
	for(int i=0;i<n;i++){
		cin>>str>>data;
		int ID=getid(str);
		stu[ID].gf=data;
		stu[ID].id=ID;
	}
	for(int i=0;i<id;i++){
		int b=stu[i].gm*0.4+stu[i].gf*0.6+0.5;
		stu[i].g=max(stu[i].gf,b);
	}
	sort(stu,stu+id,cmp);
	for(int i=0;i<id;i++){
		if(stu[i].gp>=200&&stu[i].g>=60){
			cout<<inttostr[stu[i].id]<<" "<<stu[i].gp<<" "<<stu[i].gm<<" "<<stu[i].gf<<" "<<stu[i].g<<endl;
		}
}
	return 0;
}
