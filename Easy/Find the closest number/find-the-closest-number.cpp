//{ Driver Code Starts
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    int findClosest( int n, int k,int arr[]) 
    { 
        // Complete the function
        int low = 0;
        int high = n-1;
        int ans = 0;
        int ans2 = 0;
        while(low <= high)
        {
            int mid = low + (high -low)/2;
            if(arr[mid] <= k)
            {
                ans = arr[mid];
                low = mid+1;
            }
            else{
                ans2 = arr[mid];
                high = mid - 1;
            }
        }
        if(abs(ans-k) < abs(ans2-k))
        {
            return ans;
        }
        return ans2;
    } 
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int arr[n];
        for (int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.findClosest(n,k,arr)<<endl;
    }
}

// } Driver Code Ends