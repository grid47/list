
+++
authors = ["grid47"]
title = "Leetcode 238: Product of Array Except Self"
date = "2024-10-14"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 238: Product of Array Except Self in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/238.webp"
youtube = "yKZFurr4GQA"
youtube_upload_date="2024-01-10"
youtube_thumbnail="https://i.ytimg.com/vi/yKZFurr4GQA/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/238.webp" 
    alt="A sequence of glowing numbers representing the product of elements except the current one, showing a smooth transition"
    caption="Solution to LeetCode 238: Product of Array Except Self Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given an integer array, your task is to return an array where each element at index 'i' is the product of all the elements of the original array except the element at index 'i'. You are not allowed to use division in your solution, and the algorithm must run in O(n) time.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given an integer array 'nums'. The array will contain at least two elements.
- **Example:** `Input: nums = [2,3,4,5]`
- **Constraints:**
	- 2 <= nums.length <= 10^5
	- -30 <= nums[i] <= 30
	- The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return an array where each element is the product of all the numbers in the array except the one at that index.
- **Example:** `Output: [60, 40, 30, 24]`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to compute the product of all the elements except the current element at each index.

- Create an array to store the product of all elements except the current element.
- First, iterate through the array to calculate the prefix products (product of elements before the current element).
- Then, iterate from the end of the array to calculate the suffix products (product of elements after the current element).
- Multiply the prefix and suffix values for each index to get the desired result.
{{< dots >}}
### Problem Assumptions ✅
- The input array will always contain at least two elements.
- There will be no division operations used in the solution.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: nums = [2,3,4,5]`  \
  **Explanation:** For this example, the product of all elements except the current one would be: [60, 40, 30, 24]. The output array is constructed by calculating the product of all numbers except the current one for each index.

- **Input:** `Input: nums = [1,0,3,4]`  \
  **Explanation:** Here, the output array will be: [0, 0, 0, 0]. This is because the product for each index excludes the element at that index, and the array contains zeros.

{{< dots >}}
## Approach 🚀
The optimal approach is to compute the result in two passes: one for the prefix products and one for the suffix products, and multiply the two results for each element.

### Initial Thoughts 💭
- We cannot use division to simplify the problem.
- To avoid using extra space for the prefix and suffix arrays, we can modify the result array in place.
- The result can be built in two phases: one for the prefix products and another for the suffix products.
{{< dots >}}
### Edge Cases 🌐
- The list is guaranteed to have at least two elements, so no empty list cases.
- The solution should efficiently handle large arrays with up to 100,000 elements.
- Handle cases where the array contains zeroes. The result array should correctly reflect the multiplication of other elements.
- Make sure the output array fits within a 32-bit integer range.
{{< dots >}}
## Code 💻
```cpp
vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> pre(n, 1), suf(n, 1);
    pre[0] = nums[0];
    suf[n - 1] = nums[n - 1];
    for(int i = 1; i < n; i++)
        pre[i] = pre[i - 1] * nums[i];
    for(int i = n - 2; i >= 0; i--)
        suf[i] = suf[i + 1] * nums[i];
    
    vector<int> ans(n, 1);
    for(int i = 0; i < n; i++)
        ans[i] = (i > 0? pre[i - 1]: 1) * (i < n - 1? suf[i + 1]: 1);
    
    return ans;
}
```

This function calculates the product of all elements in an array except for the current element, without using division. It uses two auxiliary arrays, one for the prefix product and one for the suffix product, to compute the result efficiently.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	vector<int> productExceptSelf(vector<int>& nums) {
	```
	Defines the function `productExceptSelf`, which takes a reference to a vector of integers (`nums`) and returns a vector of integers where each element is the product of all other elements except for the current one.

2. **Size of Array**
	```cpp
	    int n = nums.size();
	```
	Stores the size of the input array `nums` in variable `n`.

3. **Initialize Prefix and Suffix Arrays**
	```cpp
	    vector<int> pre(n, 1), suf(n, 1);
	```
	Initializes two auxiliary arrays, `pre` and `suf`, both of size `n`. `pre[i]` will store the product of all elements to the left of index `i`, and `suf[i]` will store the product of all elements to the right of index `i`.

4. **Set First Prefix Value**
	```cpp
	    pre[0] = nums[0];
	```
	Sets the first element of the `pre` array to be equal to the first element of the `nums` array.

5. **Set Last Suffix Value**
	```cpp
	    suf[n - 1] = nums[n - 1];
	```
	Sets the last element of the `suf` array to be equal to the last element of the `nums` array.

6. **Prefix Product Calculation**
	```cpp
	    for(int i = 1; i < n; i++)
	```
	Starts a loop from the second element (`i = 1`) to the last element of the array, calculating the prefix product for each index.

7. **Update Prefix Product**
	```cpp
	        pre[i] = pre[i - 1] * nums[i];
	```
	Updates the `pre[i]` array by multiplying the previous element's prefix product (`pre[i - 1]`) by the current element (`nums[i]`). This ensures that `pre[i]` holds the product of all elements to the left of index `i`.

8. **Suffix Product Calculation**
	```cpp
	    for(int i = n - 2; i >= 0; i--)
	```
	Starts a loop from the second-to-last element (`i = n - 2`) down to the first element, calculating the suffix product for each index.

9. **Update Suffix Product**
	```cpp
	        suf[i] = suf[i + 1] * nums[i];
	```
	Updates the `suf[i]` array by multiplying the next element's suffix product (`suf[i + 1]`) by the current element (`nums[i]`). This ensures that `suf[i]` holds the product of all elements to the right of index `i`.

10. **Initialize Answer Array**
	```cpp
	    vector<int> ans(n, 1);
	```
	Initializes the result array `ans` of size `n` with all elements set to 1.

11. **Compute Final Results**
	```cpp
	    for(int i = 0; i < n; i++)
	```
	Starts a loop to calculate the final result for each index `i` in the `ans` array.

12. **Calculate Product for Each Index**
	```cpp
	        ans[i] = (i > 0? pre[i - 1]: 1) * (i < n - 1? suf[i + 1]: 1);
	```
	For each index `i`, the result is calculated by multiplying the prefix product (`pre[i - 1]`) and the suffix product (`suf[i + 1]`). If `i` is the first or last index, the appropriate product (prefix or suffix) is taken as 1.

13. **Return Final Result**
	```cpp
	    return ans;
	```
	Returns the result array `ans`, which contains the product of all elements in the input array `nums` except for the current element.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) because we iterate through the list twice.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

We use only constant extra space as we update the result array in place.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/product-of-array-except-self/description/)

---
{{< youtube yKZFurr4GQA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
