#include <string>
#include <vector>
#include <iostream>

using namespace std;

int sumWeight(vector<vector<int>> trucks) {
    int sum = 0;
    for (auto it=trucks.begin(); it != trucks.end(); it++) {
        sum += (*it).at(0);
    }
    std::cout << "sum: " << sum << std::endl;
    return sum;
}

void printQueue(vector<vector<int>> queue) {
    std::cout << __func__ << std::endl;
    for (auto it=queue.begin(); it!=queue.end(); it++) {
        std::cout << (*it).at(0) << " " << (*it).at(1) << std::endl;
    }
    std::cout << "=======================================" << std::endl;
}

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    vector<vector<int>> trucks;
    for (auto it=truck_weights.begin(); it!=truck_weights.end(); it++) {
        trucks.push_back(std::vector<int>({*it, bridge_length}));
    }
    printQueue(trucks);
    vector<vector<int>> on_bridge{trucks.front()};
    while (!trucks.empty()) {
        if (on_bridge.front().at(1) > 0) {
            on_bridge.front().at(1) -= 1;
        }

        if (on_bridge.front().at(1) == 0) {
            on_bridge.erase(on_bridge.begin());
        }

        printQueue(on_bridge);

        if (sumWeight(on_bridge) + trucks.front().at(0) <= weight) {
            on_bridge.push_back(trucks.front());
            trucks.erase(trucks.begin());
        }
        answer++;
        std::cout << "answer: " << answer << std::endl;
    }
    return answer;
}

int main()
{
    vector<int> test1{7,4,5,6};
    std::cout << solution(2, 10, test1) << std::endl;
    vector<int> test2{10};
    std::cout << solution(100, 100, test2) << std::endl;
    vector<int> test3{10, 10, 10, 10, 10, 10, 10, 10, 10, 10};
    std::cout << solution(100, 100, test3) << std::endl;
}
