// Solve-1
class Solution {
public:
    int reverse(int x) {
        long long ret = 0;
        while(x) {
            ret = ret*10 + x%10;
            x /= 10;
        }
        return (ret>INT_MAX || ret<INT_MIN) ? 0 : ret;
    }
};