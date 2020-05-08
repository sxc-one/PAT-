#include<bits/stdc++.h>
using namespace std;
const int k=111;
const int INF=0x3fffffff;
struct Cust{
	int cometime,servetime;
}newcust;
vector<Cust>cust;
int convert(int h,int m,int s){
	return h*3600+m*60+s;
} 
bool cmp(Cust a,Cust b){
	return a.cometime<b.cometime;
}
int endtime[k];
int main(){
	int c,w,totaltime=0;
	int sttime=convert(8,0,0);
	int edtime=convert(17,0,0);
	scanf("%d%d",&c,&w);
	for(int i=0;i<w;i++) endtime[i]=sttime;
	for(int i=0;i<c;i++){
		int h,m,s,servetime;
		scanf("%d:%d:%d %d",&h,&m,&s,&servetime);
		int cometime=convert(h,m,s);
		if(cometime>edtime) continue;
		newcust.cometime=cometime;
		newcust.servetime=servetime<=60?servetime*60:3600;
		cust.push_back(newcust);
	}
	sort(cust.begin(),cust.end(),cmp);
	for(int i=0;i<cust.size();i++){
		int idx=-1,minend=INF;
		for(int j=0;j<w;j++){
			if(endtime[j]<minend){
				minend=endtime[j];
				idx=j;
			}
		}
		if(endtime[idx]<=cust[i].cometime){
			endtime[idx]=cust[i].cometime+cust[i].servetime;
		}else{
			totaltime+=(endtime[idx]-cust[i].cometime);
			endtime[idx]+=cust[i].servetime;
		}
	}
	if(cust.size()==0) printf("0.0");
	else printf("%.1f",totaltime/60.0/cust.size());
	return 0;
}
