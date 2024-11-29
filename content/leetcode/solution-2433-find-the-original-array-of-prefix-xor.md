
+++
authors = ["grid47"]
title = "Leetcode 2433: Find The Original Array of Prefix Xor"
date = "2024-03-08"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2433: Find The Original Array of Prefix Xor in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Bit Manipulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "idcT-p_DDrI"
youtube_upload_date="2023-01-14"
youtube_thumbnail="https://i.ytimg.com/vi/idcT-p_DDrI/maxresdefault.jpg"
comments = true
+++



---
You are given an integer array `pref` of size `n`. Your task is to find and return an array `arr` of size `n` that satisfies the following condition: each element `pref[i]` equals the XOR of all elements from `arr[0]` to `arr[i]`. In other words, `pref[i] = arr[0] ^ arr[1] ^ ... ^ arr[i]` where `^` denotes the bitwise XOR operation. It is guaranteed that there is a unique solution.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given a single array `pref` of integers.
- **Example:** `pref = [3, 1, 2, 6]`
- **Constraints:**
	- 1 <= pref.length <= 10^5
	- 0 <= pref[i] <= 10^6

{{< dots >}}
### Output Specifications 📤
- **Output:** Return an array `arr` that satisfies the condition: `pref[i] = arr[0] ^ arr[1] ^ ... ^ arr[i]`.
- **Example:** `Output: [3, 2, 0, 6]`
- **Constraints:**
	- The answer will always be unique.

{{< dots >}}
### Core Logic 🔍
**Goal:** We need to find an array `arr` such that the cumulative XOR of its elements matches the corresponding values in `pref`.

- 1. Initialize an empty array `arr` of the same size as `pref`.
- 2. Set `arr[0]` equal to `pref[0]` since the first element is directly equal.
- 3. For each subsequent index `i`, calculate `arr[i]` as `pref[i] ^ pref[i-1]`. This is because `pref[i]` represents the cumulative XOR of `arr[0]` to `arr[i]`, and `pref[i-1]` represents the cumulative XOR of `arr[0]` to `arr[i-1]`, so XORing them will give the value of `arr[i]`.
- 4. Return the array `arr`.
{{< dots >}}
### Problem Assumptions ✅
- The input array `pref` is valid and contains at least one element.
- Each element of `pref` is non-negative and less than or equal to 10^6.
{{< dots >}}
## Examples 🧩
- **Input:** `pref = [3, 1, 2, 6]`  \
  **Explanation:** To solve this, we find `arr` such that each `pref[i]` is the cumulative XOR of `arr[0]` to `arr[i]`. From `pref`, we can derive `arr` as follows: `arr[0] = 3`, `arr[1] = 3 ^ 1 = 2`, `arr[2] = 2 ^ 2 = 0`, `arr[3] = 0 ^ 6 = 6`. Thus, the result is `[3, 2, 0, 6]`.

- **Input:** `pref = [10]`  \
  **Explanation:** In this case, the array `arr` will be equal to `pref[0]` because there is only one element. Thus, the result is `[10]`.

{{< dots >}}
## Approach 🚀
The solution is based on the property of the XOR operation. By using the cumulative XOR relationship, we can deduce each element of the array `arr` from the `pref` array.

### Initial Thoughts 💭
- The problem involves working with the XOR operation, which is associative and commutative.
- We can solve the problem iteratively by using the property of XOR to derive each element of `arr` from the prefix XOR values in `pref`.
{{< dots >}}
### Edge Cases 🌐
- There are no empty inputs as `pref` always has at least one element.
- Ensure that the solution can handle arrays of size up to 100,000 efficiently.
- Handle cases where `pref` has a single element, as `arr` will just be equal to `pref`.
- Ensure the solution is efficient and runs in O(n) time complexity.
{{< dots >}}
## Code 💻
```cpp
vector<int> findArray(vector<int>& pref) {
    vector<int> res(pref.size());
    res[0] = pref[0];
    for(int i = 1; i < pref.size(); i++)
        res[i] = pref[i] ^ pref[i - 1];
    
    return res;
}
```

This function takes a reference to a vector 'pref' and reconstructs the original array by performing XOR operations between successive elements of 'pref'. The first element is directly copied from 'pref'. The result is stored in a new vector 'res', which is then returned.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	vector<int> findArray(vector<int>& pref) {
	```
	Function definition for 'findArray', which takes a reference to a vector of integers 'pref' and returns a vector of integers.

2. **Vector Initialization**
	```cpp
	    vector<int> res(pref.size());
	```
	A new vector 'res' is initialized with the same size as 'pref', which will store the reconstructed array.

3. **Initial Assignment**
	```cpp
	    res[0] = pref[0];
	```
	The first element of the result vector 'res' is set to the first element of the 'pref' vector, since it's directly copied.

4. **Loop**
	```cpp
	    for(int i = 1; i < pref.size(); i++)
	```
	A for loop is initiated to iterate through the 'pref' vector starting from the second element.

5. **XOR Operation**
	```cpp
	        res[i] = pref[i] ^ pref[i - 1];
	```
	For each iteration, the XOR operation is performed between the current element and the previous element of 'pref' to reconstruct the original array.

6. **Return Result**
	```cpp
	    return res;
	```
	Return the reconstructed array 'res' as the result.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n), where n is the length of the `pref` array. We iterate through `pref` once, and each operation inside the loop takes constant time.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n), as we need to store the result array `arr`.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/find-the-original-array-of-prefix-xor/description/)

---
{{< youtube idcT-p_DDrI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
