#include<iostream>
using namespace std;
int countzeros(int num)
{
    int zeros = 0;
    while(num>0)
    {
        zeros+=num/5;
        num/=5;
    }
    return zeros;
}
int tailingzeros(int n){
    int count=0;
    int low=0;
    int high=n*5;
    while(low<high)
    {
        int mid=(low+high)/2;
        int temp=mid;
        int zeros=0;
        zeros=countzeros(temp);
        if(zeros<n)
        {
            low=mid+1;
        }
        else
        {
            high=mid;
        }
    }
    return low;
}

int main()
{
    int n;
    cout<<"Enter the number of trailing zeros: ";
    cin>>n;
    int result=tailingzeros(n);
    cout<<"The smallest number with "<<n<<" trailing zeros is: "<<result<<endl;
    return 0;
}