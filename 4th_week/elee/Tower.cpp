#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> heights) {
    vector<int> answer;
    queue<int> q;
    int size = heights.size();
 
    reverse(heights.begin(), heights.end());
    
    for (int i = 0; i < size; i++) 
        q.push(heights[i]);
 
    int key = size;
    int pos = 1;
    
    while (!q.empty()) 
    {
        int cand = q.front(); 
        q.pop();
        
        int i = 0;
        
        for (i = pos; i < size; i++) 
        {
            if (cand < heights[i]) 
                break;
        }
        pos++;
 
        answer.push_back(size - i);
    }
    
    reverse(answer.begin(), answer.end());
    
    return answer;
}