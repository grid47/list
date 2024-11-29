
+++
authors = ["grid47"]
title = "Leetcode 2261: K Divisible Elements Subarrays"
date = "2024-03-25"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2261: K Divisible Elements Subarrays in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Trie","Rolling Hash","Hash Function","Enumeration"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "BZdbRvIM-js"
youtube_upload_date="2022-05-01"
youtube_thumbnail="https://i.ytimg.com/vi_webp/BZdbRvIM-js/maxresdefault.webp"
comments = true
+++



---
You are given an integer array `nums` and two integers `k` and `p`. Your task is to count the number of distinct subarrays where there are at most `k` elements divisible by `p`. A subarray is defined as a contiguous part of the array, and two subarrays are considered distinct if they differ in either length or at least one element.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given an integer array `nums` and two integers `k` and `p`.
- **Example:** `nums = [5, 8, 3, 5, 6], k = 2, p = 5`
- **Constraints:**
	- 1 <= nums.length <= 200
	- 1 <= nums[i], p <= 200
	- 1 <= k <= nums.length

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the number of distinct subarrays with at most `k` elements divisible by `p`.
- **Example:** `Output: 7`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** We need to find the distinct subarrays that satisfy the condition of having at most `k` elements divisible by `p`.

- Iterate over the array to consider all possible subarrays.
- For each subarray, count the elements divisible by `p`.
- If the count is less than or equal to `k`, add the subarray to a set of distinct subarrays.
- Use hashing to ensure subarrays are distinct and avoid duplicates.
{{< dots >}}
### Problem Assumptions ✅
- The input array `nums` is non-empty.
- Subarrays are considered distinct if they differ in length or in elements.
{{< dots >}}
## Examples 🧩
- **Input:** `nums = [5, 8, 3, 5, 6], k = 2, p = 5`  \
  **Explanation:** We can form the subarrays [5], [5,8], [5,8,3], [8], [8,3], [3], and [5,6], which all contain at most 2 elements divisible by 5. Hence, the output is 7.

- **Input:** `nums = [10, 20, 30], k = 1, p = 10`  \
  **Explanation:** The distinct subarrays satisfying the condition are [10], [20], [30], and [10,20], [20,30], and [10,20,30]. There are 6 distinct subarrays, and the output is 6.

{{< dots >}}
## Approach 🚀
We will iterate through all subarrays and keep track of the number of elements divisible by `p`. Using a set ensures that we count only distinct subarrays.

### Initial Thoughts 💭
- We need an efficient way to find all subarrays and check the number of divisible elements.
- Using hashing will help keep track of the distinct subarrays without manually comparing each one.
{{< dots >}}
### Edge Cases 🌐
- The input array is non-empty, so there are no empty inputs.
- Ensure the solution handles input sizes up to 200 elements efficiently.
- Consider cases where all elements are divisible by `p`.
- Ensure the solution works within the problem's constraints, especially with larger values of `k`.
{{< dots >}}
## Code 💻
```cpp
int countDistinct(vector<int>& nums, int k, int p) {
    
    int res = 0, n = nums.size();
    vector<int> cnt(201, 0); vector<long long> hash(201, 0);
    for (int sz = 0; sz < n; sz++) {
        unordered_set<int> s;
        for(int i = 0; i + sz < n; i++){

cnt[i] += ((nums[i + sz] % p) == 0);
        if(cnt[i] <= k) {
hash[i] = (hash[i] * 200 + nums[i + sz]) % 1000000007;
            res += s.insert(hash[i]).second;
        }
    }
    }
    
    return res;
}
```

This function counts the number of distinct subarrays that satisfy the condition of having at most 'k' divisible numbers by 'p' in the subarray, using hashing and a sliding window approach.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int countDistinct(vector<int>& nums, int k, int p) {
	```
	The function `countDistinct` takes three parameters: `nums` (a vector of integers), `k` (the maximum number of divisible elements), and `p` (the divisor used to check divisibility). It returns an integer representing the count of distinct subarrays that meet the given conditions.

2. **Size and Count Initialization**
	```cpp
	    int res = 0, n = nums.size();
	```
	The variable `res` is initialized to zero to store the count of distinct subarrays, and `n` is the size of the `nums` array.

3. **Auxiliary Arrays**
	```cpp
	    vector<int> cnt(201, 0); vector<long long> hash(201, 0);
	```
	Two vectors `cnt` and `hash` are initialized: `cnt` tracks how many elements in the subarray are divisible by `p`, and `hash` stores the hash value of each subarray for quick distinctness checking.

4. **Outer Loop (Subarray Size)**
	```cpp
	    for (int sz = 0; sz < n; sz++) {
	```
	The outer loop iterates over all possible subarray sizes starting from each index in the `nums` array.

5. **Set Initialization**
	```cpp
	        unordered_set<int> s;
	```
	A set `s` is initialized to store the unique hash values of the subarrays.

6. **Inner Loop (Subarray Elements)**
	```cpp
	        for(int i = 0; i + sz < n; i++){
	```
	The inner loop generates the subarrays by starting at index `i` and extending the subarray by `sz` elements.

7. **Divisibility Count Update**
	```cpp
	cnt[i] += ((nums[i + sz] % p) == 0);
	```
	The `cnt` array is updated by checking if the element at index `i + sz` in `nums` is divisible by `p`. If it is, the count for that subarray index is incremented.

8. **Condition Check**
	```cpp
	        if(cnt[i] <= k) {
	```
	This checks if the current subarray has at most `k` elements divisible by `p`. If true, it proceeds to the next steps.

9. **Hash Calculation**
	```cpp
	hash[i] = (hash[i] * 200 + nums[i + sz]) % 1000000007;
	```
	The hash value for the current subarray is updated by multiplying the existing hash by 200 and adding the current element `nums[i + sz]`, then taking the modulus to avoid overflow.

10. **Distinct Count Update**
	```cpp
	            res += s.insert(hash[i]).second;
	```
	The `insert` function of the set `s` is used to add the subarray hash. If the hash is unique, it increments the `res` counter.

11. **Return Result**
	```cpp
	    return res;
	```
	The function returns the count of distinct subarrays that satisfy the condition.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n^2)
- **Average Case:** O(n^2)
- **Worst Case:** O(n^2)

The time complexity is quadratic because we iterate over all subarrays and for each subarray, we check divisibility for each element.

### Space Complexity 💾
- **Best Case:** O(n^2)
- **Worst Case:** O(n^2)

The space complexity is O(n^2) due to the storage of distinct subarrays in a set.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/k-divisible-elements-subarrays/description/)

---
{{< youtube BZdbRvIM-js >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
