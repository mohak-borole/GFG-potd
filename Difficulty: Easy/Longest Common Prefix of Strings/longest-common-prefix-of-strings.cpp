//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:

    string longestCommonPrefix(vector<string> arr) {
        // your code here
        if(arr.size() == 0) return "-1";
        if(arr.size() == 1) return arr[0];
        
        int small = INT_MAX;
        for(int i = 0 ; i < arr.size() ; i++){
            if(arr[i].size() < small){
                small = arr[i].size();
            }
        }
        
        string ans;
        int count = 0;
        
        for(int i = 0 ; i < small ; i++) {
            char ch = arr[0][i];
            for(int j = 0 ; j < arr.size() ; j++){
                if(ch == arr[j][i]){
                    count++;
                }
            }
            if(count == arr.size()){
                ans.push_back(ch);
                count = 0;
            } else {
                break;
            }
        }
        
        if(ans.size() == 0){
            return "-1";
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.longestCommonPrefix(arr) << endl;
    }
}

// } Driver Code Ends