
+++
authors = ["grid47"]
title = "Leetcode 1726: Tuple with Same Product"
date = "2024-05-18"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1726: Tuple with Same Product in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Counting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "asI_UBkXI0M"
youtube_upload_date="2021-03-29"
youtube_thumbnail="https://i.ytimg.com/vi/asI_UBkXI0M/maxresdefault.jpg"
comments = true
+++



---
You are given an array of distinct positive integers `nums`. Your task is to count how many tuples `(a, b, c, d)` exist such that the product of `a * b` equals the product of `c * d`, where `a, b, c, d` are distinct elements of `nums` and `a != b != c != d`.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given an array `nums` containing distinct positive integers.
- **Example:** `Input: nums = [1, 2, 3, 4, 6]`
- **Constraints:**
	- 1 <= nums.length <= 1000
	- 1 <= nums[i] <= 10^4
	- All elements in nums are distinct.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the number of valid tuples `(a, b, c, d)` such that `a * b = c * d` and `a != b != c != d`.
- **Example:** `Output: 6`
- **Constraints:**
	- The output is an integer representing the number of valid tuples.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find pairs of tuples `(a, b)` and `(c, d)` such that the products `a * b` and `c * d` are equal, and then count how many such valid tuples exist.

- 1. For each pair `(a, b)` in the array, compute the product `a * b`.
- 2. Keep track of how many times each product appears using a map.
- 3. For each new product, if it has appeared before, add the number of times it has appeared to the result.
- 4. Since the tuples `(a, b)` and `(c, d)` are interchangeable, multiply the result by 8 to account for all possible orderings of the tuples.
{{< dots >}}
### Problem Assumptions ✅
- All elements in the array are distinct positive integers.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: nums = [1, 2, 3, 4, 6]`  \
  **Explanation:** The valid tuples where `a * b = c * d` are (1,6,2,3), (1,6,3,2), (6,1,2,3), (6,1,3,2), (2,3,1,6), (3,2,1,6). Therefore, the output is 6.

- **Input:** `Input: nums = [2, 4, 8, 16]`  \
  **Explanation:** The valid tuples where `a * b = c * d` are (2,8,4,4), (8,2,4,4), and there are no other valid tuples. Hence, the output is 2.

{{< dots >}}
## Approach 🚀
We can approach this problem by iterating over all unique pairs `(a, b)` in the array, computing the product `a * b`, and counting how many times each product appears. If a product appears more than once, we count all valid pairs formed by these occurrences.

### Initial Thoughts 💭
- The problem essentially asks for counting pairs of pairs that produce the same product.
- Using a map to store the products of pairs is a good way to count and then use this information to compute the valid tuples.
{{< dots >}}
### Edge Cases 🌐
- The array should not be empty as it is stated that the length of `nums` will be at least 1.
- The solution should handle the case where `nums.length` is close to 1000 efficiently.
- There will be no cases where `nums[i] == nums[j]` because all elements in `nums` are distinct.
- The constraints suggest that the solution must efficiently compute the result even with the maximum input size.
{{< dots >}}
## Code 💻
```cpp
int tupleSameProduct(vector<int>& nums) {
    map<int, int> mp;
    
    int n = nums.size(), res = 0;
    
    for(int i = 0; i < n; i++)
    for(int j = i + 1; j < n; j++) {
        int x = nums[i] * nums[j];
        if(mp.count(x)) res+=mp[x];
        mp[x]++;
    }
    return res * 8;
}
```

The `tupleSameProduct` function calculates how many distinct quadruples (a, b, c, d) can be formed such that the product of nums[a] * nums[b] is equal to the product of nums[c] * nums[d]. The algorithm uses a map to count pairs of products and efficiently computes the result.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int tupleSameProduct(vector<int>& nums) {
	```
	The function `tupleSameProduct` is defined, taking a vector `nums` as input. The goal is to find how many quadruples (a, b, c, d) satisfy nums[a] * nums[b] == nums[c] * nums[d].

2. **Map Initialization**
	```cpp
	    map<int, int> mp;
	```
	A map `mp` is initialized to store the frequency of each product that can be formed by multiplying two numbers from the input list `nums`.

3. **Variable Declaration**
	```cpp
	    int n = nums.size(), res = 0;
	```
	The variable `n` is initialized to the size of the input vector `nums`, and `res` is initialized to 0. `res` will store the total number of valid quadruples.

4. **Outer Loop**
	```cpp
	    for(int i = 0; i < n; i++)
	```
	An outer loop is initiated to iterate over each element `nums[i]` in the input vector.

5. **Inner Loop**
	```cpp
	    for(int j = i + 1; j < n; j++) {
	```
	An inner loop is initiated to iterate over all elements `nums[j]` that come after `nums[i]` to form pairs of products.

6. **Product Calculation**
	```cpp
	        int x = nums[i] * nums[j];
	```
	The product `x` is calculated by multiplying the values of `nums[i]` and `nums[j]`.

7. **Count Check**
	```cpp
	        if(mp.count(x)) res+=mp[x];
	```
	The function checks if the product `x` already exists in the map `mp`. If it does, the value in `mp[x]` is added to `res`, indicating the number of valid quadruples that can be formed using this product.

8. **Map Update**
	```cpp
	        mp[x]++;
	```
	The map `mp` is updated by incrementing the count of the product `x`. This tracks how many times the product `x` has been encountered.

9. **Return Result**
	```cpp
	    return res * 8;
	```
	The result `res` is multiplied by 8 because each pair of products represents a combination of four distinct indices, and there are 8 permutations of four distinct indices that can form the same product.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n^2), since we need to check every pair of numbers in the array.
- **Average Case:** O(n^2), as each pair is checked independently.
- **Worst Case:** O(n^2), the worst case is when we check all pairs.

The time complexity is quadratic due to the nested loops over all pairs in the array.

### Space Complexity 💾
- **Best Case:** O(n^2), as we store the products of all pairs.
- **Worst Case:** O(n^2), to store the products of all pairs.

The space complexity is quadratic, as we store the frequency of products for each pair.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/tuple-with-same-product/description/)

---
{{< youtube asI_UBkXI0M >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
