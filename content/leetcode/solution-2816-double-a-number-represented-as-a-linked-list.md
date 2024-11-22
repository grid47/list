
+++
authors = ["grid47"]
title = "Leetcode 2816: Double a Number Represented as a Linked List"
date = "2024-01-30"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2816: Double a Number Represented as a Linked List in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Linked List","Math","Stack"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "UmqNCKUeIy4"
youtube_upload_date="2023-08-13"
youtube_thumbnail="https://i.ytimg.com/vi/UmqNCKUeIy4/maxresdefault.jpg"
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
    int pin(ListNode* head) {
        if(head == NULL) return 0;
        int val = pin(head->next);
        int num = head->val;
        num = num * 2 + val;
        head->val = num % 10;
        return num/10;
    }

    ListNode* doubleIt(ListNode* head) {
        int num = pin(head);
        while(num > 0) {
            int c = num % 10;
            num /= 10;
            ListNode* node = new ListNode(c);
            node->next = head;
            head = node;
        }
        return head;
    }
};
{{< /highlight >}}
---

### Problem Statement

In this problem, you are tasked with doubling a given number represented by a singly linked list. Each node of the linked list contains a single digit, and the number is stored in reverse order, i.e., the head node contains the least significant digit. The goal is to return a new linked list that represents the doubled value of the original number.

For example, if the input linked list represents the number `123`, the list will be:
```
3 -> 2 -> 1
```
After doubling the number, the output linked list should represent `246`:
```
6 -> 4 -> 2
```

### Approach

To solve this problem, the general approach is to perform the following steps:

1. **Reverse the Linked List and Compute the Number**: First, we need to traverse the linked list and treat it as a number in reverse order. Starting from the head node, we extract the digits, double the number, and update each digit of the linked list.

2. **Handle Carrying Over**: Doubling the number may result in digits that exceed `9`, which will require handling the carry (just like in basic addition). We need to store the current digit modulo 10 in the node and carry over the quotient to the next iteration.

3. **Rebuild the Linked List**: Once the linked list has been updated with the doubled digits and carries, the final step is to rebuild the number by moving through the list and inserting new nodes if there's any leftover carry after processing all nodes.

4. **Edge Case Handling**: If the linked list is empty or contains only `0`, the result should simply be a list with the digit `0`.

### Code Breakdown (Step by Step)

The code is broken into two main functions: `pin` (helper function to recursively traverse and double the number) and `doubleIt` (main function to handle the entire process). Let’s walk through these steps:

#### 1. **The `pin` Function (Recursion to Compute the Number and Carry)**

The helper function `pin` is designed to traverse the list recursively and compute the doubled number along with any carry.

```cpp
int pin(ListNode* head) {
    if(head == NULL) return 0;
    int val = pin(head->next);
    int num = head->val;
    num = num * 2 + val;
    head->val = num % 10;
    return num / 10;
}
```

- **Base Case**: The function starts with checking if `head` is `NULL` (i.e., the end of the list). If it's `NULL`, it returns `0` because there are no more digits to process.
  
- **Recursive Call**: For each node, the function recursively processes the next node (`pin(head->next)`), which gives the carry from the next node.

- **Doubling and Carrying**: The value of the current node (`head->val`) is doubled, and the carry from the next digit (`val`) is added to it. The result (`num`) is then split into two parts:
  - The new digit is stored in the current node (`head->val = num % 10`).
  - The carry (`num / 10`) is returned to the previous node.

#### 2. **The `doubleIt` Function (Main Function to Build the Resulting Linked List)**

The main function `doubleIt` utilizes the helper function `pin` to first double the entire number, then handles any leftover carry.

```cpp
ListNode* doubleIt(ListNode* head) {
    int num = pin(head); // Step 1: Call pin to recursively process the list
    while(num > 0) { // Step 2: Handle any leftover carry
        int c = num % 10;
        num /= 10;
        ListNode* node = new ListNode(c); // Step 3: Create new nodes for carry
        node->next = head; // Step 4: Insert the new node at the front
        head = node; // Step 5: Update the head of the list
    }
    return head; // Step 6: Return the modified list
}
```

- **Step 1 (Call `pin`)**: First, the function calls the `pin` function, which will update the original list by recursively processing each node and calculating the new digit and carry. The final return value of `pin` represents the carry from the most significant digit.

- **Step 2 (Handle Carry)**: After the list has been processed, if there’s any leftover carry (`num > 0`), it is added to the list. We use the modulus operation to extract the current carry digit and the division operation to reduce the carry.

- **Step 3 (Create New Node)**: For every carry, we create a new node with the carry value as the node’s value.

- **Step 4 (Insert at Front)**: The new node is inserted at the front of the list, so the final result will have the most significant digit at the head of the list.

- **Step 5 (Update Head)**: The `head` pointer is updated to point to the newly created node, making it the new head of the list.

- **Step 6 (Return the Result)**: After processing all the carries, the modified list (which now represents the doubled number) is returned.

### Complexity

1. **Time Complexity**:
   - The `pin` function processes each node in the linked list exactly once. Thus, the time complexity for this function is **O(n)**, where `n` is the number of nodes in the list.
   - The `doubleIt` function involves iterating through the list once to call `pin`, followed by another iteration to handle any leftover carry. Therefore, the total time complexity of the `doubleIt` function is also **O(n)**.
   
   Overall, the time complexity is **O(n)**, where `n` is the number of nodes in the linked list.

2. **Space Complexity**:
   - The space complexity is **O(1)**, as the algorithm uses only a constant amount of extra space. The recursive call stack in the `pin` function takes up space proportional to the depth of the list (i.e., **O(n)**), but the rest of the algorithm uses a fixed amount of space. However, in practice, recursion can lead to a space complexity of **O(n)** in terms of stack space.
   
   Thus, the space complexity is **O(n)** due to the recursion stack.

### Conclusion

The `doubleIt` function is an efficient solution to doubling a number represented by a singly linked list. By recursively processing the list and handling carries during the doubling process, the algorithm updates the list in place. The function's time complexity is linear in terms of the number of nodes, making it optimal for large linked lists. The space complexity is also linear due to the recursion stack, but the algorithm avoids using extra data structures. This solution provides a clear, concise, and efficient way to tackle the problem of doubling a number in linked list form.

[`Link to LeetCode Lab`](https://leetcode.com/problems/double-a-number-represented-as-a-linked-list/description/)

---
{{< youtube UmqNCKUeIy4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
