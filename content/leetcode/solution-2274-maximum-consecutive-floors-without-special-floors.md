
+++
authors = ["grid47"]
title = "Leetcode 2274: Maximum Consecutive Floors Without Special Floors"
date = "2024-03-24"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2274: Maximum Consecutive Floors Without Special Floors in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "ZQ6iiXxEhRY"
youtube_upload_date="2022-05-15"
youtube_thumbnail="https://i.ytimg.com/vi_webp/ZQ6iiXxEhRY/maxresdefault.webp"
comments = true
+++



---
Alice has rented a sequence of floors in a building from `bottom` to `top` (inclusive). Some of these floors are designated as special floors where relaxation occurs. You are given an array `special` that contains the indices of these special floors. Your task is to determine the maximum number of consecutive floors that are not designated as special.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given two integers, `bottom` and `top`, representing the range of floors rented. You are also given an integer array `special` where each element represents a special floor within this range.
- **Example:** `Input: bottom = 3, top = 10, special = [4, 5, 8]`
- **Constraints:**
	- 1 <= special.length <= 10^5
	- 1 <= bottom <= special[i] <= top <= 10^9
	- All the values in the special array are unique.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the maximum number of consecutive floors that do not have a special floor.
- **Example:** `Output: 3`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** Find the longest stretch of consecutive floors without any special floor in the given range.

- Sort the special floors in ascending order.
- Track the difference between each adjacent pair of special floors and find the maximum gap.
- Include the gap before the first special floor and after the last special floor.
- Return the maximum gap.
{{< dots >}}
### Problem Assumptions ✅
- The special floors are within the range from `bottom` to `top`.
- There are no repeated special floors in the input array.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: bottom = 3, top = 10, special = [4, 5, 8]`  \
  **Explanation:** The special floors are 4, 5, and 8. The largest gap is between 7 and 10, which contains 3 consecutive floors. Therefore, the result is 3.

- **Input:** `Input: bottom = 6, top = 8, special = [6, 7, 8]`  \
  **Explanation:** All floors are special, so there are no consecutive floors without a special floor. The result is 0.

{{< dots >}}
## Approach 🚀
To solve this problem, we first sort the special floors and then calculate the gaps between consecutive special floors, including the initial gap and the final gap. The largest of these gaps will be the maximum number of consecutive non-special floors.

### Initial Thoughts 💭
- Sorting the special floors helps easily identify the gaps between them.
- We can treat the gap before the first special floor and after the last special floor as part of the solution.
- The problem can be solved by calculating the gaps between adjacent special floors and finding the largest gap. This involves sorting and a linear scan.
{{< dots >}}
### Edge Cases 🌐
- The special array will not be empty, but ensure that `bottom` and `top` are valid inputs.
- For large inputs with up to 100,000 special floors, the solution should handle sorting efficiently.
- If the special floors are at the start or end of the range, handle the gaps before and after properly.
- The solution should work efficiently even when the range between `bottom` and `top` is very large (up to 10^9).
{{< dots >}}
## Code 💻
```cpp
int maxConsecutive(int bottom, int top, vector<int>& spec) {

    sort(spec.begin(), spec.end());
    int prv = bottom - 1, n = spec.size();

    int res = 0;
    for(int cur : spec) {
        res = max(res, cur - prv - 1);
        prv = cur > prv ? cur : prv;
    }
    res = max(res, top - prv);

    return res;
}
};

// bottom - top
// spec
```

This code defines the function `maxConsecutive`, which calculates the maximum number of consecutive integers that are not present in the `spec` array within the range [bottom, top]. The function sorts the array `spec`, iterates through it, and finds gaps between consecutive integers, returning the largest gap.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int maxConsecutive(int bottom, int top, vector<int>& spec) {
	```
	This is the function header for `maxConsecutive`, which calculates the largest gap between consecutive numbers in a specified range that are missing from the array `spec`.

2. **Sorting**
	```cpp
	    sort(spec.begin(), spec.end());
	```
	Sorts the vector `spec` in ascending order to make it easier to identify gaps between consecutive integers.

3. **Variable Initialization**
	```cpp
	    int prv = bottom - 1, n = spec.size();
	```
	Initializes `prv` to `bottom - 1` (a marker for the last considered integer before `bottom`) and `n` to the size of the `spec` vector.

4. **Variable Initialization**
	```cpp
	    int res = 0;
	```
	Initializes `res` to 0, which will store the maximum gap between consecutive integers.

5. **Loop Start**
	```cpp
	    for(int cur : spec) {
	```
	Starts a for-each loop to iterate through each element `cur` in the sorted `spec` vector.

6. **Gap Calculation**
	```cpp
	        res = max(res, cur - prv - 1);
	```
	Calculates the gap between the current number `cur` and the previous number `prv`, and updates `res` if this gap is larger than the previous maximum gap.

7. **Update Previous Value**
	```cpp
	        prv = cur > prv ? cur : prv;
	```
	Updates `prv` to the maximum of `prv` and `cur` to ensure that `prv` always holds the most recent number considered.

8. **Final Gap Calculation**
	```cpp
	    res = max(res, top - prv);
	```
	After the loop, calculates the gap between the last element `prv` and the `top` value, and updates `res` if this final gap is larger than the previous maximum.

9. **Return Statement**
	```cpp
	    return res;
	```
	Returns the value of `res`, which represents the maximum consecutive gap between numbers that are missing in the range [bottom, top].

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n)
- **Average Case:** O(n log n)
- **Worst Case:** O(n log n)

The worst-case time complexity is O(n log n), where n is the number of special floors, due to the sorting step.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(n)

The space complexity is O(n) due to the storage required for the special floors array.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-consecutive-floors-without-special-floors/description/)

---
{{< youtube ZQ6iiXxEhRY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
