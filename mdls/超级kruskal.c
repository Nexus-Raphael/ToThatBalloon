#include<algorithm>
#include<iostream>
#include<vector>

using namespace std;
struct edge{
	int x;
	int y;
	int w;
};

int set[1001];

bool cmp(edge a,edge b){
	return a.w<b.w;
}

//int find(int x){
//	int r=x;
//	while(r!=set[r]){
//		r=set[r];
//	}
//	return r;
//}

int find(int x){
	if(set[x]!=x){
		set[x]=find(set[x]);
	}
	return set[x];
}

void merge(int a,int b){
	a=find(a);
	b=find(b);
	if(a>b) set[a]=b;
	else set[b]=a;
}

int kruskal(vector<edge>E,int n,int m){
	int sum=0;
	int i;
	int cnt=0;
	for(i=1;i<=n;i++){
		set[i]=i;
	}
	for(i=0;i<m;i++){
		if(find(E[i].x)!=find (E[i].y)){
			merge(find(E[i].x),find (E[i].y));
			sum+=E[i].w;
			cnt++;
		}
		if(cnt==n-1) break;
	}
	if(cnt!=n-1) sum=-1;
	return sum;
}
int main(){
	vector<edge>E;
	int n,m;

	int i;
	scanf("%d %d",&n,&m);
	for(i=0;i<m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		int t;
		if(a>b){
			t=a;
			a=b;
			b=t;
		}
		E.emplace_back(a,b,c);
	}
	sort(E.begin(),E.end(),cmp);
	int ans=kruskal(E,n,m);
	if(ans==-1) cout<<"²»Á¬Í¨àÏ"<<endl;
	else cout<<ans<<endl;
	return 0;
}
