#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    double arr[100];
    char tmp;
    cout<<"请输入一个数组：";
    int count=0;
    do
    {
        scanf("%lf%c",&arr[count],&tmp);
        count++;
    }while(tmp!='\n');
    for(int i=0; i<count; ++i)
        for(int j=0; j<count-i-1; ++j)
        {
            if(arr[j]<arr[j+1])
            {
                //tmp = arr[j];
                //arr[j] = arr[j+1];
                //arr[j+1] = tmp;
                arr[j]=arr[j]+arr[j+1];
                arr[j+1]=arr[j]-arr[j+1];
                arr[j]=arr[j]-arr[j+1];
            }
        }
    cout<<"降序序后的数组是：";
    for(int i=0; i<count; ++i)
        cout<<arr[i]<<' ';
    return 0;
}
