//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        vector<pair<int,int>> p;
        int maxi=0;
        for(int i=0;i<n;i++)
        {
            p.push_back({arr[i].profit,arr[i].dead});
            maxi=max(maxi,arr[i].dead);
        }
        
        sort(p.rbegin(),p.rend());
        vector<int> vis(maxi+1,0);
        
        set<int> s;
        for(int i=1;i<=maxi;i++)
        {
            s.insert(i);
        }
        
        int sum=0;
        int cnt=0;
        
        for(int i=0;i<p.size();i++)
        {
            if(s.empty())break;
            auto it=s.upper_bound(p[i].second);
            
            if((*it)==p[i].second)
            {
                sum+=p[i].first;
                cnt++;
                if(it==s.end())it--;
                s.erase(it);
                // return {*it,p[i].second};
            }else
            if(it!=s.begin())
            {
                it--;
                sum+=p[i].first;
                cnt++;
                s.erase(it);
            }
        }
        
        return {cnt,sum};
        
    } 
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends