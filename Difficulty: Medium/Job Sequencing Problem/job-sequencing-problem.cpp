//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array
// of jobs with deadlines and profits
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  
    struct Job{
        int id;
        int deadline;
        int profit;
    };
  
    static bool comparision(Job a,Job b){
        return (a.profit>b.profit);
    }
  
    vector<int> JobSequencing(vector<int> &id, vector<int> &deadline,
                              vector<int> &profit) {
        // code here
        int n=id.size();
        
        //data of size n
        vector<Job>job(n);
        
        for(int i=0;i<job.size();i++){
            job[i].id=id[i];
            job[i].deadline=deadline[i];
            job[i].profit=profit[i];
        }
        
        sort(job.begin(),job.end(),comparision);
        
        int totalProfit=0;
        int count=0;
        int maxDeadline=-1;
        
        for(int i=0;i<n;i++){
            maxDeadline=max(maxDeadline,job[i].deadline);
        }
        vector<int> slot(maxDeadline + 1, -1); // -1 means the slot is free
        
        for(int i=0;i<n;i++){
            for(int j=job[i].deadline;j>0;j--){
                if(slot[j]==-1){
                    slot[j]=job[i].id;
                    totalProfit+=job[i].profit;
                    count++;
                    break; //job is scheduled no need to check further
                }
            }
        }
        return {count,totalProfit};
    }
};


//{ Driver Code Starts.
//            Driver program to test methods
int main() {
    int t;
    // testcases
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> jobIDs, deadlines, profits;
        string temp;
        getline(cin, temp);
        istringstream ss1(temp);
        int x;
        while (ss1 >> x)
            jobIDs.push_back(x);

        getline(cin, temp);
        istringstream ss2(temp);
        while (ss2 >> x)
            deadlines.push_back(x);

        getline(cin, temp);
        istringstream ss3(temp);
        while (ss3 >> x)
            profits.push_back(x);

        int n = jobIDs.size();

        Solution obj;
        vector<int> ans = obj.JobSequencing(jobIDs, deadlines, profits);
        cout << ans[0] << " " << ans[1] << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends