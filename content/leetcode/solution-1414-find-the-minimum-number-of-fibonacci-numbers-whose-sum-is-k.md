
+++
authors = ["grid47"]
title = "Leetcode 1414: Find the Minimum Number of Fibonacci Numbers Whose Sum Is K"
date = "2024-06-18"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1414: Find the Minimum Number of Fibonacci Numbers Whose Sum Is K in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
comments = true
+++



---
You are given an integer k, and you need to determine the minimum number of Fibonacci numbers whose sum equals k. Note that the same Fibonacci number can be used multiple times. The Fibonacci sequence is defined as F1 = 1, F2 = 1, and Fn = Fn-1 + Fn-2 for n > 2.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a single integer k.
- **Example:** `k = 8`
- **Constraints:**
	- 1 <= k <= 10^9

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the minimum number of Fibonacci numbers whose sum is equal to k.
- **Example:** `For k = 8, output 1 as only one Fibonacci number is needed.`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** Determine the minimum number of Fibonacci numbers that sum to k.

- Generate all Fibonacci numbers less than or equal to k.
- Greedily subtract the largest Fibonacci numbers from k until k becomes 0.
- Count the number of Fibonacci numbers used.
{{< dots >}}
### Problem Assumptions ✅
- The given number k is always solvable with Fibonacci numbers.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: k = 8`  \
  **Explanation:** The Fibonacci sequence is [1, 1, 2, 3, 5, 8]. For k = 8, we can directly use the Fibonacci number 8, so the answer is 1.

{{< dots >}}
## Approach 🚀
To solve this problem, generate all Fibonacci numbers less than or equal to k and greedily select the largest Fibonacci numbers that sum to k.

### Initial Thoughts 💭
- The Fibonacci numbers grow exponentially, so we can limit the number of Fibonacci numbers we need to check.
- Greedy selection from the largest Fibonacci numbers should work well here.
- We can generate Fibonacci numbers up to k, then iteratively subtract the largest Fibonacci numbers from k until we reach 0.
{{< dots >}}
### Edge Cases 🌐
- There are no empty inputs since k is always a positive integer.
- For large values of k near 10^9, ensure the Fibonacci sequence is generated efficiently.
- When k is a Fibonacci number itself, the solution should return 1.
- Ensure the correct implementation for all valid inputs within the given constraints.
{{< dots >}}
## Code 💻
```cpp
int findMinFibonacciNumbers(int k) {
    vector<int> arr = {1, 1};
    while(arr[arr.size() - 1] + arr[arr.size() - 2] <= k) {
        arr.push_back(arr[arr.size() - 1] + arr[arr.size() - 2]);
    }

    set<int> cnt;
    int i = arr.size() -1;
    while(k > 0) {
        while(i >= 0 && arr[i] > k) i--;
        if(i == -1) break;
        k -= arr[i];
        cnt.insert(arr[i]);
    }
    return cnt.size();
}
```

The function `findMinFibonacciNumbers` calculates the minimum number of Fibonacci numbers whose sum equals `k` by iterating over Fibonacci numbers until the sum reaches `k`.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int findMinFibonacciNumbers(int k) {
	```
	This line defines the function `findMinFibonacciNumbers`, which takes an integer `k` as input and returns an integer representing the minimum number of Fibonacci numbers whose sum equals `k`.

2. **Variable Initialization**
	```cpp
	    vector<int> arr = {1, 1};
	```
	Initializes a vector `arr` containing the first two Fibonacci numbers, `1` and `1`.

3. **Loop Constructs**
	```cpp
	    while(arr[arr.size() - 1] + arr[arr.size() - 2] <= k) {
	```
	This while loop continues to generate Fibonacci numbers and adds them to `arr` as long as the sum of the last two Fibonacci numbers is less than or equal to `k`.

4. **Vector Operations**
	```cpp
	        arr.push_back(arr[arr.size() - 1] + arr[arr.size() - 2]);
	```
	Adds the next Fibonacci number to the vector `arr` by summing the last two numbers in the vector.

5. **Set Operations**
	```cpp
	    set<int> cnt;
	```
	Initializes a set `cnt` to store unique Fibonacci numbers that contribute to the sum `k`.

6. **Variable Initialization**
	```cpp
	    int i = arr.size() -1;
	```
	Initializes the variable `i` to the index of the last element in the `arr` vector, representing the largest Fibonacci number.

7. **Loop Constructs**
	```cpp
	    while(k > 0) {
	```
	Begins a while loop that runs until `k` becomes 0, indicating that the sum of selected Fibonacci numbers has been achieved.

8. **Loop Constructs**
	```cpp
	        while(i >= 0 && arr[i] > k) i--;
	```
	In this inner while loop, the index `i` is decremented until a Fibonacci number less than or equal to `k` is found.

9. **Control Flow**
	```cpp
	        if(i == -1) break;
	```
	If no suitable Fibonacci number is found (i.e., `i` becomes -1), the loop is exited.

10. **Arithmetic Operations**
	```cpp
	        k -= arr[i];
	```
	Decreases `k` by the current Fibonacci number `arr[i]`.

11. **Set Operations**
	```cpp
	        cnt.insert(arr[i]);
	```
	Inserts the selected Fibonacci number `arr[i]` into the set `cnt` to ensure each number is counted only once.

12. **Return Statement**
	```cpp
	    return cnt.size();
	```
	Returns the size of the set `cnt`, which represents the minimum number of Fibonacci numbers required to sum up to `k`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(log k), due to the exponential growth of Fibonacci numbers.
- **Average Case:** O(log k), since we need to process Fibonacci numbers up to k.
- **Worst Case:** O(log k), as the number of Fibonacci numbers required is small relative to k.

The time complexity is logarithmic relative to k due to the fast growth of the Fibonacci sequence.

### Space Complexity 💾
- **Best Case:** O(log k), as the space for the Fibonacci numbers is proportional to the logarithm of k.
- **Worst Case:** O(log k), for storing the Fibonacci numbers up to k.

The space complexity is also logarithmic because we only need to store a small number of Fibonacci numbers.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/find-the-minimum-number-of-fibonacci-numbers-whose-sum-is-k/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
