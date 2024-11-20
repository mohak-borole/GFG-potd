//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find the majority elements in the array
    vector<int> findMajority(vector<int>& arr) {
        unordered_map<int, int> mp;
        int n = arr.size();
        vector<int> ans;
    
        // Count occurrences of each element
        for (auto ele : arr) {
            mp[ele]++;
        }
    
        // Check if any candidate has votes > n/3
        for (auto ele : mp) {
            if (ele.second > n / 3) {
                ans.push_back(ele.first);
            }
        }
    
        // Sort the result in increasing order
        sort(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        vector<int> ans = ob.findMajority(nums);
        if (ans.empty()) {
            cout << "[]";
        } else {
            for (auto &i : ans)
                cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends