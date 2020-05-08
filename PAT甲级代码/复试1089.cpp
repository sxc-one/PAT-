#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=110;
int origin[maxn],temp[maxn],target[maxn];
int n;
bool issame(int a[],int b[]){
	for(int i=0;i<n;i++){
		if(a[i]!=b[i]) return false;
	}
	return true;
}
void showarray(int a[]){
	for(int i=0;i<n;i++){
		printf("%d",a[i]);
		if(i!=n-1) printf(" ");
	}
}
bool insert(){
	bool flag=false;
	for(int i=1;i<n;i++){
		if(i!=1&&issame(temp,target)){
			flag=true;
		}
		int x=temp[i],j;
		for(j=i-1;j>=0&&temp[j]>x;j--){
			 temp[j+1]=temp[j];
		}
		temp[j+1]=x;
		if(flag==true) return true;
	}
	return false;
}
void merge(){
	bool flag=false;
	for(int step=2;step/2<n;step*=2){
		if(step!=2&&issame(temp,target)){
			flag=true;
		}
		for(int i=0;i<n;i+=step){
			sort(temp+i,temp+min(i+step,n));
		}
		if(flag==true) {
			showarray(temp);
			return;
		}
	}
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&origin[i]);
		temp[i]=origin[i];
	}
	for(int i=0;i<n;i++){
		scanf("%d",&target[i]);
	}
	if(insert()){
		printf("Insertion Sort\n");
		showarray(temp);
	}else{
		printf("Merge Sort\n");
		for(int i=0;i<n;i++){
			temp[i]=origin[i];
		}
		merge();
	}
	return 0;
} 
