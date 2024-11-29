
+++
authors = ["grid47"]
title = "Leetcode 553: Optimal Division"
date = "2024-09-12"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 553: Optimal Division in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/553.webp"
youtube = "SFNvfrvWxVQ"
youtube_upload_date="2019-11-27"
youtube_thumbnail="https://i.ytimg.com/vi_webp/SFNvfrvWxVQ/maxresdefault.webp"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/553.webp" 
    alt="A sequence of numbers being divided optimally, with each division step softly glowing as the optimal result is reached."
    caption="Solution to LeetCode 553: Optimal Division Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given an array of integers, you need to add parentheses in such a way that the division expression evaluates to the maximum possible value. The division must respect the adjacency of integers in the array.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input is an array of integers 'nums'. The adjacent integers will perform the division operation.
- **Example:** `Input: nums = [200, 50, 10]`
- **Constraints:**
	- 1 <= nums.length <= 10
	- 2 <= nums[i] <= 1000

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the corresponding expression with parentheses added optimally, resulting in the maximum evaluated value.
- **Example:** `Output: '200/(50/10)'`
- **Constraints:**
	- The returned expression should not have redundant parentheses.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to determine the optimal arrangement of parentheses in the given division expression to maximize the evaluated result.

- If the array has only one element, return the number as a string.
- If the array has two elements, return them with a '/' operator.
- For arrays with more than two elements, always add parentheses around all but the first element.
{{< dots >}}
### Problem Assumptions ✅
- The input is valid, and there is always a unique optimal expression.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: nums = [200, 50, 10]`  \
  **Explanation:** By adding parentheses around (50/10), the expression becomes '200/(50/10)', which gives the maximum value of 40.

{{< dots >}}
## Approach 🚀
To maximize the result of a division expression, we need to add parentheses in a way that minimizes the divisors in the sequence. This can be done by wrapping the divisions between all but the first number in parentheses.

### Initial Thoughts 💭
- When dividing numbers, larger numbers should ideally divide smaller ones.
- The expression with the maximum value will involve minimizing the number of divisors in the sequence by grouping all but the first numbers into parentheses.
- By focusing the parentheses around the numbers that need to be divided first, we maximize the value of the expression.
{{< dots >}}
### Edge Cases 🌐
- There are no edge cases with empty inputs, as the array will always have at least one number.
- The solution should work efficiently for arrays of size up to 10.
- Ensure that the parentheses are placed optimally, without redundant brackets that do not affect the order of operations.
- The input size is small, and the solution should handle this easily.
{{< dots >}}
## Code 💻
```cpp
string optimalDivision(vector<int>& nums) {
    string s = "";
    if(nums.size() == 1) return to_string(nums[0]);
    if(nums.size() == 2) return to_string(nums[0]) + '/' + to_string(nums[1]);

    for(int i = 0; i < nums.size(); i++) {
        s += to_string(nums[i]) + "/";
        if(i == 0)
            s += "(";
    }
    s[s.size() -1] = ')';
    return s;
}
```

This function generates an optimal division string for the given array of integers. The division result is formatted as a string where the first element is divided by the sum of the remaining elements enclosed in parentheses, with special handling for arrays of size 1 or 2.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	string optimalDivision(vector<int>& nums) {
	```
	Defines the function `optimalDivision`, which takes a vector of integers `nums` and returns the optimal division string for them.

2. **String Initialization**
	```cpp
	    string s = "";
	```
	Initializes an empty string `s` to build the division result.

3. **Edge Case Handling (Single Element)**
	```cpp
	    if(nums.size() == 1) return to_string(nums[0]);
	```
	Checks if the input vector contains only one element. If true, converts the element to a string and returns it as the result.

4. **Edge Case Handling (Two Elements)**
	```cpp
	    if(nums.size() == 2) return to_string(nums[0]) + '/' + to_string(nums[1]);
	```
	Handles the case where the input vector contains exactly two elements. Returns a string representing the division of the two elements.

5. **Main Loop (Array Traversal)**
	```cpp
	    for(int i = 0; i < nums.size(); i++) {
	```
	Starts a loop to traverse the `nums` array and build the division string.

6. **String Building**
	```cpp
	        s += to_string(nums[i]) + "/";
	```
	Appends each number in `nums` followed by a division sign ('/') to the string `s`.

7. **Condition (First Element)**
	```cpp
	        if(i == 0)
	```
	Checks if the current index is the first element in the array.

8. **Parentheses Addition**
	```cpp
	            s += "(";
	```
	If the current index is 0 (first element), appends an opening parenthesis to the string `s`.

9. **Parentheses Closure**
	```cpp
	    s[s.size() -1] = ')';
	```
	Replaces the last division sign with a closing parenthesis to properly close the division string.

10. **Return Statement**
	```cpp
	    return s;
	```
	Returns the formatted division string `s`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

Since we are processing the elements in a linear fashion, the time complexity is O(n).

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) because we store the resulting expression as a string.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/optimal-division/description/)

---
{{< youtube SFNvfrvWxVQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
