#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct Stu{
	int ge,gi,sum,id,r;
	int cho[6];
}stu[40010];
struct Sch{
	int quo,num,last;
	int stuid[40010];
}sch[105];
bool cmp(Stu a,Stu b){
	if(a.sum!=b.sum) return a.sum>b.sum;
	return a.ge>b.ge;
}
bool cmpid(int a,int b){
	return stu[a].id<stu[b].id;
}
int main(){
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<m;i++){
		scanf("%d",&sch[i].quo);
		sch[i].num=0;
		sch[i].last=-1;
	}
	for(int i=0;i<n;i++){
		stu[i].id=i;
		scanf("%d%d",&stu[i].ge,&stu[i].gi);
		stu[i].sum=stu[i].ge+stu[i].gi;
		for(int j=0;j<k;j++){
			scanf("%d",&stu[i].cho[j]);
		}
	}
	sort(stu,stu+n,cmp);
	for(int i=0;i<n;i++){
		if(i>0&&stu[i].sum==stu[i-1].sum&&stu[i].ge==stu[i-1].ge){
			stu[i].r=stu[i-1].r;
		}else stu[i].r=i;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<k;j++){
			int choice=stu[i].cho[j];
			int num=sch[choice].num;
			int last=sch[choice].last;
			if(num<sch[choice].quo||(last!=-1&&stu[i].r==stu[last].r)){
			   sch[choice].stuid[num]=i;
			   sch[choice].last=i;
			   sch[choice].num++;
			   break;	                         
			}
		}
	}
	for(int i=0;i<m;i++){
		if(sch[i].num>0){
			sort(sch[i].stuid,sch[i].stuid+sch[i].num,cmpid);
			for(int j=0;j<sch[i].num;j++){
				printf("%d",stu[sch[i].stuid[j]].id);
				if(j<sch[i].num-1){
					printf(" ");
				}
			}
		}
		printf("\n");
	}
	return 0;
}
