#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const string &str1, const string &str2)
{
    // �� ��� �� �� ū ���ڰ� �Ǵ� ���� ���Ѵ�.
    if(str1 + str2 > str2 + str1)
        return true;
    return false;
}

string solution(vector<int> numbers) {
    string answer = "";
    int size = numbers.size();
    vector<string> numString;
    
    // numbers�� ���� string���� ��ȯ�Ѵ�.
    for(int i = 0; i < size; ++i)
    {
        numString.push_back(to_string(numbers[i]));
    }
    
    sort(numString.begin(), numString.end(), compare);
    
    for(int i = 0; i < size; ++i)
    {
        answer += numString[i];
    }
    
    // numbers�� ��� ���� 0�� ��
    if(answer[0] == '0')
        answer = "0";
    
    return answer;
}