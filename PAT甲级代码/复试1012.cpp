#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1010;
int toll[24];
struct Record{
	char name[24];
	int month,dd,hh,mm;
	bool status;
}rec[maxn],temp;
bool cmp(Record a,Record b){
	if(strcmp(a.name,b.name)!=0) return strcmp(a.name,b.name)<0;
	else if(a.dd!=b.dd) return a.dd<b.dd;
	else if(a.hh!=b.hh) return a.hh<b.hh;
	else return a.mm<b.mm;
}
void getsum(int on,int off,int &time,int &money){
	temp=rec[on];
	while(temp.dd<rec[off].dd||temp.hh<rec[off].hh||temp.mm<rec[off].mm){
		time++;
		money+=toll[temp.hh];
		temp.mm++;
		if(temp.mm==60){
			temp.mm=0;
			temp.hh++;
		}
		if(temp.hh==24){
			temp.hh=0;
			temp.dd++;
		}
	}
}
int main(){
	for(int i=0;i<24;i++){
		scanf("%d",&toll[i]);
	}
	int n;
	char line[10];
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%s %d:%d:%d:%d %s",rec[i].name,&rec[i].month,&rec[i].dd,&rec[i].hh,&rec[i].mm,line);
		if (strcmp(line,"on-line")==0) rec[i].status=true;
		else rec[i].status=false; 
	}
	sort(rec,rec+n,cmp);
	int on=0,off,next;
	while(on<n){
		next=on;
		int need=0;
		while(next<n&&strcmp(rec[on].name,rec[next].name)==0){
			if(need==0&&rec[next].status==true) need=1;
			else if(need==1&&rec[next].status==false) need=2;
			next++;
		}
		if(need!=2){
			on=next;
			continue;
		}
		int allmoney=0;
		printf("%s %02d\n",rec[on].name,rec[on].month);
		while(on<next){
			while(on<next-1&&!(rec[on].status==true&&rec[on+1].status==false)) on++;
		off=on+1;
		if(off==next){
			on=next;
			break;
		}
		printf("%02d:%02d:%02d ",rec[on].dd,rec[on].hh,rec[on].mm);
		printf("%02d:%02d:%02d ",rec[off].dd,rec[off].hh,rec[off].mm);
		int time=0,money=0;
		getsum(on,off,time,money);
		allmoney+=money;
		printf("%d $%.2f\n",time,money/100.0);
		on=off+1;
	}
	printf("Total amount: $%.2f\n",allmoney/100.0);
}
	return 0;
}
