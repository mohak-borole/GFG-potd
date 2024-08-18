//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool canSplit(vector<int>& arr) {
        // code here
        int n = arr.size();
            
        if (n == 1)
            return false;
        
        int l = 0, r = n - 1;
        
        int lsum = arr[l], rsum = arr[r];
        l++, r--;
        
        while (l <= r) {
            if (l == r) {
                return abs(rsum - lsum) == arr[l];
            }
            
            if (lsum < rsum) {
                lsum += arr[l++];
            } else {
                rsum += arr[r--];
            }
        }
        
        return lsum == rsum;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t-- > 0) {
        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> arr;
        string temp;
        while (ss >> temp) {
            arr.push_back(stoi(temp));
        }

        Solution obj;
        bool res = obj.canSplit(arr);
        cout << (res ? "true" : "false") << endl;
    }
    return 0;
}
// } Driver Code Ends