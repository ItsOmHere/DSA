#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxShopsVisited(vector<int> S, vector<int> E, int K) {
    vector<pair<int, int>> shops;

    for (int i = 0; i < S.size(); i++)
        shops.push_back({E[i], S[i]});

    sort(shops.begin(), shops.end());

    vector<int> endTime;
    int count = 0;

    for (auto shop : shops) {
        bool assigned = false;

        for (int i = 0; i < endTime.size(); i++) {
            if (endTime[i] <= shop.second) {
                endTime[i] = shop.first;
                assigned = true;
                count++;
                break;
            }
        }

        if (!assigned && endTime.size() < K) {
            endTime.push_back(shop.first);
            count++;
        }
    }

    return count;
}

int main() {
    vector<int> S = {1, 8, 3, 2, 6};
    vector<int> E = {5, 10, 6, 5, 9};
    int K = 2;

    cout << "Maximum shops visited: " << maxShopsVisited(S, E, K);

    return 0;
}