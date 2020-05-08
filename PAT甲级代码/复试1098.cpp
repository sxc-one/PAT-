#include<bits/stdc++.h>
using namespace std;
const int maxn=110;
int n,origin[maxn],change[maxn],temp[maxn];
bool issame(int a[],int b[]){
	for(int i=1;i<=n;i++){
		if(a[i]!=b[i]){
			return false;
		}
	}
	return true;
}
void print(){
	for(int i=1;i<=n;i++){
		printf("%d",temp[i]);
		if(i!=n) printf(" ");
	}
}
bool insert(){
	bool flag=false;
	for(int i=2;i<=n;i++){
		if(i!=2&&issame(temp,change)){
			flag=true;
		}
		temp[0]=temp[i];
		int j;
		for(j=i-1;j>=1;j--){
			if(temp[j]>temp[0]){
				temp[j+1]=temp[j];
			}
			else break;
		}
		temp[j+1]=temp[0];
		if(flag==true) return true;
	}
	return false;
}
void downadjust(int low,int high){
	int i=low,j=i*2;
	while(j<=high){
		if(j+1<=high&&temp[j+1]>temp[j]){
			j++;
		}
		if(temp[j]>temp[i]){
			swap(temp[j],temp[i]);
			i=j;
			j=i*2;
		}else break;
	}
}
void heapsort(){
	bool flag=false;
	for(int i=n/2;i>=1;i--){
		downadjust(i,n);
	}
	for(int i=n;i>1;i--){
		if(i!=n&&issame(temp,change)){
			flag=true;
		}
		swap(temp[i],temp[1]);
		downadjust(1,i-1);
		if(flag==true){
			print();
			return;
		}
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&origin[i]);
		temp[i]=origin[i];
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&change[i]);
	}
	if(insert()){
		printf("Insertion Sort\n");
		print();
	}else{
		printf("Heap Sort\n");
		for(int i=1;i<=n;i++){
			temp[i]=origin[i];
		}
		heapsort();
	}
	return 0;
} 

