
+++
authors = ["grid47"]
title = "Leetcode 382: Linked List Random Node"
date = "2024-09-29"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 382: Linked List Random Node in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Linked List","Math","Reservoir Sampling","Randomized"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/382.webp"
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/382.webp" 
    alt="A glowing linked list where the randomly selected node is softly highlighted."
    caption="Solution to LeetCode 382: Linked List Random Node Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given a singly linked list, implement a class that supports the initialization of the list and the ability to return a random node's value with equal probability.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of the initialization of a linked list followed by multiple calls to the getRandom method.
- **Example:** `Example input: [[1, 2, 3]] for initialization followed by calls to getRandom.`
- **Constraints:**
	- 1 <= Number of nodes <= 10^4
	- -10^4 <= Node.val <= 10^4
	- At most 10^4 calls to getRandom.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is a sequence of results from each getRandom() call, where each result corresponds to a random node's value from the list.
- **Example:** `Example output: [null, 2, 3, 1, 2, 3]`
- **Constraints:**
	- Each getRandom() call returns one node's value randomly chosen from the linked list.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to implement getRandom in such a way that each node in the list has an equal probability of being chosen.

- Initialize the linked list with the given nodes.
- Iterate through the linked list, maintaining a count of the nodes encountered.
- At each node, decide randomly whether to select that node or not using a probability of 1/i, where i is the number of nodes visited so far.
{{< dots >}}
### Problem Assumptions ✅
- The linked list is not empty.
- The list can contain a maximum of 10^4 nodes.
{{< dots >}}
## Examples 🧩
- **Input:** `Example 1: [[], [1], [2], [2], [], [1], [2], []]`  \
  **Explanation:** For each call to getRandom, one of the nodes (1, 2, or 3) should be selected randomly with equal probability.

- **Input:** `Example 2: [[], [5], [10], [15], [], [5], [10], [15]]`  \
  **Explanation:** Here, 5, 10, or 15 is selected randomly on each call to getRandom.

{{< dots >}}
## Approach 🚀
We will use the Reservoir Sampling algorithm to randomly select a node from the linked list, ensuring each node has an equal chance of being chosen.

### Initial Thoughts 💭
- We need to ensure that each node is equally likely to be chosen, which suggests using a random selection approach while traversing the list.
- The linked list is traversed once, and a random value is chosen during each iteration with a decreasing probability, ensuring each node has equal selection chance.
{{< dots >}}
### Edge Cases 🌐
- An empty linked list is not possible in this problem as the number of nodes will always be at least 1.
- The solution must handle linked lists with up to 10^4 nodes efficiently.
- Ensure that the solution handles edge values such as -10^4 and 10^4.
- The getRandom method must return a value from the linked list in constant space and linear time.
{{< dots >}}
## Code 💻
```cpp
class Solution {
ListNode* head;
public:
Solution(ListNode* head) {
    this->head = head;
}

int getRandom() {
    int ans = 0, i = 1;
    ListNode* p = this->head;
    while(p) {
        if(rand() % i == 0) ans = p->val;
        i++;
        p = p->next;
    }
    return ans;
}
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
```

This code defines a Solution class that takes the head of a linked list. The `getRandom` method returns a random node's value using a reservoir sampling algorithm.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Class Declaration**
	```cpp
	class Solution {
	```
	This line begins the declaration of the `Solution` class.

2. **Variable Declaration**
	```cpp
	ListNode* head;
	```
	A pointer `head` to the first node in a linked list is declared.

3. **Access Modifiers**
	```cpp
	public:
	```
	The `public:` keyword denotes the start of the public section of the class, where the methods will be defined.

4. **Constructor**
	```cpp
	Solution(ListNode* head) {
	```
	This is the constructor for the `Solution` class that initializes the `head` pointer with the provided argument.

5. **Variable Assignment**
	```cpp
	    this->head = head;
	```
	The constructor assigns the provided `head` to the class's `head` variable.

6. **Method Definition**
	```cpp
	int getRandom() {
	```
	This defines the `getRandom` method which will return a random node's value from the linked list.

7. **Variable Initialization**
	```cpp
	    int ans = 0, i = 1;
	```
	Two variables, `ans` and `i`, are initialized. `ans` stores the random node's value, and `i` is used to determine the probability of selecting each node.

8. **Pointer Initialization**
	```cpp
	    ListNode* p = this->head;
	```
	A pointer `p` is initialized to the `head` of the linked list.

9. **Loop Structure**
	```cpp
	    while(p) {
	```
	The `while` loop iterates over each node in the linked list until `p` becomes `NULL`.

10. **Reservoir Sampling**
	```cpp
	        if(rand() % i == 0) ans = p->val;
	```
	This line implements the reservoir sampling algorithm to randomly select a node's value. The probability of selecting each node decreases with each additional node.

11. **Incrementing Counter**
	```cpp
	        i++;
	```
	The counter `i` is incremented to reflect the number of nodes encountered so far.

12. **Pointer Advancement**
	```cpp
	        p = p->next;
	```
	The pointer `p` moves to the next node in the linked list.

13. **Return Statement**
	```cpp
	    return ans;
	```
	The method returns the value of the randomly selected node.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The getRandom method requires a full traversal of the linked list, which takes O(n) time.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) because the algorithm uses no extra space other than for the iteration variable.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/linked-list-random-node/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
