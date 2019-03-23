#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq; // 내림차순 우선순위 큐
    
    for(int i = 0; i < scoville.size(); ++i)
    {
        pq.push(scoville[i]);
    }
    
    while(true)
    {
        if(scoville.size() == 1)
        {
            answer = -1;
            break;
        }
        
        int firstFood = pq.top();
        
        if(firstFood >= K)
           break;
        
        pq.pop(); 
        
        int secondFood = pq.top();
        pq.pop();
        
        int newFood = firstFood + secondFood * 2;
        pq.push(newFood);
        
        ++answer;
    }
    
    return answer;
}