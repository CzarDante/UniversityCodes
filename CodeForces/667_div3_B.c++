#include <stdio.h>
#include <math.h>

int main(){
	int t;
	long long int a,b,x,y,n,c,d,ans,m;
	scanf("%d",&t);
	while(t--){
		scanf("%lld %lld %lld %lld %lld",&a,&b,&x,&y,&n);
		m=n;
		c=min(a-x,m);
		m-=c;
		d=min(b-y,m);
		ans=(a-c)*(b-d);
		
		m=n;
		d=min(b-y,m);
		m-=d;
		c=min(a-x,m);
		ans=min((a-c)*(b-d),ans);
		printf("%lld\n",ans);
	}
	return 0;
}