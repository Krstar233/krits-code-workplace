#include <cstdio>

int main(){
	int m;
	int D,I; 
	scanf("%d", &m);
	while (m--){
		scanf("%d%d", &D, &I);
		int n = 1<<D - 1;
		int k = 1;
		for (int i = 0; i < D-1; i++){
			if (I % 2){
				k = k*2;
				I = (I+1)/2;
			}else{
				k = k*2 + 1;
				I = I/2;
			}
		}
		printf("%d\n", k);
	}
	scanf("%d", &m);
}
