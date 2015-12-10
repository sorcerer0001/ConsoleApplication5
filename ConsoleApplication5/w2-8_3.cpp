#include <iostream>
using namespace std;

void display(int *arr,int n)
{
    for(int i=0; i<n;++i)
    {   
        cout<<arr[i]*5; 
        if(i!=n-1)
            cout<<", ";
    }
    cout<<endl;
}

int max(int *arr,int n)
{
    int max_pos =0;
    for(int i=1; i<n; ++i)
    {   if(arr[max_pos]<arr[i])
            max_pos = i;
    }
    return max_pos;
}

int main()
{
    int n; cin>>n;
    while(n)
    {

        int h; cin>>h;
        int fsh[25] = {};
        int dec[25] = {}; 
        int trv[25] = {};
        for(int i=0; i<n; ++i)
        {   cin>>fsh[i];    }
        for(int i=0; i<n; ++i)
        {   cin>>dec[i];    }
        for(int i=0; i<n-1; ++i)
        {   cin>>trv[i];    }


        /*calculate the result*/
        int spend [25][25] = {};
        int fishes[25]    = {}; /*捕了多少鱼*/

        /*枚举一共经过的湖的数量，从0到n-1个*/
        for(int i=0;i<n;++i)
        {   
            /*最远到达i号湖最大的捕鱼量*/
            int intervals = h*12;
            for(int j=0; j<i; ++j)
            {   intervals -= trv[j];}

            for(int j=0;j<intervals;++j)
            {   
                int max  = fsh[0]-spend[i][0]*dec[0];
                if(max<0)max = 0;
                int lake = 0;
                for(int j=0; j<=i; ++j)
                {   
                    int tmp = fsh[j]-spend[i][j]*dec[j];
                    if(tmp<0){  tmp=0;  }
                    if(max < tmp)
                    {   
                        max  = tmp;
                        lake = j;
                    }
                }
                spend[i][lake]++;
                fishes[i] += max;
            }   
        }

    
        int lakes = max(fishes,n);
        display(spend[lakes],n);
        cout<<"Number of fish expected: "
             <<fishes[lakes]<<endl<<endl;

        cin>>n;
    }
    return 0;
}
