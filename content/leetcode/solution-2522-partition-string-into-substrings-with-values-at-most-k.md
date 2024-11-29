
+++
authors = ["grid47"]
title = "Leetcode 2522: Partition String Into Substrings With Values at Most K"
date = "2024-02-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2522: Partition String Into Substrings With Values at Most K in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Dynamic Programming","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "XQh9V8PEIiI"
youtube_upload_date="2023-01-01"
youtube_thumbnail="https://i.ytimg.com/vi_webp/XQh9V8PEIiI/maxresdefault.webp"
comments = true
+++



---
Given a string `s` consisting of digits between 1 and 9, and an integer `k`, you need to partition the string into the fewest possible substrings such that the value of each substring is less than or equal to `k`. Each substring must consist of contiguous digits and must be interpreted as an integer. If it's not possible to partition the string in such a way, return `-1`.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given a string `s` containing digits from '1' to '9' and an integer `k`. The task is to partition the string into the fewest number of substrings where each substring has a value less than or equal to `k`.
- **Example:** `s = "123456", k = 50`
- **Constraints:**
	- 1 <= s.length <= 10^5
	- 1 <= k <= 10^9

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the minimum number of substrings required to partition the string `s` where the value of each substring is less than or equal to `k`. If it's not possible to partition the string, return `-1`.
- **Example:** `Output: 4`
- **Constraints:**
	- The output should be an integer representing the minimum number of substrings or -1 if no valid partition exists.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the minimum number of substrings where each substring has a value less than or equal to `k`. If such a partition isn't possible, return -1.

- Iterate through the string and attempt to form the largest valid substrings starting from the current position.
- For each substring, check if its value is less than or equal to `k`.
- If a valid substring is found, continue to form the next substring from the remaining characters.
- If a substring exceeds `k`, try partitioning earlier and minimize the number of substrings.
{{< dots >}}
### Problem Assumptions ✅
- Each digit in the string `s` is between '1' and '9', so the string contains no zero digits.
{{< dots >}}
## Examples 🧩
- **Input:** `s = "123456", k = 50`  \
  **Explanation:** The string can be partitioned into substrings '12', '34', '5', and '6'. Each substring is less than or equal to 50, so the minimum number of substrings is 4.

- **Input:** `s = "987654", k = 100`  \
  **Explanation:** The string can be partitioned into substrings '9', '8', '7', '6', and '54'. Each substring is less than or equal to 100, so the minimum number of substrings is 5.

- **Input:** `s = "238182", k = 5`  \
  **Explanation:** It's not possible to partition the string such that all substrings are less than or equal to 5, so the answer is -1.

{{< dots >}}
## Approach 🚀
To solve this problem, a dynamic programming approach can be used to recursively find the minimum number of valid partitions. At each index, try partitioning the string into substrings, and keep track of the minimum number of partitions.

### Initial Thoughts 💭
- Each substring must be interpreted as an integer and must be less than or equal to `k`.
- A dynamic programming approach can be used to explore all possible valid partitions efficiently.
{{< dots >}}
### Edge Cases 🌐
- There are no empty strings in the problem as the length of `s` is always at least 1.
- The solution must handle strings with up to 100,000 characters efficiently.
- If `k` is very small (e.g., 1), the problem becomes much harder as only substrings with a value of 1 will be valid.
- Ensure that the solution runs in time proportional to the length of the string `s` to handle the maximum input size.
{{< dots >}}
## Code 💻
```cpp
string str;
vector<map<int, int>> mem;

int dp(int idx, int k, int num) {
    
    if(idx == str.size()) return 1;
    
    if(mem[idx].count(num)) return mem[idx][num];

    int ans = 1 + dp(idx + 1, k, str[idx] - '0');

    long long net = (long long)num * 10 + (str[idx] - '0');
    if(net <= k) {
        ans = min(ans, dp(idx + 1, k, net));
    }

    return mem[idx][num] = ans;
}

int minimumPartition(string s, int k) {
    str = s;
    for(char x: s)
        if(x - '0' > k) return -1;
    mem.resize(s.size());
    int ans = dp(0, k, 0);
    return ans;
}
```

