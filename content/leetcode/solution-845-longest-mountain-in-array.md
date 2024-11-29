
+++
authors = ["grid47"]
title = "Leetcode 845: Longest Mountain in Array"
date = "2024-08-14"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 845: Longest Mountain in Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","Dynamic Programming","Enumeration"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "uGnRaCqWflI"
youtube_upload_date="2020-11-16"
youtube_thumbnail="https://i.ytimg.com/vi/uGnRaCqWflI/maxresdefault.jpg"
comments = true
+++



---
Given an integer array `arr`, you need to find the length of the longest subarray that forms a mountain. A mountain subarray has the following properties: it must have at least three elements, the elements strictly increase to a peak, and then strictly decrease after the peak. If no such subarray exists, return 0.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given an integer array `arr` containing non-negative integers.
- **Example:** `Input: arr = [1, 3, 2, 4, 7, 5, 3]`
- **Constraints:**
	- 1 <= arr.length <= 10^4
	- 0 <= arr[i] <= 10^4

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the length of the longest mountain subarray. If no valid mountain exists, return 0.
- **Example:** `Output: 5`
- **Constraints:**
	- The array must have at least 3 elements to form a valid mountain.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the longest subarray in the form of a mountain. A peak must be surrounded by strictly increasing and strictly decreasing elements.

- Step 1: Traverse through the array and calculate the length of the subarray before and after each peak.
- Step 2: For each peak, calculate how far the elements on the left strictly increase and how far the elements on the right strictly decrease.
- Step 3: Keep track of the longest mountain found and return its length.
{{< dots >}}
### Problem Assumptions ✅
- The array is not empty and contains valid integers.
- The array elements are non-negative.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: [1, 3, 2, 4, 7, 5, 3]`  \
  **Explanation:** The longest mountain is [3, 2, 4, 7, 5], which has length 5.

- **Input:** `Input: [1, 2, 3, 4]`  \
  **Explanation:** There is no mountain because the array only increases.

- **Input:** `Input: [8, 7, 6, 5]`  \
  **Explanation:** There is no mountain because the array only decreases.

{{< dots >}}
## Approach 🚀
We will calculate the length of the longest mountain using two passes through the array. In the first pass, we compute the lengths of increasing and decreasing subsequences from each peak, and in the second pass, we identify the longest mountain.

### Initial Thoughts 💭
- The mountain is defined by a peak with elements strictly increasing before and strictly decreasing after it.
- We can calculate the lengths of increasing and decreasing subsequences for each potential peak.
- We can compute the lengths of increasing and decreasing sequences for each element and then use this information to calculate the mountain size.
{{< dots >}}
### Edge Cases 🌐
- The input cannot be empty since the array must have at least 3 elements to form a valid mountain.
- Ensure that the solution handles large inputs efficiently (up to 10^4 elements).
- Arrays with all equal elements cannot form a mountain.
- An array that only increases or only decreases does not form a valid mountain.
- The solution must operate in linear time to handle the maximum array length efficiently.
{{< dots >}}
## Code 💻
```cpp
int longestMountain(vector<int>& arr) {
    int res = 0;
    
    int n = arr.size();
    
    if(n < 3) return 0;

    vector<int> pre(n, 0), suf(n, 0);
    
    int cur = 0;
    for(int i = 1; i < n; i++) {
        if(arr[i] > arr[i - 1])
            cur++;
        else cur = 0;
        pre[i] = cur;
    }

    cur = 0;
    for(int i = n - 2; i >= 0; i--) {
        if(arr[i] > arr[i + 1])
            cur++;
        else cur = 0;
        suf[i] = cur;
    }
    
    for(int i = 0; i < n; i++)
        if(pre[i] > 0 && suf[i] > 0)
    res = max(pre[i] + suf[i] + 1, res);
    
    return res == 1? 0: res;
}
```

This function calculates the length of the longest mountain in an array. A mountain is defined as a sequence of integers that is strictly increasing, followed by strictly decreasing, with at least one element in each part.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int longestMountain(vector<int>& arr) {
	```
	This is the function declaration where the longestMountain function is defined. It takes a reference to a vector of integers as input and returns an integer.

2. **Variable Initialization**
	```cpp
	    int res = 0;
	```
	The result variable 'res' is initialized to 0. This will store the length of the longest mountain.

3. **Variable Initialization**
	```cpp
	    
	```
	Empty line for readability.

4. **Array Size Calculation**
	```cpp
	    int n = arr.size();
	```
	The size of the array 'arr' is calculated and stored in variable 'n'.

5. **Conditional Check**
	```cpp
	    if(n < 3) return 0;
	```
	If the array size is less than 3, return 0 as a valid mountain cannot exist.

6. **Array Initialization**
	```cpp
	    vector<int> pre(n, 0), suf(n, 0);
	```
	Two vectors 'pre' and 'suf' are initialized to store the lengths of increasing and decreasing sequences.

7. **Variable Initialization**
	```cpp
	    int cur = 0;
	```
	The variable 'cur' is initialized to 0. It will be used to track the current length of increasing or decreasing sequences.

8. **Loop Start**
	```cpp
	    for(int i = 1; i < n; i++) {
	```
	Loop starts to fill the 'pre' vector with the lengths of increasing sequences from the left.

9. **Conditional Check**
	```cpp
	        if(arr[i] > arr[i - 1])
	```
	If the current element is greater than the previous element, it is part of an increasing sequence.

10. **Increment Variable**
	```cpp
	            cur++;
	```
	Increment the 'cur' variable to track the length of the increasing sequence.

11. **Reset Variable**
	```cpp
	        else cur = 0;
	```
	If the current element is not greater than the previous, reset 'cur' to 0.

12. **Array Update**
	```cpp
	        pre[i] = cur;
	```
	Store the current length of the increasing sequence in the 'pre' array.

13. **Variable Reset**
	```cpp
	    cur = 0;
	```
	Reset 'cur' to 0 for the second loop.

14. **Loop Start**
	```cpp
	    for(int i = n - 2; i >= 0; i--) {
	```
	Second loop starts to fill the 'suf' array with the lengths of decreasing sequences from the right.

15. **Conditional Check**
	```cpp
	        if(arr[i] > arr[i + 1])
	```
	If the current element is greater than the next element, it is part of a decreasing sequence.

16. **Increment Variable**
	```cpp
	            cur++;
	```
	Increment the 'cur' variable to track the length of the decreasing sequence.

17. **Reset Variable**
	```cpp
	        else cur = 0;
	```
	If the current element is not greater than the next, reset 'cur' to 0.

18. **Array Update**
	```cpp
	        suf[i] = cur;
	```
	Store the current length of the decreasing sequence in the 'suf' array.

19. **Loop Start**
	```cpp
	    for(int i = 0; i < n; i++)
	```
	Loop through the array to check if both 'pre[i]' and 'suf[i]' are greater than 0, indicating a valid mountain.

20. **Conditional Check**
	```cpp
	        if(pre[i] > 0 && suf[i] > 0)
	```
	Check if both increasing and decreasing sequences are present at the current index.

21. **Update Result**
	```cpp
	    res = max(pre[i] + suf[i] + 1, res);
	```
	Update the result with the maximum length of the mountain found.

22. **Return Statement**
	```cpp
	    return res == 1? 0: res;
	```
	Return the result. If the mountain length is 1, return 0, as it doesn't meet the criteria of a mountain.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is linear, as we traverse the array twice: once for increasing subsequences and once for decreasing subsequences.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) because we store the lengths of increasing and decreasing subsequences in separate arrays.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/longest-mountain-in-array/description/)

---
{{< youtube uGnRaCqWflI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
