
/**************************************************************************************** 
* 
* Merge Two sorted list
*
* Merge two sorted linked lists and return it as a sorted list. 
* The list should be made by splicing together the nodes of the first two lists.
*
* Link: https://leetcode.com/problems/merge-two-sorted-lists/
* 
* Input: 
* l1 = [1,2,4], 
* l2 = [1,3,4]
* 
* Output: 
* [1,1,2,3,4,4]
*
****************************************************************************************/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 *

//Code Starts from here
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL){
            return l2;              
        }
        if(l2 == NULL){
            return l1;
        }
        
        ListNode* list;
        if(l1->val < l2->val){
            list = l1;
            list->next = mergeTwoLists(l1->next, l2);
        }
        else{
            list = l2;
            list->next = mergeTwoLists(l1, l2->next);
        }

        return list;
    }
};

*/