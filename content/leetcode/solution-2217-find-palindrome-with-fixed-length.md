
+++
authors = ["grid47"]
title = "Leetcode 2217: Find Palindrome With Fixed Length"
date = "2024-03-30"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2217: Find Palindrome With Fixed Length in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "yHa83HDgTdk"
youtube_upload_date="2022-03-27"
youtube_thumbnail="https://i.ytimg.com/vi/yHa83HDgTdk/maxresdefault.jpg"
comments = true
+++



---
You are given an array of queries and a positive integer intLength. For each query, you need to find the query-th smallest palindrome of length intLength. A palindrome is a number that reads the same backward and forward, and it cannot have leading zeros. If no such palindrome exists for a query, return -1.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given a list of queries and an integer intLength that specifies the desired length of the palindrome.
- **Example:** `queries = [1,2,3,4,5], intLength = 3`
- **Constraints:**
	- 1 <= queries.length <= 5 * 10^4
	- 1 <= queries[i] <= 10^9
	- 1 <= intLength <= 15

{{< dots >}}
### Output Specifications 📤
- **Output:** For each query, return the query-th smallest palindrome of the specified length, or -1 if it doesn't exist.
- **Example:** `Output: [101, 111, 121, 131, 141]`
- **Constraints:**
	- Palindromes cannot have leading zeros.

{{< dots >}}
### Core Logic 🔍
**Goal:** To generate palindromes of a specified length and determine the query-th smallest palindrome.

- Calculate the start and end bounds for the first half of the palindrome.
- For each query, check if it corresponds to a valid palindrome within the bounds.
- If valid, generate the palindrome by mirroring the first half; otherwise, return -1.
{{< dots >}}
### Problem Assumptions ✅
- Queries can be as large as 1 billion, and intLength can be as large as 15.
- All queries are valid non-negative integers.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: queries = [1,2,3,4,5], intLength = 3`  \
  **Explanation:** The first five palindromes of length 3 are 101, 111, 121, 131, and 141. The queries ask for the 1st, 2nd, 3rd, 4th, and 5th smallest palindromes, so the result is [101, 111, 121, 131, 141].

{{< dots >}}
## Approach 🚀
To solve this problem, the key is to generate palindromes of a given length and efficiently find the query-th smallest palindrome.

### Initial Thoughts 💭
- Palindromes of length intLength are formed by the first half mirrored to create the second half.
- If the query is too large, there may not be enough palindromes of the given length.
- We need to compute the range of valid numbers and reverse the first half to form the palindrome. If the query exceeds the possible range, return -1.
{{< dots >}}
### Edge Cases 🌐
- An empty query array should return an empty result.
- The solution must handle large queries efficiently, up to 1 billion.
- When intLength is 1, the palindromes are simply the numbers 1, 2, 3, etc.
- Ensure that the solution can handle large queries efficiently.
{{< dots >}}
## Code 💻
```cpp
long long reverse(long long n, int skip) {
    long long res = 0;
    for(n = skip?n/10: n; n > 0; n/=10)
        res = res * 10 + n % 10;
    return res;
}

vector<long long> kthPalindrome(vector<int>& queries, int sz) {
    vector<long long> ans;
    long long start = pow(10, (sz + 1)/2-1), end = pow(10, (sz + 1)/2), mul= pow(10, sz/2);
    for(auto q: queries)
        if(start + q > end)
            ans.push_back(-1);
        else {
            long long res = (start + q - 1) * mul + reverse(start + q - 1, sz % 2);
            ans.push_back(res);
        }
    
    return ans;
}
```

The function `reverse` reverses the digits of a number `n` while skipping a specific number of digits based on the value of `skip`. The `kthPalindrome` function generates a list of palindrome numbers of a given size `sz` based on queries, where each query corresponds to a specific palindrome in the range.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	long long reverse(long long n, int skip) {
	```
	This is the function declaration for `reverse`, which takes two parameters: `n` (the number to be reversed) and `skip` (a flag that determines whether to skip a digit when reversing).

2. **Variable Initialization**
	```cpp
	    long long res = 0;
	```
	A variable `res` is initialized to 0. This will hold the result of the reversed number as we process the digits of `n`.

3. **For Loop**
	```cpp
	    for(n = skip?n/10: n; n > 0; n/=10)
	```
	The `for` loop iterates over the digits of `n`. If `skip` is true, the first digit of `n` is skipped by dividing `n` by 10. Otherwise, the loop proceeds with the entire number.

4. **Digit Processing**
	```cpp
	        res = res * 10 + n % 10;
	```
	Each digit of `n` is extracted using the modulus operation `n % 10` and added to `res` after shifting the current digits of `res` one place to the left (multiplying by 10).

5. **Return Statement**
	```cpp
	    return res;
	```
	The function returns the reversed number stored in `res` after the loop completes.

6. **Function Declaration**
	```cpp
	vector<long long> kthPalindrome(vector<int>& queries, int sz) {
	```
	This is the function declaration for `kthPalindrome`, which takes a vector of queries and a size `sz`, and returns a vector of long long integers representing the palindromes corresponding to each query.

7. **Variable Initialization**
	```cpp
	    vector<long long> ans;
	```
	An empty vector `ans` is initialized to store the results (palindromes) corresponding to each query.

8. **Variable Initialization**
	```cpp
	    long long start = pow(10, (sz + 1)/2-1), end = pow(10, (sz + 1)/2), mul= pow(10, sz/2);
	```
	The variables `start`, `end`, and `mul` are initialized. `start` and `end` define the range of numbers that will be used to form the palindromes, and `mul` is a multiplier used to construct the palindrome number.

9. **For Loop**
	```cpp
	    for(auto q: queries)
	```
	This loop iterates over each query in the `queries` vector. Each query `q` represents a request for a specific palindrome.

10. **Condition Check**
	```cpp
	        if(start + q > end)
	```
	The condition checks whether the sum of `start` and the query `q` exceeds `end`. If it does, it means the palindrome number corresponding to the query does not exist within the range.

11. **Push Back - Invalid Query**
	```cpp
	            ans.push_back(-1);
	```
	If the condition is true (no palindrome exists for the query), `-1` is added to the result vector `ans` to indicate an invalid query.

12. **Else Block**
	```cpp
	        else {
	```
	If the condition is false (a valid palindrome exists), the code proceeds to construct the palindrome.

13. **Palindrome Construction**
	```cpp
	            long long res = (start + q - 1) * mul + reverse(start + q - 1, sz % 2);
	```
	The palindrome is constructed by first calculating the base number (`start + q - 1`) and multiplying it by `mul`. Then, the reverse function is called to mirror the digits to form a complete palindrome.

14. **Push Back - Valid Query**
	```cpp
	            ans.push_back(res);
	```
	The resulting palindrome is added to the `ans` vector.

15. **Return Statement**
	```cpp
	    return ans;
	```
	After processing all queries, the function returns the `ans` vector containing the resulting palindromes for each query.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(1) for each query if the query is small enough to directly calculate the palindrome.
- **Average Case:** O(1) for each query, as the palindrome generation involves basic arithmetic operations.
- **Worst Case:** O(1) for each query, as the complexity is determined by simple arithmetic and digit reversal.

Each query requires constant time to check if the palindrome exists and to compute it.

### Space Complexity 💾
- **Best Case:** O(1), as no extra space is required aside from the result storage.
- **Worst Case:** O(1), as the space used is constant for each query.

The solution uses a constant amount of extra space.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/find-palindrome-with-fixed-length/description/)

---
{{< youtube yHa83HDgTdk >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
