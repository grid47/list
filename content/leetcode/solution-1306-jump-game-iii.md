
+++
authors = ["grid47"]
title = "Leetcode 1306: Jump Game III"
date = "2024-06-29"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1306: Jump Game III in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Depth-First Search","Breadth-First Search"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "9oUhzPLmLZQ"
youtube_upload_date="2024-04-07"
youtube_thumbnail="https://i.ytimg.com/vi/9oUhzPLmLZQ/maxresdefault.jpg"
comments = true
+++



---
You are given an array of non-negative integers arr and a starting index start. You can jump forward or backward from any index based on the values at the index. Your task is to determine whether you can reach an index with a value of 0.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an array of integers and a starting index. The array contains non-negative integers and the starting index is within the bounds of the array.
- **Example:** `Input: arr = [5, 3, 4, 0, 1, 6], start = 4`
- **Constraints:**
	- 1 <= arr.length <= 5 * 10^4
	- 0 <= arr[i] < arr.length
	- 0 <= start < arr.length

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is a boolean value indicating whether it is possible to reach an index with a value of 0.
- **Example:** `Output: true`
- **Constraints:**
	- The result is either true or false depending on whether it's possible to reach an index with value 0.

{{< dots >}}
### Core Logic 🔍
**Goal:** To check if it is possible to reach an index with value 0 by jumping forward or backward.

- Use a queue or DFS to explore all reachable indices.
- Mark visited indices to avoid infinite loops.
- Check if any visited index contains value 0.
{{< dots >}}
### Problem Assumptions ✅
- The array is non-empty and contains valid non-negative integers.
- The start index is within the valid range of the array.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: arr = [5, 3, 4, 0, 1, 6], start = 4`  \
  **Explanation:** From index 4, you can move to index 3 (which has value 0), so the answer is true.

- **Input:** `Input: arr = [2, 0, 1, 4, 2], start = 2`  \
  **Explanation:** There is no possible way to reach index 1 (value 0) from the start index 2, so the answer is false.

{{< dots >}}
## Approach 🚀
The solution involves traversing the array using a queue or depth-first search (DFS) to check if it's possible to reach an index with value 0.

### Initial Thoughts 💭
- We need to efficiently explore all possible jumps without revisiting indices.
- A breadth-first search (BFS) can be used to explore all reachable indices from the start position.
{{< dots >}}
### Edge Cases 🌐
- If the array is empty, it's impossible to reach an index with value 0.
- For large arrays, the solution should efficiently traverse the array while avoiding unnecessary recomputation.
- If the start index is already at a position with value 0, the answer should be true.
- Ensure that the solution can handle up to 50,000 elements in the array.
{{< dots >}}
## Code 💻
```cpp
bool canReach(vector<int>& arr, int start) {
    
    int n = arr.size();
    queue<int> q;
    q.push(start);

    while(!q.empty()) {
        int i = q.front();
        q.pop();

        if (arr[i] == 0)
            return true;
        int l = i - arr[i];
        int r = i + arr[i];
        arr[i] = -arr[i];
        if (l > -1 && arr[l] > -1) q.push(l);
        if (r < n  && arr[r] > -1) q.push(r);
    }
    
    return false;
}
```

This code implements a breadth-first search (BFS) approach to determine if it is possible to reach a position with a value of 0, starting from a given index. It uses a queue to traverse all reachable indices, marking them as visited and checking if the goal is met.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	bool canReach(vector<int>& arr, int start) {
	```
	The function 'canReach' is defined to take a vector of integers 'arr' and an integer 'start' as input. The goal is to determine if it's possible to reach an index where the value is 0 by jumping through the array.

2. **Variable Initialization**
	```cpp
	    int n = arr.size();
	```
	The size of the array 'arr' is stored in the variable 'n' to track the bounds of the array when checking indices.

3. **Data Structure Initialization**
	```cpp
	    queue<int> q;
	```
	A queue is initialized to facilitate breadth-first search (BFS). It will store indices that need to be processed.

4. **Queue Operation**
	```cpp
	    q.push(start);
	```
	The starting index is pushed into the queue to begin the traversal from that position.

5. **Loop Control**
	```cpp
	    while(!q.empty()) {
	```
	The while loop starts and runs as long as the queue is not empty. It processes each index from the queue.

6. **Queue Operation**
	```cpp
	        int i = q.front();
	```
	The front element of the queue, which represents the current index, is retrieved and stored in variable 'i'.

7. **Queue Operation**
	```cpp
	        q.pop();
	```
	The current index is popped from the queue after it is processed.

8. **Condition**
	```cpp
	        if (arr[i] == 0)
	```
	A check is made to see if the value at index 'i' is 0. If it is, the goal has been reached, and the function will return true.

9. **Return Statement**
	```cpp
	            return true;
	```
	If the value at 'arr[i]' is 0, the function immediately returns true, indicating that the goal has been reached.

10. **Calculation**
	```cpp
	        int l = i - arr[i];
	```
	The left index 'l' is calculated as the current index 'i' minus the value at 'arr[i]'. This represents a possible jump to the left.

11. **Calculation**
	```cpp
	        int r = i + arr[i];
	```
	The right index 'r' is calculated as the current index 'i' plus the value at 'arr[i]'. This represents a possible jump to the right.

12. **Marking Visited**
	```cpp
	        arr[i] = -arr[i];
	```
	The value at index 'i' is negated to mark it as visited, ensuring that the same index is not processed again.

13. **Queue Operation**
	```cpp
	        if (l > -1 && arr[l] > -1) q.push(l);
	```
	If the left index 'l' is valid and not visited, it is pushed into the queue for further processing.

14. **Queue Operation**
	```cpp
	        if (r < n  && arr[r] > -1) q.push(r);
	```
	If the right index 'r' is valid and not visited, it is pushed into the queue for further processing.

15. **Return Statement**
	```cpp
	    return false;
	```
	If the queue is emptied without finding a 0, the function returns false, indicating that it is not possible to reach an index with 0.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n) - The best case occurs when the first index with value 0 is reached immediately.
- **Average Case:** O(n) - In the average case, all indices may need to be visited.
- **Worst Case:** O(n) - In the worst case, every index may need to be processed.

The time complexity is O(n), where n is the length of the array.

### Space Complexity 💾
- **Best Case:** O(n) - Even in the best case, we may need to use space for the queue and visited array.
- **Worst Case:** O(n) - The space complexity is O(n) due to the queue used for BFS and the space needed for marking visited indices.

The space complexity is O(n), where n is the length of the array.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/jump-game-iii/description/)

---
{{< youtube 9oUhzPLmLZQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
