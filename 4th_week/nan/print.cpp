#include <string>
#include <vector>
#include <iostream>

using namespace std;

int highestPriority(vector<int> priorities) {
    if (priorities.empty()) {
        return 0;
    }
    int highest = priorities.front();
    for (auto it = priorities.begin(); it != priorities.end(); it++) {
        if (highest < (*it)) {
            highest = *it;
        }
    }
    std::cout << "highest: " << highest << std::endl;
    return highest;
}

void printQueue(vector<int> priorities) {
    for (auto it = priorities.begin(); it != priorities.end(); it++) {
        std::cout << *it;
    }
    std::cout << std::endl;
}

int solution(vector<int> priorities, int location) {
    int answer = 0;
    while (!priorities.empty()) {
        int j = priorities.front();
        std::cout << "j: " << j << std::endl;
        std::cout << "location: " << location << std::endl;
        priorities.erase(priorities.begin());
        if (j < highestPriority(priorities)) {
            priorities.push_back(j);
            if (location == 0) {
                location = priorities.size();
            }
        } else {
            std::cout << "print " << j << std::endl;
            answer++;
            if (location == 0) {
                std::cout << "print done!" << std::endl;
                break;
            }
        }
        location--;
        printQueue(priorities);
    }
    return answer;
}

int main()
{
    vector<int> test1{2,1,3,2};
    printQueue(test1);
    std::cout << solution(test1, 2) << std::endl;
    vector<int> test2{1,1,9,1,1,2,3};
    printQueue(test2);
    std::cout << solution(test2, 3);
    return 0;
}
