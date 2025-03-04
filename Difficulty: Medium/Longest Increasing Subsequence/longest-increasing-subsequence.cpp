//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int lis(vector<int>& arr) {
        // code here
        vector<int> tail;
        
        for (int num : arr) {
            auto it = lower_bound(tail.begin(), tail.end(), num);  // Find position to replace
    
            if (it == tail.end()) {
                tail.push_back(num);  // Extend the sequence
            } else {
                *it = num;  // Replace with smaller value
            }
        }
        
        return tail.size();
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input

    while (t--) {
        int n;
        vector<int> arr;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            arr.push_back(num);

        Solution obj;
        cout << obj.lis(arr) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends