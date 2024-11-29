
+++
authors = ["grid47"]
title = "Leetcode 1696: Jump Game VI"
date = "2024-05-21"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1696: Jump Game VI in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Queue","Heap (Priority Queue)","Monotonic Queue"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "dHAsYTvbbj4"
youtube_upload_date="2020-12-20"
youtube_thumbnail="https://i.ytimg.com/vi/dHAsYTvbbj4/maxresdefault.jpg"
comments = true
+++



---
You are given a 0-indexed integer array 'nums' and an integer 'k'. You start at index 0 and can jump up to 'k' steps forward at a time. Your task is to find the maximum sum of elements you can get by jumping to the last index, visiting subarrays of unique elements.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an array 'nums' containing integers and an integer 'k' which defines the maximum jump range.
- **Example:** `[3, -2, 5, -1, 2, 4], k = 2`
- **Constraints:**
	- 1 <= nums.length, k <= 10^5
	- -10^4 <= nums[i] <= 10^4

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is a single integer representing the maximum score you can obtain by jumping to the last index.
- **Example:** `9`
- **Constraints:**
	- The score is the sum of the elements in the subsequence of jumps you choose.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to compute the maximum score from jumping to the last index while maintaining the sum of visited elements.

- Start from the first index (0) and maintain a deque to track the indices of the array.
- At each index, compute the best score by considering jumps from the previous valid indices (within the range of 'k' jumps).
- For each step, update the current score based on the previous best score.
- Ensure that the deque only holds indices that provide the highest score within the jump range.
{{< dots >}}
### Problem Assumptions ✅
- You will always have a valid input, i.e., the array will not be empty.
{{< dots >}}
## Examples 🧩
- **Input:** `[3, -2, 5, -1, 2, 4], k = 2`  \
  **Explanation:** The maximum score is achieved by jumping through the subsequence [3, -2, 5, 2, 4], which results in a sum of 9.

- **Input:** `[1, -3, 2, 4, -1, 2], k = 3`  \
  **Explanation:** The best subsequence to jump through is [1, -3, 2, 4, 2], resulting in a sum of 7.

{{< dots >}}
## Approach 🚀
To solve this problem efficiently, use dynamic programming with a deque to maintain the optimal subsequence sums for valid jumps.

### Initial Thoughts 💭
- The sliding window approach is helpful here, as we need to consider the best jump within the range of 'k'.
- We can use a deque to keep track of the maximum score in the sliding window of size 'k'.
{{< dots >}}
### Edge Cases 🌐
- There are no empty inputs since the array will have at least one element.
- For large inputs, ensure the solution handles arrays with lengths up to 10^5 efficiently.
- When the array contains all negative numbers, the result will be the maximum negative number within the valid subsequence.
- Ensure that the time complexity remains O(n) to handle large input sizes.
{{< dots >}}
## Code 💻
```cpp
int maxResult(vector<int>& nums, int k) {
    int n = nums.size();
    
    deque<int> dq = {0};
    
    for(int i = 1; i < n; i++) {
        
        nums[i] = nums[dq.front()] + nums[i];
        while(!dq.empty() && nums[dq.back()] <= nums[i])
            dq.pop_back();
        dq.push_back(i);
        
        if(i - dq.front() >= k) dq.pop_front();
        
    }
    
    return nums[n - 1];
}
```

This function computes the maximum score achievable by starting from the first element of `nums` and making jumps to the right, with a jump distance no greater than `k`. It uses a sliding window technique, optimized with a deque to maintain the indices of the maximum scores in the window.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int maxResult(vector<int>& nums, int k) {
	```
	Defines the function `maxResult` that takes a vector `nums` and an integer `k`, returning the maximum result achievable by making jumps in the array with a maximum jump length of `k`.

2. **Variable Initialization**
	```cpp
	    int n = nums.size();
	```
	Initialize `n` to store the size of the `nums` array, which helps in managing the loop boundaries.

3. **Deque Initialization**
	```cpp
	    deque<int> dq = {0};
	```
	Initialize a deque `dq` with the index `0` to represent the first element of the array, as it is the starting point for the score calculations.

4. **Main Loop**
	```cpp
	    for(int i = 1; i < n; i++) {
	```
	The main loop that iterates through the array starting from the second element (`i = 1`) to the last element.

5. **Score Update**
	```cpp
	        nums[i] = nums[dq.front()] + nums[i];
	```
	Update `nums[i]` to be the sum of the current value `nums[i]` and the value at the front of the deque (`dq.front()`), which holds the maximum value within the current window.

6. **Deque Maintenance**
	```cpp
	        while(!dq.empty() && nums[dq.back()] <= nums[i])
	```
	Ensure that the deque maintains the largest value at the front by removing indices of values that are less than or equal to `nums[i]`.

7. **Deque Maintenance**
	```cpp
	            dq.pop_back();
	```
	Remove elements from the back of the deque where `nums[dq.back()]` is less than or equal to the current `nums[i]` because they won't contribute to the maximum score.

8. **Deque Update**
	```cpp
	        dq.push_back(i);
	```
	Push the current index `i` to the deque, as it may contribute to the maximum score in future iterations.

9. **Window Size Check**
	```cpp
	        
	```
	Check if the current window exceeds the size `k` and adjust accordingly.

10. **Window Size Check**
	```cpp
	        if(i - dq.front() >= k) dq.pop_front();
	```
	If the window size exceeds `k`, pop the front of the deque, effectively removing the index of an element that is out of range.

11. **Return Result**
	```cpp
	    return nums[n - 1];
	```
	Return the maximum score at the last index of the array, which has been calculated during the iteration.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The algorithm processes each element exactly once, giving a time complexity of O(n).

### Space Complexity 💾
- **Best Case:** O(k)
- **Worst Case:** O(k)

The space complexity is O(k) due to the deque storing indices of the array.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/jump-game-vi/description/)

---
{{< youtube dHAsYTvbbj4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
