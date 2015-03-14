#include <iostream>

using namespace std;

double *Value(double a[])
{
    double *b = new double[100];
    for(int i=0; i<100; ++i)
        b[i] = a[i];
    return b;
}

void Swap(double *a, double *b)
{
    double tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

double *QuickSort(double arr[],int low,int high)
{
    if(low > high) return arr;
    int k = low;
    int i = low , j = high;
    while(i<j)
    {
        if(k>i)
        {
            if(arr[k]>=arr[i]){Swap(&arr[k], &arr[i]); k=i;}
            i++;
        }
        if(k<j)
        {
            if(arr[k]<arr[j]){Swap(&arr[k], &arr[j]); k=j;}
            j--;
        }
    }

    QuickSort(arr , low , k-1);
    QuickSort(arr , k+1 , high);
}

double *BubbleSort(double arr[], int count)
{
    for(int i=0; i<count; ++i)
        for(int j=0; j<count-i-1; ++j)
        {
            if(arr[j]<arr[j+1])
                Swap(&arr[j],&arr[j+1]);
        }
    return arr;
}

double *Merge(double arr[], int low, int mid, int high)
{
    double *tmp = new double[high-mid];
    for(int i = 0 ; i<(high-mid) ; i++)
    {
        tmp[i] = arr[mid+i+1];
    }

    int m = mid, n = high-mid-1;
    for(int i = high; i >= low; --i)
    {
        if(m>=low&&n>=0&&arr[m]<=tmp[n]) {arr[i]=arr[m];m--;}
        else if(m>=low&&n>=0&&arr[m]>tmp[n]) {arr[i]=tmp[n];n--;}
        else if(m>=low&&n<0) {arr[i]=arr[m];m--;}
        else if(m<low&&n>=0) {arr[i]=tmp[n];n--;}
    }

    return arr;
}

double *MergeSort(double arr[],int low, int high)
{
    if(low >= high) return NULL;
    else
    {
        int mid = (low + high)/2;
        MergeSort(arr, low, mid);
        MergeSort(arr, mid+1, high);
        return Merge(arr, low, mid, high);
    }
}

void test()
{
    double arr[100] = {9,10,1,2,5,7,6,61,2};
    int count = 9;

    cout<<"Origin    :";
    for(int i=0; i<count; ++i)
        cout<<arr[i]<<' ';
    cout<<endl;

    double *arr0 = QuickSort(Value(arr), 0, count-1);
    cout<<"QuickSort :";
    for(int i=0; i<count; ++i)
        cout<<arr0[i]<<' ';
    cout<<endl;

    double *arr1 = BubbleSort(Value(arr), count);
    cout<<"BubbleSort:";
    for(int i=0; i<count; ++i)
        cout<<arr1[i]<<' ';
    cout<<endl;

    double *arr2 = MergeSort(Value(arr), 0, count-1);
    cout<<"MergeSort :";
    for(int i=0; i<count; ++i)
        cout<<arr2[i]<<' ';
    cout<<endl;
}

int main()
{
    test();
    return 0;
}
