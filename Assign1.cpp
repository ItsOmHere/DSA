#include <iostream>
using namespace std;

void moveZeros(int arr[], int n)
{
    int j = 0; 
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0)
        {
            int temp;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            j++;
        }
    }
}

int main()
{
    int n;
    cout<<"ENter the size of array:";
    cin>>n;
    int arr[n];
    cout<<"Enter the element of array:";
    for(int i=0;i<n;i++)
    {  
        cin>>arr[i];
    }
    moveZeros(arr, n);

    cout << "Array after moving zeroes: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}