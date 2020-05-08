#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char fy[10][5]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
int main(){
	char str[11];
	int num[9]={0};
	scanf("%s",str);
	int len=strlen(str);
	if(str[0]=='-'){
		printf("Fu ");
		for(int i=1;i<len;i++){
			str[i-1]=str[i];
		}
		len--;
	}
	for(int i=0;i<len;i++){
		num[i]=str[i]-'0';
	}
	reverse(num,num+len);
	bool flag=false,wan=false,shouwei=false;
	if(num[8]!=0){
		printf("%s Yi",fy[num[8]]);
	}else shouwei=true;
	if(num[7]!=0){
		if(len-1!=7) printf(" ");
		printf("%s Qian",fy[num[7]]);
		shouwei=false;
		wan=true;
	}else{
		if(shouwei==false) flag=true;
	}
	if(num[6]!=0){
		if(flag==true){
			if(len-1!=6) printf(" ");
			printf("ling %s Bai",fy[num[6]]);
			shouwei=false;
			wan=true;
		    flag=false;
		}else {
			if(len-1!=6) printf(" ");
			printf("%s Bai",fy[num[6]]); 
			shouwei=false;
			wan=true;
		    flag=false;
		}
	}else{
		if(shouwei==false) flag=true;
	}
	if(num[5]!=0){
		if(flag==true){
			if(len-1!=5) printf(" ");
			printf("ling %s Shi",fy[num[5]]);
			shouwei=false;
			wan=true;
		    flag=false;
		}else {
			if(len-1!=5) printf(" ");
			printf("%s Shi",fy[num[5]]); 
			shouwei=false;
			wan=true;
		    flag=false;
		}
	}else{
		if(shouwei==false) flag=true;
	}
	if(num[4]!=0){
		if(flag==true){
			if(len-1!=4) printf(" ");
			printf("ling %s",fy[num[4]]);
			shouwei=false;
			wan=true;
		    flag=false;
		}else{
			if(len-1!=4) printf(" ");
			printf("%s",fy[num[4]]); 
			shouwei=false;
			wan=true;
		    flag=false;
		} 
	}else{
		if(shouwei==false) flag=true;
	}
	if(wan==true) printf(" Wan");
	if(num[3]!=0){
		if(flag==true){
			if(len-1!=3) printf(" ");
			printf("%s Qian",fy[num[3]]);
			shouwei=false;
			wan=true;
		    flag=false;
		}else {
			if(len-1!=3) printf(" ");
			printf("%s Qian",fy[num[3]]); 
			shouwei=false;
			wan=true;
		    flag=false;
		}
	}else{
		if(shouwei==false) flag=true;
	}
	if(num[2]!=0){
		if(flag==true){
			if(len-1!=2) printf(" ");
			printf("ling %s Bai",fy[num[2]]);
			shouwei=false;
			wan=true;
		    flag=false;
		}else {
			if(len-1!=2) printf(" ");
			printf("%s Bai",fy[num[2]]); 
			shouwei=false;
			wan=true;
		    flag=false;
		}
	}else{
		if(shouwei==false) flag=true;
	}
	if(num[1]!=0){
		if(flag==true){
			if(len-1!=1) printf(" ");
			printf("ling %s Shi",fy[num[1]]);
			shouwei=false;
			wan=true;
		    flag=false;
		}else{
			if(len-1!=1) printf(" ");
			printf("%s Shi",fy[num[1]]);
			shouwei=false;
			wan=true;
		    flag=false;
		}  
	}else{
		if(shouwei==false) flag=true;
	}
	if(num[0]!=0){
		if(flag==true){
			if(len-1!=7) printf(" ");
			printf("ling %s",fy[num[0]]);
			wan=true;
		    flag=false;
		}else {
		    if(len-1!=0) printf(" ");
		    printf("%s",fy[num[0]]); 
		}
	}else{
		if(shouwei==true) printf("ling");
	}
	return 0;

}
