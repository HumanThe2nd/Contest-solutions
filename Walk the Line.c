// Meta Hacker Cup, 2024, Pratice Round, Problem A: Walk the Line
// Author: Dan Shan
// Date: 2024-09-21
// formula time = m*((n-1)*2-1), where m is the fatest person
#include <stdio.h>
int main() {
    int t;
	scanf("%d",&t);
	for(int ti=1;ti<=t;ti++){
		long long n,k,m=2e11,ai;
		scanf("%lld %lld",&n,&k);
		for(int i=0;i<n;i++){
			scanf("%lld",&ai);
			if(ai<m) m=ai;
		}
		if(n>2) {
			m*=(n-1)*2-1;
		}
		printf("Case #%d: %s\n",ti,m>k?"NO":"YES");
	}
}
