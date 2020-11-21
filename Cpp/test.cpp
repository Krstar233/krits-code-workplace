#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, m;

    cin >> n >> m;

    vector<long> arr(n);

    for (int i = 1; i <= m; i++){
        int l, r;
        cin >> l >> r;

        for (int j = l; j <= r; j++){
            arr[j] = i;
        }
    }

    long ans  = 0;

    for (int i = 0; i < n; i++){
        ans += i * arr[i];
    }

    cout << ans % 100000009 << endl;
    return 0;
}