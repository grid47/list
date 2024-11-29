
+++
authors = ["grid47"]
title = "Leetcode 376: Wiggle Subsequence"
date = "2024-09-30"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 376: Wiggle Subsequence in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/376.webp"
youtube = "IpWoZvKzpug"
youtube_upload_date="2021-03-18"
youtube_thumbnail="https://i.ytimg.com/vi/IpWoZvKzpug/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/376.webp" 
    alt="A sequence of numbers gently moving into a wiggle pattern, each step softly highlighted as they align."
    caption="Solution to LeetCode 376: Wiggle Subsequence Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
A wiggle subsequence is a sequence where the differences between successive numbers strictly alternate between positive and negative. The first difference (if one exists) may be either positive or negative. A sequence with one element and a sequence with two non-equal elements are trivially wiggle sequences. Given an integer array `nums`, return the length of the longest wiggle subsequence of `nums`.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given an integer array `nums`.
- **Example:** `nums = [1, 8, 3, 5, 2, 7]`
- **Constraints:**
	- 1 <= nums.length <= 1000
	- 0 <= nums[i] <= 1000

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the length of the longest subsequence that forms a wiggle sequence.
- **Example:** `Output: 6`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** Determine the longest subsequence that alternates between increasing and decreasing differences.

- Create two arrays to store the lengths of the wiggle subsequences that end in an upward or downward direction.
- Iterate through the array and for each element, update the subsequence lengths based on the current and previous elements.
- The final answer is the maximum value between the two subsequence lengths at the end of the array.
{{< dots >}}
### Problem Assumptions ✅
- The array `nums` is non-empty and contains at least one integer.
{{< dots >}}
## Examples 🧩
- **Input:** `nums = [1, 8, 3, 5, 2, 7]`  \
  **Explanation:** In this case, the entire sequence is a valid wiggle sequence, and the differences between consecutive elements alternate between positive and negative.

- **Input:** `nums = [10, 15, 12, 9, 18, 7, 11, 13]`  \
  **Explanation:** In this case, a valid wiggle subsequence can be formed as `[10, 15, 9, 18, 7, 13]`.

{{< dots >}}
## Approach 🚀
To solve the problem efficiently, we can use dynamic programming.

### Initial Thoughts 💭
- We can maintain two states: one where the current element is part of an increasing subsequence, and one where it is part of a decreasing subsequence.
- Dynamic programming can be used to store the lengths of subsequences that end in an increasing or decreasing direction.
{{< dots >}}
### Edge Cases 🌐
- There are no empty inputs as per the constraints.
- The algorithm should efficiently handle inputs up to the size of 1000.
- The input may contain repeated elements, but this does not affect the logic since we are only concerned with the differences between consecutive elements.
- The array should not contain negative numbers or be empty.
{{< dots >}}
## Code 💻
```cpp
int wiggleMaxLength(vector<int> nums) {
    if(nums.size() == 0) return 0;
    
    int n = nums.size();
    
    vector<int> up(n, 0);
    vector<int> down(n, 0);        
    
    up[0] = 1;
    down[0] = 1;
    
    for(int i = 1; i < n; i++) {
             if(nums[i] < nums[i - 1]) {
            down[i] = up[i - 1] + 1;
            up[i] = up[i - 1];
        }
        else if(nums[i] > nums[i - 1]) {            
            up[i] = down[i - 1] + 1;
            down[i] = down[i - 1];                
        }
        else {
            down[i] = down[i - 1];
            up[i]   =   up[i - 1];                
        }
    }
    
    return max(down[n - 1], up[n - 1]);
}
```

