/*
给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。

示例 1：
输入：head = [1,2,3,4,5]
输出：[5,4,3,2,1]

示例 2：
输入：head = [1,2]
输出：[2,1]

示例 3：
输入：head = []
输出：[]
 
提示：
链表中节点的数目范围是 [0, 5000]
-5000 <= Node.val <= 5000

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
/*
使用栈来进行反转
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
#include <stack>
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        stack <ListNode*> stackLN;
        ListNode* p = head;
        while (p != nullptr) {
            stackLN.push(p);
            p = p->next;
        }
        if (stackLN.empty()) {
            return NULL;
        }
        ListNode* temp = stackLN.top();
        head = temp;
        stackLN.pop();
        while (!stackLN.empty()) {
            temp->next = stackLN.top();
            temp = temp->next;
            stackLN.pop();
        }
        temp->next = NULL;
        return head;

    }
};