
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
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
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
};
{{< /highlight >}}
---

### Problem Statement

The goal of the problem is to determine the minimum number of adjacent swaps required to transform a given number represented as a string into its k-th lexicographical permutation. For example, if the input number is "273" and \( k = 1 \), the next permutation of "273" is "327". The task is to find out how many adjacent swaps are needed to turn "273" into "327".

### Approach

To solve the problem, we can break the solution into two primary components:

1. **Finding the k-th Permutation**: We will use the `next_permutation` function to generate the k-th lexicographical permutation of the number.

2. **Calculating the Minimum Swaps**: We will then calculate the minimum number of adjacent swaps required to convert the original number into the k-th permutation. This involves finding the positions of the characters and counting how many swaps are needed to bring them into their correct order.

### Code Breakdown (Step by Step)

Here’s the implementation of the solution:

```cpp
class Solution {
public:
    int getMinSwaps(string num, int k) {
        string og = num;
        while(k--) {
            next_permutation(num.begin(), num.end());
        }
        return steps(og, num);
    }
```
- **Class Definition**: We define a class `Solution` that contains the method `getMinSwaps`.
- **Input Parameters**: The method takes a string `num` representing the number and an integer `k` that indicates how many permutations to generate.
- **Original Number Storage**: We store the original number in a variable `og` to compare later.
- **Next Permutation Loop**: We call `next_permutation` \( k \) times on `num` to get the k-th permutation of the string.
- **Return Swap Steps**: After obtaining the k-th permutation, we call the `steps` function to calculate the minimum swaps required and return the result.

```cpp
    int steps(string s1, string s2) {
        int sz = s1.size();
        int i = 0, j = 0;
        int res = 0;
```
- **Steps Function**: We define a helper function `steps` that takes two strings: `s1` (original number) and `s2` (k-th permutation).
- **Initialization**: We initialize variables `sz` to store the size of the strings, and `res` to keep track of the total number of swaps.

```cpp
        while(i < sz) {
            j = i;
            while(s1[i] != s2[j]) j++;
```
- **Outer While Loop**: We iterate through each character in `s1` with index `i`.
- **Find Matching Character**: For each character in `s1`, we search for its matching character in `s2` starting from index `j`.

```cpp
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
- **Inner While Loop**: If the character in `s1` at index `i` is not at the same position in `s2`, we perform adjacent swaps to bring it into position. Each swap increases the `res` counter.
- **Return Swaps Count**: After processing all characters, we return the total count of swaps.

### Complexity

- **Time Complexity**: 
  - The time complexity for finding the k-th permutation using `next_permutation` is \( O(n \cdot k) \), where \( n \) is the length of the string and \( k \) is the number of permutations we are generating. 
  - The swap calculation in the `steps` function is \( O(n^2) \) in the worst case since each character might need to be swapped multiple times until it reaches its correct position. 
  - Thus, the overall complexity can be approximated as \( O(n^2 + n \cdot k) \).

- **Space Complexity**: 
  - The space complexity is \( O(n) \) for storing the original number and any additional space required for swap operations.

### Conclusion

The provided solution efficiently computes the minimum number of adjacent swaps needed to achieve the k-th lexicographical permutation of a given number represented as a string. The use of `next_permutation` simplifies the task of generating permutations, while the `steps` function systematically counts the necessary swaps.

This method illustrates an effective blend of combinatorial generation (via permutations) and localized sorting (via adjacent swaps). The approach is both straightforward and efficient for the problem constraints typically found in competitive programming and algorithmic challenges.

Overall, the solution showcases essential programming techniques, such as string manipulation, the use of standard library functions like `next_permutation`, and efficient counting of operations, making it a robust method for solving the problem of transforming one string into another through minimum adjacent swaps.

[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-adjacent-swaps-to-reach-the-kth-smallest-number/description/)

---
{{< youtube _83XSvgd_is >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
