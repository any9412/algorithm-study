#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for(int i = 0; i < commands.size(); ++i)
    {
        vector<int> vecTemp;
        
        for(int j = commands[i][0]; j <= commands[i][1]; ++j)
        {
            vecTemp.push_back(array[j-1]);
        }
        
        for(int n = 0; n < vecTemp.size(); ++n)
        {
            int min = n;
            
            for(int m = n; m  < vecTemp.size(); ++m)
            {
                if(vecTemp[min] > vecTemp[m])
                {
                    min = m;
                }
            }
            
            int temp = vecTemp[min];
            vecTemp[min] = vecTemp[n];
            vecTemp[n] = temp;
        }
        
        answer.push_back(vecTemp[commands[i][2] - 1]);
    }
    
    
    return answer;
}