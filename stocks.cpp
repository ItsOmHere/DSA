#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the no. of Days: ";
    cin>>n;
    int stock[n];
    char action[n];
    for(int i=0;i<n;i++)
    {
        cout<<"Enter the stock price of day "<<i+1<<": ";
        cin>>stock[i];
    }
    int maxProfit=0;
    int maxprice=0;
    for(int i=n-1;i>=0;i--)
    {
        if(stock[i]>maxprice)
        {
            maxprice=stock[i];
            action[i]='S';
        }
        else
        {
        maxProfit+=(maxprice-stock[i]);
        action[i]='B';
    }
}
    cout<<"Maximum Profit: "<<maxProfit<<endl;
    cout<<"Actions: ";
    for(int i=0;i<n;i++)
    {
        if(action[i]=='B')
        {
            cout<<"Buy on day "<<i+1<<"> ";
        }
        else if(action[i]=='S')
        {
            cout<<"Sell on day "<<i+1<<"> ";
        }
    }
    cout<<endl;

}