//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> minPartition(int N)
    {
        vector<int>ans;
        
        vector<int> coins{1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};

        
        for(int i=coins.size()-1;i>=0;i--){
            while(coins[i]<=N){
                N=N-coins[i];
                ans.push_back(coins[i]);
            }
            
            // If N becomes zero, break early as we have found the answer
            if (N == 0) break;
           
        }
        
        // if(N!=0) return -1;
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> numbers = ob.minPartition(N);
        for(auto u: numbers)
            cout<<u<<" ";
        cout<<"\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends