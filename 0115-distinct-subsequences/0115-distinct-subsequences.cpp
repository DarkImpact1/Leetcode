class Solution {
public:

    int count(string&s, string&t, int i, int j,vector<vector<int>>&dp){
        if(i==0 || j==0){
            if(j==0) return 1;
            return 0;
        }
        if(dp[i][j] != -1) return dp[i][j];
        
        if(s[i-1] == t[j-1]){ // both char are matching 
            int take = count(s,t,i-1, j-1,dp);
            int not_take = count(s,t,i-1,j,dp);
            return dp[i][j] = take + not_take;
        }
        // not matched 
        return dp[i][j] = count(s,t,i-1,j,dp);// don't take the char and search further

    }
    int numDistinct(string s, string t) {
        int n1 = s.size(), n2 = t.size();
        if(n2 > n1) return 0;
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,-1));
        int ans = count(s,t,n1,n2,dp);
        return ans;
    }
};