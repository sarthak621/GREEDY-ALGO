class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        vector<vector<int>>result;
        int count=0;
        int n=intervals.size();
        if(n==1) {
            return 0;
        }

       // Sort intervals by their end times........so that minimum number of intervals are removed
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        
        int lastEnd = intervals[0][1];
        
        for(int i=1;i<n;i++){
            if(lastEnd>intervals[i][0]){
                count++;
            }
            else{
                lastEnd=intervals[i][1];
                

            }
        }
        return count;
    }
};