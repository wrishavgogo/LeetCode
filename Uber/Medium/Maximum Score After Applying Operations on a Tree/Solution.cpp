// https://leetcode.com/problems/maximum-score-after-applying-operations-on-a-tree/ 

// Code 


class Solution {
    const static int sz = 1e5 + 1;
    vector<long long> vt[sz];
    long long dp[sz];
    long long sum[sz];
    
public:
    long long maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& values) {
        
        
        memset(sum , 0 , sizeof(sum));
        memset(dp , 0 , sizeof(dp));
        
        
        for(auto edge : edges) {
            
            int u = edge[0];
            int v = edge[1];
            
            vt[u].push_back(v);
            vt[v].push_back(u);
            
        }
        
        return dfs(0 , -1 , values);
    }
    
    long long dfs(long long node , long long parent , vector<int>& values ) {
        
        
        
        
        long long subTreeSum = 0;
        long long dpSum = 0;
        
        for(auto child : vt[node] ) {
            
            if(child == parent ) {
                continue;
            }
            
            dfs(child , node , values);
            
            subTreeSum += sum[child];
            dpSum += dp[child];
        }
        
        // 1st option , let the node be not removed , and remove all the subtrees 
        dp[node] = subTreeSum;
        
        // 2nd option , let the node be removed , 
        // dp[j] contains max score obtained from the subtrees such that each is healthy 
        // if node is removed and each subtree is still healthy , then whole tree is healthy
        
        if(subTreeSum != 0 ) {
            // that means it is the leaf node , then we cannot remove the root 
            dp[node] = max(dp[node] , values[node] + dpSum );
        }
        
        sum[node] = values[node] + subTreeSum;
        
        
        return dp[node];
    }
};
  
