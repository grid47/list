
+++
authors = ["grid47"]
title = "Leetcode 1673: Find the Most Competitive Subsequence"
date = "2024-05-23"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1673: Find the Most Competitive Subsequence in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Stack","Greedy","Monotonic Stack"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "GBJFxSD3B_s"
youtube_upload_date="2021-02-22"
youtube_thumbnail="https://i.ytimg.com/vi/GBJFxSD3B_s/maxresdefault.jpg"
comments = true
+++



---
Given an integer array `nums` and a positive integer `k`, return the most competitive subsequence of `nums` of size `k`. A subsequence is more competitive than another if at the first position where they differ, the subsequence has a smaller number.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an array of integers `nums` and an integer `k` which is the size of the subsequence.
- **Example:** `nums = [6, 3, 4, 5], k = 2`
- **Constraints:**
	- 1 <= nums.length <= 10^5
	- 0 <= nums[i] <= 10^9
	- 1 <= k <= nums.length

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the most competitive subsequence of size `k`.
- **Example:** `Output: [3, 5]`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** Find the most competitive subsequence by maintaining a stack and ensuring that subsequences are in increasing order.

- Initialize an empty stack.
- Iterate through each element of the array `nums`.
- For each element, pop elements from the stack if they are greater than the current element and if there are enough remaining elements to form a subsequence of size `k`.
- Push the current element to the stack if the size of the stack is less than `k`.
- After iterating through all elements, return the stack as the result.
{{< dots >}}
### Problem Assumptions ✅
- The input array `nums` will have at least one element.
- The value of `k` will be a valid integer between 1 and the length of `nums`.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: nums = [6, 3, 4, 5], k = 2`  \
  **Explanation:** Among all possible subsequences of size 2, [3, 5] is the most competitive because the first position where the subsequences differ is at the second position, and 3 is smaller than 4 and 5.

{{< dots >}}
## Approach 🚀
We can solve this problem using a greedy approach with a stack. As we iterate through the array, we ensure that the stack contains the most competitive subsequence by removing larger elements when necessary.

### Initial Thoughts 💭
- We need to select `k` elements that form the most competitive subsequence.
- Using a stack allows us to efficiently maintain the subsequence in increasing order.
- We need to ensure that at each point we are maintaining the smallest possible elements in the subsequence, using the stack to enforce this.
{{< dots >}}
### Edge Cases 🌐
- The input will always contain at least one element.
- The algorithm should handle inputs up to 100,000 elements efficiently.
- The array elements can be as large as 1 billion.
{{< dots >}}
## Code 💻
```cpp
vector<int> mostCompetitive(vector<int>& nums, int k) {

    vector<int> stk;
    for(int i = 0; i < nums.size(); i++) {

        while (!stk.empty()          &&
             stk.back() > nums[i] &&
            (stk.size() + nums.size() - (i + 1)) >= k )
            stk.pop_back();

        if(stk.size() < k)
            stk.push_back(nums[i]);

    }
    
    return stk;
    
}
```

This is the complete code for solving the problem of finding the most competitive subsequence of length 'k' from the given list of integers 'nums'. The code uses a stack-based approach to maintain the most competitive elements in the subsequence.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Initialization**
	```cpp
	vector<int> mostCompetitive(vector<int>& nums, int k) {
	```
	Define the function mostCompetitive that takes a reference to a vector of integers 'nums' and an integer 'k' as input. The function will return a vector of integers representing the most competitive subsequence.

2. **Stack Initialization**
	```cpp
	    vector<int> stk;
	```
	Initialize an empty vector 'stk' that will be used as a stack to store elements from 'nums' in the most competitive order.

3. **Looping Through Elements**
	```cpp
	    for(int i = 0; i < nums.size(); i++) {
	```
	Start a loop to iterate through each element in the 'nums' array.

4. **Stack Operations**
	```cpp
	        while (!stk.empty() && stk.back() > nums[i] && (stk.size() + nums.size() - (i + 1)) >= k )
	```
	Inside the loop, use a while loop to check if the stack is not empty, the top element of the stack is greater than the current element, and there are enough remaining elements to form a valid subsequence of length 'k'.

5. **Pop Operation**
	```cpp
	            stk.pop_back();
	```
	If the above conditions are true, pop the top element from the stack to make room for potentially smaller and more competitive elements.

6. **Conditional Insertion**
	```cpp
	        if(stk.size() < k)
	```
	Check if the current size of the stack is less than 'k', meaning there is space to add more elements.

7. **Push Operation**
	```cpp
	            stk.push_back(nums[i]);
	```
	If there is space in the stack (i.e., the stack's size is less than 'k'), push the current element onto the stack.

8. **Return Statement**
	```cpp
	    return stk;
	```
	After the loop finishes, return the stack, which now contains the most competitive subsequence of length 'k'.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

We iterate through the list once, and each element is pushed and popped from the stack at most once.

### Space Complexity 💾
- **Best Case:** O(k)
- **Worst Case:** O(k)

The space complexity is proportional to the size of the subsequence `k`.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/find-the-most-competitive-subsequence/description/)

---
{{< youtube GBJFxSD3B_s >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
