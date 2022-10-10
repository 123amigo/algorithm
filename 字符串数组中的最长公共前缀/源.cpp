/*
编写一个函数来查找字符串数组中的最长公共前缀。
如果不存在公共前缀，返回空字符串 ""。
示例 1：

输入：strs = ["flower","flow","flight"]
输出："fl"
示例 2：

输入：strs = ["dog","racecar","car"]
输出：""
解释：输入不存在公共前缀。
*/
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans;
        for (int i = 0; i < strs[0].size(); i++) {
            ans.push_back(strs[0][i]);
            for (int j = 0; j < strs.size(); j++) {
                if (strs[j][i] != ans.back()) {
                    ans.pop_back();
                    return ans;
                }
            }
        }
        return ans;
    }
};
int main() {
    Solution S;
    vector <string> strs = { "flower", "flow", "flight" };
    string ans = S.longestCommonPrefix(strs);
    cout <<"longestCommonPrefix: "<< ans << endl;
}