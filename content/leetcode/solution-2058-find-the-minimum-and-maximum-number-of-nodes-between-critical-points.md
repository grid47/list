
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
comments = true
+++



---
In a linked list, a critical point is defined as either a local maxima or a local minima. A local maxima is when a node's value is strictly greater than both its previous and next node, while a local minima is when a node's value is strictly smaller than both its previous and next node. Given a linked list, return an array containing the minimum and maximum distances between any two distinct critical points. If there are fewer than two critical points, return [-1, -1].
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a linked list represented by its head node and a series of values.
- **Example:** `Input: head = [4, 6, 2, 7, 5, 1, 9]`
- **Constraints:**
	- 2 <= The number of nodes in the list <= 10^5
	- 1 <= Node.val <= 10^5

{{< dots >}}
### Output Specifications 📤
- **Output:** Return an array of length 2 where the first element is the minimum distance between two distinct critical points, and the second element is the maximum distance. If fewer than two critical points exist, return [-1, -1].
- **Example:** `Output: [2, 4]`
- **Constraints:**
	- The array must contain two elements representing min and max distances.

{{< dots >}}
### Core Logic 🔍
**Goal:** Identify critical points in the linked list and calculate the minimum and maximum distances between them.

- Traverse the linked list to identify critical points (local maxima and minima).
- Track the positions of these critical points as you traverse the list.
- For each query, compute the distance between any two distinct critical points and determine the minimum and maximum distances.
{{< dots >}}
### Problem Assumptions ✅
- The linked list has at least two nodes.
- If no critical points are found, return [-1, -1].
{{< dots >}}
## Examples 🧩
- **Input:** `Input: head = [5, 3, 2, 6, 7, 5, 4, 2]`  \
  **Explanation:** Critical points are found at nodes 2 (local minima), 4 (local maxima), and 6 (local minima). The distances between the critical points are calculated to return [1, 5], which are the minimum and maximum distances.

{{< dots >}}
## Approach 🚀
Use a single pass through the linked list to identify critical points. Track the positions of these points and then compute the distances between them.

### Initial Thoughts 💭
- A linked list traversal is required to identify critical points.
- Distances between critical points must be calculated in a second pass or while traversing.
- The problem can be solved in O(n) time complexity with efficient space usage.
{{< dots >}}
### Edge Cases 🌐
- An empty list should return [-1, -1].
- Ensure the solution handles the maximum size of the linked list efficiently.
- If all nodes are in increasing or decreasing order, there may be no critical points.
- Handle cases where the number of critical points is less than two.
{{< dots >}}
## Code 💻
```cpp
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
```

This function finds the minimum and maximum distances between critical points in a linked list where critical points are defined as a point where the value is either greater than or less than its adjacent nodes.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Initialization**
	```cpp
	vector<int> nodesBetweenCriticalPoints(ListNode* head) {
	```
	Begin by defining the function that accepts a linked list and returns a vector containing the minimum and maximum distances between critical points.

2. **Variable Initialization**
	```cpp
	    int mn = INT_MAX, mx = 0;
	```
	Initialize two variables, mn and mx, to keep track of the minimum and maximum distances. The initial values represent extreme bounds.

3. **Edge Case Handling**
	```cpp
	    if(head == NULL || head->next == NULL) return {-1, -1};
	```
	Handle the edge case where the linked list is empty or has only one node, returning {-1, -1} as no critical points exist.

4. **Pointer Manipulation**
	```cpp
	    auto nxt = head->next;
	```
	Define a pointer 'nxt' to the next node in the list to compare the current node with the next one.

5. **State Management**
	```cpp
	    int state = head->val > nxt->val? -1: head->val == nxt->val? 0:1;
	```
	Initialize the 'state' variable to track the comparison between the current and next node values (increasing, decreasing, or equal).

6. **Variable Initialization**
	```cpp
	    int prv, cnt = -1, cnt2 = -1;
	```
	Initialize variables for the previous state (prv), and counters (cnt and cnt2) for distance calculations.

7. **Looping**
	```cpp
	    while(nxt->next) {
	```
	Begin a loop that iterates over the linked list nodes until the second-to-last node is reached.

8. **Pointer Manipulation**
	```cpp
	        head = nxt;
	```
	Move the 'head' pointer to the 'nxt' node as we process the list.

9. **Pointer Manipulation**
	```cpp
	        nxt = nxt->next;
	```
	Move the 'nxt' pointer to the next node in the list.

10. **State Management**
	```cpp
	        prv = state;
	```
	Store the previous state to compare with the current state in the next iteration.

11. **State Management**
	```cpp
	        state = head->val > nxt->val? -1: (head->val == nxt->val? 0:1);
	```
	Update the 'state' variable based on the comparison of current and next node values.

12. **Conditional Logic**
	```cpp
	        if(cnt != -1) {
	```
	Check if a valid counter has been initialized (i.e., not -1), indicating the presence of critical points.

13. **Counting**
	```cpp
	            cnt++;
	```
	Increment the distance counter for the current critical point distance.

14. **Counting**
	```cpp
	            cnt2++;
	```
	Increment the distance counter for the maximum distance.

15. **Conditional Logic**
	```cpp
	        if((prv == -1 && state == 1) || (prv == 1 && state == -1)) {
	```
	Check if a critical point is detected by comparing the previous and current states.

16. **Conditional Logic**
	```cpp
	            if(cnt2 == -1) cnt2 = 0;
	```
	If the distance counter is uninitialized, set it to 0.

17. **Max Calculation**
	```cpp
	            else {
	```
	If a valid distance counter exists, proceed to update the maximum distance.

18. **Max Calculation**
	```cpp
	                mx = max(mx, cnt2);                    
	```
	Update the maximum distance if the current distance is greater than the previous maximum.

19. **Min Calculation**
	```cpp
	            if(cnt != -1)
	```
	Check if the minimum distance counter is initialized before updating the minimum distance.

20. **Min Calculation**
	```cpp
	            mn = min(mn, cnt);                                
	```
	Update the minimum distance if the current distance is smaller than the previous minimum.

21. **Counting**
	```cpp
	            cnt = 0;
	```
	Reset the counter after detecting a critical point.

22. **Edge Case Handling**
	```cpp
	    if(mn == INT_MAX || mx == 0) return {-1, -1};
	```
	Return {-1, -1} if no valid critical points were found.

23. **Return Statement**
	```cpp
	    return {mn, mx};
	```
	Return the calculated minimum and maximum distances between critical points.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) because we are performing a single traversal of the linked list to identify critical points.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the storage of critical points in an array.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/description/)

---
{{< youtube UddDgt52h9g >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
