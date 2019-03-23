#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {                              
    vector<int> answer;                                                 
    int index = 0;                                                      
    while(index < prices.size()) {                                      
        int price = prices.at(index);                                   
        int count = 0;                                                  
        for (auto it=prices.begin()+index+1; it != prices.end(); it++) {
            count++;                                                    
            if (price > (*it)) {                                        
                answer.push_back(count);                                
                break;                                                  
            }                                                           
        }                                                               
        index++;                                                        
        if (answer.size() != index) {                                   
            answer.push_back(count);                                    
        }                                                               
    }                                                                   
    return answer;                                                      
}
