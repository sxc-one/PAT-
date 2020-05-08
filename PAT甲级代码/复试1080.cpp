#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
#include<string>
using namespace std;
const int maxn=10010;
struct Car{
	char id[8];
	int time;
	bool flag;
}all[maxn],valid[maxn];
map<string,int> parktime;
int timetoint(int hh,int mm,int ss){
	return hh*3600+mm*60+ss;
}
bool cmp(Car a,Car b){
	if(strcmp(a.id,b.id)) return strcmp(a.id,b.id)<0;
	else return a.time<b.time;
}
bool cmp1(Car a,Car b){
	return a.time<b.time;
}
int main(){
	int n,k,hh,mm,ss,num=0;
	char status[5];
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++){
		 scanf("%s %d:%d:%d %s",all[i].id,&hh,&mm,&ss,status);
		 if(strcmp(status,"in")==0) all[i].flag=true;
		 else all[i].flag=false;
		 all[i].time=timetoint(hh,mm,ss);
	}
	sort(all,all+n,cmp);
	int maxtime=-1;
	for(int i=0;i<n;i++){
		if((strcmp(all[i].id,all[i+1].id)==0)&&all[i].flag==true&&all[i+1].flag==false){
			valid[num++]=all[i];
			valid[num++]=all[i+1];
			int intime=all[i+1].time-all[i].time;
			if(parktime.count(all[i].id)==0){
				parktime[all[i].id]=0;
			}
			parktime[all[i].id]+=intime;
			maxtime=max(maxtime,parktime[all[i].id]);
		}
	}
	sort(valid,valid+num,cmp1);
	int numcar=0,now=0;
	for(int i=0;i<k;i++){
		scanf("%d:%d:%d",&hh,&mm,&ss);
		int time=timetoint(hh,mm,ss);
		while(now<num&&valid[now].time<=time){
			if(valid[now].flag==true) numcar++;
			else numcar--;
			now++;
		}
		printf("%d\n",numcar);
	}
	for(auto it=parktime.begin();it!=parktime.end();it++){
		if(it->second==maxtime){
			printf("%s ",it->first.c_str());
		}
	}
	printf("%02d:%02d:%02d\n",maxtime/3600,maxtime%3600/60,maxtime%60);
	return 0;
}
