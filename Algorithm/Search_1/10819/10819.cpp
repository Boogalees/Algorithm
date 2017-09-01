

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int Fac(int n)
{

    if(n == 1)
        return 1;
    else
    {
        return n*Fac(n-1);
    }
}

int main()
{
    int N;
    int temp=0;
    int rst=0;
    int Max=0;
    int Arr[8]={0,};


    cin >>N;
    vector<int> V(N);

    for (int i=0; i<N; i++) {
        cin >> V[i];
    }
    sort(V.begin(), V.end());

    for(int i=0; i<Fac(N); i++)
    {

        for(int j=1; j<N; j++)
        {
            rst += abs(V[j]-V[j-1]);
        }
        if(Max < rst)
            Max = rst;

        rst = 0;
        /*
        temp = Arr[i%N];
        Arr[i%N] = Arr[(i+1)%N];
        Arr[(i+1)%N] = temp;
        */
        next_permutation(V.begin(),V.end());

    }

    cout << Max;






    return 0;
}
//.
