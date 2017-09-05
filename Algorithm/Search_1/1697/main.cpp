
#include <iostream>
#include <queue>


using namespace std;
int main()
{
    int N,K;
    int i=0;
    bool X[100001] = {false,};
    int  dis[100001] = {0,};
    queue<int> Q;

    cin >> N >> K;

    Q.push(N);
    X[N] = true;
    dis[N] = 0;

    while(!Q.empty())
    {

        int cur = Q.front();
        Q.pop();

        if(cur-1 >= 0)
        {
            if(X[cur-1]==false)
            {
                X[cur-1] = true;
                Q.push(cur-1);
                dis[cur-1] = dis[cur] + 1;
            }
        }

        if(cur+1 < 100001)
        {
            if(X[cur+1]==false)
            {
                X[cur+1] = true;
                Q.push(cur+1);
                dis[cur+1] = dis[cur] + 1;
            }
        }

        if(cur*2 < 100001)
        {
            if(X[cur*2]==false)
            {
                X[cur*2] = true;
                Q.push(cur*2);
                dis[cur*2] = dis[cur] + 1;
            }
        }



    }

    cout << dis[K];


    return 0;
}

