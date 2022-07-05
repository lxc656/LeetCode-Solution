class Solution {
public:
    vector<string> ans;
    vector<string> restoreIpAddresses(string s) {
        dfs(s, 0, 0, "");
        return ans;
    }
    /*
    参数说明：
    cnt代表着已经插入了几个“.“，index代表着现在走到了字符串哪个位置
    path是现在为止复原出来的IP地址
    */
    void dfs(string& s, int cnt, int index, string path) {
        //设置边界条件
        if(cnt == 4 && index == s.size()) {
            path.pop_back();
            ans.push_back(path);
            return;
        }
        if(cnt == 4) {
            return;
        }
        //number是接下来要往IP地址里插入的数据
        int number = 0;
        for(int i = index; i<s.size(); i++) {
            if(i>index && s[index] == '0') {
                return;
            }
            number = number*10 + (s[i]-'0');
            if(number > 255) {
                break;
            } else {
                dfs(s, cnt+1, i+1, path+to_string(number)+'.');                
            }
        }
    }
};