This code computes the length of the longest wiggle subsequence from the given input array `nums`. The approach uses dynamic programming to track the longest wiggle sequence in both upward and downward directions at each point.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int wiggleMaxLength(vector<int> nums) {
	```
	This is the function definition for `wiggleMaxLength`, which computes the maximum length of a wiggle subsequence. It takes a vector `nums` as input.

2. **Edge Case Handling**
	```cpp
	    if(nums.size() == 0) return 0;
	```
	Checks if the input array `nums` is empty. If it is, the function returns 0 as there is no wiggle subsequence possible.

3. **Size Calculation**
	```cpp
	    int n = nums.size();
	```
	Calculates the size `n` of the input vector `nums`, which is used to initialize dynamic programming tables.

4. **Dynamic Programming Array Initialization**
	```cpp
	    vector<int> up(n, 0);
	```
	Declares a vector `up` of size `n` initialized to zero, which will track the length of the longest subsequence ending in an upward direction.

5. **Dynamic Programming Array Initialization**
	```cpp
	    vector<int> down(n, 0);        
	```
	Declares a vector `down` of size `n` initialized to zero, which will track the length of the longest subsequence ending in a downward direction.

6. **Initial Condition Setup**
	```cpp
	    up[0] = 1;
	```
	Sets the base case: the first element of the `nums` array is considered to be part of a wiggle sequence of length 1, starting with an upward direction.

7. **Initial Condition Setup**
	```cpp
	    down[0] = 1;
	```
	Sets the base case: the first element of the `nums` array is considered to be part of a wiggle sequence of length 1, starting with a downward direction.

8. **Loop Iteration**
	```cpp
	    for(int i = 1; i < n; i++) {
	```
	This loop iterates through the `nums` array starting from the second element, checking whether each element is part of an increasing or decreasing subsequence.

9. **Condition Check (Decrease)**
	```cpp
	             if(nums[i] < nums[i - 1]) {
	```
	Checks if the current number `nums[i]` is less than the previous number `nums[i - 1]`. If true, it signifies a downward direction in the wiggle subsequence.

10. **Dynamic Programming Update (Decrease)**
	```cpp
	            down[i] = up[i - 1] + 1;
	```
	Updates the `down[i]` value, representing the longest subsequence ending in a downward direction, considering the previous subsequence's upward direction.

11. **Dynamic Programming Update (Maintain Up)**
	```cpp
	            up[i] = up[i - 1];
	```
	Maintains the previous `up[i - 1]` value since the current number does not extend the upward sequence.

12. **Condition Check (Increase)**
	```cpp
	        else if(nums[i] > nums[i - 1]) {            
	```
	Checks if the current number `nums[i]` is greater than the previous number `nums[i - 1]`. If true, it signifies an upward direction in the wiggle subsequence.

13. **Dynamic Programming Update (Increase)**
	```cpp
	            up[i] = down[i - 1] + 1;
	```
	Updates the `up[i]` value, representing the longest subsequence ending in an upward direction, considering the previous subsequence's downward direction.

14. **Dynamic Programming Update (Maintain Down)**
	```cpp
	            down[i] = down[i - 1];                
	```
	Maintains the previous `down[i - 1]` value since the current number does not extend the downward sequence.

15. **Condition Check (No Change)**
	```cpp
	        else {
	```
	Handles the case where the current number is equal to the previous number, meaning the sequence does not change direction.

16. **Dynamic Programming Update (No Change)**
	```cpp
	            down[i] = down[i - 1];
	```
	Maintains the previous `down[i - 1]` value since there is no change in direction.

17. **Dynamic Programming Update (Maintain Up)**
	```cpp
	            up[i]   =   up[i - 1];                
	```
	Maintains the previous `up[i - 1]` value since there is no change in direction.

18. **Return Result**
	```cpp
	    return max(down[n - 1], up[n - 1]);
	```
	Returns the maximum value between `down[n - 1]` and `up[n - 1]`, which represents the length of the longest wiggle subsequence.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is linear because we only need to iterate through the array once.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the storage required for the `up` and `down` arrays.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/wiggle-subsequence/description/)

---
{{< youtube IpWoZvKzpug >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
