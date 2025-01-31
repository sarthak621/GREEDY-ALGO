class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>result;
        int i=0;
        int n=intervals.size();
        // vector<int>newInterval;
        
        if(n==1) {
            return intervals;
        }

        sort(intervals.begin(),intervals.end());
        
        result.push_back(intervals[0]);
        for(int i=1;i<n;i++){
            if(result.back()[1]>=intervals[i][0]){
                result.back()[1]=max(result.back()[1],intervals[i][1]);
               
            }
            else{
                result.push_back(intervals[i]);
            }
        }
        return result;
    }
};