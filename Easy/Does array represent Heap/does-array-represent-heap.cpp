//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    bool isMaxHeap(int arr[], int n)
    {
        // Your code goes here
        for(int i = 0 ; i < n; i++) {
        // Calculate the indices of left and right children
        int left_child = 2*i + 1;
        int right_child = 2*i + 2;

        // Check if the left child is within bounds and if the parent is less than the left child
        if (left_child < n && arr[i] < arr[left_child])
            return false;

        // Check if the right child is within bounds and if the parent is less than the right child
        if (right_child < n && arr[i] < arr[right_child])
            return false;
        }
    
    // If all conditions are satisfied, it's a max heap
    return true;
    }
};

//{ Driver Code Starts.
int main() {
    
    int t;
    cin >> t;
    while(t--)
    {
       int n;
       cin >> n;
       int a[4*n]={0};
       for(int i =0;i<n;i++){
           cin >> a[i];
       }
       Solution ob;
       cout<<ob.isMaxHeap(a, n)<<endl;
        
    }
    return 0;
}

// } Driver Code Ends