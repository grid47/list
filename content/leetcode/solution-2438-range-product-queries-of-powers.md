
+++
authors = ["grid47"]
title = "Leetcode 2438: Range Product Queries of Powers"
date = "2024-03-08"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2438: Range Product Queries of Powers in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Bit Manipulation","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "BGr1RD2mxhs"
youtube_upload_date="2022-10-15"
youtube_thumbnail="https://i.ytimg.com/vi_webp/BGr1RD2mxhs/maxresdefault.webp"
comments = true
+++



---
Given a positive integer `n`, you need to construct an array called `powers` that contains the minimum number of powers of 2 that sum up to `n`. The array `powers` should be sorted in non-decreasing order. You are also given a set of queries where each query asks for the product of the powers in the `powers` array between indices `left` and `right` (both inclusive). For each query, return the product modulo 10^9 + 7.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an integer `n` and a 2D array `queries`. Each element of `queries` is a pair of indices `[left, right]` that specifies the range of indices in the `powers` array.
- **Example:** `n = 10, queries = [[0, 1], [0, 0], [1, 2]]`
- **Constraints:**
	- 1 <= n <= 10^9
	- 1 <= queries.length <= 10^5
	- 0 <= left <= right < length of powers

{{< dots >}}
### Output Specifications 📤
- **Output:** Return an array of integers where each element corresponds to the product of the elements in the `powers` array between the indices `left` and `right` for each query. The result of each product should be returned modulo 10^9 + 7.
- **Example:** `Output: [6, 2, 16]`
- **Constraints:**
	- Each product should be computed modulo 10^9 + 7.

{{< dots >}}
### Core Logic 🔍
**Goal:** We need to generate the `powers` array from the integer `n`, and then efficiently answer each query by computing the product of elements within the specified index range.

- 1. Extract the powers of 2 that sum up to `n` and store them in the `powers` array.
- 2. For each query, calculate the product of the elements in `powers` between the indices `left` and `right`.
- 3. Return the product modulo 10^9 + 7 for each query.
{{< dots >}}
### Problem Assumptions ✅
- The number `n` is guaranteed to be a positive integer.
- The input queries are valid and the `left` and `right` indices are within bounds for the `powers` array.
{{< dots >}}
## Examples 🧩
- **Input:** `n = 15, queries = [[0, 1], [2, 2], [0, 3]]`  \
  **Explanation:** For `n = 15`, the `powers` array will be `[1, 2, 4, 8]` because 15 can be represented as the sum of 1 + 2 + 4 + 8. For the queries: Query [0, 1] asks for the product of `powers[0]` and `powers[1]`, which is 1 * 2 = 2. Query [2, 2] asks for `powers[2]`, which is 4. Query [0, 3] asks for the product of all elements in the `powers` array, which is 1 * 2 * 4 * 8 = 64.

- **Input:** `n = 2, queries = [[0, 0]]`  \
  **Explanation:** For `n = 2`, the `powers` array will be `[2]` because 2 is a power of 2. The query [0, 0] asks for the product of `powers[0]`, which is 2.

{{< dots >}}
## Approach 🚀
The goal is to first generate the `powers` array by finding all the powers of 2 that sum up to `n`. Then, for each query, compute the product of the corresponding elements in the `powers` array within the given range, applying the modulo operation to keep the result manageable.

### Initial Thoughts 💭
- The number `n` can be broken down into a sum of powers of 2. This suggests that the `powers` array will contain a small number of elements, even for large values of `n`.
- Efficient querying is key, so instead of recalculating the product for every query, we can compute the prefix product of the `powers` array and use it to answer each query in constant time.
{{< dots >}}
### Edge Cases 🌐
- There will always be at least one query, so empty inputs are not a concern.
- For large values of `n`, the `powers` array will have at most 30 elements (since log2(10^9) ≈ 30).
- If `n` is a power of 2, the `powers` array will contain exactly one element.
- The solution should handle up to 10^5 queries efficiently.
{{< dots >}}
## Code 💻
```cpp
int mod = (int) 1e9 + 7;
vector<int> productQueries(int n, vector<vector<int>>& q) {
    
    vector<long long> pow;
    long long init = 1;
    while(n) {
        if(n & 1) pow.push_back(init);
        init *= 2;
        n /= 2;
    }
    
    
    
    vector<int> ans;
    for(int i = 0; i < q.size(); i++) {
        int tmp = pow[q[i][0]];
        for(int j = q[i][0] + 1; j <= q[i][1]; j++)
            tmp = (tmp * pow[j]) % mod;
        ans.push_back(tmp);
    }
    return ans;
}
```

