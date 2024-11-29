
+++
authors = ["grid47"]
title = "Leetcode 2178: Maximum Split of Positive Even Integers"
date = "2024-04-03"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2178: Maximum Split of Positive Even Integers in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Backtracking","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "fM7MJFhrm-8"
youtube_upload_date="2022-02-20"
youtube_thumbnail="https://i.ytimg.com/vi_webp/fM7MJFhrm-8/maxresdefault.webp"
comments = true
+++



---
Given an integer `finalSum`, split it into a sum of as many unique positive even integers as possible. If such a split is not possible, return an empty array.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a single integer `finalSum`.
- **Example:** `18`
- **Constraints:**
	- 1 <= finalSum <= 10^10

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is a list of unique even integers that sum up to `finalSum`. If no valid split is possible, return an empty array.
- **Example:** `[2, 4, 6, 8]`
- **Constraints:**
	- The integers must be positive, even, and unique.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the maximum number of unique positive even integers that sum up to `finalSum`.

- Check if `finalSum` is even. If it is not, return an empty array.
- Start with the smallest even integer (2), and keep adding the next even integers (4, 6, 8, ...) until the sum exceeds `finalSum`.
- If there is any remaining sum, adjust the last integer in the list to make the total sum equal to `finalSum`.
{{< dots >}}
### Problem Assumptions ✅
- The integer `finalSum` is positive.
{{< dots >}}
## Examples 🧩
- **Input:** `18`  \
  **Explanation:** The number 18 can be expressed as the sum of four unique even integers: 2 + 4 + 6 + 8.

{{< dots >}}
## Approach 🚀
The approach involves adding consecutive even integers until the sum reaches or exceeds `finalSum`, and then adjusting the last integer if necessary.

### Initial Thoughts 💭
- The sum of unique positive even integers grows quickly, so we can stop once we reach or exceed `finalSum`.
- Start from the smallest even integer and continue adding consecutive even integers until the sum is close to `finalSum`.
{{< dots >}}
### Edge Cases 🌐
- If `finalSum` is an odd number, return an empty list.
- Ensure the solution works efficiently for large inputs, up to 10^10.
- For very small values like `finalSum = 1`, the result should be an empty list since no even numbers can sum to 1.
- Ensure the solution handles large values of `finalSum` efficiently.
{{< dots >}}
## Code 💻
```cpp
vector<long long> ans;
vector<long long> maximumEvenSplit(long long sum) {
    vector<long long> tmp;
    if(sum % 2 == 1) return ans;
    
    int cur = 2;
    while(sum >= cur) {
        ans.push_back(cur);
        sum -= cur;
        cur += 2;
    }
    if(sum > 0) ans[ans.size() - 1] += sum;
    
    return ans;
}

```

This function, `maximumEvenSplit`, takes a number `sum` and splits it into even parts (starting from 2) such that their sum equals the original `sum`. If `sum` is odd, an empty vector is returned. The result is returned as a vector of long long integers.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Initialization**
	```cpp
	vector<long long> ans;
	```
	Initialize an empty vector `ans` to store the result.

2. **Function Definition**
	```cpp
	vector<long long> maximumEvenSplit(long long sum) {
	```
	Define the function `maximumEvenSplit` that takes a long long integer `sum` and returns a vector of long long integers.

3. **Variable Initialization**
	```cpp
	    vector<long long> tmp;
	```
	Declare an unused vector `tmp`. This line doesn't impact the algorithm and could be removed.

4. **Condition Check**
	```cpp
	    if(sum % 2 == 1) return ans;
	```
	Check if `sum` is odd. If true, return the empty vector `ans`.

5. **Variable Initialization**
	```cpp
	    int cur = 2;
	```
	Initialize the variable `cur` to 2, which will be used to split the sum into even numbers.

6. **Loop**
	```cpp
	    while(sum >= cur) {
	```
	Start a while loop that continues as long as `sum` is greater than or equal to `cur`.

7. **Vector Modification**
	```cpp
	        ans.push_back(cur);
	```
	Push the current value of `cur` into the `ans` vector.

8. **Update Sum**
	```cpp
	        sum -= cur;
	```
	Reduce `sum` by the value of `cur`.

9. **Update Variable**
	```cpp
	        cur += 2;
	```
	Increase `cur` by 2 to maintain the even sequence (2, 4, 6, 8, ...).

10. **Final Adjustment**
	```cpp
	    if(sum > 0) ans[ans.size() - 1] += sum;
	```
	If there's any remaining `sum` (less than the next even number), add it to the last element of the `ans` vector.

11. **Return Statement**
	```cpp
	    return ans;
	```
	Return the `ans` vector, which contains the even splits of `sum`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is linear with respect to the number of integers required to reach `finalSum`.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is linear because we store the list of even integers.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-split-of-positive-even-integers/description/)

---
{{< youtube fM7MJFhrm-8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
