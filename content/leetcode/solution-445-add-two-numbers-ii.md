
+++
authors = ["grid47"]
title = "Leetcode 445: Add Two Numbers II"
date = "2024-09-23"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 445: Add Two Numbers II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Linked List","Math","Stack"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/445.webp"
youtube = "ovGnWmf2sew"
youtube_upload_date="2021-04-14"
youtube_thumbnail="https://i.ytimg.com/vi/ovGnWmf2sew/maxresdefault.jpg"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/445.webp" 
    alt="Two linked lists gently adding their digits, with each addition softly illuminated as it occurs."
    caption="Solution to LeetCode 445: Add Two Numbers II Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;
        
        while(l1) {
            s1.push(l1->val);
            l1 = l1->next;
        }
        
        while(l2) {
            s2.push(l2->val);
            l2 = l2->next;
        }
        
        int cry = 0;
        
        ListNode* node = NULL, *prv = NULL;
        
        while(!s1.empty() || !s2.empty()) {
            
            if(!s1.empty()) {
                cry += s1.top();
                s1.pop();
            }

            if(!s2.empty()) {
                cry += s2.top();
                s2.pop();
            }
            
            node = new ListNode(cry % 10);
            node->next = prv;
            
            prv = node;
            cry /= 10;
            
        }
        
        if(cry != 0) {
            node = new ListNode(cry %10);
            node->next = prv;
            
        }
        
        return node;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem asks us to add two numbers that are represented as linked lists. Each node in the linked list represents a single digit of the number, where the digits are stored in reverse order (i.e., the least significant digit comes first). The goal is to add these two numbers and return the sum, also represented as a linked list in reverse order.

For example:
- Input: `l1 = [2,4,3]`, `l2 = [5,6,4]`
- Output: `[7,0,8]`
  
This is because the numbers represented are `342` and `465`, and their sum is `807`, which is stored in reverse order.

### Approach

To solve this problem, we can follow the following steps:

1. **Use Stacks to Reverse the Linked Lists**:
   - Since the digits are stored in reverse order in the input lists, it makes sense to push each digit onto a stack. The stack allows us to pop the digits in reverse order, so we can simulate adding the numbers from the least significant digit to the most significant digit.

2. **Add the Two Numbers Digit by Digit**:
   - While there are digits left in either of the input lists, we pop the digits from the stacks, add them, and keep track of any carry from the addition.
   - If the sum of the digits exceeds 9, we set a carry for the next addition.

3. **Handle Carry**:
   - After adding all digits, if there is any remaining carry (i.e., the sum of the last digits is greater than 9), we need to create a new node with the carry as the value.

4. **Construct the Result Linked List**:
   - Since we need to return the result in reverse order, we can maintain a linked list that is built from the last digit to the first. We start by creating new nodes and linking them together.

### Code Breakdown (Step by Step)

#### Step 1: Push Digits to Stacks
```cpp
stack<int> s1, s2;
while(l1) {
    s1.push(l1->val);
    l1 = l1->next;
}
while(l2) {
    s2.push(l2->val);
    l2 = l2->next;
}
```
- First, we initialize two stacks `s1` and `s2` to store the digits of `l1` and `l2` respectively.
- We iterate over the linked lists `l1` and `l2`, pushing the values of each node onto the respective stack until we reach the end of both lists.

#### Step 2: Add Digits with Carry
```cpp
int cry = 0;
ListNode* node = NULL, *prv = NULL;
while(!s1.empty() || !s2.empty()) {
    if(!s1.empty()) {
        cry += s1.top();
        s1.pop();
    }
    if(!s2.empty()) {
        cry += s2.top();
        s2.pop();
    }
    node = new ListNode(cry % 10);
    node->next = prv;
    prv = node;
    cry /= 10;
}
```
- We initialize a variable `cry` to keep track of the carry, and pointers `node` and `prv` to build the new linked list.
- We enter a loop that continues until both stacks are empty.
  - Inside the loop, we check if the stacks `s1` and `s2` are non-empty. If they are, we pop the top element from each stack and add it to `cry`.
  - We create a new node with the value `cry % 10` (the digit part of the sum) and update the `next` pointer of this new node to point to the previously created node (to reverse the order).
  - After that, we update the carry (`cry`) to be the integer division of `cry` by 10, so we can carry over the value if the sum of digits was greater than 9.

#### Step 3: Handle Remaining Carry
```cpp
if(cry != 0) {
    node = new ListNode(cry % 10);
    node->next = prv;
}
```
- After the loop ends, if there is any leftover carry (`cry != 0`), we create a new node for it and link it to the result list.

#### Step 4: Return the Result
```cpp
return node;
```
- Finally, we return the head of the newly created linked list, which holds the sum of the two numbers.

### Complexity

#### Time Complexity:
- **Pushing digits to stacks**: We iterate through the entire length of both input lists (`l1` and `l2`), which takes `O(n + m)` time where `n` is the length of `l1` and `m` is the length of `l2`.
- **Adding digits**: In the second loop, we process the digits from the stacks and add them. Since we process each digit once, this also takes `O(n + m)` time.
- **Overall Time Complexity**: The time complexity is `O(n + m)`, where `n` and `m` are the lengths of the two input lists.

#### Space Complexity:
- We use two stacks to hold the digits of the input linked lists, which each take `O(n)` and `O(m)` space respectively.
- Additionally, we create a new linked list to hold the result, which takes `O(n + m)` space.
- **Overall Space Complexity**: The space complexity is `O(n + m)` due to the use of the stacks and the result list.

### Conclusion

This approach solves the problem efficiently by:
- Reversing the linked lists using stacks.
- Adding the digits from the least significant to the most significant, while handling carries.
- Constructing the result linked list in the correct order by using a simple iterative process.

The algorithm is optimal with a time complexity of `O(n + m)` and space complexity of `O(n + m)`, making it suitable for large input sizes. The solution is simple, easy to understand, and leverages stack operations to reverse the digit order and handle carries effectively.

[`Link to LeetCode Lab`](https://leetcode.com/problems/add-two-numbers-ii/description/)

---
{{< youtube ovGnWmf2sew >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
