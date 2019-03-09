#include <iostream>
#include <string>
#include <vector>

using namespace std;
vector<int> sorting(vector<int> array) {
    for(int i=0; i<array.size(); i++) {
        for(int j=0; j<i; j++) {
            if (array.at(i) >array.at(j)) {
                int tmp = array.at(i);
                array.at(i) = array.at(j);
                array.at(j) =tmp;
            }
        }
    }
}

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    int index = 0;
    while(index < commands.size()-1) {
        vector<int> command = commands.at(index);
        vector<int> tmp;
        for(int j = command.at(0)-1;j < command.at(1); j++) {
            tmp.push_back(array.at(j));
        }
        // sorting
        sorting(tmp);
        answer.push_back(tmp.at(command.at(2)));
        index++;
    }
    return answer;
}

int main() {
    std::vector<int> array{1, 5, 2, 6, 3, 7, 4};
    std::vector<vector<int>> commands{{2,5,3}, {4,4,1}, {1,7,3}};
    vector<int> answer = solution(array, commands);
    
    std::cout << "answer: ";
    for (int j=0; j<answer.size(); j++) {
        std::cout << answer.at(j) << " ";
    }
    std::cout << std::endl;
}
