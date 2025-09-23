//
// Created by arsen on 21.09.2025.
//
#include <iostream>
#include <stack>
#include <vector>
int main() {
    int n;
    int transfered = 1;
    int sent = 0;
    std::vector <std::pair<int, int>> operations;
    std::stack<int> deadend;
    std::cin >> n;
    std::vector<int> first(n);
    for (int i = 0; i < n; i++) {
        std::cin >> first[i];
    }
    while (!first.empty()) {
        deadend.push(first.front());
        first.erase(first.begin());
        operations.emplace_back(1, 1);
        while (!deadend.empty() && deadend.top() == transfered) {
            deadend.pop();
            operations.emplace_back(2, 1);
            ++transfered;
        }
    }
    if (transfered != n + 1) {
        std::cout << 0 << "\n";
        return 0;
    }
    std::vector<std::pair<int, int>> groupedOperations;
    for (auto& o : operations) {
        if (groupedOperations.empty() || groupedOperations.back().first != o.first) {
            groupedOperations.push_back(o);
        }
        else {
            groupedOperations.back().second += o.second;
        }
    }
    for (auto& o : groupedOperations) {
        std::cout << o.first << " " << o.second << "\n";
    }
    return 0;
}