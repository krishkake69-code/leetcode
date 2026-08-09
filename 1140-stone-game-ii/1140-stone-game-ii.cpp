class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();

        vector<int> suffixSum(n);
        suffixSum[n-1] = piles[n-1];
        for(int i = n-2 ; i >= 0; --i){
            suffixSum[i] = suffixSum[i+1]+piles[i];
        }

        vector<vector<int>> dp(n, vector<int>(n+1,-1));
        return solve(0,1, suffixSum, dp,n);
    }
private:
    int solve(int i,int M, const vector<int>& suffixSum, vector<vector<int>>& dp, int n){
        if (i>=n) return 0;

        if(i+2*M>=n){
            return suffixSum[i];
        }
        if (dp[i][M]!= -1) return dp[i][M];

        int maxStones = 0;

        for(int X=1; X<=2*M;++X){
            int nextM = max(M, X);
            int opponentStones = solve(i+X, nextM, suffixSum,dp,n);
            maxStones = max(maxStones,suffixSum[i]- opponentStones);
        }
        return dp[i][M] = maxStones;
    }

};