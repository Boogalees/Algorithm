#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

bool check[10001];
int dist[10001];
bool prime[10001];

int change(int k, int l, int m) {
	if (l == 0 && m == 0) return -1;
	string s = to_string(k);
	s[l] = m;
	return stoi(s);
}

int main(void) {
	int T, p1, p2;
	queue<int> q;

	scanf("%d", &T);

	for (int i = 1000; i < 10000; i++) {
		for (int j = 2; j <= i; j++) {
			if (i%j == 0)
				prime[i] = true; //소수가 아님
		}
	}

	while (T--) {
		scanf("%d %d", &p1, &p2);

		q.push(p1);
		check[p1] = true;
		dist[p1] = 0;
		while (!q.empty()) {
			int now = q.front();
			q.pop();
			
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 10; j++) {
					int tmp = change(now, i, j);
					if (tmp != -1) {
						if (prime[tmp] && check[tmp] == false) {
							q.push(tmp);
							check[tmp] = true;
							dist[tmp] = dist[now] + 1;
						}
					}
					
				}
			}

		}

	
	}

	return 0;
}
