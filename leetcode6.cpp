/*
这是一个找规律的题，
Z字形变换后得到的字符矩阵的第一行是一个公差为(2n-2)的等差数列，
此处的等差数列是说第一行的字符在原始字符串中的index是一个等差数列的关系
最后一行也是一个公差为(2n-2)的等差数列
除了第一行和最后一行，其他的行可以拆分成两个等差数列，这两个等差数列的公差也是(2n-2)
这两个数列分别由位于Z字形的竖线和斜线上的字符所构成，for exmaple，如下图所示：
a     g     n
b   f h    m
c-e---i---l---------- 这一行上的c,i,...这些属于竖线上的元素构成的等差数列，
d     j k             e,l,...这些属于斜线上的元素构成的等差数列
无论是斜线上的数构成的等差数列还是竖线上的数构成的等差数列，它们的公差都是(2n-2)
并且可以发现，第i行的斜线上的元素构成的等差数列的首项所对应的index是(2n-2-i)
*/
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) {
            return s;
        }
        string ans;
        for(int line_count = 0; line_count<numRows; line_count++) {
            if(line_count == 0 || line_count == numRows-1) {
                for(int i = line_count; i<s.size(); i+=2*numRows-2) {
                    ans+=s[i];
                }
            } else {
                for(int i=line_count, j=2*numRows-2-line_count; ; i+=numRows*2-2, j+=numRows*2-2) {
                    if(i<s.size()) {
                        ans+=s[i];
                    }
                    if(j<s.size()) {
                        ans+=s[j];
                    }
                    if(i>=s.size() && j>=s.size()) {
                        break;
                    }
                }
            }
        }
        return ans;
    }
};