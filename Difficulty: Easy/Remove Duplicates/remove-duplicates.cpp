//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:

    string removeDups(string str) {
        // Your code goes here
        int n = str.size(), len = 0, mask = 0;
        for(int i = 0; i < n; i++) {
            int ch = str[i] - 'a';
            if((mask >> ch) & 1) continue;
            mask |= (1 << ch);
            str[len++] = ch + 'a';
        }
        return str.substr(0, len);
    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution ob;
        cout << ob.removeDups(s) << "\n";
    }

    return 0;
}
// } Driver Code Ends