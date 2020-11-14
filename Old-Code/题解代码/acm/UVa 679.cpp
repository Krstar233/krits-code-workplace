#include <cstdio>
#include <string> 
#include <memory.h>
const int maxd = 20;
int s[1<<maxd];
int main(){
	int D, I;
	int m;
	scanf("%d", &m);
	while (m--){
		scanf("%d%d", &D, &I);
		memset(s, 0, sizeof(s));
		int k, n = (1<<D) - 1;
		for (int i = 0; i < I; i++){
			k = 1;
			while (true){
				s[k] = !s[k];
				k = s[k] ? k*2 : k*2 + 1;
				if (k > n)
					break;
			}
		}
		printf("%d\n", k/2);
	}
	scanf("%d", &m);
}
