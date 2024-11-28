//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int myAtoi(char *s) {
        // Your code here
        long res = 0;
        bool neg = false;
        while( *s != '\0' && *s == ' ' )
            s++;
        if( *s == '+' || *s == '-' ) {
            neg = ( *s == '-' );
            s++;
        }
        while( *s != '\0' && *s >= '0' && *s <= '9' ) {
            res = res * 10 + *s - '0';
            if( !neg && res > INT_MAX )
                return INT_MAX;
            else if( neg && ( -1 * res ) < INT_MIN )
                return INT_MIN;
            s++;
        }
        if( neg )
            res = -1 * res;
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        char s[20];
        cin >> s;
        Solution ob;
        int ans = ob.myAtoi(s);
        cout << ans << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends