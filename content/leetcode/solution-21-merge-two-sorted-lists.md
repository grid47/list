
+++
authors = ["grid47"]
title = "Leetcode 21: Merge Two Sorted Lists"
date = "2024-11-04"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 21: Merge Two Sorted Lists in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Linked List","Recursion"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/21.webp"
youtube = "XIdigk956u0"
youtube_upload_date="2020-08-19"
youtube_thumbnail="https://i.ytimg.com/vi/XIdigk956u0/maxresdefault.jpg"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/21.webp" 
    alt="Two glowing lists merging, with soft energy flowing together in sync."
    caption="Solution to LeetCode 21: Merge Two Sorted Lists Problem"
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        
        if(l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;            
    }
};
{{< /highlight >}}
---

### 🌟 **Merging Two Sorted Linked Lists** – A Simple and Elegant Approach!

When you're faced with merging two sorted linked lists into a single sorted list, don’t worry—it’s simpler than it sounds! By breaking the problem into smaller steps, we can easily solve this in an efficient manner. Let’s dive in! 🚀

---

#### 📝 **The Problem**  
We are given two **sorted singly linked lists**, `l1` and `l2`, and our goal is to **merge** them into a single, sorted linked list. Both lists are already in non-decreasing order, so we just need to combine them while preserving that order.

---

#### 🔑 **Key Idea: Think Recursively!**

We’ll approach this problem using **recursion**—a technique that breaks a complex problem into simpler subproblems. The idea is to always pick the smaller value between the two lists and recursively merge the remaining elements. By doing this, we ensure that the merged list remains sorted.

---

#### 🧩 **Step-by-Step Breakdown**  
1. **Base Case**: If one of the lists is `NULL`, simply return the other list. This is because if one list is empty, there’s nothing to merge, so we just return the other sorted list.

    ```cpp
    if(l1 == NULL) return l2;
    if(l2 == NULL) return l1;
    ```

2. **Recursive Case**: Now, we compare the values of the current nodes in `l1` and `l2`. We then take the smaller node and recursively merge the rest of the lists.

    ```cpp
    if(l1->val < l2->val) {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    }
    ```

   - **Explanation Simply**: If the current node in `l1` has a smaller value, we attach it to the merged list and continue merging the remaining `l1` with `l2`.

3. **If the Current Node of `l2` is Smaller**: If `l2` has a smaller or equal value, we do the same thing for `l2`:

    ```cpp
    l2->next = mergeTwoLists(l1, l2->next);
    return l2;
    ```

---

#### 🧠 **Time and Space Complexity**  
- **Time Complexity**:  
  **O(n + m)** — where `n` and `m` are the lengths of `l1` and `l2`, respectively. We traverse both lists once, making this solution linear.

- **Space Complexity**:  
  **O(n + m)** — due to the recursion call stack. In the worst case, the maximum depth of the recursion is the total number of nodes in both lists.

---

#### 💡 **Why Recursion Rocks!**

- **Elegant Solution**: The recursive approach is clean and intuitive, especially when merging sorted lists. It follows the principle of "divide and conquer" by breaking down the problem into smaller subproblems.
  
- **Optimal Performance**: We make sure to visit each node once and do a simple comparison at each step, making this solution both **efficient** and **easy to understand**.

---

#### 🌱 **Practice Makes Perfect!**  
By applying this recursive method, you’ll not only master this problem but also enhance your understanding of linked lists and recursion. The more you practice, the more you’ll see the elegance in recursive solutions. Keep going, coder! 💪



[`Link to LeetCode Lab`](https://leetcode.com/problems/merge-two-sorted-lists/description/)

---
{{< youtube XIdigk956u0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
