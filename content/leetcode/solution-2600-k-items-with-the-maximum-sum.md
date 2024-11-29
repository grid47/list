
+++
authors = ["grid47"]
title = "Leetcode 2600: K Items With the Maximum Sum"
date = "2024-02-21"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2600: K Items With the Maximum Sum in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Greedy"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "HmEYKbfjCLA"
youtube_upload_date="2023-03-26"
youtube_thumbnail="https://i.ytimg.com/vi_webp/HmEYKbfjCLA/maxresdefault.webp"
comments = true
+++



---
You are given a bag with items, where each item has a number written on it, which could be 1, 0, or -1. You are also given the counts of items with 1s, 0s, and -1s, as well as a positive integer k. Your task is to pick exactly k items from the bag, maximizing the sum of the numbers written on the selected items.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of four non-negative integers: numOnes, numZeros, numNegOnes, and an integer k.
- **Example:** `For numOnes = 5, numZeros = 3, numNegOnes = 2, k = 4.`
- **Constraints:**
	- 0 <= numOnes, numZeros, numNegOnes <= 50
	- 0 <= k <= numOnes + numZeros + numNegOnes

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the maximum possible sum of the k selected items.
- **Example:** `For numOnes = 5, numZeros = 3, numNegOnes = 2, k = 4, the output is 5.`
- **Constraints:**
	- The sum will be a non-negative integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** Maximize the sum of selected items by picking the most valuable items, prioritizing 1s first, then 0s, and finally -1s.

- 1. First, pick as many 1s as possible from the bag until reaching k items.
- 2. If k items are still not picked, choose 0s next (as they do not affect the sum).
- 3. If k items are still left, select -1s (which decrease the sum).
{{< dots >}}
### Problem Assumptions ✅
- The array size is manageable, as the maximum sum of numOnes, numZeros, and numNegOnes is 150.
{{< dots >}}
## Examples 🧩
- **Input:** `For numOnes = 5, numZeros = 3, numNegOnes = 2, k = 4`  \
  **Explanation:** Select 4 items with 1s to maximize the sum, which gives a total sum of 5.

- **Input:** `For numOnes = 4, numZeros = 2, numNegOnes = 1, k = 3`  \
  **Explanation:** Select 3 items with 1s to maximize the sum, which gives a total sum of 3.

{{< dots >}}
## Approach 🚀
The approach is to select items with the highest possible values (1s first), followed by zeros, and finally, -1s, ensuring that exactly k items are selected.

### Initial Thoughts 💭
- Selecting 1s first is optimal as they contribute the most to the sum.
- Zeros do not affect the sum, so we can use them as fillers if needed.
- Negatives should be avoided if possible, as they reduce the sum.
- We need to carefully prioritize the selection to maximize the sum.
{{< dots >}}
### Edge Cases 🌐
- If k is 0, the sum will always be 0, regardless of the contents of the bag.
- For large inputs, the solution should ensure that the selection logic is efficient to handle up to 150 items.
- If k is exactly the sum of available 1s and 0s, no negative numbers will be selected.
- Handle cases where there are no 1s or no -1s efficiently.
{{< dots >}}
## Code 💻
```cpp
int kItemsWithMaximumSum(int one, int zero, int neg, int k) {
    int sum = 0;
    sum += min(one, k);
    k -= min(one, k);
    if(k > 0) {
        k -= min(zero, k);
    }
    if(k > 0) {
        sum -= min(neg, k);
        k -= min(neg, k);
    }
    return sum;
}
```

This function calculates the maximum sum achievable by selecting 'k' items from three categories: positive, zero, and negative. It adds positive values, subtracts negative values, and takes zeros into account to maximize the sum.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int kItemsWithMaximumSum(int one, int zero, int neg, int k) {
	```
	Defines the function 'kItemsWithMaximumSum' that takes four arguments: 'one', 'zero', 'neg' representing counts of 1s, 0s, and negative numbers, and 'k' representing the number of items to select.

2. **Variable Initialization**
	```cpp
	    int sum = 0;
	```
	Initializes the variable 'sum' to 0, which will accumulate the maximum sum by selecting the appropriate number of items.

3. **Add Positive Items**
	```cpp
	    sum += min(one, k);
	```
	Adds the minimum of 'one' and 'k' to 'sum', representing the positive numbers that can be selected.

4. **Update Remaining Selection**
	```cpp
	    k -= min(one, k);
	```
	Decreases 'k' by the number of positive items selected, to track the remaining items to select.

5. **Check for Zero Items**
	```cpp
	    if(k > 0) {
	```
	Checks if there are still items left to select (if 'k' is greater than 0).

6. **Add Zero Items**
	```cpp
	        k -= min(zero, k);
	```
	Subtracts the minimum of 'zero' and 'k' from 'k', selecting zeros if any remaining items are left to choose.

7. **Check for Negative Items**
	```cpp
	    if(k > 0) {
	```
	Checks if there are still items to be selected after choosing positive and zero items.

8. **Subtract Negative Items**
	```cpp
	        sum -= min(neg, k);
	```
	Subtracts the minimum of 'neg' and 'k' from 'sum', selecting negative values if necessary.

9. **Update Remaining Negative Selection**
	```cpp
	        k -= min(neg, k);
	```
	Decreases 'k' by the number of negative items selected.

10. **Return Result**
	```cpp
	    return sum;
	```
	Returns the accumulated 'sum' as the result, which represents the maximum sum achievable by selecting 'k' items.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(1)
- **Average Case:** O(1)
- **Worst Case:** O(1)

The time complexity is constant as the number of operations is minimal for each input set.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is constant as no extra space is needed beyond the input values.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/k-items-with-the-maximum-sum/description/)

---
{{< youtube HmEYKbfjCLA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
