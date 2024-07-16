//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:

    string printString(string s, char ch, int count) {
        // Your code goes here
        int n=s.length();
        int flag=0;
        
        //Traverse in string
        for(int i=0;i<n;i++){
            if(s[i] == ch){
                flag++;
            }
            // When the required occurrence is found
            if(flag == count){
                if(i+1 < n){
                    return s.substr(i+1,n-i-1);
                }
                else{
                    return ""; //Remaining substring is empty
                }
            }
        }
          // If the character did not appear the required number of times
          return "";
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
        char ch;
        int count;

        cin >> s >> ch >> count;
        Solution ob;
        cout << ob.printString(s, ch, count) << "\n";
    }

    return 0;
}
// } Driver Code Ends