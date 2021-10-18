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
    bool isPalindrome(ListNode* head) {
        string word = "";
        while(head != NULL) {
            word += head->val;
            head = head->next;
        }
        
        bool res = true;
        for(int i = 0; i < word.length()/2; i++) {
            if(word[i] != word[word.length()-1-i]) {
                res = false;
                break;
            }
        }
        
        return res;
    }
};