This is the complete code for the `productQueries` function, which computes the product of powers of two for a range of indices specified in the query list.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Initialization**
	```cpp
	int mod = (int) 1e9 + 7;
	```
	Initializing the modulus value used for the final result to avoid overflow. This is a common practice in competitive programming to keep the numbers within a manageable range.

2. **Function Definition**
	```cpp
	vector<int> productQueries(int n, vector<vector<int>>& q) {
	```
	Defining the `productQueries` function, which takes an integer `n` and a vector of queries `q`. The function will return a vector of integers containing the results for each query.

3. **Variable Declaration**
	```cpp
	    vector<long long> pow;
	```
	Declaring a vector `pow` to store the powers of 2, which will be used to compute the products for the queries.

4. **Variable Initialization**
	```cpp
	    long long init = 1;
	```
	Initializing the `init` variable to 1, which will be used as the starting point for calculating powers of 2.

5. **Loop**
	```cpp
	    while(n) {
	```
	A while loop that runs as long as `n` is greater than zero. The loop is used to calculate the powers of 2 for the binary representation of `n`.

6. **Condition Check**
	```cpp
	        if(n & 1) pow.push_back(init);
	```
	Using a bitwise AND to check if the least significant bit of `n` is 1. If it is, `init` (the current power of 2) is added to the `pow` vector.

7. **Mathematical Operation**
	```cpp
	        init *= 2;
	```
	Doubling the value of `init` to calculate the next power of 2.

8. **Mathematical Operation**
	```cpp
	        n /= 2;
	```
	Dividing `n` by 2 to move to the next bit in the binary representation of `n`.

9. **Variable Declaration**
	```cpp
	    vector<int> ans;
	```
	Declaring a vector `ans` to store the answers for each query.

10. **Loop**
	```cpp
	    for(int i = 0; i < q.size(); i++) {
	```
	A loop that iterates through each query in the vector `q`.

11. **Array Access**
	```cpp
	        int tmp = pow[q[i][0]];
	```
	Accessing the power of 2 corresponding to the start index of the current query and storing it in the `tmp` variable.

12. **Loop**
	```cpp
	        for(int j = q[i][0] + 1; j <= q[i][1]; j++)
	```
	A nested loop that iterates from the start index to the end index of the current query, computing the product of the corresponding powers of 2.

13. **Mathematical Operation**
	```cpp
	            tmp = (tmp * pow[j]) % mod;
	```
	Multiplying `tmp` by the next power of 2 in the range and taking the result modulo `mod` to avoid overflow.

14. **Vector Operation**
	```cpp
	        ans.push_back(tmp);
	```
	Storing the result of the current query in the `ans` vector.

15. **Return Statement**
	```cpp
	    return ans;
	```
	Returning the final vector `ans` containing the results for each query.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(1)
- **Average Case:** O(1)
- **Worst Case:** O(q + p), where q is the number of queries and p is the number of powers of 2 in `n`.

The time complexity is O(q + p) where `q` is the number of queries, and `p` is the number of powers of 2 in `n`. Calculating the prefix product array takes O(p), and each query can be answered in O(1) time.

### Space Complexity 💾
- **Best Case:** O(p)
- **Worst Case:** O(p + q)

The space complexity is O(p + q) where `p` is the number of powers of 2 in `n` and `q` is the number of queries.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/range-product-queries-of-powers/description/)

---
{{< youtube BGr1RD2mxhs >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
