//{ Driver Code Starts
// Initial Template for C++



#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int pageFaults(int N, int C, int pages[]){
        // queue<int>q;
        // unordered_set<int> inMemory;  // This will track the pages in the queue
        
        // // int capacity=0;
        // int pf=0; //page fault
        
        // for(int i=0;i<N;i++){
            
        //     //if the page is not in the memory
        //     if(inMemory.find(pages[i])==inMemory.end()){
        //         pf++;
                
                
        //         if(q.size()>=C){
        //             int lruPage=q.front();
        //             q.pop();
        //             inMemory.erase(lruPage);
        //         }
                
        //         q.push(pages[i]);
        //         inMemory.insert(pages[i]);
        //     }
        // }
        // return pf;
        
        int count = 0;

    // To store elements in memory of size c
    vector<int> v;
    
    for (int i = 0; i < N ; i++) {

        // Find if element is present in memory or not
        auto it = find(v.begin(), v.end(), pages[i]);

        // If element is not present
        if (it == v.end()) {

            // If memory is full
            if (v.size() == C) {
            
                // Remove the first element
                // As it is least recently used
                v.erase(v.begin());
            }

            // Add the recent element into memory
            v.push_back(pages[i]);

            // Increment the count
            count++;
        }
        else {

            // If element is present
            // Remove the element
            // And add it at the end as it is
            // the most recent element
            v.erase(it);
            v.push_back(pages[i]);
        }
    }

    // Return total page faults
    return count;
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