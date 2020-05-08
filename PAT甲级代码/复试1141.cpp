#include<bits/stdc++.h>
using namespace std;
const int maxn=100010;
struct Stu{
	double score=0;
	string school;
}stu[maxn];
struct Sch{
	int rank,ns;
	double weight=0;
	string id;
}sch[maxn];
bool cmp(Stu a,Stu b){
	return a.school<b.school;
}
bool cmp2(Sch a,Sch b){
	if((int)a.weight!=(int)b.weight) return (int)a.weight>(int)b.weight;
	else if(a.ns!=b.ns) return a.ns<b.ns;
	else return a.id<b.id;
}
int main(){
	int n;
	double score;
	string str1,str2;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		cin>>str1>>score>>str2;
		if(str1[0]=='B') score/=1.5;
		else if(str1[0]=='T') score*=1.5;
		stu[i].score=score;
		for(int j=0;j<str2.size();j++){
			if(str2[j]>='A'&&str2[j]<='Z') str2[j]+=32;
		}
		stu[i].school=str2;
	}
	sort(stu,stu+n,cmp);
	int numschool=0,j;
	for(int i=0;i<n;i=j){
		j=i;
		sch[numschool].id=stu[i].school;
		while(j<n){
			if(stu[j].school==stu[i].school){
				sch[numschool].ns++;
				sch[numschool].weight+=stu[j].score;
			}else {
				numschool++;
				break;
			}
			j++;
		}
	}
	sort(sch,sch+numschool+1,cmp2);
	sch[0].rank=1;
	for(int i=1;i<=numschool;i++){
		if((int)sch[i].weight==(int)sch[i-1].weight) sch[i].rank=sch[i-1].rank;
		else sch[i].rank=i+1;;
	}
	printf("%d\n",numschool+1);
	for(int i=0;i<=numschool;i++){
		cout<<sch[i].rank<<" "<<sch[i].id<<" "<<(int)sch[i].weight<<" "<<sch[i].ns<<endl;
	}
	return 0;
}
/*  使用字符数组处理，并且是对学生分数直接取整了，会有3分不通过 
#include<bits/stdc++.h>
using namespace std;
const int maxn=100010;
struct Stu{
	int score;
	char school[8];
}stu[maxn];
struct Sch{
	int rank,weight,ns;
	char id[8];
}sch[maxn];
bool cmp(Stu a,Stu b){
	return strcmp(a.school,b.school)<0;
}
bool cmp2(Sch a,Sch b){
	if(a.weight!=b.weight) return a.weight>b.weight;
	else if(a.ns!=b.ns) return a.ns<b.ns;
	else return strcmp(a.id,b.id)<0;
}
int main(){
	int n,score;
	char str1[8],str2[8];
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%s%d%s",str1,&score,stu[i].school);
		if(str1[0]=='B') score/=1.5;
		else if(str1[0]=='T') score*=1.5;
		stu[i].score=score;
		int len=strlen(stu[i].school);
		for(int j=0;j<len;j++){
			if(stu[i].school[j]>='A'&&stu[i].school[j]<='Z') stu[i].school[j]+=32;
		}
	}
	sort(stu,stu+n,cmp);
	int numschool=0,j;
	for(int i=0;i<n;i=j){
		j=i;
		int len=strlen(stu[i].school);
		for(int k=0;k<=len;k++){
			sch[numschool].id[k]=stu[i].school[k];
		}
		while(j<n){
			if(strcmp(stu[j].school,stu[i].school)==0){
				sch[numschool].ns++;
				sch[numschool].weight+=stu[j].score;
			}else {
				numschool++;
				break;
			}
			j++;
		}
	}
	sort(sch,sch+numschool+1,cmp2);
	sch[0].rank=1;
	for(int i=1;i<=numschool;i++){
		if(sch[i].weight==sch[i-1].weight) sch[i].rank=sch[i-1].rank;
		else sch[i].rank=i+1;;
	}
	printf("%d\n",numschool+1);
	for(int i=0;i<=numschool;i++){
		printf("%d %s %d %d\n",sch[i].rank,sch[i].id,sch[i].weight,sch[i].ns);
	}
	return 0;
}*/
