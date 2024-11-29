
+++
authors = ["grid47"]
title = "Leetcode 1497: Check If Array Pairs Are Divisible by k"
date = "2024-06-10"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1497: Check If Array Pairs Are Divisible by k in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Counting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "lLEmqIblivA"
youtube_upload_date="2020-06-28"
youtube_thumbnail="https://i.ytimg.com/vi_webp/lLEmqIblivA/maxresdefault.webp"
comments = true
+++



---
You are given an array of integers arr of even length n and an integer k. The task is to check if you can divide the array into exactly n / 2 pairs such that the sum of each pair is divisible by k. Return true if it's possible to divide the array into valid pairs, otherwise return false.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an array arr of even length n and an integer k.
- **Example:** `arr = [3, 1, 2, 6, 4, 10], k = 5`
- **Constraints:**
	- 1 <= n <= 10^5
	- n is even.
	- -10^9 <= arr[i] <= 10^9
	- 1 <= k <= 10^5

{{< dots >}}
### Output Specifications 📤
- **Output:** Return true if it is possible to divide the array into valid pairs such that the sum of each pair is divisible by k. Otherwise, return false.
- **Example:** `Output: true`
- **Constraints:**
	- The length of the array is even.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to check whether each element of the array can be paired with another element such that their sum is divisible by k.

- Initialize an array to count the frequency of the remainders when dividing each element by k.
- For each element, compute its remainder when divided by k, and store this in the frequency array.
- Check if the frequency of elements with remainder 0 is even.
- For each non-zero remainder, check if the frequency of elements with remainder r is equal to the frequency of elements with remainder k-r.
{{< dots >}}
### Problem Assumptions ✅
- The input array always has an even number of elements.
{{< dots >}}
## Examples 🧩
- **Input:** `arr = [3, 1, 2, 6, 4, 10], k = 5`  \
  **Explanation:** The valid pairs are (3, 7), (1, 9), (2, 8), and (4, 10), all of which sum to multiples of 5.

- **Input:** `arr = [1, 2, 3, 4, 5, 6], k = 10`  \
  **Explanation:** There are no valid pairs whose sum is divisible by 10.

{{< dots >}}
## Approach 🚀
To solve this problem, we can use a frequency map to track the remainders of the array elements when divided by k. By checking the frequencies of complementary remainders, we can determine if it's possible to form the required pairs.

### Initial Thoughts 💭
- The problem boils down to checking remainders when dividing elements by k.
- If the frequency of remainders can be paired correctly, then the array can be divided as required.
{{< dots >}}
### Edge Cases 🌐
- The array cannot be empty as its length is guaranteed to be even.
- The solution must handle arrays with sizes up to 10^5.
- If k is 1, any pair of numbers will satisfy the condition since any sum is divisible by 1.
- The array must always have an even number of elements.
{{< dots >}}
## Code 💻
```cpp
bool canArrange(vector<int>& arr, int k) {
    vector<int> frq(k, 0);
    for(int num : arr) {
        num %= k;
        if (num < 0) num += k;
        frq[num]++;
    }
    if(frq[0]%2 != 0) return false;
    for(int i = 1; i <= k/2; i++)
        if(frq[i] != frq[k - i]) return false;
    return true;
}
```

The `canArrange` function checks whether it's possible to rearrange the elements in an array such that the sum of pairs is divisible by a given integer `k`. It uses the frequency of remainders when each element is divided by `k` to ensure the pairing condition is satisfied.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	bool canArrange(vector<int>& arr, int k) {
	```
	The function `canArrange` takes an array `arr` and an integer `k` as input, and returns a boolean indicating whether the array can be rearranged such that the sum of any two elements is divisible by `k`.

2. **Vector Initialization**
	```cpp
	    vector<int> frq(k, 0);
	```
	Initialize a vector `frq` of size `k` to store the frequency of remainders when elements of the array are divided by `k`. Each element in `frq` is initially set to 0.

3. **Loop**
	```cpp
	    for(int num : arr) {
	```
	Loop through each element `num` in the array `arr`.

4. **Modulo Operation**
	```cpp
	        num %= k;
	```
	Take the remainder when `num` is divided by `k` and update `num` to this value.

5. **Negative Adjustment**
	```cpp
	        if (num < 0) num += k;
	```
	If `num` is negative after the modulo operation, adjust it by adding `k` to ensure the remainder is non-negative.

6. **Frequency Update**
	```cpp
	        frq[num]++;
	```
	Increment the frequency of the remainder `num` in the vector `frq`.

7. **Check Zero Frequency**
	```cpp
	    if(frq[0] % 2 != 0) return false;
	```
	Check if the frequency of elements that give a remainder of 0 when divided by `k` is even. If it's odd, return `false` because pairs can't be formed.

8. **Pairing Check**
	```cpp
	    for(int i = 1; i <= k / 2; i++)
	```
	Loop through each possible remainder from 1 to `k/2` to check if the frequency of elements with remainder `i` matches the frequency of elements with remainder `k - i`.

9. **Pair Frequency Check**
	```cpp
	        if(frq[i] != frq[k - i]) return false;
	```
	If the frequency of elements with remainder `i` does not match the frequency of elements with remainder `k - i`, return `false` because they can't be paired.

10. **Return True**
	```cpp
	    return true;
	```
	If all checks pass, return `true` indicating that the array can be rearranged to satisfy the pairing condition.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) as we only iterate through the array once and perform constant time operations for each element.

### Space Complexity 💾
- **Best Case:** O(k)
- **Worst Case:** O(k)

The space complexity is O(k) to store the frequency map of remainders modulo k.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/check-if-array-pairs-are-divisible-by-k/description/)

---
{{< youtube lLEmqIblivA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
