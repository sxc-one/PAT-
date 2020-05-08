#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=100010;
struct Stu{
	int id,grade;
	char name[10];
}stu[maxn];
bool cmp1(Stu a,Stu b){
	return a.id<b.id;
}
bool cmp2(Stu a,Stu b){
	if(strcmp(a.name,b.name)!=0) return strcmp(a.name,b.name)<0;
	else return a.id<b.id;
}
bool cmp3(Stu a,Stu b){
	if(a.grade!=b.grade) return a.grade<b.grade;
	else return a.id<b.id;
}
int main(){
	int n,c;
	scanf("%d%d",&n,&c);
	for(int i=0;i<n;i++){
		scanf("%d %s %d",&stu[i].id,stu[i].name,&stu[i].grade);
	}
	if(c==1) sort(stu,stu+n,cmp1);
	else if(c==2) sort(stu,stu+n,cmp2);
	else sort(stu,stu+n,cmp3);
	for(int i=0;i<n;i++){
		printf("%06d %s %d\n",stu[i].id,stu[i].name,stu[i].grade);
	}
	return 0;
}
