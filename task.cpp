#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to check if a given max time per day is possible
bool isPossible(const vector<int>& task, int n, int days, int mid) {
    int sum = 0;
    int count = 1;
    for (int i = 0; i < n; i++) {
        if (sum + task[i] > mid) {
            count++;
            sum = task[i];
            if (count > days) {
                return false;
            }
        } else {
            sum += task[i];
        }
    }
    return true;
}

int main() {
    int n, days;
    
    cout << "Enter a number of Tasks: ";
    cin >> n;
    
    cout << "Enter a number of days: ";
    cin >> days;
    
    vector<int> task(n);
    for (int i = 0; i < n; i++) {
        cout << "Enter task for day " << (i + 1) << ": ";
        cin >> task[i];
    }
    int low= *max_element(task.begin(), task.end());
    int high=0;
    for(int i=0;i<n;i++){
        high+=task[i];
    }
    while(low<high){
        int mid=low+(high-low)/2;
        if(isPossible(task,n,days,mid)){
            high=mid;
        }
        else{
            low=mid+1;
        }
    }
    cout << "Maximum capacity required: " << low << endl;
}

