class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n=g.size(); //greed
        int m=s.size(); //size

        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        
        int l=0;//left for greed array
        int r=0; //right for size array
        while(r<m){
           if(s[r]>=g[l]){
            l++;
           }
           r++;

           //edge case
           if(l==n) break; //for the case when g={1,2} and s={1,2,3}
        }
        return l;

    }
};