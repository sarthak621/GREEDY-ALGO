//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution {
  public:
  
  struct Item {
    double value;
    double weight;
    double ratio;
};
    // Function to get the maximum total value in the knapsack.
    
    static bool myComp(Item a,Item b){
        if(a.ratio>b.ratio){
            return true;
        }
        return false;
    }
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        double n=wt.size();
        
        // Create an array of Item objects
        vector<Item> items(n);
        
        for(double i=0;i<n;i++){
            items[i].value = val[i];
            items[i].weight = wt[i];
            items[i].ratio = (double)val[i] / wt[i];
        }
        
        sort(items.begin(),items.end(),myComp);
        
        double totalVal=0;
        double capacity_remaining=capacity;
        
        
        
        for(double i=0;i<n;i++){
            if(items[i].weight<=capacity_remaining){
                totalVal+=items[i].value;
                capacity_remaining=capacity_remaining-items[i].weight;
            }
            
            else {
                totalVal+=(items[i].value/items[i].weight)*capacity_remaining;
                break;
            }
            
            
                if(capacity_remaining==0) break;
            
        }
        return totalVal;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    // taking testcases
    cin >> t;
    cin.ignore(); // to ignore the newline after the number of test cases
    cout << setprecision(6) << fixed;

    while (t--) {
        // Reading the value array
        vector<int> values;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            values.push_back(number);
        }

        // Reading the weight array
        vector<int> weights;
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number) {
            weights.push_back(number);
        }

        // Reading the capacity
        int w;
        cin >> w;
        cin.ignore(); // to ignore the newline after capacity

        // function call
        Solution ob;
        cout << ob.fractionalKnapsack(values, weights, w) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends