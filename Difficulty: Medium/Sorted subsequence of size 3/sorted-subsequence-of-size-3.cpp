//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

bool isSubSequence(vector<int> &v1, vector<int> &v2) {
    int m = v2.size();
    int n = v1.size();
    int j = 0; // For index of v2

    // Traverse v1 and v2
    for (int i = 0; i < n && j < m; i++) {
        if (v1[i] == v2[j]) {
            j++;
        }
    }
    return (j == m);
}


// } Driver Code Ends
// Function to find three numbers in the given array
// such that arr[smaller[i]] < arr[i] < arr[greater[i]] 

class Solution {
  public:
    vector<int> find3Numbers(vector<int> &arr) {
        // Code here
        if(arr.size() < 3) return {};
        int a1 = arr[0];
        int a2 = arr[1];
        int a3;
        int hold1 = INT_MAX;
        int hold2 = INT_MAX;
        for(int i=2;i<arr.size();i++){
            if(arr[i]>hold2) return {hold1,hold2,arr[i]};
            if(a1>=a2){
                a1=a2;
                a2=arr[i];
            }
            else{
                if(arr[i]>a2) return {a1,a2,arr[i]};
                else if(arr[i]>a1 && arr[i]<a2) a2 = arr[i];
                else if(arr[i]<a1){
                    hold1 = a1;
                    hold2 = a2;
                    a2 = arr[i];
                }
            }
        }
        return {};
    }
};

//{ Driver Code Starts.

// Driver program to test above function
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int n = arr.size();
        Solution obj;
        auto res = obj.find3Numbers(arr);
        // wrong format output
        if (!res.empty() and res.size() != 3) {
            cout << -1 << "\n";
        }

        if (res.empty()) {
            cout << 0 << "\n";
        } else if ((res[0] < res[1] and res[1] < res[2]) and isSubSequence(arr, res)) {
            cout << 1 << "\n";
        } else {
            cout << -1 << "\n";
        }
    }

    return 0;
}
// } Driver Code Ends