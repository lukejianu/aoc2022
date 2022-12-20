#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stack>
#include <numeric>
#include <algorithm>

// Parses the input in the specified file.
std::vector<std::vector<int>> parseInput(std::string fileName) {
    std::vector<std::vector<int>> elvesItems;
    elvesItems.push_back(*new std::vector<int>);

    std::string line;
    std::ifstream infile("input.txt");
    while (std::getline(infile, line)) {
        if (line == "") {
            elvesItems.push_back(*new std::vector<int>);
        } else {
            elvesItems.back().push_back(std::stoi(line));
        }
    }
    return elvesItems; 
}

// Returns the sum of the list with the largest sum. 
int maxSum(std::vector<std::vector<int>> items) {
    int maxSoFar = -1; 

    for (int i = 0; i < items.size(); ++i) {
        auto curr = items.at(i);
        // std::cout << curr.size() << std::endl;
        maxSoFar = std::max(maxSoFar, std::accumulate(curr.begin(), curr.end(), 0));
    }
    return maxSoFar;
} 

// Returns the sums of the provided lists. 
std::vector<int> sums(std::vector<std::vector<int>> items) {
    std::vector<int> res; 

    for (auto l : items) {
        res.push_back(std::accumulate(l.begin(), l.end(), 0));
    }

    return res;
}

int main() {
    auto items = parseInput("input.txt");
    std::cout << maxSum(items) << std::endl;
    auto allSums = sums(items);
    std::sort(allSums.begin(), allSums.end());
    std::vector<int> lastThree(allSums.end() - 3, allSums.end());
    std::cout << std::accumulate(lastThree.begin(), lastThree.end(), 0) << std::endl;
}