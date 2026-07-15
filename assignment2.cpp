#include<iostream>
using namespace std;
int countZeros(int arr[], int n)
{
    int i = 0;
    while (i < n && arr[i] == 1)
    {
        i++;
    }
    return n - i;
}
int main()
{
    int n = 7;
    int arr[n] = {1, 1, 1, 1, 0, 0, 0};

    cout << "Number of zeros = " << countZeros(arr, n);

    return 0;
}