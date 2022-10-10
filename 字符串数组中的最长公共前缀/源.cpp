/*
��дһ�������������ַ��������е������ǰ׺��
��������ڹ���ǰ׺�����ؿ��ַ��� ""��
ʾ�� 1��

���룺strs = ["flower","flow","flight"]
�����"fl"
ʾ�� 2��

���룺strs = ["dog","racecar","car"]
�����""
���ͣ����벻���ڹ���ǰ׺��
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