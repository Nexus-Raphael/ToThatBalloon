#include<cstdio>
#include<cstring>

int gcd(int a,int b){
	return b>0?gcd(b,a%b):a;
}

int main(){
	int step,mod;
	while(~ scanf("%d %d",&step,&mod)){
		if(gcd(step,mod)==1) 
		
	}
	return 0;
}
