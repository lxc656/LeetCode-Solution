class Solution {
public:
    int divide(int dividend, int divisor) {
        typedef long long LL;
        bool is_minus = false;
        if((divisor > 0 &&  dividend < 0) || (divisor < 0 && dividend > 0 )) {
            is_minus = true;
        }
        if(dividend == 0) {
            return 0;
        }
        LL a = abs((LL)dividend), b = abs((LL)divisor);
        vector<LL> exp;
        //构造幂次序列
        LL x = b, y = a;
        while(x <= y) {
            exp.push_back(x);
            x+=x;
        }
        LL ans = 0;
        //从幂次序列尾部一个一个减
        for(int i=exp.size()-1; i>=0; i--) {
            if(exp[i] <= a) {
                a -= exp[i];
                ans += 1LL<<i; //防止极端情况下(INT_MIN / 1)i为31然后溢出
            }
        }
        if(is_minus) {
            ans = -1*ans;
        }
        if(ans > INT_MAX || ans <INT_MIN) {
            return INT_MAX;
        }
        return ans;
    }
};

/*作者：lxc656-z
链接：https://leetcode.cn/problems/divide-two-integers/solution/liao-e-tou-cou-de-9-by-lxc656-z-rl62/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。*/