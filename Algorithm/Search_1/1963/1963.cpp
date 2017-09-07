
#include <iostream>
#include <queue>
#include <string.h>

int arr[4];

int Arr_to_Int(int arr[])
{
    int temp = arr[0]*1000 + arr[1]*100 + arr[2]*10 + arr[3];
    return temp;
}
void Set_arr(int arr[],int n)
{
    arr[0] = n / 1000;
    arr[1] = (n%1000 - (n%100))/100;
    arr[2] = (n%100 - (n%10))/10;
    arr[3] = n%10;
}
using namespace std;
int main()
{


    int dis[10000] = {0,};
    bool prime[10000] = {false,};
    bool check[10000] = {false,};
    int T;
    cin >>T;



    for (int i=2; i<=10000; i++) {
        if (prime[i] == false) {
          for (int j=i*i; j <= 10000; j+=i) {
                prime[j] = true;
            }
        }
    }

     for (int i=0; i<=10000; i++) {
        prime[i] = !prime[i];
    }



    while(T--)
    {
         int n,m;
         cin >> n >> m;
         memset(dis,false,sizeof(dis));
         memset(check,false,sizeof(check));
         queue<int> Q;
         Q.push(n);
         Set_arr(arr,n);
         dis[n] = 0;
         check[n] = true;
         while(!Q.empty())
         {

          //  cout << Q.front() << endl;

            int next;
            int cur = Q.front();

            Q.pop();

            //cout << cur << endl;

            for(int j=0; j<4; j++)
            {

                Set_arr(arr,cur);
                for(int i=0; i<10; i++)
                {
                       if(j==0 && i==0) continue;
                       arr[j] = i;
                       next = Arr_to_Int(arr);
                       if(prime[next] && !check[next])
                       {
                         Q.push(next);
                         check[next] = true;
                         dis[next] = dis[cur] + 1;

                       }
                }
                 //Set_arr(arr,cur);
            }


        }

      cout<< dis[m]<< endl;
    }



    return 0;
}

