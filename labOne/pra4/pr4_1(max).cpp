
/* which is  the highest temperature and its index ???*/

#include <iostream>
#include <cmath>

using namespace std;


void read(float [],int&,int);
float max_val_ind(float [], int,int&);

int main()
{

   const int max_v=30;
   float h[max_v];
   int db;

    read(h,db,max_v);

	int index=0;
	float max_val=max_val_ind(h,db,index);

  cout << "The highest temp. is :  " <<max_val<<" its index: "<<index<<endl;
    return 0;
}

void read(float h[],int& db,int max_v){
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

}


float max_val_ind(float h[], int db,int& index){

    float max_val=h[0];
	for(int i=1; i<db; ++i)
    {
        if(max_val<h[i])
        {
            max_val=h[i];
            index=i;
        }
    }

    return max_val;
}

