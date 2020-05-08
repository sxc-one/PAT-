#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=10010;
struct Stu{
	int id,all,solve;
	int score[6];
	bool flag;
}stu[maxn];
bool cmp(Stu a,Stu b){
	if(a.flag!=b.flag) return a.flag>b.flag;
	else if(a.all!=b.all) return a.all>b.all;
	else if(a.solve!=b.solve) return a.solve>b.solve;
	else return a.id<b.id;
}
int full[6];
int n,k,m;
void init(){
	for(int i=1;i<=n;i++){
		stu[i].id=i;
		stu[i].solve=0;
		stu[i].all=0;
		stu[i].flag=false;
		memset(stu[i].score,-1,sizeof(stu[i].score));
	}
}
int main(){
	
	scanf("%d%d%d",&n,&k,&m);
	init();
	for(int i=1;i<=k;i++){
		scanf("%d",&full[i]);
	}
	int uid,pid,par;
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&uid,&pid,&par);
		if(par!=-1) stu[uid].flag=true;
		if(par==-1&&stu[uid].score[pid]==-1) stu[uid].score[pid]=0;
		if(par>stu[uid].score[pid]) {
			stu[uid].score[pid]=par;
			if(par==full[pid]) stu[uid].solve++;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k;j++){
			if(stu[i].score[j]!=-1) stu[i].all+=stu[i].score[j];
		}
	}
	sort(stu+1,stu+1+n,cmp);
	int r=1;
	for(int i=1;i<=n&&stu[i].flag==true;i++){
		if(i>1&&stu[i-1].all!=stu[i].all) r=i;
		printf("%d %05d %d",r,stu[i].id,stu[i].all);
		for(int j=1;j<=k;j++){
			if(stu[i].score[j]==-1) printf(" -");
			else printf(" %d",stu[i].score[j]);
		}
		printf("\n");
	}
	return 0;
}
