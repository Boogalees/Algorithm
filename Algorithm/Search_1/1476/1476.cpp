/*
#include <iostream>

using namespace std;

int main()
{
    int arr[3] = {1,1,1};
    int E,S,M;
    int i=1;

    cin >> E >> S >> M;

    for(i=1;;i++)
    {
        if(arr[0] == E && arr[1] == S && arr[2] == M)
        {
            break;
        }

        if(arr[0]+1 == 16)
            arr[0] = 1;
        else
            arr[0]++;

        if(arr[1]+1 == 29)
            arr[1] = 1;
        else
            arr[1]++;

        if(arr[2]+1 == 20)
            arr[2] = 1;
        else
            arr[2]++;

    }

    cout << i << endl;

    return 0;
}
*/
