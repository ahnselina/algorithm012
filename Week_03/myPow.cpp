class Solution {
public:
    double fastPow(double x, long n) {
        if (n == 0) return 1.0;

        double result = fastPow(x, n/2);
        return n % 2 == 0 ? result * result : result * result * x;
    }
    double myPow(double x, int n) {
       long N = n;
       return N >= 0 ? fastPow(x, N) : fastPow(1/x, -N);
    }
};