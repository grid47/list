
+++
authors = ["grid47"]
title = "Leetcode 1171: Remove Zero Sum Consecutive Nodes from Linked List"
date = "2024-07-12"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1171: Remove Zero Sum Consecutive Nodes from Linked List in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","Linked List"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "xZRozZEjizg"
youtube_upload_date="2022-11-10"
youtube_thumbnail="https://i.ytimg.com/vi/xZRozZEjizg/maxresdefault.jpg"
comments = true
+++



---
Given the head of a linked list, iteratively remove all consecutive subsequences of nodes whose sum is 0. Return the modified linked list after all such subsequences have been removed. You may return any valid result.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input is the head of a singly linked list.
- **Example:** `Input: head = [2,-2,3,1,-1,4,-4,5]`
- **Constraints:**
	- 1 <= length of linked list <= 1000
	- -1000 <= node.val <= 1000

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the head of the modified linked list with all zero-sum subsequences removed.
- **Example:** `Output: [5]`
- **Constraints:**
	- The output linked list should not contain any zero-sum consecutive subsequences.

{{< dots >}}
### Core Logic 🔍
**Goal:** Iteratively remove zero-sum consecutive subsequences from the linked list.

- 1. Create a dummy node and link it to the head of the list.
- 2. Traverse the list while maintaining a prefix sum.
- 3. Use a hash map to track nodes corresponding to each prefix sum.
- 4. When a prefix sum is encountered again, remove all nodes in the subsequence between the two occurrences.
- 5. Return the updated list starting from the dummy node’s next pointer.
{{< dots >}}
### Problem Assumptions ✅
- Input is always a valid singly linked list.
- Zero-sum subsequences can span multiple nodes.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: head = [1,3,-3,4,5,-4]`  \
  **Explanation:** The sequence [3,-3] sums to 0 and is removed. Then [4,5,-4] sums to 0 and is also removed. The final list is [1].

- **Input:** `Input: head = [2,3,-5,5,-2,1]`  \
  **Explanation:** The sequence [2,3,-5] sums to 0. Removing it leaves [5,-2,1]. No further zero-sum sequences exist. The result is [5,-2,1].

{{< dots >}}
## Approach 🚀
Use a prefix sum and a hash map to efficiently detect and remove zero-sum subsequences in a single traversal.

### Initial Thoughts 💭
- Using prefix sums allows quick identification of zero-sum subsequences.
- A hash map can store references to nodes corresponding to each prefix sum.
- Removing nodes in-place avoids unnecessary space usage and preserves the list structure.
{{< dots >}}
### Edge Cases 🌐
- An empty list returns an empty list.
- A list with 1000 nodes processes efficiently using prefix sums.
- Lists with all nodes summing to 0 should return an empty list.
- Negative and positive values should be handled correctly.
{{< dots >}}
## Code 💻
```cpp
ListNode* removeZeroSumSublists(ListNode* head) {
    ListNode* dummy = new ListNode(0), *cur = dummy;
    dummy->next= head;
    int prefix = 0;
    map<int, ListNode*> mp;
    while(cur) {
        prefix += cur->val;
        if(mp.count(prefix)) {
            cur = mp[prefix]->next;
            int p = prefix + cur->val;
            while(p != prefix) {
                mp.erase(p);
                cur = cur->next;
                p += cur->val;
            }
            mp[prefix]->next = cur->next;
        } else mp[prefix]  = cur;

        cur = cur->next;
    }
    return dummy->next;
}
```

This code defines the function `removeZeroSumSublists` that removes any sublist of consecutive nodes in a linked list where the sum of the node values is zero. The function uses a prefix sum approach combined with a hash map to efficiently find and remove such sublists.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	ListNode* removeZeroSumSublists(ListNode* head) {
	```
	Define the function `removeZeroSumSublists`, which takes a `ListNode* head` as input and returns a `ListNode*` after removing any sublist with a sum of zero.

2. **Variable Initialization**
	```cpp
	    ListNode* dummy = new ListNode(0), *cur = dummy;
	```
	Initialize a dummy node to simplify list manipulation and set `cur` to point to the dummy node.

3. **Variable Initialization**
	```cpp
	    dummy->next = head;
	```
	Set the `next` pointer of the dummy node to point to the head of the input linked list.

4. **Variable Initialization**
	```cpp
	    int prefix = 0;
	```
	Initialize the variable `prefix` to 0 to keep track of the prefix sum of node values.

5. **Variable Initialization**
	```cpp
	    map<int, ListNode*> mp;
	```
	Initialize a map `mp` to store the first occurrence of each prefix sum and its corresponding node.

6. **Loop**
	```cpp
	    while(cur) {
	```
	Start a while loop that iterates through the linked list until `cur` is null.

7. **Prefix Sum Calculation**
	```cpp
	        prefix += cur->val;
	```
	Update the prefix sum by adding the value of the current node.

8. **Conditional**
	```cpp
	        if(mp.count(prefix)) {
	```
	Check if the prefix sum has already been encountered in the map `mp`.

9. **Pointer Update**
	```cpp
	            cur = mp[prefix]->next;
	```
	Set `cur` to the node right after the node corresponding to the previous occurrence of the same prefix sum.

10. **Variable Initialization**
	```cpp
	            int p = prefix + cur->val;
	```
	Initialize `p` with the sum of `prefix` and the value of the current node.

11. **Loop**
	```cpp
	            while(p != prefix) {
	```
	Start a loop to erase any prefix sums between the first occurrence and the current node, effectively removing the nodes in the zero-sum sublist.

12. **Map Operation**
	```cpp
	                mp.erase(p);
	```
	Erase the prefix sum `p` from the map `mp`.

13. **Pointer Update**
	```cpp
	                cur = cur->next;
	```
	Move the `cur` pointer to the next node in the list.

14. **Prefix Sum Calculation**
	```cpp
	                p += cur->val;
	```
	Update the value of `p` by adding the value of the current node.

15. **Loop**
	```cpp
	            }
	```
	End the loop for erasing nodes between the two prefix sums.

16. **Pointer Update**
	```cpp
	            mp[prefix]->next = cur->next;
	```
	Update the `next` pointer of the node corresponding to the previous prefix sum to skip over the zero-sum sublist.

17. **Map Operation**
	```cpp
	        } else mp[prefix] = cur;
	```
	If the prefix sum is not found in the map, store the current node in the map with the prefix sum as the key.

18. **Pointer Update**
	```cpp
	        cur = cur->next;
	```
	Move the `cur` pointer to the next node.

19. **Return Statement**
	```cpp
	    return dummy->next;
	```
	Return the next node after the dummy node, which represents the head of the modified linked list.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(N)
- **Average Case:** O(N)
- **Worst Case:** O(N)

Each node is processed once, with hash map operations taking constant time.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(N)

Space complexity is proportional to the number of unique prefix sums in the worst case.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/description/)

---
{{< youtube xZRozZEjizg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
