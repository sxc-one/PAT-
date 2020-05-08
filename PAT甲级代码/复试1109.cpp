#include<bits/stdc++.h>
using namespace std;
const int maxn=10010;
int n,k,temp[maxn];
struct Stu{
	char name[10];
	int height;
}stu[maxn];
bool cmp(Stu a,Stu b){
	if(a.height!=b.height) return a.height>b.height;
	else return strcmp(a.name,b.name)<0;
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++){
		scanf("%s%d",stu[i].name,&stu[i].height);
	}
	sort(stu,stu+n,cmp);
	int rownum=n/k;
	int lastnum=n-rownum*(k-1);
	int id=0,cen=lastnum/2+1,pos=1;
	temp[cen]=id++;
	while(1){
		if(cen-pos>=1) temp[cen-pos]=id++;
		else break;
		if(cen+pos<=lastnum) temp[cen+pos]=id++;
		else break;
		pos++;
	}
	for(int i=1;i<=lastnum;i++){
		printf("%s",stu[temp[i]].name);
		if(i!=lastnum) printf(" ");
		else printf("\n");
	}
	int times=k-1;
	while(times--){
		cen=rownum/2+1,pos=1;
	temp[cen]=id++;
	while(1){
		if(cen-pos>=1) temp[cen-pos]=id++;
		else break;
		if(cen+pos<=rownum) temp[cen+pos]=id++;
		else break;
		pos++;
	}
	for(int i=1;i<=rownum;i++){
		printf("%s",stu[temp[i]].name);
		if(i!=rownum) printf(" ");
		else printf("\n");
	}
	}
	return 0;
}
