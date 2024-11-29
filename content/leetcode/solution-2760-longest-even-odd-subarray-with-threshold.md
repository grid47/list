
+++
authors = ["grid47"]
title = "Leetcode 2760: Longest Even Odd Subarray With Threshold"
date = "2024-02-05"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2760: Longest Even Odd Subarray With Threshold in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Sliding Window"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "_XNaJUXSh04"
youtube_upload_date="2023-07-02"
youtube_thumbnail="https://i.ytimg.com/vi/_XNaJUXSh04/maxresdefault.jpg"
comments = true
+++



---
You are given a 0-indexed integer array 'nums' and an integer 'threshold'. Find the length of the longest subarray of 'nums' that satisfies the following conditions: (1) 'nums[l]' is even, (2) the elements alternate between even and odd, and (3) all elements in the subarray are <= threshold.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You will be given an array of integers, 'nums', and a threshold integer.
- **Example:** `nums = [1, 4, 3, 2, 7], threshold = 5`
- **Constraints:**
	- 1 <= nums.length <= 100
	- 1 <= nums[i] <= 100
	- 1 <= threshold <= 100

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the length of the longest subarray satisfying the conditions.
- **Example:** `For nums = [1, 4, 3, 2, 7] and threshold = 5, the output is 4.`
- **Constraints:**
	- Return the length of the longest valid subarray.

{{< dots >}}
### Core Logic 🔍
**Goal:** Find the longest subarray that satisfies all three conditions: starting with an even number, alternating between even and odd, and all elements <= threshold.

- Iterate through the array and check the conditions for each potential subarray.
- Track the length of valid subarrays and update the result when a longer valid subarray is found.
{{< dots >}}
### Problem Assumptions ✅
- The input array will have at least one element.
{{< dots >}}
## Examples 🧩
- **Input:** `For nums = [1, 4, 3, 2, 7] and threshold = 5`  \
  **Explanation:** We are looking for the longest subarray that starts with an even number, alternates between even and odd numbers, and has all numbers <= 5. The valid subarray is [4, 3, 2, 7], which satisfies all conditions, and its length is 4.

{{< dots >}}
## Approach 🚀
The solution involves iterating over the array, checking for subarrays that meet the required conditions, and keeping track of the longest valid subarray.

### Initial Thoughts 💭
- The subarray must start with an even number and alternate between even and odd numbers.
- We need to check if all numbers in the subarray are <= threshold.
- To find the longest valid subarray, we can iterate through the array while checking if the current subarray meets the conditions.
{{< dots >}}
### Edge Cases 🌐
- The input array will always have at least one element.
- The array is small enough (up to 100 elements) that the solution can handle it in a reasonable amount of time.
- All elements in the array may be odd or even, and the threshold may be larger than the maximum element in the array.
- Ensure that the subarrays are contiguous and that all elements satisfy the threshold condition.
{{< dots >}}
## Code 💻
```cpp
  int longestAlternatingSubarray(vector<int>& n, int threshold) {
int res = 0;
for (int l = 0, cnt = 0; l < n.size(); ++l) {
    if (n[l] <= threshold)
        cnt = cnt == 0 ?
            n[l] % 2 == 0 :
            n[l] % 2 == n[l - 1] % 2 ? n[l] % 2 == 0 : cnt + 1;
    else
        cnt = 0;
    res = max(res, cnt);
}
return res;
  }
```

This function calculates the length of the longest alternating subarray of numbers in a given array `n`, where each element is less than or equal to a given threshold. The alternating subarray should alternate between even and odd numbers.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	  int longestAlternatingSubarray(vector<int>& n, int threshold) {
	```
	Defines the function `longestAlternatingSubarray`, which takes a vector of integers `n` and an integer `threshold` as input and returns the length of the longest alternating subarray.

2. **Variable Initialization**
	```cpp
	int res = 0;
	```
	Initializes the variable `res` to 0, which will store the length of the longest alternating subarray found during the loop.

3. **For Loop Setup**
	```cpp
	for (int l = 0, cnt = 0; l < n.size(); ++l) {
	```
	Starts a for loop with index `l` to iterate through the array `n`. It also initializes a counter `cnt` to track the length of the current alternating subarray.

4. **Threshold Check**
	```cpp
	    if (n[l] <= threshold)
	```
	Checks if the current element `n[l]` is less than or equal to the specified `threshold`. If it is, the element can be considered for the alternating subarray.

5. **First Alternating Element**
	```cpp
	        cnt = cnt == 0 ?
	```
	If `cnt` is 0 (i.e., the first element of a potential alternating subarray), it checks whether the current element is even. If it is even, it sets `cnt` to 1 to start the subarray.

6. **Alternating Check**
	```cpp
	            n[l] % 2 == 0 :
	```
	Checks if the current element is even (i.e., `n[l] % 2 == 0`). If so, `cnt` is initialized to 1.

7. **Alternating Subarray Continuation**
	```cpp
	            n[l] % 2 == n[l - 1] % 2 ? n[l] % 2 == 0 : cnt + 1;
	```
	If the current element is part of an alternating subarray, it checks if the element has the same parity (odd/even) as the previous element. If it alternates correctly, it increments `cnt`; otherwise, it resets `cnt` to start a new alternating subarray.

8. **Element Greater Than Threshold**
	```cpp
	    else
	```
	If the current element exceeds the threshold, it resets the counter `cnt` because the element cannot be part of the alternating subarray.

9. **Reset Counter After Invalid Element**
	```cpp
	        cnt = 0;
	```
	Resets the counter `cnt` to 0 if the current element is greater than the threshold, indicating the end of a potential alternating subarray.

10. **Update Result**
	```cpp
	    res = max(res, cnt);
	```
	Updates the result `res` to the maximum value between the current longest alternating subarray length (`res`) and the current subarray length (`cnt`).

11. **Return Result**
	```cpp
	return res;
	```
	Returns the result `res`, which contains the length of the longest alternating subarray found in the array `n`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n), where n is the length of the input array.
- **Average Case:** O(n).
- **Worst Case:** O(n).

We iterate through the array once, checking the conditions for each element, which results in linear time complexity.

### Space Complexity 💾
- **Best Case:** O(1).
- **Worst Case:** O(1).

We only need a few variables to store the current subarray length and the result, so the space complexity is constant.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/longest-even-odd-subarray-with-threshold/description/)

---
{{< youtube _XNaJUXSh04 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
