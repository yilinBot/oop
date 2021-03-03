/* which is  the highest average temperature of 3 consecutive days, and its index ???*/

#include <iostream>
#include <cmath>

using namespace std;

int main()
{

   const int max_v=30;
   float h[max_v];
   int db;

   do
   {
     cout << "Nr. of data  between: (1<=db<= "<<max_v<< ") " << endl;
     cin>>db;
   }while(db<=1 || db>=max_v);

   cout << "Give the values :  " << endl;

    for(int i=0; i<db; ++i)
    {
        cin>>h[i];
    }

   int index=0;

   float s=h[0]+h[1]+h[2];
   float aver=s/3;

    for(int i=0; i<db-3; ++i)
    {
        s-=h[i];
        s+=h[i+3];

        if(aver<s/3)
        {
            aver=s/3;
            index=i+1;
        }
    }

   cout<<" the moving average of 3 days is:  "<<aver<<"  its 1st index:  "<<index<<endl;


    return 0;
}


