//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to reverse words in a given string.
    string reverseWords(string str) {
        // code here
         int index = 0;
        vector<string>vs;
        for(int i=0;i<str.length();i++){
            if(str[i] =='.'){
                string slice = str.substr(index,i-index);
                index = i+1;
                vs.push_back(slice);
            }
        }
        if(index!=str.length()){
            string slice = str.substr(index,str.length());
            vs.push_back(slice);
        }
        reverse(vs.begin(),vs.end());
        string reverse="";
        for(int i=0;i<vs.size();i++){
           reverse+=vs[i];
           if(i<vs.size()-1){
               reverse+='.';
           }
        }
        return reverse;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.reverseWords(s) << endl;
    }
}
// } Driver Code Ends