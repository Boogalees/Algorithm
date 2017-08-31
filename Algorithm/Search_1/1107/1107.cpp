/*
#include <iostream>
using namespace std;


int main() {
    int n, m;
    int broke[10] = {0,};
    int gap;
    int CH;

    bool flag;

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a;
        cin >> a;
        broke[a] = 1;
    }


    gap = (n>100)? n-100 : 100-n;

    for(int i=0; i<=1000000; i++)
    {
        int cnt=0;
        CH = i;
        flag =false;
        while(1)
        {
            if(broke[CH%10] == 1)
                break;
            else
            {
                CH /= 10;
                cnt++;

                if(CH ==0)
                {
                    flag = true;
                    break;
                }
            }
        }

        if(flag)
        {
            flag = false;
            int rst = (n-i)>0 ? n-i : i-n;
            if(cnt+rst < gap)
            {
                gap = cnt + rst;
            }
        }


    }




    cout << gap << '\n';
    return 0;
}
*/
