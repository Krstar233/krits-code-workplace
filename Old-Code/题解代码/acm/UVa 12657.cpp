#include <iostream>
#include <algorithm>
#include <memory.h>

long long typedef LL;
LL data[100015];
LL node = 1;
LL left[100015];
LL right[100015];
LL tail = 0;
LL head = 0;

void add(LL a){
	data[node] = a;
	right[tail] = node;
	right[node] = -1;
	left[node] = tail;
	tail = node;
	node++;
}
void link(LL L, LL R){
	right[L] = R;
	left[R] = L;
}
int main(){
	LL n, m;
	LL cases = 0;
	while (std::cin >> n >> m){
		left[0] = -1;
		right[0] = -1;
		tail = 0;
		head = 0;
		node = 1;
		for (LL i = 1; i <= n; i++){
			add(i);
		}
		
		while (m--){
			LL a, b, c;
			std::cin >> a;
			if (a == 4){
				link(tail,head);
				tail = right[head];
				right[head] = -1;
				left[tail] = -1;
				std::swap(left, right);
				
//				for (LL i = right[head]; i != -1; i = right[i]){
//					printf("%lld\n", data[i]);
//				}
			}else{
				std::cin >> b >> c;
				switch (a){
					case 1:
						link(left[b], right[b]);
						link(left[c], b);
						link(b, c);
//						for (LL i = right[head]; i != -1; i = right[i]){
//					printf("%lld\n", data[i]);
//				}
				
						break;
					case 2:
						if (c != tail){
							link(left[b], right[b]);
							link(b, right[c]);
							link(c, b);
						}else{
							link(left[b], right[b]);
							link(c, b);
							right[b] = -1;
							tail = b;
						}
//						for (LL i = right[head]; i != -1; i = right[i]){
//					printf("%lld\n", data[i]);
//				}
				
						break;
					case 3:
						if (b == tail) tail = c;
						else if (c == tail) tail = b;
						if (b == head) head = c;
						else if (c == head) head = b;
						
						LL b_left = left[b];
						LL c_left = left[c];
						
						link(left[c], right[c]);
						link(c, b);
						link(b_left, c);
						link(left[b], right[b]);
						link(b, right[c_left]);
						link(c_left, b);
//						for (LL i = right[head]; i != -1; i = right[i]){
//					printf("%lld\n", data[i]);
//				}
				
						break;
				}
			}
		}
		LL ans = 0;
		int flag = -1;
		for (LL i = right[head]; i != -1; i = right[i]){
			flag = -flag;
			if (flag == 1){
				ans += data[i];
			}
		}
		printf ("Case %lld: %lld\n", ++cases, ans);
	}
} 
