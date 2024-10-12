//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int pairWithMaxSum(vector<int>& arr) {
        // code here
        if(arr.size() == 1){
            return -1;
        }
        
        // hint : compute for only two element subarray
        
        int left = 0 ;
        int right = 1;
        
        int max_sum = 0 ;
        while(right != arr.size()){
            
            max_sum = max(max_sum , (arr[left] + arr[right]));
            
            left++;
            right++;
            
        }
        return max_sum;
    }
};

//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore();

    while (tc--) {
        string input;
        getline(cin, input);

        stringstream ss(input);
        vector<int> a;
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution obj;
        int res = obj.pairWithMaxSum(a);
        cout << res << endl;
    }
}
// } Driver Code Ends