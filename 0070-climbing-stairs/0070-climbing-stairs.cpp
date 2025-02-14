class Solution {
public:
// same as fibonacii nothing new
    int climbStairs(int n) {
            if(n==0 || n== 1) return 1;
            int fpre = 1;
            int spre = 1;
            for(int i = 2; i<=n; i++){
                int temp = fpre+ spre;
                fpre = spre;
                spre = temp;
            }
            return spre;
    }
};