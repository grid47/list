
+++
authors = ["grid47"]
title = "Leetcode 725: Split Linked List in Parts"
date = "2024-08-26"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 725: Split Linked List in Parts in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Linked List"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/725.webp"
youtube = "ZITsHLE5mbE"
youtube_upload_date="2023-09-06"
youtube_thumbnail="https://i.ytimg.com/vi_webp/ZITsHLE5mbE/maxresdefault.webp"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/725.webp" 
    alt="A linked list being split into parts, with each split segment softly glowing as it’s separated."
    caption="Solution to LeetCode 725: Split Linked List in Parts Problem"
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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int len = 0;
        ListNode* temp = head;
        while(temp) {
            len++;
            temp = temp->next;
        }

        int numNodes = len/k;
        int ext = len % k;
        int i = 0;
        vector<ListNode*> res;
        temp = head;
        while(temp) {
            res.push_back(temp);
            int curLen = 1;
            while(curLen < numNodes) {
                temp =  temp->next;
                curLen++;
            }
            if(ext > 0 && len > k) {
                temp = temp->next;
                ext--;
            }
            ListNode* x = temp->next;
            temp->next = NULL;
            temp = x;
        }

        while(len < k) {
            res.push_back(NULL);
            len++;
        }
        return res;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem asks us to split a singly linked list into **k parts** of approximately equal size. If the list cannot be evenly divided, the extra nodes should be distributed across the first few parts. Each part should be represented by the head of a sublist, and if there are fewer nodes than parts, some parts should be `NULL`.

### Approach

To approach this problem, we need to break the linked list into **k parts**, while maintaining the size constraints. Specifically, we want to:

1. **Calculate the length of the list**: We need to determine how many nodes are in the linked list.
2. **Divide nodes into approximately equal parts**: If the total number of nodes is not divisible by `k`, then the first few parts will contain one extra node.
3. **Iterate through the list**: We can split the list by adjusting the `next` pointers and creating new heads for each part.
4. **Edge cases**: Handle cases where the list is shorter than `k` by returning `NULL` for the remaining parts.

### Code Breakdown (Step by Step)

Let's break down the code step by step to understand how it works:

#### Step 1: Calculate the length of the list

```cpp
int len = 0;
ListNode* temp = head;
while(temp) {
    len++;
    temp = temp->next;
}
```
- We initialize `len` to 0 to track the number of nodes in the linked list.
- We traverse the entire list, incrementing `len` with each node.
- After the loop finishes, `len` will hold the total number of nodes in the list.

#### Step 2: Determine the size of each part and the remainder

```cpp
int numNodes = len / k;
int ext = len % k;
```
- `numNodes`: This is the base number of nodes in each part, calculated by dividing the total length of the list by `k`.
- `ext`: This is the remainder when dividing the list length by `k`, indicating how many parts should contain one extra node. These extra nodes will be distributed across the first `ext` parts.

#### Step 3: Split the list into parts

```cpp
vector<ListNode*> res;
temp = head;
while(temp) {
    res.push_back(temp);
    int curLen = 1;
    while(curLen < numNodes) {
        temp =  temp->next;
        curLen++;
    }
    if(ext > 0 && len > k) {
        temp = temp->next;
        ext--;
    }
    ListNode* x = temp->next;
    temp->next = NULL;
    temp = x;
}
```
- **Initialize an empty vector `res`**: This will store the heads of the resulting sublists.
- **Iterate through the list**: We start at the head of the list and keep adding parts to `res`. In each iteration:
  - We push the current node (`temp`) to `res`.
  - We traverse `numNodes` nodes for the current part, and if the current part is one of the `ext` parts that needs one extra node, we handle that.
  - After reaching the last node of the current part, we set the `next` pointer to `NULL` to terminate the part.
  - We move `temp` to the next node in the list to start the next part.
  
#### Step 4: Handle the case where there are fewer nodes than parts

```cpp
while(len < k) {
    res.push_back(NULL);
    len++;
}
```
- If the list is shorter than `k`, we need to append `NULL` to the result vector to ensure that the final output has exactly `k` parts.

#### Step 5: Return the result

```cpp
return res;
```
- After splitting the list into parts, we return the vector `res`, which contains the heads of the sublists.

### Complexity Analysis

#### Time Complexity: **O(n)**

- We traverse the linked list twice: once to calculate its length and once to split it into parts. Each traversal takes O(n) time, where `n` is the number of nodes in the linked list.
- Other operations inside the loop (such as pushing elements into the vector) are O(1) operations.
- Therefore, the overall time complexity is **O(n)**, where `n` is the number of nodes in the linked list.

#### Space Complexity: **O(k)**

- We are storing the resulting sublists in a vector of size `k`. This is the primary space usage.
- The space complexity is independent of the length of the list, but depends on the number of parts (`k`), and is therefore **O(k)**.

### Conclusion

The solution efficiently splits a singly linked list into **k parts** while maintaining the required size constraints. It calculates the total length of the list, divides it into parts of approximately equal size, and then adjusts for the remainder by adding extra nodes to the first few parts. The solution handles edge cases such as when the list is shorter than `k` or when the list length is not evenly divisible by `k`.

By iterating through the list once and using a few auxiliary variables to track the division of nodes, the algorithm achieves an optimal time complexity of **O(n)** and space complexity of **O(k)**, making it efficient for large input sizes.

This approach provides a clear, scalable way to split a list into multiple parts while ensuring that the list is divided as evenly as possible, and it elegantly handles the edge cases by appending `NULL` for any extra parts that do not have nodes.

[`Link to LeetCode Lab`](https://leetcode.com/problems/split-linked-list-in-parts/description/)

---
{{< youtube ZITsHLE5mbE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
