#include<stdio.h>
#define INF 999999

int min(int a,int b){return a<b?a:b;}

int cc[1001][1001];

int main(){
	int d[1001],s[1001]={0};
	int m,n;
	int i,j;
	int mini,u,v,a,b,c;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++){
		d[i]=INF;
		for(j=1;j<=n;j++){
			cc[i][j]=INF;
		}
		cc[i][i]=0;
	}
	d[1]=0;
	for(i=0;i<m;i++){
		scanf("%d %d %d",&a,&b,&c);
        if (c < cc[a][b]) {
            cc[a][b] = c;
            cc[b][a] = c;
        }
	}
	for(i=1;i<=n;i++){
		u=-1,mini=INF;
		for(j=1;j<=n;j++){
			if(!s[j]&&d[j]<mini){
				mini=d[j];
				u=j;
			}
		}
		if(u==-1) break;
		s[u]=1;
		
		for(v=1;v<=n;v++){
			if(!s[v]&&d[u]+cc[u][v]<d[v]){
				d[v] = d[u] + cc[u][v];
			}
		}
	}
	printf("%d\n", d[n] == INF ? -1 : d[n]);
return 0;
}
/*
4 4
2 3 1
1 2 1
3 4 1
2 4 1
*/
