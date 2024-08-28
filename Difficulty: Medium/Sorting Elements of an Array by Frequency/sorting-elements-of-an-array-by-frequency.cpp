//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Complete this function
    // Function to sort the array according to frequency of elements.
    vector<int> sortByFreq(vector<int>& arr) {
        // Your code here
        map<int, int> freqMap;
        for (int i = 0; i < arr.size(); i++) {
            freqMap[arr[i]]++;
        }

        // Vector to store elements along with their frequencies
        vector<pair<int, int>> freqVec;
        for (auto& it : freqMap) {
            freqVec.push_back(it);
        }

        // Sort the vector based on frequency, and if equal, by the element value
        sort(freqVec.begin(), freqVec.end(), [](pair<int, int>& a, pair<int, int>& b) {
            if (a.second == b.second) return a.first < b.first;
            return a.second > b.second;
        });

        // Result vector to store the sorted elements
        vector<int> res;
        for (auto& it : freqVec) {
            while (it.second--) {
                res.push_back(it.first);
            }
        }

        return res;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution obj;
        vector<int> v;
        v = obj.sortByFreq(arr);
        for (int i : v)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends