#include <iostream>
#include <vector>	
#include <algorithm>	

using namespace std;

int ans;

void find(int n, int k, int cnt) {
	if (n == k){
		if (ans == 0)
			ans = cnt;
		if (ans > cnt)
			ans = cnt;
		return;
	}
	if (ans != 0 && cnt > ans)
		return;

	find(n + 1, k, cnt + 1);
	find(2 * n, k, cnt + 1);
	find(n - 1, k, cnt + 1);
}

int main(void) {
	int n, k;
	
	scanf("%d %d", &n, &k);

	find(n, k, 0);
	
	
	printf("%d\n", ans);

	return 0;
}