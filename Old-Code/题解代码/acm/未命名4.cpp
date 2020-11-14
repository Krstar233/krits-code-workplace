#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int mod, len;

struct mat {
    int m[105][105];
}ans, base;

mat mat_mul(mat A, mat B) {
    mat C;
    for(int i = 1; i <= len; i++) {
        for(int j = 1; j <= len; j++) {
            C.m[i][j] = 0;
            for(int k = 1; k <= len; k++) {
                C.m[i][j] = (C.m[i][j] + A.m[i][k] * B.m[k][j]) % mod;
            }
        }
    }
    return C;
}

mat mat_pow(mat A, mat B, int n) {
    while(n) {
        if(n & 1) B = mat_mul(B, A);
        A = mat_mul(A, A);
        n >>= 1;
    }
    return B;
}

int main() {
    int n, k;
    while(scanf("%d %d %d", &n, &k, &mod) != EOF) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                scanf("%d", &ans.m[i][j]);
            }
        }
        for(int i = 1; i <= n; i++) {
            for(int j = n + 1; j <= n * 2; j++) {
                if(i + n == j)
                    ans.m[i][j] = 1;
                else ans.m[i][j] = 0;
            }
        }
        for(int i = n + 1; i <= n * 2; i++) {
            for(int j = 1; j <= n; j++) {
                ans.m[i][j] = 0;
            }
        }
        for(int i = n + 1; i <= n * 2; i++) {
            for(int j = n + 1; j <= n * 2; j++) {
                if(i == j)
                    ans.m[i][j] = 1;
                else ans.m[i][j] = 0;
            }
        }
        for(int i = 1; i <= n * 2; i++) {
            for(int j = 1; j <= n * 2; j++) {
                if(i == j)
                    base.m[i][j] = 1;
                else base.m[i][j] = 0;
            }
        }
        len = n * 2;
        ans = mat_pow(ans, base, k + 1);
        for(int i = 1; i <= n; i++) {
            for(int j = n + 1; j <= len; j++) {
                if(i + n == j)
                    ans.m[i][j]--;
                while(ans.m[i][j] < 0) {
                    ans.m[i][j] += mod;
                }
            }
        }
        for(int i = 1; i <= n; i++) {
            for(int j = n + 1; j < len; j++) {
                printf("%d ", ans.m[i][j]);
            }
            printf("%d\n", ans.m[i][len]);
        }
    }
    return 0;
}

