#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> done;
    while (!progresses.empty()) {
        for (int i=0; i<progresses.size(); i++) {
            progresses.at(i) += speeds.at(i);
        }
        
        if (progresses.front() >= 100) {
            done.push_back(0);
            int count = 1;
            for (int i=1; i<progresses.size(); i++) {
                if (progresses.at(i) >= 100) {
                    count++;
                    done.push_back(i);
                }
            }
            answer.push_back(count);
            for (int i=0; i<done.size(); i++) {
                progresses.erase(progresses.begin() + done.at(i) - i);
                speeds.erase(speeds.begin() + done.at(i) - i);
            }
            done.clear();
        }
    }
    return answer;
}

int main()
{
    vector<int> progresses{93, 0, 99, 0, 0, 0, 0};
    vector<int> speeds{1, 2, 3, 90, 10, 2, 1};
    vector<int> result = solution(progresses, speeds);
    for (auto it=result.begin(); it!=result.end(); it++) {
        std::cout << *it << ", ";
    }
    std::cout << std::endl;
}

