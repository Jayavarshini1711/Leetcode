class Solution {
public:
    double myPow(double x, int n) {
        long long nn = n;  // Use long long to handle -2^31
        if (nn < 0) {
            x = 1 / x;
            nn = -nn;
        }

        double ans = 1.0;

        while (nn > 0) {
            if (nn % 2 == 1) {  // if n is odd
                ans *= x;
            }
            x *= x;     // square x
            nn /= 2;    // divide n by 2
        }

        return ans;
    }
};
