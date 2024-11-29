
+++
authors = ["grid47"]
title = "Leetcode 1734: Decode XORed Permutation"
date = "2024-05-17"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1734: Decode XORed Permutation in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Bit Manipulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "uA9lPzogB7Y"
youtube_upload_date="2021-01-23"
youtube_thumbnail="https://i.ytimg.com/vi/uA9lPzogB7Y/maxresdefault.jpg"
comments = true
+++



---
You are given an array `encoded` of length `n - 1`, which represents the XOR of consecutive elements of a permutation of the first `n` integers. Your task is to decode the `encoded` array and return the original permutation `perm` of size `n`.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a single integer array `encoded` of length `n - 1`, where `encoded[i] = perm[i] XOR perm[i + 1]`. The permutation `perm` is a permutation of integers from `1` to `n` and `n` is odd.
- **Example:** `Input: encoded = [4, 3, 7]`
- **Constraints:**
	- 3 <= n < 10^5
	- n is odd
	- encoded.length == n - 1

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the decoded permutation array `perm` of size `n`.
- **Example:** `Output: [2, 4, 1, 5, 3]`
- **Constraints:**
	- The output is a list of integers representing the decoded permutation of the integers from 1 to n.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to decode the encoded array and reconstruct the original permutation by finding a way to use XOR operations efficiently.

- 1. Compute the XOR of all integers from 1 to n.
- 2. XOR every second element of the `encoded` array with the computed XOR to obtain the first element of the permutation.
- 3. Use the XOR relationship between consecutive elements of the permutation to find the entire permutation array.
- 4. Return the reconstructed permutation array.
{{< dots >}}
### Problem Assumptions ✅
- The encoded array always provides a valid and unique solution for the permutation.
- The permutation consists of the integers from 1 to n, and each integer appears exactly once.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: encoded = [4, 3, 7]`  \
  **Explanation:** The XOR of all integers from 1 to 5 is 7. XORing every second element of `encoded` with 7 gives the first element of the permutation, which is 2. Then we can use the XOR of consecutive elements to find the rest of the permutation.

- **Input:** `Input: encoded = [3, 1]`  \
  **Explanation:** If perm = [1, 2, 3], then `encoded = [1 XOR 2, 2 XOR 3] = [3, 1]`. Therefore, the decoded permutation is [1, 2, 3].

{{< dots >}}
## Approach 🚀
To solve this problem, we leverage the XOR properties to decode the given array and reconstruct the permutation.

### Initial Thoughts 💭
- The XOR operation has properties that can be used to decode the encoded array efficiently.
- We can compute the XOR of all integers from 1 to n to use in decoding the array.
{{< dots >}}
### Edge Cases 🌐
- The array `encoded` cannot be empty because n >= 3.
- For large values of n, the solution should efficiently handle up to n < 10^5 elements.
- Since n is always odd, the total number of elements in `encoded` will always be even.
- The XOR operation is commutative and associative, which allows for efficient decoding.
{{< dots >}}
## Code 💻
```cpp
vector<int> decode(vector<int>& enc) {
    int n = enc.size() + 1;
    vector<int> ans(n, 0);
    
    int x = 0;
    for(int i = 1; i < n + 1; i++)
        x ^= i;
    
    ans[0] = x;
    for(int i = 1; i < enc.size(); i += 2)
        ans[0] ^= enc[i];
    
    for(int i = 1; i < n; i++)
        ans[i] = ans[i - 1] ^ enc[i - 1];
    
    return ans;
}
```

This function decodes an encoded list by performing bitwise XOR operations at each step to reverse the encoding.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	vector<int> decode(vector<int>& enc) {
	```
	The function `decode` is defined, which takes a reference to a vector of integers `enc` (encoded values) and returns a vector of integers (decoded values).

2. **Variable Initialization**
	```cpp
	    int n = enc.size() + 1;
	```
	The size of the original decoded array `n` is determined by adding 1 to the size of the encoded array `enc`.

3. **Array Initialization**
	```cpp
	    vector<int> ans(n, 0);
	```
	A new vector `ans` of size `n` is initialized with all elements set to 0, which will hold the decoded values.

4. **Variable Initialization**
	```cpp
	    int x = 0;
	```
	The variable `x` is initialized to 0. This will be used for XOR operations to decode the values.

5. **Loop**
	```cpp
	    for(int i = 1; i < n + 1; i++)
	```
	A loop is initiated from 1 to `n`, used to XOR the values for decoding.

6. **Bitwise Operation**
	```cpp
	        x ^= i;
	```
	The variable `x` is XOR'd with the current value of `i`, effectively encoding the range of numbers.

7. **Assignment**
	```cpp
	    ans[0] = x;
	```
	The first element of the `ans` array is assigned the value of `x` after the XOR operations in the previous loop.

8. **Loop**
	```cpp
	    for(int i = 1; i < enc.size(); i += 2)
	```
	A loop iterates over the encoded array `enc`, starting from index 1 and incrementing by 2, ensuring only the elements at odd indices are processed.

9. **Bitwise Operation**
	```cpp
	        ans[0] ^= enc[i];
	```
	The first element of the `ans` array is XOR'd with the value from the encoded array `enc` at the current index `i`.

10. **Loop**
	```cpp
	    for(int i = 1; i < n; i++)
	```
	A second loop starts from index 1 to `n - 1`, used to calculate the remaining values in the `ans` array.

11. **Bitwise Operation**
	```cpp
	        ans[i] = ans[i - 1] ^ enc[i - 1];
	```
	Each element of the `ans` array is calculated by XOR'ing the previous element in `ans` with the corresponding element in the encoded array `enc`.

12. **Return Statement**
	```cpp
	    return ans;
	```
	The function returns the decoded `ans` array, which now contains the original sequence of numbers.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n), where n is the number of elements in the permutation.
- **Average Case:** O(n), as we need to process each element in the array once.
- **Worst Case:** O(n), since the algorithm processes all elements in linear time.

The time complexity is linear, O(n), since we need to process each element of the encoded array and compute the XOR operations.

### Space Complexity 💾
- **Best Case:** O(n), as we need space to store the decoded permutation array.
- **Worst Case:** O(n), where n is the number of elements in the permutation.

The space complexity is O(n) because we need to store the decoded permutation array, which has size n.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/decode-xored-permutation/description/)

---
{{< youtube uA9lPzogB7Y >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
