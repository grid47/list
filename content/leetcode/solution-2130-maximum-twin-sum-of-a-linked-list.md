
+++
authors = ["grid47"]
title = "Leetcode 2130: Maximum Twin Sum of a Linked List"
date = "2024-04-08"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2130: Maximum Twin Sum of a Linked List in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Linked List","Two Pointers","Stack"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "FnKG0uH2PVc"
youtube_upload_date="2023-05-18"
youtube_thumbnail="https://i.ytimg.com/vi/FnKG0uH2PVc/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
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
    int pairSum(ListNode* head) {
        
        ListNode* slow = head, *fast = head;
        while(slow && fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        /*
        
        if its a even chain fast pointer will go out of index
        slow will reach at second of middle elements or first of second half of the chain
        
        */
        
        ListNode *cur = slow, *prv = NULL, *nxt;
        
        while(cur) {
            nxt = cur->next;
            cur->next = prv;
            prv = cur;
            cur = nxt;
        }
        
        int res = 0;
        while(prv) {
            res = max(res, head->val + prv->val);
            head = head->next;
            prv = prv->next;
        }
        return res;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem requires us to find the maximum twin sum of a linked list. A twin sum is defined as the sum of pairs of nodes from the front and back of the list. Given a singly linked list, we need to calculate the twin sums formed by taking the first element with the last, the second with the second last, and so on. The objective is to return the maximum twin sum from these pairs.

### Approach

To tackle this problem, we can utilize a two-pointer technique along with reversing the second half of the linked list. The steps are as follows:

1. **Find the Middle of the Linked List**: Use the slow and fast pointer technique to locate the midpoint of the list.
2. **Reverse the Second Half**: Once the midpoint is identified, reverse the second half of the linked list.
3. **Calculate Maximum Twin Sum**: Traverse through the original first half and the reversed second half simultaneously, computing the twin sums and tracking the maximum sum encountered.

This approach ensures we traverse the linked list a minimal number of times, maintaining efficiency.

### Code Breakdown (Step by Step)

Here's a detailed breakdown of the implementation:

1. **ListNode Definition**:
   ```cpp
   struct ListNode {
       int val;
       ListNode *next;
       ListNode() : val(0), next(nullptr) {}
       ListNode(int x) : val(x), next(nullptr) {}
       ListNode(int x, ListNode *next) : val(x), next(next) {}
   };
   ```
   - This struct defines a node in a singly linked list, which contains an integer value `val` and a pointer to the next node `next`.

2. **Class Declaration**:
   ```cpp
   class Solution {
   public:
   ```
   - The `Solution` class is defined, encapsulating the method that will solve the problem.

3. **Function Definition**:
   ```cpp
   int pairSum(ListNode* head) {
   ```
   - The public member function `pairSum` takes a pointer to the head of the linked list and will return the maximum twin sum as an integer.

4. **Finding the Middle of the Linked List**:
   ```cpp
   ListNode* slow = head, *fast = head;
   while(slow && fast && fast->next) {
       slow = slow->next;
       fast = fast->next->next;
   }
   ```
   - Two pointers, `slow` and `fast`, are initialized at the head of the list. The `slow` pointer moves one step at a time, while the `fast` pointer moves two steps. This loop continues until the `fast` pointer cannot advance two steps (indicating the end of the list). When this happens, `slow` will be at the midpoint of the list.

5. **Reversing the Second Half of the List**:
   ```cpp
   ListNode *cur = slow, *prv = NULL, *nxt;
   while(cur) {
       nxt = cur->next;
       cur->next = prv;
       prv = cur;
       cur = nxt;
   }
   ```
   - We initialize `cur` to the `slow` pointer (midpoint) and `prv` to `NULL`. We then reverse the linked list by adjusting the `next` pointers of each node until we reach the end of the list. The `prv` pointer will ultimately point to the new head of the reversed second half of the list.

6. **Calculating the Maximum Twin Sum**:
   ```cpp
   int res = 0;
   while(prv) {
       res = max(res, head->val + prv->val);
       head = head->next;
       prv = prv->next;
   }
   return res;
   ```
   - We initialize `res` to store the maximum twin sum. In a loop, we calculate the twin sums by adding the values of the nodes pointed to by `head` (first half) and `prv` (reversed second half). We continue until `prv` reaches the end of the list, updating `res` with the maximum sum found.

7. **End of Class**:
   ```cpp
   };
   ```
   - This curly brace marks the end of the `Solution` class definition.

### Complexity Analysis

- **Time Complexity**: \(O(n)\)
  - The time complexity is \(O(n)\) because we traverse the linked list three times: once to find the middle, once to reverse the second half, and once to compute the maximum twin sum.

- **Space Complexity**: \(O(1)\)
  - The space complexity is \(O(1)\) as we are not using any additional data structures that grow with input size. We only use a constant amount of extra space for pointers.

### Conclusion

The `pairSum` function effectively calculates the maximum twin sum of a linked list using an efficient approach that combines the two-pointer technique with in-place list reversal. By minimizing the number of traversals, the algorithm achieves optimal time complexity while maintaining constant space usage.

This method is robust and works effectively for a variety of input cases, including even and odd-length linked lists. The elegant use of linked list manipulations showcases the power of understanding data structures in solving complex problems efficiently.

In summary, this solution exemplifies how to tackle linked list challenges with clarity and efficiency, making it a useful reference for similar problems in algorithm design and implementation. The overall design is both effective and efficient, ensuring that the maximum twin sum is found with minimal computational overhead.

[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/description/)

---
{{< youtube FnKG0uH2PVc >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
