#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    vector<int> distance;
    queue<int> q;
    
    for(int i = 0; i < n; ++i)
        distance.push_back(0);
    
    for(int i = 0; i < edge.size(); ++i)
    {        
        if(edge[i][0] == 1)
        {
            q.push(edge[i][1]);
            distance[edge[i][1]-1] = 1;
        }
        else if(edge[i][1] == 1)
        {
            q.push(edge[i][0]);
            distance[edge[i][0]-1] = 1;
        }
    }
    
    while(!q.empty())
    {
        int index = q.front();
        
        for(int i = 0; i < edge.size(); ++i)
        {
            if(edge[i][0] == 1 || edge[i][1] == 1)
                continue;
            
            if(edge[i][0] == index
              && distance[edge[i][1]-1] == 0)
            {
				q.push(edge[i][1]);
                distance[edge[i][1]-1] = distance[index-1] + 1;
            }
            else if(edge[i][1] == index
                   && distance[edge[i][0]-1] == 0)
            {
				q.push(edge[i][0]);
                distance[edge[i][0]-1] = distance[index-1] + 1;
            }
        }
            
        q.pop();
    }
    
    for(int i = 0; i < n; ++i)
    {
        for(int j = i; j < n; ++j)
        {
            if(distance[i] < distance[j])
            {
                int temp = distance[i];
                distance[i] = distance[j];
                distance[j] = temp;
            }
        }
    }
    
    int max_dis = distance[0];
    for(int i = 0; i < n; ++i)
    {
        if(distance[i] != max_dis)
            break;
        
        answer++;
    }
    
    return answer;
}