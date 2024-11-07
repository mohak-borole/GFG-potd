//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
//  Class Solution to contain the method for solving the problem.
class Solution {
  public:
    // Function to determine if array arr can be split into three equal sum sets.
    vector<int> findSplit(vector<int>& arr) {
        // code here
        int totalSum = 0; 
        // total sum of all elements of array
        for(auto i : arr) {
            totalSum += i;
        }
        
        // if totalSum is not EVENLY divisible by 3
        // then it CANNOT BE split into three equal parts
        if(totalSum % 3 != 0) { 
            return {-1 , -1};
        }
        
        int part = totalSum / 3; // sum of each consecutive part 
        int i = 0 , j = arr.size() - 1; // two pointers
        int sum1 = 0 , sum2 = 0; 
        // sum1 : sum of the part from the beginning
        // sum2 : sum of the part from the end
        
        // add in sum1 until sum1 < part
        // move 'i' pointer ahead
        while( i < j && sum1 < part){ 
            sum1 += arr[i++];
        }
        
        // if sum1 != 'part'
        // it cannot be achieved
        if(sum1 != part) {
            return {-1 , -1};
        }
        
        
        // add in sum2 until sum2 < part
        // move 'j' pointer back
        while(j > i && sum2 < part){ 
            sum2 += arr[j--];
        }
        
        // if sum2 != 'part'
        // it cannot be achieved
        if(sum2 != part) {
            return {-1 , -1};
        }
        
        // sum of subarray from [0,i] = [i+1,j] = [j+1 , end]
        return {i - 1, j};
    }
};

//{ Driver Code Starts.

int main() {
    int test_cases;
    cin >> test_cases;
    cin.ignore();
    while (test_cases--) {
        string input;
        vector<int> arr;

        // Read the array from input line
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        // Solution instance to invoke the function
        Solution ob;
        vector<int> result = ob.findSplit(arr);

        // Output result
        if (result[0] == -1 && result[1] == -1 || result.size() != 2) {
            cout << "false" << endl;
        } else {
            int sum1 = 0, sum2 = 0, sum3 = 0;
            for (int i = 0; i < arr.size(); i++) {
                if (i <= result[0])
                    sum1 += arr[i];

                else if (i <= result[1])
                    sum2 += arr[i];

                else
                    sum3 += arr[i];
            }
            if (sum1 == sum2 && sum2 == sum3) {
                cout << "true" << endl;
            } else {
                cout << "false" << endl;
            }
        }
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends