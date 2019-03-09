#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    int sum = 0;
    for (std::vector<int>::iterator it = citations.begin() ; it != citations.end(); ++it) {
        sum += *it;
    }
    int tmp = 0;
    int count = 0;
    while(true) {
        count = 0;
        tmp = sum;
        std::cout << "tmp: " << tmp << std::endl;
        for (std::vector<int>::iterator it = citations.begin() ; it != citations.end(); ++it) {
            if ((*it) < answer) {
                count++;
                tmp -= (*it);
            }
        }
        
        if (count >= answer && tmp <= answer) {
            return answer;
        }
        answer++;
    }
    return answer;
}

int main()
{
    // testcase 1
    std::vector<int> test;
    test.push_back(3);
    test.push_back(0);
    test.push_back(6);
    test.push_back(1);
    test.push_back(5);
    solution(test);
}
