//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int longestStringChain(vector<string>& words) {
        // Code here
        sort(words.begin(), words.end(), [](const string &a, const string &b) {
            return a.size() < b.size();
        });
    
        unordered_map<string, int> dp;  // Stores the longest chain ending at each word
        int maxLength = 1;  // At minimum, a single word is a valid chain
    
        for (const string &word : words) {
            dp[word] = 1;  // Default chain length for this word
            for (int i = 0; i < word.size(); i++) {  // Try removing each character
                string prevWord = word.substr(0, i) + word.substr(i + 1);  // Generate predecessor
                if (dp.find(prevWord) != dp.end()) {  // Check if predecessor exists
                    dp[word] = max(dp[word], dp[prevWord] + 1);
                }
            }
            maxLength = max(maxLength, dp[word]);  // Update max chain length
        }
    
        return maxLength;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> words;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number) {
            words.push_back(number);
        }
        Solution obj;
        cout << obj.longestStringChain(words) << "\n";
        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends