#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

class Aircraft {
public:
    int id;
    double x, y;

    double distance(Aircraft p) {
        return sqrt((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y));
    }
};

Aircraft ans1, ans2;
double minDist = 1e9;

bool compareX(Aircraft a, Aircraft b) {
    return a.x < b.x;
}

void bruteForce(Aircraft p[], int l, int r) {
    for (int i = l; i <= r; i++) {
        for (int j = i + 1; j <= r; j++) {
            double d = p[i].distance(p[j]);
            if (d < minDist) {
                minDist = d;
                ans1 = p[i];
                ans2 = p[j];
            }
        }
    }
}

void closestPair(Aircraft p[], int l, int r) {

    if (r - l <= 2) {
        bruteForce(p, l, r);
        return;
    }

    int mid = (l + r) / 2;

    closestPair(p, l, mid);
    closestPair(p, mid + 1, r);

    for (int i = l; i <= mid; i++) {
        for (int j = mid + 1; j <= r; j++) {

            if (abs(p[i].x - p[j].x) < minDist) {
                double d = p[i].distance(p[j]);

                if (d < minDist) {
                    minDist = d;
                    ans1 = p[i];
                    ans2 = p[j];
                }
            }
        }
    }
}

int main() {

    int n;
    cout << "Enter number of aircraft: ";
    cin >> n;

    Aircraft planes[100];

    for (int i = 0; i < n; i++) {
        cout << "Enter X and Y for Flight " << i + 1 << ": ";
        cin >> planes[i].x >> planes[i].y;
        planes[i].id = 101 + i;
    }

    sort(planes, planes + n, compareX);

    closestPair(planes, 0, n - 1);

    cout << "\nClosest Aircraft:\n";
    cout << "Flight " << ans1.id << " and Flight " << ans2.id << endl;
    cout << "Minimum Distance = " << minDist << endl;

    return 0;
}