
+++
authors = ["grid47"]
title = "Leetcode 2058: Find the Minimum and Maximum Number of Nodes Between Critical Points"
date = "2024-04-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2058: Find the Minimum and Maximum Number of Nodes Between Critical Points in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Linked List"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "UddDgt52h9g"
youtube_upload_date="2024-07-05"
youtube_thumbnail="https://i.ytimg.com/vi_webp/UddDgt52h9g/maxresdefault.webp"
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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int mn = INT_MAX, mx = 0;
        if(head == NULL || head->next == NULL) return {-1, -1};
        auto nxt = head->next;
        int state = head->val > nxt->val? -1: head->val == nxt->val? 0:1;
        int prv, cnt = -1, cnt2 = -1;
        while(nxt->next) {
            head = nxt;
            nxt = nxt->next;
            prv = state;
            state = head->val > nxt->val? -1: (head->val == nxt->val? 0:1);
            // cout << prv << ":" << state << " ";
            if(cnt != -1) {
                cnt++;
                cnt2++;
            }
            if((prv == -1 && state == 1) || (prv == 1 && state == -1)) {
                if(cnt2 == -1) cnt2 = 0;
                else {
                    mx = max(mx, cnt2);                    
                }
                if(cnt != -1)
                mn = min(mn, cnt);                                
                cnt = 0;
            }
        }
        // cout << mn << " " << mx;
        if(mn == INT_MAX || mx == 0) return {-1, -1};
        
        return {mn, mx};
    }
};
{{< /highlight >}}
---

### Problem Statement

Given a singly linked list, we are tasked with finding the distance between the first and last critical points of the list. A critical point is defined as a node that is either a local maximum or a local minimum compared to its immediate neighbors. The distance is defined as the number of nodes between two critical points, excluding the critical points themselves. If there are fewer than two critical points, we return `{-1, -1}`.

### Approach

The solution employs a linear traversal of the linked list to identify critical points and calculate the distances between them. The algorithm utilizes two variables, `mn` and `mx`, to track the minimum and maximum distances between critical points. A few key variables maintain the state of the previous and current nodes' values as we iterate through the list.

### Code Breakdown (Step by Step)

1. **Initialization**:
   - We define two integer variables `mn` and `mx` to track the minimum and maximum distances between critical points, initialized to `INT_MAX` and `0`, respectively.
   - We check if the list is empty or has only one node. In these cases, we return `{-1, -1}` since there can’t be any critical points.

    ```cpp
    int mn = INT_MAX, mx = 0;
    if(head == NULL || head->next == NULL) return {-1, -1};
    ```

2. **Setting Up Initial State**:
   - We establish pointers `nxt` to point to the next node and set `state` to indicate whether the current node is greater than, less than, or equal to the next node.
   - We also declare variables `prv` to hold the state of the previous node and two counters `cnt` and `cnt2` for the distances.

    ```cpp
    auto nxt = head->next;
    int state = head->val > nxt->val? -1: head->val == nxt->val? 0: 1;
    int prv, cnt = -1, cnt2 = -1;
    ```

3. **Traversing the Linked List**:
   - We iterate through the linked list until the second last node (`while(nxt->next)`).
   - For each node:
     - Update the state based on the comparison between the current node's value and the next node's value.
     - If `cnt` is not `-1`, increment it to count the number of nodes since the last critical point.
     - Check if the current node is a critical point:
       - A local maximum if the previous state is increasing and the current state is decreasing.
       - A local minimum if the previous state is decreasing and the current state is increasing.
     - If we find a critical point, we:
       - Update the maximum distance `mx` if we already have a distance between critical points.
       - Update the minimum distance `mn`.

    ```cpp
    while(nxt->next) {
        head = nxt;
        nxt = nxt->next;
        prv = state;
        state = head->val > nxt->val? -1: (head->val == nxt->val? 0:1);
        if(cnt != -1) {
            cnt++;
            cnt2++;
        }
        if((prv == -1 && state == 1) || (prv == 1 && state == -1)) {
            if(cnt2 == -1) cnt2 = 0;
            else {
                mx = max(mx, cnt2);
            }
            if(cnt != -1)
                mn = min(mn, cnt);
            cnt = 0;
        }
    }
    ```

4. **Final Check and Return**:
   - After completing the iteration, we check if we have found valid distances. If `mn` remains `INT_MAX` or `mx` is `0`, we return `{-1, -1}` indicating insufficient critical points.
   - Otherwise, we return the minimum and maximum distances found.

    ```cpp
    if(mn == INT_MAX || mx == 0) return {-1, -1};
    
    return {mn, mx};
    ```

### Complexity

- **Time Complexity**: O(N), where N is the number of nodes in the linked list. We traverse the list only once to identify critical points and calculate distances.
- **Space Complexity**: O(1), as we are using a constant amount of extra space for variables, regardless of the input size.

### Conclusion

The implemented solution efficiently determines the distances between the first and last critical points in a singly linked list by leveraging a single pass through the list and maintaining the necessary state information. This method is optimal for this problem, providing clear insights into local maxima and minima while adhering to a linear time complexity. The result, an array of minimum and maximum distances, allows easy interpretation of the critical point distances in the linked list.

[`Link to LeetCode Lab`](https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/description/)

---
{{< youtube UddDgt52h9g >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
