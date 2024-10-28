
class Solution {
public:
    TreeNode* toBST(ListNode* start, ListNode* end) {

        if(start == end) return NULL;

        ListNode* slw = start;
        ListNode* fst = start;

        while(fst != end && fst->next != end) {
            slw = slw->next;
            fst = fst->next->next;
        }

        TreeNode* node = new TreeNode(slw->val);
        node->left = toBST(start, slw);
        node->right = toBST(slw->next, end);
        return node;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        if(head == NULL) return NULL;
        return toBST(head, NULL);
    }
};