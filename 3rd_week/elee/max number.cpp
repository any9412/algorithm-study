#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const string &str1, const string &str2)
{
    // 두 경우 중 더 큰 숫자가 되는 쪽을 구한다.
    if(str1 + str2 > str2 + str1)
        return true;
    return false;
}

string solution(vector<int> numbers) {
    string answer = "";
    int size = numbers.size();
    vector<string> numString;
    
    // numbers의 값을 string으로 변환한다.
    for(int i = 0; i < size; ++i)
    {
        numString.push_back(to_string(numbers[i]));
    }
    
    sort(numString.begin(), numString.end(), compare);
    
    for(int i = 0; i < size; ++i)
    {
        answer += numString[i];
    }
    
    // numbers의 모든 값이 0일 때
    if(answer[0] == '0')
        answer = "0";
    
    return answer;
}