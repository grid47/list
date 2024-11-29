
+++
authors = ["grid47"]
title = "Leetcode 1850: Minimum Adjacent Swaps to Reach the Kth Smallest Number"
date = "2024-05-06"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1850: Minimum Adjacent Swaps to Reach the Kth Smallest Number in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Two Pointers","String","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "_83XSvgd_is"
youtube_upload_date="2021-05-02"
youtube_thumbnail="https://i.ytimg.com/vi/_83XSvgd_is/maxresdefault.jpg"
comments = true
+++



---
You are given a string `num`, representing a large integer, and an integer `k`. Return the minimum number of adjacent swaps required to transform `num` into the `k`-th smallest wonderful integer that is greater than `num` and is a permutation of its digits.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a string `num` which represents a large integer and an integer `k`.
- **Example:** `"1234", 2`
- **Constraints:**
	- 2 <= num.length <= 1000
	- 1 <= k <= 1000
	- num consists only of digits

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the minimum number of adjacent swaps required to transform `num` into the `k`-th smallest wonderful integer.
- **Example:** `1`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the `k`-th smallest wonderful integer and then compute the minimum number of adjacent swaps to transform the input `num` into that integer.

- Find the k-th smallest permutation of the digits of `num` that is greater than `num`.
- Count the number of adjacent swaps required to transform `num` into this k-th smallest permutation.
{{< dots >}}
### Problem Assumptions ✅
- The input string will always consist of at least two digits.
{{< dots >}}
## Examples 🧩
- **Input:** `"1234", 2`  \
  **Explanation:** The second smallest wonderful number is '1243'. To transform '1234' to '1243', only one swap is needed: swap the last two digits.

{{< dots >}}
## Approach 🚀
To solve this problem, we need to find the k-th smallest wonderful permutation of the string `num` and count how many adjacent swaps it takes to get from `num` to that permutation.

### Initial Thoughts 💭
- We need to generate the k-th smallest permutation greater than the original number.
- Using a permutation generator to find the next permutations of the string `num` can help us reach the desired result.
{{< dots >}}
### Edge Cases 🌐
- The string `num` is guaranteed to have a length of at least 2.
- The input string can have up to 1000 digits, so efficient string manipulation is necessary.
- Consider cases where the string `num` contains repeated digits or leading zeros.
- The solution must handle strings with lengths from 2 to 1000 efficiently.
{{< dots >}}
## Code 💻
```cpp
int getMinSwaps(string num, int k) {
    string og = num;
    while(k--) {
        next_permutation(num.begin(), num.end());
    }
    return steps(og, num);
}

int steps(string s1, string s2) {
    int sz = s1.size();
    int i = 0, j = 0;
    int res = 0;

    while(i < sz) {
        j = i;
        while(s1[i] != s2[j]) j++;
        while(i < j) {
            swap(s2[j], s2[j - 1]);
            j--;
            res++;
        }
        i++;
    }
    return res;
}
```

This is the complete solution for finding the minimum number of swaps needed to convert a string into its next permutation a given number of times (k). The function `steps` calculates the number of swaps required to rearrange one string into another.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Initialization**
	```cpp
	int getMinSwaps(string num, int k) {
	```
	Declares the function `getMinSwaps`, which takes a string `num` and an integer `k` to compute the minimum number of swaps.

2. **Variable Assignment**
	```cpp
	    string og = num;
	```
	Stores the original string `num` in a variable `og` to later compute the difference after permutations.

3. **Looping**
	```cpp
	    while(k--) {
	```
	A loop that runs `k` times to generate the next permutation of the string.

4. **Library Functions**
	```cpp
	        next_permutation(num.begin(), num.end());
	```
	Uses the standard library function `next_permutation` to generate the next lexicographically greater permutation of the string `num`.

5. **Function Call**
	```cpp
	    return steps(og, num);
	```
	Calls the `steps` function to calculate the number of swaps required to convert the original string `og` into the newly generated permutation `num`.

6. **Function Definition**
	```cpp
	int steps(string s1, string s2) {
	```
	Defines the helper function `steps`, which calculates the number of swaps needed to convert string `s1` into string `s2`.

7. **Variable Initialization**
	```cpp
	    int sz = s1.size();
	```
	Stores the size of the string `s1` in variable `sz`.

8. **Variable Initialization**
	```cpp
	    int i = 0, j = 0;
	```
	Initializes two indices, `i` and `j`, to iterate over the strings.

9. **Variable Initialization**
	```cpp
	    int res = 0;
	```
	Initializes `res` to store the count of swaps made during the conversion.

10. **Looping**
	```cpp
	    while(i < sz) {
	```
	A loop that iterates over the string `s1`.

11. **Variable Assignment**
	```cpp
	        j = i;
	```
	Sets `j` to `i`, which will help find the position of the character in `s2`.

12. **Looping**
	```cpp
	        while(s1[i] != s2[j]) j++;
	```
	Finds the position of the character `s1[i]` in `s2` starting from index `i`.

13. **Looping**
	```cpp
	        while(i < j) {
	```
	A nested loop that moves the found character in `s2` to its correct position by swapping.

14. **Swap Operations**
	```cpp
	            swap(s2[j], s2[j - 1]);
	```
	Swaps the characters in `s2` to move the character at position `j` to position `j-1`.

15. **Variable Update**
	```cpp
	            j--;
	```
	Decrements `j` to continue moving the character to the left.

16. **Variable Update**
	```cpp
	            res++;
	```
	Increments the swap counter `res` for each swap made.

17. **Variable Update**
	```cpp
	        i++;
	```
	Increments the outer loop index `i`.

18. **Return**
	```cpp
	    return res;
	```
	Returns the total number of swaps made to convert `s1` into `s2`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n^2)
- **Worst Case:** O(n^2)

The time complexity depends on finding the k-th smallest permutation and counting the swaps. The worst case occurs when the permutations are far apart.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(n)

The space complexity is O(n) due to the space required for storing the string and its permutations.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-adjacent-swaps-to-reach-the-kth-smallest-number/description/)

---
{{< youtube _83XSvgd_is >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
