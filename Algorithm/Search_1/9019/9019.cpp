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

			//D: D �� n�� �� ��� �ٲ۴�. ��� ���� 9999 ���� ū ��쿡�� 10000 ���� ���� �������� ���Ѵ�. �� ��� ��(2n mod 10000)�� �������Ϳ� �����Ѵ�.
			temp = now * 2;
			if (temp > 9999)
				temp = temp % 10000;
			if (check[temp] == false) {
				check[temp] = true;
				dist[temp] = 'D';
				from[temp] = now;
				q.push(temp);
			}
			

			//S: S �� n���� 1 �� �� ��� n-1�� �������Ϳ� �����Ѵ�. n�� 0 �̶�� 9999 �� ��� �������Ϳ� ����ȴ�.
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
			

			//L: L �� n�� �� �ڸ����� �������� ȸ������ �� ����� �������Ϳ� �����Ѵ�. �� ������ ������ �������Ϳ� ����� �� �ڸ����� ������� d2, d3, d4, d1�� �ȴ�.
			temp = (now % 1000) * 10 + (now / 1000);
		
			if (check[temp] == false) {
				check[temp] = true;
				dist[temp] = 'L';
				from[temp] = now;
				q.push(temp);
			}
			

			//R: R �� n�� �� �ڸ����� ���������� ȸ������ �� ����� �������Ϳ� �����Ѵ�. �� ������ ������ �������Ϳ� ����� �� �ڸ����� ������� d4, d1, d2, d3�� �ȴ�.
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