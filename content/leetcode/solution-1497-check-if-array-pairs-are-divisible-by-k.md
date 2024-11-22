
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
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
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
};
{{< /highlight >}}
---

### Problem Statement

The task is to determine if an array of integers can be divided into pairs such that the sum of each pair is divisible by a given integer \( k \). This problem requires us to assess the modular properties of the elements in the array to identify whether such pairings can be formed.

### Approach

To solve the problem, we can leverage the concept of modular arithmetic. The main idea is to track the frequency of each remainder when the elements of the array are divided by \( k \). By analyzing these frequencies, we can ascertain if the elements can be paired correctly.

1. **Calculate Remainders**: For each element in the array, compute the remainder when divided by \( k \).
2. **Frequency Counting**: Use a frequency array to count how many times each remainder appears.
3. **Check Conditions**:
   - Ensure that the number of elements with a remainder of 0 is even, as they can only pair with themselves.
   - For other remainders, check if the count of elements with remainder \( i \) is equal to the count of elements with remainder \( k - i \).
4. **Return Result**: If all conditions are satisfied, return `true`; otherwise, return `false`.

### Code Breakdown (Step by Step)

```cpp
class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
```
This line defines a class `Solution` with a public member function `canArrange`, which takes a vector of integers `arr` and an integer `k` as inputs.

#### Step 1: Initialize Frequency Array

```cpp
        vector<int> frq(k, 0);
```
Here, we initialize a frequency array `frq` of size \( k \) filled with zeros. This array will be used to count how many numbers produce each remainder when divided by \( k \).

#### Step 2: Count Frequencies of Remainders

```cpp
        for(int num : arr) {
            num %= k;
            if (num < 0) num += k;
            frq[num]++;
        }
```
- We iterate through each number in the array `arr`.
- For each number, we compute the remainder using `num % k`. 
- If the remainder is negative (which can occur for negative integers), we adjust it to ensure it's in the range `[0, k-1]` by adding \( k \).
- The frequency of this remainder is incremented in the `frq` array.

#### Step 3: Check for Even Count of Remainders

```cpp
        if(frq[0] % 2 != 0) return false;
```
- We first check if the count of numbers that are perfectly divisible by \( k \) (i.e., remainder 0) is even. If it's odd, it is impossible to pair all such numbers, and we return `false`.

#### Step 4: Validate Pairing of Other Remainders

```cpp
        for(int i = 1; i <= k / 2; i++)
            if(frq[i] != frq[k - i]) return false;
```
- Next, we loop through all possible remainders from 1 to \( k/2 \). For each remainder \( i \), we check if its frequency matches the frequency of its complement \( k - i \).
- If any mismatch occurs, it means that there aren't enough numbers to form pairs for that remainder, so we return `false`.

#### Step 5: Return True if All Conditions Met

```cpp
        return true;
    }
};
```
- If all checks pass, we conclude that the elements can be arranged in pairs that satisfy the condition and return `true`.

### Complexity

#### Time Complexity
- The time complexity of this algorithm is **O(n)**, where \( n \) is the number of elements in the input array `arr`. We process each element once to compute its remainder and count frequencies.

#### Space Complexity
- The space complexity is **O(k)** due to the storage of the frequency array, which has a size of \( k \).

### Conclusion

This solution effectively determines whether it is possible to pair elements of an array such that the sum of each pair is divisible by a given integer \( k \). By using a frequency array to track remainders, the algorithm simplifies the pairing conditions into straightforward checks.

**Key Points**:
- **Efficient Pairing Check**: The use of modular arithmetic allows for a clear and efficient way to assess pair compatibility.
- **Handles Negatives**: The algorithm is robust enough to handle negative integers by normalizing remainders.
- **Direct Condition Checks**: By reducing the problem to frequency checks of remainders, we avoid unnecessary complexities in pair selection.

In summary, the `canArrange` function is a powerful implementation of modular arithmetic that simplifies the problem of pairing integers in an array based on divisibility conditions, making it an effective solution to the problem statement.

[`Link to LeetCode Lab`](https://leetcode.com/problems/check-if-array-pairs-are-divisible-by-k/description/)

---
{{< youtube lLEmqIblivA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
