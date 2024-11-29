//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    string addBinary(string& s1, string& s2) {
        // your code here
        int n = s1.length();
        int m = s2.length();
        
        reverse(s1.begin() , s1.end());
        reverse(s2.begin() , s2.end());
        
        string ans ; 
        int i = 0 ; 
        int j = 0 ; 
        int carry = 0 ;
        
        while(i < n && j < m){
            int sum = (s1[i] - '0') + (s2[j] - '0') + carry ;
            ans.push_back(sum % 2 + '0') ;
            carry = sum / 2 ;
            i ++ ; j ++ ;
        }
        
        while(i < n){
            int sum = (s1[i] - '0') + carry ;
            ans.push_back(sum % 2 + '0') ;
            carry = sum / 2 ;
            i ++ ;
        }
        
        while(j < m){
            int sum = (s2[j] - '0') + carry ;
            ans.push_back(sum % 2 + '0') ;
            carry = sum / 2 ;
            j ++ ;
        }
        
        if(carry > 0) ans.push_back('1') ;
        
        while(ans.length() && ans.back() == '0') ans.pop_back() ;
        
        reverse(ans.begin() , ans.end()) ;
        return ans ; 
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string A, B;
        cin >> A >> B;
        Solution ob;
        cout << ob.addBinary(A, B);
        cout << "\n";

        cout << "~"
             << "\n";
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends