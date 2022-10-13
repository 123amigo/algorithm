/*
有一个单链表的 head，我们想删除它其中的一个节点 node。

给你一个需要删除的节点 node 。你将 无法访问 第一个节点  head。

链表的所有值都是 唯一的，并且保证给定的节点 node 不是链表中的最后一个节点。

删除给定的节点。注意，删除节点并不是指从内存中删除它。这里的意思是：

给定节点的值不应该存在于链表中。
链表中的节点数应该减少 1。
node 前面的所有值顺序相同。
node 后面的所有值顺序相同。

输入：head = [4,5,1,9], node = 5
输出：[4,1,9]
解释：指定链表中值为 5 的第二个节点，那么在调用了你的函数之后，该链表应变为 4 -> 1 -> 9

提示：

链表中节点的数目范围是 [2, 1000]
-1000 <= Node.val <= 1000
链表中每个节点的值都是 唯一 的
需要删除的节点 node 是 链表中的节点 ，且 不是末尾节点

*/
#include <iostream>
#include <vector>
#include <assert.h>
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(NULL) {}
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
class Solution {
public:

    //创建长度为len的单向链表
    void createList(ListNode* head, int len) {
        for (int i = 1; i < len; i++)   //len-1个节点，加上head节点共len个
        {
            ListNode* node = new ListNode;   //每次都需要实例化一个ListNode
            node->val = i * i;    //为节点赋值
            node->next = nullptr;
            head->next = node;   //head指向下一个节点（即当前节点）
            head = node;     //将当前节点设为head
        }
        cout << "Create a new ListNode with len of " << len << " successfully." << endl;
    }

    //打印链表(顺序)
    void printList(ListNode* head) {
        if (head == nullptr)
            cout << "empty list." << endl;
        else
            while (head != nullptr)
            {
                cout << head->val << '\t';
                head = head->next;
            }
        cout << endl;
    }

    //打印链表（逆序）
    void reversePrintList(ListNode* head) {
        //因为ListNode只能根据next单向索引，无法逆向回溯，所以只能将节点数值存在vector中反向输出。
        //目前只想到了这种方法。
        if (head == nullptr)
        {
            cout << "empty list." << endl;
            exit(1);
        }
        else
        {
            vector<int> node;
            while (head != nullptr)
            {
                node.push_back(head->val);
                head = head->next;
            }
            while (!node.empty())
            {
                //先输出node中的最后一个元素，再删除最后一个元素。而不是先对node做reverse再正向输出。
                cout << node.back() << '\t';
                node.pop_back();
            }
            cout << endl;
        }
    }

    //在链表尾节点添加一个新节点
    void pushBack(ListNode* head, int val) {
        ListNode* node = new ListNode(val, nullptr);   //要添加的新节点
        if (head == nullptr)
            head = node;
        else
        {
            while (head->next != nullptr)    //while循环结束后head就是尾结点了
                head = head->next;
            head->next = node;
        }
    }

    //更改链表尾节点数值
    void changeBackValue(ListNode* head, int val) {
        assert(head != nullptr);
        while (head->next != nullptr)    //while循环结束后head就是尾结点了
            head = head->next;
        head->val = val;
    }

    //删除链表尾节点
    void popBack(ListNode* head) {
        assert(head != nullptr);
        while (head->next->next != nullptr)   //while循环结束后head是倒数第二个节点，其next指向尾节点
            head = head->next;
        head->next = nullptr;   //删除尾节点
        //注意不要直接delete尾结点，因为尾结点的next是nullptr，直接delete nullptr会输出很多乱码。
    }

   /*
   void deleteNode(ListNode* node) {
        ListNode* tmp = node;
        tmp = tmp->next;
        node->val = tmp->val;
        node->next = tmp->next;
        free(&tmp);
    }
   */ 

    //删除链表中节点值等于指定值的节点（不包括头节点）
    void deleteNode(ListNode* head, int val) {
        assert(head != nullptr);
        ListNode* node = head;    //copy一份链表
        while (head->next != nullptr)
        {
            if (head->next->val == val)
                node->next = head->next->next;
            head = head->next;
            node = node->next;
        }
    }
};
int main() {
    Solution solution;
    ListNode* listnode = new ListNode(5, nullptr);
    solution.createList(listnode, 5);
    solution.printList(listnode);
    solution.deleteNode(listnode, 1);
    solution.printList(listnode);
    
    
    
    return 0;

}