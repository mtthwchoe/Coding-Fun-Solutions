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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* original1 = list1;
        ListNode* original2 = list2;
        if(list1 == nullptr && list2 != nullptr) {
            return(list2);
        }
        if(list2 == nullptr && list1 != nullptr) {
            return(list1);
        }
        while(list2 != nullptr) {
            if((list1->val) < (list2->val)) {
                if(list1->next == nullptr) {
                    list1->next = list2;
                    list2 = nullptr;
                }
                else if(list2->val > list1->next->val) {
                    ListNode * org = list1;

                    while((list2->val) > (list1->next->val)) {
                        if(list1->next == nullptr) {
                            list1->next = list2;
                            list2 = nullptr;
                            return(org);
                        }
                        list1 = list1->next;

                        if(list1->next == nullptr) {
                            list1->next = list2;
                            list2 = nullptr;
                            return(org);
                        }
                    }
                    ListNode * q = list1->next;
                    ListNode * r = list2;
                    list2 = list2->next;
                    list1->next = r;
                    r->next = q;
                    list1 = org;
                    original1 = org;
                }
                else {
                    ListNode* spliced = list2;
                    list2 = list2->next;
                    
                    ListNode* next = list1->next;
                    list1->next = spliced;
                    spliced->next = next;
                    original1 = list1;
                }
            }
            else if(list1->val > list2->val) {
                if(list2->next == nullptr) {
                    list2->next = list1;
                    original1 = list2;
                    list2 = nullptr;
                    return(original1);
                }
                ListNode * t = list2;
                list2 = list2->next;
                t->next = list1;
                list1 = t;

            }
            else if(list1->val == list2->val) {
                ListNode * temp = list2;
                list2 = list2->next;
                ListNode * temp2 = list1->next;
                list1->next = temp;
                temp->next = temp2;
            }
        }
        return(original1);
    }
};