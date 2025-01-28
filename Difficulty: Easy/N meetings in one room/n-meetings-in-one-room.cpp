//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    
    struct Data{
        int starting_pt;
        int ending_pt;
        int position;
    };
    
    //comaprator
    static bool comp(Data a,Data b){
        return a.ending_pt<b.ending_pt;
    }
    int maxMeetings(vector<int>& start, vector<int>& end) {
            
            int n= start.size();
            
            //data of size n 
            vector<Data>data(n);
            
            for(int i=0;i<data.size();i++){
                data[i].starting_pt=start[i];
                data[i].ending_pt=end[i];
                data[i].position=i+1;
            }   
            
            sort(data.begin(),data.end(),comp); //sort in asc order acc to ending pt. 
            
            int count=1;
            int freeTime=data[0].ending_pt;
            
            vector<int>ds; //for storing position
            
            ds.push_back(data[0].position);
            
            for(int i=1;i<start.size();i++){
                if(data[i].starting_pt>freeTime){
                    count+=1;
                    freeTime=data[i].ending_pt;
                    ds.push_back(data[i].position);
                }
            }
            return count;
        
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> start;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            start.push_back(num);
        }

        vector<int> end;
        getline(cin, input);
        stringstream s22(input);
        while (s22 >> num) {
            end.push_back(num);
        }

        Solution ob;
        int ans = ob.maxMeetings(start, end);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends