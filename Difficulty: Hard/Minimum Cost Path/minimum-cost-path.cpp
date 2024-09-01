//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define ff first
#define ss second
class Solution
{
    public:
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.
    bool ex(int x,int y,int n)
	{
	    return x>=0&&x<n&&y>=0&&y<n;
	}
    int minimumCostPath(vector<vector<int>>& g) 
    {
        // Code here
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>> > pq;
        int n=g.size();
        vector<vector<int>>dp(n,vector<int>(n,INT_MAX));
        pq.push({g[0][0],{0,0}});
        dp[0][0]=g[0][0];
        int dx[]={0,-1,1,0};
        int dy[]={-1,0,0,1};
      //  vector<vector<int>>vis(n,vector<int>(n,0));
        
        while(!pq.empty())
        {
            auto p=pq.top();
            pq.pop();
            // if(vis[p.ss.ff][p.ss.ss])continue;
            // vis[p.ss.ff][p.ss.ss]=1;
            for(int i=0;i<4;i++)
            {
                int nx=p.ss.ff+dx[i];
                int ny=p.ss.ss+dy[i];
                if(!ex(nx,ny,n))continue;
                if(dp[nx][ny]>dp[p.ss.ff][p.ss.ss]+g[nx][ny])
                {
                    pq.push({dp[p.ss.ff][p.ss.ss]+g[nx][ny],{nx,ny}});
                    dp[nx][ny]=dp[p.ss.ff][p.ss.ss]+g[nx][ny];
                }
            }
        }
        return dp[n-1][n-1];
        
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.minimumCostPath(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends