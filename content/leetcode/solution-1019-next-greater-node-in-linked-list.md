
+++
authors = ["grid47"]
title = "Leetcode 1019: Next Greater Node In Linked List"
date = "2024-07-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1019: Next Greater Node In Linked List in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Linked List","Stack","Monotonic Stack"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> stk, res;
        
        for(ListNode* node = head; node != NULL; node = node->next) {
            
            while(!stk.empty() && res[stk.back()] < node->val) {
                res[stk.back()] = node->val;
                stk.pop_back();
            }

            
            stk.push_back(res.size());
            res.push_back(node->val);
        }
        
        for(int i : stk) res[i] = 0;
        
        return res;
    }
};
{{< /highlight >}}
---


### Problem Statement
The task is to process a singly linked list and return an array where each element represents the next greater value for the corresponding node in the list. If no greater value exists for a node, the value should be `0`. For example, given the linked list represented as \( 2 \to 1 \to 5 \), the output should be \( [5, 5, 0] \), as the next greater values for the first and second nodes are \( 5 \), and there is no next greater value for the last node.

### Approach
To solve this problem, we can utilize a stack to efficiently track indices of the nodes whose next larger values we have not yet found. The main idea is to iterate through the list while maintaining a stack of indices for which we have yet to determine the next larger value:
1. **Iteration through the List**: Traverse the linked list node by node.
2. **Using a Stack**: For each node, check if the current node's value is greater than the values at the indices stored in the stack. If it is, it means we have found the next larger value for those indices.
3. **Updating Results**: If a larger value is found, update the corresponding index in the results array.
4. **Default Value**: After processing all nodes, any indices remaining in the stack will have no next larger value, so they will be set to \( 0 \).

### Code Breakdown (Step by Step)

1. **Function Declaration**:
   - The function `nextLargerNodes` is defined as a public member of the `Solution` class, taking a pointer to the head of a linked list as an input parameter.

2. **Variable Initialization**:
   - Two vectors are declared: `stk` for storing indices and `res` for storing the values from the linked list along with their next larger values.

3. **Iterating Through the Linked List**:
   - A `for` loop is used to iterate through each node in the linked list. The loop continues until `node` is not `NULL`.
   - Inside the loop, a `while` loop checks whether there are any indices in `stk` and whether the value at those indices in `res` is less than the current node's value (`node->val`).

4. **Finding Next Larger Values**:
   - If the current node’s value is greater, it means we have found the next larger node for the index at the top of the stack (`stk.back()`), so we update `res[stk.back()]` to be the current node's value and then remove that index from the stack.

5. **Storing Current Node's Index**:
   - The index of the current node (the size of the `res` vector before the current push) is pushed onto the stack to keep track of it for future comparisons.
   - The current node’s value is then pushed into the `res` vector.

6. **Final Adjustments**:
   - After the loop, a final `for` loop iterates through any remaining indices in `stk`, setting the corresponding entries in `res` to \( 0 \), as these nodes have no next larger value.

7. **Return Statement**:
   - Finally, the function returns the `res` vector containing the next larger values for all nodes.

### Complexity Analysis
- **Time Complexity**: The time complexity of this algorithm is \( O(n) \), where \( n \) is the number of nodes in the linked list. Each node is processed once, and each index is pushed and popped from the stack at most once.
- **Space Complexity**: The space complexity is also \( O(n) \), which accounts for the storage of the results vector and the stack.

### Conclusion
The `nextLargerNodes` function provides an efficient way to find the next greater node for each node in a singly linked list. By employing a stack to keep track of indices for which we need to find the next greater value, the solution achieves optimal performance.

This approach highlights the usefulness of stacks in problems where we need to manage relationships between elements, particularly in linear structures such as linked lists. It also illustrates how to leverage data structures to maintain state across iterations, which is a valuable technique in algorithm design.

Overall, the solution demonstrates a clear and effective methodology for solving the next greater node problem, showcasing how to balance clarity and performance. It is an excellent example of how to tackle similar problems involving searching and comparing elements in sequences.

In summary, the `nextLargerNodes` function serves as a practical illustration of how to effectively utilize stacks to solve problems related to finding next greater elements in data structures. This technique is applicable to various scenarios, making it a valuable addition to any programmer’s toolkit. The combination of efficient time complexity and straightforward implementation ensures that this approach can be used confidently in coding interviews and real-world applications.


[`Link to LeetCode Lab`](https://leetcode.com/problems/next-greater-node-in-linked-list/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
