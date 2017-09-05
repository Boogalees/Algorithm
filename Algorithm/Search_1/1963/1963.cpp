#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
bool check[10001];
int dist[10001];

int main(void) {
	int testCase;
	int p1, p2;
	scanf("%d", &testCase);

	for (int i = 0; i < 10001; i++) {
		for (int j = 2; j < i; j++) {
			if (i%j == 0) {
				check[i] = true;
				break;
			}
		}
	}

	for (int i = 0; i < testCase; i++) {
		scanf("%d %d", &p1, &p2);
		
		queue<int> q;
		q.push(p1);
		dist[p1] = 0;
		while (!q.empty()) {
			int now = q.front();
			q.pop();
			
			//1000ÀÚ¸´¼ö º¯°æ
			for (int i = 1; i < 10; i++) {
				if (i == now / 1000)
					continue;
				else {
					int tmp = i * 1000 + now % 1000;
					if (check[tmp] == false) {
						q.push(tmp);
						dist[tmp] = dist[now] + 1;
					}

				}

			}

			//100ÀÚ¸´¼ö º¯°æ
			for (int i = 1; i < 10; i++) {
				if (i == (now%1000)/100)
					continue;
				else {
					int tmp = (now - now % 1000) + i * 100 + now % 100;
					if (check[tmp] == false) {
						q.push(tmp);
						dist[tmp] = dist[now] + 1;
					}

				}

			}

			//10ÀÚ¸´¼ö º¯°æ
			for (int i = 1; i < 10; i++) {
				if (i == (now %100)/10)
					continue;
				else {
					int tmp = (now - now % 100) + i * 10 + now % 10;
					if (check[tmp] == false) {
						q.push(tmp);
						dist[tmp] = dist[now] + 1;
					}

				}

			}

			//1ÀÚ¸´¼ö º¯°æ
			for (int i = 1; i < 10; i++) {
				if (i == now%10)
					continue;
				else {
					int tmp = (now - now % 10) + i;
					if (check[tmp] == false) {
						q.push(tmp);
						dist[tmp] = dist[now] + 1;
					}

				}

			}
		}
		printf("%d\n", dist[p2]);
	}


	return 0;
}