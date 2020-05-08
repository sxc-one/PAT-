#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=100010;
struct Stu{
	char name[10];
	int age,net;
}stu[maxn];
bool cmp(Stu a,Stu b){
	if(a.net!=b.net) return a.net>b.net;
	else if(a.age!=b.age) return a.age<b.age;
	else return strcmp(a.name,b.name)<0;
}
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++){
		scanf("%s %d %d",stu[i].name,&stu[i].age,&stu[i].net);
	}
	sort(stu,stu+n,cmp);
	for(int i=1;i<=k;i++){
		int m,min,max;
		scanf("%d%d%d",&m,&min,&max);
		printf("Case #%d:\n",i);
		int now=0,flag=0;
		for(int j=0;j<n;j++){
			if(stu[j].age>=min&&stu[j].age<=max){
			printf("%s %d %d\n",stu[j].name,stu[j].age,stu[j].net);
			now++;
			if(now==m) break;
			flag=1;
			}
		}
		if(flag==0) printf("None\n");
	}
	return 0;
}
