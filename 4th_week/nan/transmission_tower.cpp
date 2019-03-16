/* 수평 직선에 탑 N대를 세웠습니다. 모든 탑의 꼭대기에는 신호를 송/수신하는 장치를 설치했습니다.
 * 발사한 신호는 신호를 보낸 탑보다 높은 탑에서만 수신합니다. 또한, 한 번 수신된 신호는 다른 탑으로 송신되지 않습니다.
 * 예를 들어 높이가 6, 9, 5, 7, 4인 다섯 탑이 왼쪽으로 동시에 레이저 신호를 발사합니다.
 * 그러면, 탑은 다음과 같이 신호를 주고받습니다. 높이가 4인 다섯 번째 탑에서 발사한 신호는 높이가 7인 네 번째 탑이 수신하고,
 * 높이가 7인 네 번째 탑의 신호는 높이가 9인 두 번째 탑이, 높이가 5인 세 번째 탑의 신호도 높이가 9인 두 번째 탑이 수신합니다.
 * 높이가 9인 두 번째 탑과 높이가 6인 첫 번째 탑이 보낸 레이저 신호는 어떤 탑에서도 수신할 수 없습니다.
 *
 * 맨 왼쪽부터 순서대로 탑의 높이를 담은 배열 heights가 매개변수로 주어질 때
 * 각 탑이 쏜 신호를 어느 탑에서 받았는지 기록한 배열을 return 하도록 solution 함수를 작성해주세요.
 */
#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> heights) {
    vector<int> answer;
    int size = heights.size();
    for (int i=0; i<size; i++) {
        answer.push_back(0);
    }
    int h = 0;
    while (!heights.empty()) {
        h = heights.back();
        heights.pop_back();
        for (int i=heights.size()-1; i>=0; i--) {
            std::cout << "i: " << i << ", heights.at(i): " << heights.at(i) << ", h: " << h << std::endl;
            if (heights.at(i) > h) {
                answer[size-1] = i+1;
                break;
            }
        }
        size--;
    }
    return answer;
}

int main()
{
    vector<int> test1{6,9,5,7,4};
    vector<int> result = solution(test1);
    for (auto it=result.begin(); it!=result.end(); it++) {
        std::cout << *it << ", ";
    }
    std::cout << std::endl;
    vector<int> test2{3,9,9,3,5,7,2};
    result = solution(test2);
    for (auto it=result.begin(); it!=result.end(); it++) {
        std::cout << *it << ", ";
    }
    std::cout << std::endl;
    vector<int> test3{1,5,3,6,7,6,5};
    result = solution(test3);
    for (auto it=result.begin(); it!=result.end(); it++) {
        std::cout << *it << ", ";
    }
    std::cout << std::endl;
}
