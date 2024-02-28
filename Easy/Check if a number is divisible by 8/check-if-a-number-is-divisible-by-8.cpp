//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#include<vector>
#include<string>
class Solution{
    public:
    int DivisibleByEight(string s){
        //code here
        int size = s.size();
        long long num = 0;
        for(char ch: s) {
            num *= 10;
            num += ch-'0';
        }
        
        if(num % 8 == 0)
            return 1;
        else
            return -1;
        
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.DivisibleByEight(S)<<"\n";
    }
}
// } Driver Code Ends