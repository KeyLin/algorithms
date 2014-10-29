#include <iostream>
#include <stdio.h>

using namespace std;

void Swap(double *a, double *b)
{
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

void Quicksort(double *sub,int low,int high)
{
    if(low > high) return;
    int k = low;
    int i = low , j = high;
    while(i<=j)
    {
        if(k>i && sub[k]>sub[i]) {Swap(&sub[k], &sub[i]); k=i;}
        i++;
        if(k<j && sub[k]<sub[j]) {Swap(&sub[k], &sub[j]); k=j;}
        j--;
    }
    Quicksort(sub , low , k-1);
    Quicksort(sub , k+1 , high);
}

void test()
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
    Quicksort(arr, 0, count-1);
    cout<<"降序序后的数组是：";
    for(int i=0; i<count; ++i)
        cout<<arr[i]<<' ';
    cout<<endl;
}

int main()
{
    while(1)
        test();
    return 0;
}
