//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    int countOnes(vector<int> &arr) {
        int count = 0;
        for(int i = 0 ; i < arr.size() ; i++) {
            if(arr[i] == 1) count++;
        }
        return count;
    }
    
    int rowWithMax1s(vector<vector<int> > &arr) {
        // code here
        int max_count = 0;
        int max_index = -1;
        for(int i = 0 ; i<arr.size() ; i++) {
            int current_count = countOnes(arr[i]);
            if (current_count > max_count) {
                max_count = current_count;
                max_index = i;
            }
        }
        
        return max_index;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int> > arr(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends