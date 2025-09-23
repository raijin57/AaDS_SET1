//
// Created by arsen on 22.09.2025.
//
#include <iosfwd>
#include <iostream>
#include <deque>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::string command;
    std::deque<std::string> left;
    std::deque<std::string> right;
    std::cin >> t;
    while (t--) {
        getline(std::cin >> std::ws, command);
        if (command[0] == '+') {
            right.push_back(command.substr(2));
            if (right.size() > left.size()) {
                left.push_back(right.front());
                right.pop_front();
            }
        }
        else if (command[0] == '-') {
            // if (left.empty() && !right.empty()) {
            //     left.push_back(right.front());
            //     right.pop_front();
            // }
            std::cout << left.front() << "\n";
            left.pop_front();
            if (right.size() > left.size()) {
                left.push_back(right.front());
                right.pop_front();
            }
        }
        else if (command[0] == '*') {
            left.push_back(command.substr(2));
            if (right.size() + 1 < left.size()) {
                right.push_front(left.back());
                left.pop_back();
            }
        }
    }
    return 0;
}