This code defines a solution to the problem of partitioning a string into the minimum number of partitions such that each partition represents a number smaller than or equal to a given integer `k`. It uses dynamic programming (DP) to explore possible partitions and memoization to store already calculated results.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **String Initialization**
	```cpp
	string str;
	```
	Declare a string `str` that will hold the input string for the partition problem.

2. **Memoization Structure**
	```cpp
	vector<map<int, int>> mem;
	```
	Declare a 2D vector `mem` of maps to store previously computed results for each index and number during the DP process.

3. **Function Definition**
	```cpp
	int dp(int idx, int k, int num) {
	```
	Define the recursive DP function `dp` which calculates the minimum number of partitions starting from index `idx` with a current number `num`.

4. **Base Case**
	```cpp
	    if(idx == str.size()) return 1;
	```
	Check if the current index is equal to the size of the string. If so, return 1 as we've reached the end and this partition is valid.

5. **Memoization Check**
	```cpp
	    if(mem[idx].count(num)) return mem[idx][num];
	```
	Check if the result for the current state (index and number) has already been computed and stored in the `mem` vector. If so, return the cached result.

6. **Recursive Case**
	```cpp
	    int ans = 1 + dp(idx + 1, k, str[idx] - '0');
	```
	Recursively call `dp` for the next index, assuming the current digit forms a new partition. Add 1 to the result to account for this partition.

7. **Net Calculation**
	```cpp
	    long long net = (long long)num * 10 + (str[idx] - '0');
	```
	Form a new number `net` by appending the current digit (`str[idx] - '0'`) to the existing number `num`.

8. **Condition Check (k Limit)**
	```cpp
	    if(net <= k) {
	```
	Check if the newly formed number `net` is less than or equal to `k`. If true, attempt to extend the current partition.

9. **Recursive Call (Valid Partition)**
	```cpp
	        ans = min(ans, dp(idx + 1, k, net));
	```
	Recursively call `dp` to check if the current number can be extended further. Store the minimum value between the previous result and the new call.

10. **Return Result**
	```cpp
	    return mem[idx][num] = ans;
	```
	Store the result for the current index and number in the memoization table `mem`, and return the result.

11. **Function Definition**
	```cpp
	int minimumPartition(string s, int k) {
	```
	Define the function `minimumPartition` which computes the minimum number of partitions of the input string `s` such that each partition is a number less than or equal to `k`.

12. **Input Assignment**
	```cpp
	    str = s;
	```
	Assign the input string `s` to the global string variable `str`.

13. **Loop (Initial Check)**
	```cpp
	    for(char x: s)
	```
	Iterate through each character `x` in the string `s`.

14. **Early Exit Condition**
	```cpp
	        if(x - '0' > k) return -1;
	```
	Check if any character in the string represents a number greater than `k`. If true, return -1 as it's impossible to partition the string.

15. **Memoization Resize**
	```cpp
	    mem.resize(s.size());
	```
	Resize the `mem` vector to match the size of the input string `s` to store memoization results for each index.

16. **Initial DP Call**
	```cpp
	    int ans = dp(0, k, 0);
	```
	Call the `dp` function to start the process from index 0, with initial number 0, and given constraint `k`.

17. **Return Result**
	```cpp
	    return ans;
	```
	Return the final result of the minimum partition calculations.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n^2)
- **Worst Case:** O(n^2)

The worst case occurs when checking all substrings for each character, leading to a time complexity of O(n^2).

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

Space complexity is O(n) due to memoization and the recursion stack.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/partition-string-into-substrings-with-values-at-most-k/description/)

---
{{< youtube XQh9V8PEIiI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
