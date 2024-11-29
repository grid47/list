
+++
authors = ["grid47"]
title = "Leetcode 2683: Neighboring Bitwise XOR"
date = "2024-02-12"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2683: Neighboring Bitwise XOR in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Bit Manipulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "DDQR_mDTTFI"
youtube_upload_date="2023-05-14"
youtube_thumbnail="https://i.ytimg.com/vi/DDQR_mDTTFI/maxresdefault.jpg"
comments = true
+++



---
You are given a binary array `derived` of length `n`. The `derived` array is obtained by computing the bitwise XOR of adjacent values in an original binary array. Specifically, for each index `i`, if `i` is the last index, `derived[i] = original[i] ⊕ original[0]`, otherwise, `derived[i] = original[i] ⊕ original[i + 1]`. The task is to determine if there exists a valid binary array `original` that could have formed the given `derived` array.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given a binary array `derived`, where each value is either 0 or 1. You need to determine if there exists a binary array `original` such that applying the XOR operation on adjacent values produces `derived`.
- **Example:** `Input: derived = [0, 1, 1]`
- **Constraints:**
	- 1 <= derived.length <= 10^5
	- The values in the derived array are either 0 or 1.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return `true` if a valid binary array `original` exists, otherwise return `false`.
- **Example:** `Output: true`
- **Constraints:**
	- The output should be a boolean value.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to check if there exists a valid `original` array that could have been transformed into the `derived` array using the bitwise XOR operation.

- Step 1: For the given array `derived`, initialize two variables to track the XOR of elements.
- Step 2: Iterate through the `derived` array and compute the cumulative XOR to check if a valid `original` exists.
- Step 3: Return `true` if the cumulative XOR values meet the conditions for a valid `original` array, otherwise return `false`.
{{< dots >}}
### Problem Assumptions ✅
- The derived array will always be valid (it will not contain values outside the range of 0 and 1).
- The problem will be solved by checking the XOR conditions across the array.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: derived = [0, 1, 1]`  \
  **Explanation:** The `derived` array is obtained by XORing adjacent values of the `original` array. A valid `original` array that satisfies this condition is [0, 1, 0]. Therefore, the output is true.

- **Input:** `Input: derived = [1, 0]`  \
  **Explanation:** It is not possible to create a valid `original` array from this `derived` array using the XOR operation, so the output is false.

{{< dots >}}
## Approach 🚀
We can determine if a valid `original` array exists by computing the XOR of elements in `derived` and checking if the cumulative XOR satisfies certain conditions.

### Initial Thoughts 💭
- The XOR operation is reversible, so we can check the feasibility of creating the `original` array by comparing the XOR values across adjacent elements.
- By using XOR properties, we can efficiently determine if a valid `original` exists without explicitly constructing it.
{{< dots >}}
### Edge Cases 🌐
- The input array is always non-empty as per the constraints.
- The solution needs to be efficient enough to handle arrays with up to 100,000 elements.
- The solution should handle cases where the `derived` array contains all 0's or all 1's.
- The values in `derived` are either 0 or 1, and the length of the array is within the specified constraints.
{{< dots >}}
## Code 💻
```cpp
bool doesValidArrayExist(vector<int>& nums) {
    int n = nums.size();
    // same 0 0
    
    int fst = 0, scd = 1;
    for(int i = 0; i < n; i++) {
        fst ^= nums[i];
        scd ^= nums[i];
    }
    if(fst == 0 || scd == 1) return true;
    return false;
    // same 1 1
    // different 1 0
    // different 0 1        
}
```

The function 'doesValidArrayExist' checks if a valid array exists based on a given condition involving XOR operations. The function iterates through the array and applies XOR on two variables, 'fst' and 'scd', and then checks if either of them satisfies certain conditions to return true or false.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	bool doesValidArrayExist(vector<int>& nums) {
	```
	The function 'doesValidArrayExist' takes a reference to a vector 'nums' and returns a boolean indicating whether a valid array exists based on the XOR conditions.

2. **Variable Initialization**
	```cpp
	    int n = nums.size();
	```
	The variable 'n' is initialized to the size of the 'nums' vector, representing the number of elements in the array.

3. **Variable Initialization**
	```cpp
	    int fst = 0, scd = 1;
	```
	Two variables, 'fst' and 'scd', are initialized to 0 and 1 respectively. These variables will be used to accumulate the XOR results as the loop iterates through 'nums'.

4. **Loop**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	A for loop is initiated to iterate through the elements of the 'nums' array from index 0 to 'n-1'.

5. **XOR Operation**
	```cpp
	        fst ^= nums[i];
	```
	The variable 'fst' is updated by applying the XOR operation between its current value and the current element of 'nums'. This operation will accumulate the XOR of all elements.

6. **XOR Operation**
	```cpp
	        scd ^= nums[i];
	```
	The variable 'scd' is updated by applying the XOR operation between its current value and the current element of 'nums'. This will accumulate a separate XOR of all elements.

7. **Condition Check**
	```cpp
	    if(fst == 0 || scd == 1) return true;
	```
	The function checks if either 'fst' is 0 or 'scd' is 1. If this condition is satisfied, it returns true, indicating that a valid array exists.

8. **Return**
	```cpp
	    return false;
	```
	If the condition is not met, the function returns false, indicating that no valid array exists.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

We iterate through the array once to check the XOR conditions, which gives a linear time complexity.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is constant as we only need a few variables to track the XOR results.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/neighboring-bitwise-xor/description/)

---
{{< youtube DDQR_mDTTFI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
