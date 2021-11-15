/**************************************************************************************** 
* 
* Remove Duplicates from Sorted List
*
* Given the head of a sorted linked list, delete all duplicates such that each element appears only once. 
* Return the linked list sorted as well.
*
* Link: https://leetcode.com/problems/remove-duplicates-from-sorted-list/
*
* Input: 
* head = [1,1,2,3,3]
* 
* Output: 
* [1,2,3]
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
 
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* current = head;
        
        while(current != NULL and current->next != NULL){
            if(current->val == current->next->val){
                current->next = current->next->next;
            }
            else{
                current = current->next;
            }
        }
        return head;
    }
};
*/
