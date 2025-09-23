//
// Created by arsen on 20.09.2025.
//
#include <iostream>
#include <set>
#include <vector>
int main() {
    int n;
    std::cin >> n;
    std::vector<int> positions(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> positions[i];
    }
    int best = -1;
    std::set<std::vector<int>> bestSet;
    for (int shift = 0; shift < n; ++shift) {
        int hamm = 0;
        for (int i = 0; i < n; ++i) {
            int k = i - shift;
            if (k < 0) {
                k += n;
            }
            if (positions[i] != positions[k]) {
                ++hamm;
            }
        }
        if (hamm > best) {
            best = hamm;
            bestSet.clear();
        }
        if (hamm == best) {
            std::vector<int> rotated(n);
            for (int i = 0; i < n; ++i) {
                int k = i - shift;
                if (k < 0) {
                    k += n;
                }
                rotated[i] = positions[k];
            }
            bestSet.insert(std::move(rotated));
        }
    }
    std::cout << bestSet.size() << "\n";
    return 0;
}