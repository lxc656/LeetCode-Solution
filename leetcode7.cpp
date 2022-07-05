//因为负数取模的结果也是负数，所以这个算法对负数同样适用
class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        while(x) {
            if(x>0 && ans > (INT_MAX-x%10)/10) {
                return 0;
            }
            if(x<0 && ans < (INT_MIN-x%10)/10) {
                return 0;
            }
            ans = ans*10 + x%10;
            x = x/10;
        }
        return ans;
    }
};
/*
int32溢出检测的实现方法：
- 当发生正溢出时，10*r+x%10 > INT_MAX，但左边的数值因为溢出了所以无法用int32正确表示
那么可以转化成：10*r > INT_MAX - x%10，
则有：r > (INT_MAX-x%10)/10，这样的话左侧和右侧都不会溢出
- 发生负溢出时，同理，有：
10*r+x < INT_MIN
则有：r < (INT_MIN-x)/10，同样，两边都不会溢出
*/