没想到LeetCode和Lisp还能梦幻联动（

lc26和lc736的解法很类似，因此先介绍LC726的解法，然后介绍LC736的解法

## LeetCode 726

[题目链接](https://leetcode.cn/problems/number-of-atoms/)

采用递归来解决，遇到括号就递归地求出括号内部所有的原子的数量，然后再将这些原子的数量依次乘以括号外面的倍数。使用`map`这种数据结构来存储每个元素的原子个数（`map`和`unordered_map`的主要区别在于`map`可以按照插入的Key的顺序输出KV，因为它底层是通过红黑树来实现的，题目中要求以字典序输出，因此用`map`来存储）

```cpp
class Solution {
public:
    map<string, int> recursive_parse(string& formula, int& index) {
        map<string, int> atom_cnt;
        while(index < formula.size()) {
            if(formula[index] == '(') {
                index++;
                map<string, int> sub_cnt = recursive_parse(formula, index);
                index++;
                int tmp = index;
                while(isdigit(formula[index])) {
                    index++;
                }
                if(index > tmp) {
                    int cnt = stoi(formula.substr(tmp, index-tmp));
                    for(auto [x, y]:sub_cnt) {
                        atom_cnt[x] += cnt * y;
                    }
                }
                else {
                    for(auto [x, y]:sub_cnt) {
                        atom_cnt[x] += y;
                    }
                }
            }
            else if(formula[index] == ')') {
                break;
            }
            else {
                int tmp = index;
                index++;
                while(formula[index] >= 'a' && formula[index] <= 'z') {
                    index++;
                }
                string atom_name = formula.substr(tmp, index-tmp);
                tmp = index;
                while(isdigit(formula[index])) {
                    index++;
                }
                if(index > tmp) {
                    int cnt = stoi(formula.substr(tmp, index-tmp));
                    atom_cnt[atom_name]+=cnt;
                }
                else {
                    atom_cnt[atom_name]+=1;
                }
            }
        }
        return atom_cnt;
    }
    string countOfAtoms(string formula) {
        int index = 0;
        map<string, int> atom_count = recursive_parse(formula, index);
        string ans;
        for(auto[x, y] : atom_count) {
            ans += x;
            if(y>1) {
                ans += to_string(y);            
            }
        }
        return ans;
    }
};
```



## LeetCode736

[题目链接](https://leetcode.cn/problems/parse-lisp-expression/)



Reference:

www.acwing.com