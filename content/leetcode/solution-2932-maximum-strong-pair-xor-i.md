
+++
authors = ["grid47"]
title = "Leetcode 2932: Maximum Strong Pair XOR I"
date = "2024-01-18"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2932: Maximum Strong Pair XOR I in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Bit Manipulation","Trie","Sliding Window"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "n6CncKaYGwk"
youtube_upload_date="2023-11-14"
youtube_thumbnail="https://i.ytimg.com/vi/n6CncKaYGwk/maxresdefault.jpg"
comments = true
+++



---
You are given a 0-indexed array 'nums'. A pair of integers 'x' and 'y' is called a strong pair if it satisfies the condition |x - y| <= min(x, y). Your task is to find two integers from 'nums' that form a strong pair and have the highest possible bitwise XOR value among all strong pairs in the array. You can pick the same integer twice.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given a 0-indexed integer array 'nums'.
- **Example:** `For nums = [1, 2, 3, 4, 5], the maximum XOR of a strong pair is 7.`
- **Constraints:**
	- 1 <= nums.length <= 50
	- 1 <= nums[i] <= 100

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the maximum XOR value among all possible strong pairs in the array 'nums'.
- **Example:** `For nums = [10, 100], the output will be 0.`
- **Constraints:**
	- The result will be a non-negative integer representing the maximum XOR value.

{{< dots >}}
### Core Logic 🔍
**Goal:** Find the maximum XOR value of strong pairs in the given array 'nums'.

- Sort the array 'nums' to simplify comparison and checking for strong pairs.
- Iterate over all possible pairs (i, j) in the array.
- For each pair, check if it satisfies the strong pair condition: |nums[i] - nums[j]| <= min(nums[i], nums[j]).
- Calculate the XOR for all valid pairs and track the maximum XOR value.
{{< dots >}}
### Problem Assumptions ✅
- The array will contain integers in the given range, and the XOR operation is safe for these values.
{{< dots >}}
## Examples 🧩
- **Input:** `Example 1: nums = [1, 2, 3, 4, 5]`  \
  **Explanation:** The strong pairs (1, 1), (1, 2), (2, 2), (2, 3), (2, 4), (3, 3), (3, 4), (3, 5), (4, 4), (4, 5), and (5, 5) are formed. The maximum XOR value from these pairs is 7 (from pair (3, 4)).

- **Input:** `Example 2: nums = [10, 100]`  \
  **Explanation:** There are two strong pairs: (10, 10) and (100, 100), both of which yield an XOR of 0.

- **Input:** `Example 3: nums = [5, 6, 25, 30]`  \
  **Explanation:** The strong pairs (5, 5), (5, 6), (6, 6), (25, 25), (25, 30), and (30, 30) are formed. The maximum XOR value from these pairs is 7 (from pair (25, 30)).

{{< dots >}}
## Approach 🚀
The approach involves checking all possible pairs and evaluating their XOR values while ensuring the strong pair condition is met.

### Initial Thoughts 💭
- A brute force approach works for this problem due to the small constraints (array length up to 50).
- We can simplify the pair generation by sorting the array and then checking for valid strong pairs in a nested loop.
{{< dots >}}
### Edge Cases 🌐
- There will always be at least one element in the input array, so no need to handle empty inputs.
- The maximum input size is 50 elements, so the solution can comfortably check all pairs.
- If all elements in the array are the same, the XOR of all pairs will be zero.
- The approach works efficiently within the given constraints.
{{< dots >}}
## Code 💻
```cpp
int maximumStrongPairXor(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size(), res = 0;
    for(int i = 0; i < n; i++)
    for(int j = i; j < n; j++) {
        if((nums[j] - nums[i] <= nums[i]) && (res <= (nums[i] ^ nums[j]))){
            // cout << nums[i] << " " << nums[j] << "\n";
            res = max(res, nums[i] ^ nums[j]);
        }
    }
    return res;
}
```

This function calculates the maximum XOR value of a 'strong pair' of numbers from the given vector. A 'strong pair' is defined as a pair of numbers where the difference between them is less than or equal to one of the numbers, and the XOR value of the pair is greater than the current result.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int maximumStrongPairXor(vector<int>& nums) {
	```
	Defines the function 'maximumStrongPairXor' which takes a vector of integers 'nums' and returns the maximum XOR value of a strong pair.

2. **Sorting**
	```cpp
	    sort(nums.begin(), nums.end());
	```
	Sorts the input vector 'nums' in ascending order to simplify the search for valid pairs.

3. **Variable Initialization**
	```cpp
	    int n = nums.size(), res = 0;
	```
	Initializes 'n' to the size of the vector and 'res' to 0, which will hold the maximum XOR value of the valid pairs.

4. **Outer Loop**
	```cpp
	    for(int i = 0; i < n; i++)
	```
	Starts the outer loop over each element in the sorted vector 'nums'.

5. **Inner Loop**
	```cpp
	    for(int j = i; j < n; j++) {
	```
	Starts the inner loop, which iterates through the remaining elements starting from the current element 'i'.

6. **Condition Check**
	```cpp
	        if((nums[j] - nums[i] <= nums[i]) && (res <= (nums[i] ^ nums[j]))) {
	```
	Checks if the difference between the two numbers 'nums[j]' and 'nums[i]' is less than or equal to 'nums[i]' and if the XOR of the pair is greater than the current result 'res'.

7. **Update Result**
	```cpp
	            res = max(res, nums[i] ^ nums[j]);
	```
	Updates 'res' with the maximum XOR value found between the current pair 'nums[i]' and 'nums[j]'.

8. **Return Result**
	```cpp
	    return res;
	```
	Returns the maximum XOR value of any valid 'strong pair' found in the input vector.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n^2)
- **Average Case:** O(n^2)
- **Worst Case:** O(n^2)

Since we need to check all pairs of elements in the array, the time complexity is O(n^2).

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to sorting the array.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-strong-pair-xor-i/description/)

---
{{< youtube n6CncKaYGwk >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
