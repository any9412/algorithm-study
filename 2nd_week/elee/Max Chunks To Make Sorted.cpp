class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int iAnswer = 0, iMax = 0;
        
        for(int i = 0; i < arr.size(); ++i) {
            if(iMax < arr[i])
                iMax = arr[i];
            
            if(iMax == i)
                iAnswer++;
        }
        
        return iAnswer;
    }
};