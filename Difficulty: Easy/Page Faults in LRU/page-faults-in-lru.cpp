//{ Driver Code Starts
// Initial Template for C++



#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int pageFaults(int N, int C, int pages[]){
        vector<int>ans;
        
        int pf=0;
        
        for(int i=0;i<N;i++){
            //check whether the page is present in ans vector or not
            auto finder=find(ans.begin(),ans.end(),pages[i]);
            
            //if it is not present
            if(finder==ans.end()){
                //if capacity exceeds
                if(ans.size()==C){
                    ans.erase(ans.begin());
                }
                ans.push_back(pages[i]);
                pf++;
            }
            
            //present in ans array ... 
            //means page hit 
            //so it is recently used...update it to the end of ans array
            
            else{
                ans.erase(finder);
                ans.push_back(pages[i]);
            }
            
            
        }
        
        return pf;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, C;
        cin>>N;
        int pages[N];
        for(int i = 0;i < N;i++)
            cin>>pages[i];
        cin>>C;
        
        Solution ob;
        cout<<ob.pageFaults(N, C, pages)<<"\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends
