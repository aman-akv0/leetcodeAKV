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
class Solution {
public:
    int count(ListNode *head){
        int c=0;
        while(head!=NULL){
            c++;
            head=head->next;
        }return c;
    }
    ListNode* middleNode(ListNode* head) {
        int res= count(head)/2;
        int kaunt=0;
        ListNode *temp = head;
        while(kaunt<res){
            kaunt++;
            temp=temp->next;
        }return temp;
    }
};
