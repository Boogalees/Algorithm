
#include <iostream>
#include <vector>
using namespace std;



int main()
{
    int T;
 //   int cnt = 0;


    cin >> T;


    for(int i=1; i<=T; i++)
    {
        int n =0;
        int cnt=0;
        cin >> n;

        for(int i=1; i<=3; i++)
        {
            if( i == n) cnt+=1;

            for(int i2=1; i2<=3; i2++)
            {
                 if( i+i2 == n) cnt+=1;
                for(int i3=1; i3<=3; i3++)
                {
                     if( i+i2+i3 == n) cnt+=1;
                    for(int i4=1; i4<=3; i4++)
                    {
                         if( i+i2+i3+i4 == n) cnt+=1;
                        for(int i5=1; i5<=3; i5++)
                        {
                            if( i+i2+i3+i4+i5 == n) cnt+=1;

                            for(int i6=1; i6<=3; i6++)
                            {
                                if( i+i2+i3+i4+i5+i6 == n) cnt+=1;

                                for(int i7=1; i7<=3; i7++)
                                {
                                     if( i+i2+i3+i4+i5+i6+i7 == n) cnt+=1;

                                    for(int i8=1; i8<=3; i8++)
                                    {
                                          if( i+i2+i3+i4+i5+i6+i7+i8 == n) cnt+=1;


                                        for(int i9=1; i9<=3; i9++)
                                        {
                                              if( i+i2+i3+i4+i5+i6+i7+i8+i9== n) cnt+=1;
                                            for(int i10=1; i10<=3; i10++)
                                            {
                                                 if( i+i2+i3+i4+i5+i6+i7+i8+i9+i10== n) cnt+=1;


                                            }


                                        }


                                    }


                                }


                            }


                        }


                    }


                }


            }

        }

    cout << cnt<<endl;

    }




    return 0;
}

