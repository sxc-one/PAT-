#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=30010;
struct Stu{
	char id[15];
	int location,local,grade;
}stu[maxn];
bool cmp(Stu a,Stu b){
	if(a.grade!=b.grade) return a.grade>b.grade;
	else return strcmp(a.id,b.id)<0;
}
int main(){
	int n,k,count=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&k);
		for(int j=0;j<k;j++){
			scanf("%s %d",stu[count].id,&stu[count].grade);
			stu[count].location=i;
			count++;
		}
		sort(stu+count-k,stu+count,cmp);
		stu[count-k].local=1;
		for(int j=1;j<k;j++){
			if(stu[j+count-k].grade==stu[j+count-k-1].grade) stu[j+count-k].local=stu[j+count-k-1].local;
			else stu[j+count-k].local=j+1;
		}
	}
	printf("%d\n",count);
	sort(stu,stu+count,cmp);
	int r=1;
	printf("%s %d %d %d\n",stu[0].id,r,stu[0].location,stu[0].local);
	for(int i=1;i<count;i++){
		if(stu[i].grade!=stu[i-1].grade) r=i+1;
		printf("%s %d %d %d\n",stu[i].id,r,stu[i].location,stu[i].local);
	}
	return 0;
}
