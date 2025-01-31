class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>result;

        int n=intervals.size();
        int i=0;

        //checking in left
        while(i<n && intervals[i][1]<newInterval[0]){
            result.push_back(intervals[i]);
            i++;
        }

        //overlap case
        while(i<n && intervals[i][0]<=newInterval[1]){
            newInterval[0]=min(intervals[i][0],newInterval[0]);
            newInterval[1]=max(intervals[i][1],newInterval[1]);
            i++;
        }

        result.push_back(newInterval);

        //moving right
        while(i<n){
             result.push_back(intervals[i]);
             i++;
        }

        return result;


    }
};