class Solution {
public:
    double calPow(double x, long long n) {
        if (n == 0) return 1;
        double ans = calPow(x, n / 2);
        if (n % 2 == 0) {
            return ans * ans;
        }
        return x * ans * ans;
    }

    double myPow(double x, int n) {
        long long new_n = n; 
        if (new_n < 0) {
            new_n = -new_n;
            return 1.0 / calPow(x, new_n);
        }
        return calPow(x, new_n);
    }
};
