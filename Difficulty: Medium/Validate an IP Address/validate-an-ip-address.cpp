//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int isValid(string str) {
        // code here
        int n=str.size();
        string s="";
        int cnt=0;
        for(int i=0;i<n;i++){
            if(str[i]!='.'){
                s+=str[i];
            }
            else{
                if(s.empty()){
                    return false;
                }
                if(s.length()>1 && s[0]=='0')
                    return false;
                if(stoi(s)<0 || stoi(s)>255){
                    return false;
                }
                s="";
                cnt++;
            }
        }
        if(s.length()>1 && s[0]=='0')
                    return false;
        if(stoi(s)<0 || stoi(s)>255){
                    return false;
        }
        cnt++;
        if(cnt==4)return true;
        return false;
    }
};

//{ Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        // if (s.size() == 3) {
        //     cout << "false" << endl;
        //     return 0;
        // }
        Solution ob;
        bool f = ob.isValid(s);
        if (f)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends