/*给你一个单链表的头节点 head ，请你判断该链表是否为回文链表。如果是，返回 true ；否则，返回 false 。

示例 1：
输入：head = [1, 2, 2, 1]
输出：true
示例 2：
输入：head = [1, 2]
输出：false

提示：
链表中节点数目在范围[1, 105] 内
0 <= Node.val <= 9
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include <iostream>
#include <vector>
#include <assert.h>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution1 {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        //通过快慢指针找到中点
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        //如果fast不为空，则链表的长度是奇数个。
        if (fast != nullptr) {
            slow = slow->next;
        }
        //反转后半部分链表
        slow = reverse(slow);
        fast = head;
        while (slow != nullptr) {
            if (fast->val != slow->val) {
                return false;
            }
            slow = slow->next;
            fast = fast->next;
        }
        return true;
    }
private:
    ListNode* reverse(ListNode* head) {
        ListNode* pre = nullptr;
        ListNode* cur = head;
        while (cur != nullptr) {
            ListNode* temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        return pre;
    }

};
#include <stack>
class Solution2 {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* temp = head;
        ListNode* tp;
        stack <ListNode*> stackLN;
        while (temp != nullptr) {
            stackLN.push(temp);
            temp = temp->next;
        }
        while (head != nullptr) {
            tp = stackLN.top();
            stackLN.pop();
            if (head->val != tp->val)
                return false;
            head = head->next;
        }
        return true;
    }
};