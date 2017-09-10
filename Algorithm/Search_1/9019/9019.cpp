#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;
char dist[10000];
int from[10000];
bool check[10000];

void print(int b) {
	int i = b;
	vector<char> ary;

	if (check[b] == false) {
		cout << "imposible";
		return;
	}
	while (true) {
		if (from[i] == -1) {
			while(!ary.empty()) {
				cout << ary[ary.size() - 1];
				ary.pop_back();
			}
			cout << "\n";
			break;
		}
		ary.push_back(dist[i]);
		i = from[i];
	}
}

int main(void) {
	int T, a, b;
	queue<int> q;
	
	cin >> T;
	
	while (T--) {
		memset(dist, '0', sizeof(dist));
		memset(check, false, sizeof(check));
		memset(from, 0, sizeof(from));
		vector<char> d;
		cin >> a >> b;
		
		q.push(a);
		dist[a] = '0'; 
		check[a] = true;
		from[a] = -1;

		while (!q.empty()) {
			int temp;
			int now = q.front();
			q.pop();

			//D: D 는 n을 두 배로 바꾼다. 결과 값이 9999 보다 큰 경우에는 10000 으로 나눈 나머지를 취한다. 그 결과 값(2n mod 10000)을 레지스터에 저장한다.
			temp = now * 2;
			if (temp > 9999)
				temp = temp % 10000;
			if (check[temp] == false) {
				check[temp] = true;
				dist[temp] = 'D';
				from[temp] = now;
				q.push(temp);
			}
			

			//S: S 는 n에서 1 을 뺀 결과 n-1을 레지스터에 저장한다. n이 0 이라면 9999 가 대신 레지스터에 저장된다.
			if (now == 0)
				temp = 9999;
			else
				temp = now - 1;
			if (check[temp] == false) {
				check[temp] = true;
				dist[temp] = 'S';
				from[temp] = now;
				q.push(temp);
			}
			

			//L: L 은 n의 각 자릿수를 왼편으로 회전시켜 그 결과를 레지스터에 저장한다. 이 연산이 끝나면 레지스터에 저장된 네 자릿수는 왼편부터 d2, d3, d4, d1이 된다.
			temp = (now % 1000) * 10 + (now / 1000);
		
			if (check[temp] == false) {
				check[temp] = true;
				dist[temp] = 'L';
				from[temp] = now;
				q.push(temp);
			}
			

			//R: R 은 n의 각 자릿수를 오른편으로 회전시켜 그 결과를 레지스터에 저장한다. 이 연산이 끝나면 레지스터에 저장된 네 자릿수는 왼편부터 d4, d1, d2, d3이 된다.
			temp = (now / 10) + (now % 10) * 1000;

			if (check[temp] == false) {
				check[temp] = true;
				dist[temp] = 'R';
				from[temp] = now;
				q.push(temp);
			}
			
		}
		
		print(b);
	}


	return 0;
}