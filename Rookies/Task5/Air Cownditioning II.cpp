#include <bits/stdc++.h>

using namespace std;

struct Range {
    int start, end, requirement;
};

struct Conditioner {
    int start, end, power, price;
};

int numCows, numConditioners;
vector<Range> cowRanges;
vector<Conditioner> conditioners;
int minTotalCost = INT_MAX;

bool checkCooling(const vector<int> &coolingLevels) {
    for (const auto &range : cowRanges) {
        for (int i = range.start; i <= range.end; i++) {
            if (coolingLevels[i] < range.requirement)
                return false;
        }
    }
    return true;
}

void findMinCost(int currentIndex, vector<int> &coolingLevels, int currentCost) {
    if (currentIndex == numConditioners) {
        if (checkCooling(coolingLevels)) {
            minTotalCost = min(minTotalCost, currentCost);
        }
        return;
    }

    findMinCost(currentIndex + 1, coolingLevels, currentCost);

    for (int i = conditioners[currentIndex].start; i <= conditioners[currentIndex].end; i++) {
        coolingLevels[i] += conditioners[currentIndex].power;
    }
    findMinCost(currentIndex + 1, coolingLevels, currentCost + conditioners[currentIndex].price);
    for (int i = conditioners[currentIndex].start; i <= conditioners[currentIndex].end; i++) {
        coolingLevels[i] -= conditioners[currentIndex].power;
    }
}

int main() {
    cin >> numCows >> numConditioners;
    cowRanges.resize(numCows);
    for (int i = 0; i < numCows; i++) {
        cin >> cowRanges[i].start >> cowRanges[i].end >> cowRanges[i].requirement;
    }

    conditioners.resize(numConditioners);
    for (int i = 0; i < numConditioners; i++) {
        cin >> conditioners[i].start >> conditioners[i].end >> conditioners[i].power >> conditioners[i].price;
    }

    vector<int> coolingLevels(101, 0);
    findMinCost(0, coolingLevels, 0);

    cout << minTotalCost << endl;
    return 0;
}
