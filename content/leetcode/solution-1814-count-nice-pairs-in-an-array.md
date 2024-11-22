
+++
authors = ["grid47"]
title = "Leetcode 1814: Count Nice Pairs in an Array"
date = "2024-05-09"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1814: Count Nice Pairs in an Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Math","Counting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "qUNprFiUKyw"
youtube_upload_date="2021-04-03"
youtube_thumbnail="https://i.ytimg.com/vi_webp/qUNprFiUKyw/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        
        unordered_map<int, long> mp;
        for(auto &n: nums) mp[n - rev(n)]++;
        
        int mod = 1000000007;
        long count = 0;
        
        for(auto &it: mp) 
        count = (count + (it.second * (it.second - 1))/ 2) % mod;
        
        return count;
    }

    int rev(int x) {
        int revNum = 0;
        while(x) revNum = revNum * 10 + (x%10), x /= 10;
        return revNum;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem is to count the number of "nice pairs" in an array of integers. A nice pair consists of two indices \(i\) and \(j\) (where \(i < j\)) such that the condition \(nums[i] + rev(nums[j]) = nums[j] + rev(nums[i])\) holds true. Here, `rev(x)` represents the reverse of the integer \(x\). The goal is to return the total count of such nice pairs modulo \(10^9 + 7\).

### Approach

To solve this problem, the following steps are taken:

1. **Understanding the Condition**: The condition \(nums[i] + rev(nums[j]) = nums[j] + rev(nums[i])\) can be rearranged to \(nums[i] - rev(nums[i]) = nums[j] - rev(nums[j])\). This means that for every pair of indices to be considered "nice," the difference between the number and its reversed form must be the same for both numbers.

2. **Using a HashMap**: Utilize a hash map (or unordered map) to count occurrences of each unique value of \(nums[i] - rev(nums[i])\). By counting how many times each value appears, we can derive the number of combinations of indices that can be formed.

3. **Counting Combinations**: For each unique difference stored in the hash map, if it appears \(k\) times, the number of ways to choose pairs from these \(k\) occurrences is given by the combination formula \(C(k, 2) = \frac{k(k - 1)}{2}\). This counts the number of nice pairs that can be formed from these indices.

4. **Return the Result**: The final count is accumulated and returned after applying the modulo operation to prevent overflow.

### Code Breakdown (Step by Step)

Here’s the step-by-step breakdown of the code:

```cpp
class Solution {
public:
```
- A class `Solution` is defined, which contains methods for solving the problem.

```cpp
    int countNicePairs(vector<int>& nums) {
```
- The method `countNicePairs` takes a vector of integers `nums` as input and returns an integer representing the count of nice pairs.

```cpp
        unordered_map<int, long> mp;
```
- An unordered map `mp` is declared to store the count of occurrences for each unique value of \(nums[i] - rev(nums[i])\).

```cpp
        for(auto &n: nums) mp[n - rev(n)]++;
```
- This loop iterates through each number `n` in the `nums` vector:
  - The difference \(n - rev(n)\) is calculated, and the count of this difference is incremented in the map `mp`.

```cpp
        int mod = 1000000007;
        long count = 0;
```
- A variable `mod` is defined with the value \(10^9 + 7\) to use for modulo operations.
- A variable `count` is initialized to zero, which will be used to accumulate the total number of nice pairs.

```cpp
        for(auto &it: mp) 
        count = (count + (it.second * (it.second - 1))/ 2) % mod;
```
- This loop iterates through each entry in the map `mp`:
  - For each unique difference, it calculates the number of pairs that can be formed using the combination formula \(\frac{it.second \cdot (it.second - 1)}{2}\), where `it.second` is the count of occurrences of that difference.
  - The result is added to `count`, and modulo operation is applied to keep the value within bounds.

```cpp
        return count;
    }
```
- Finally, the accumulated `count` is returned as the output.

```cpp
    int rev(int x) {
```
- This function `rev` takes an integer \(x\) as input and returns its reverse.

```cpp
        int revNum = 0;
```
- A variable `revNum` is initialized to zero, which will hold the reversed number.

```cpp
        while(x) revNum = revNum * 10 + (x%10), x /= 10;
```
- A loop is used to reverse the number:
  - The last digit of \(x\) is added to `revNum` (multiplied by 10 to shift left), and \(x\) is divided by 10 to remove the last digit.

```cpp
        return revNum;
    }
};
```
- The reversed number `revNum` is returned.

### Complexity

- **Time Complexity**: The time complexity is \(O(n \cdot k)\), where \(n\) is the number of elements in the `nums` vector and \(k\) is the number of digits in the largest number. This is due to the need to reverse each number in the input array.

- **Space Complexity**: The space complexity is \(O(m)\), where \(m\) is the number of unique values of \(nums[i] - rev(nums[i])\). This space is used by the unordered map to store counts.

### Conclusion

The `countNicePairs` method efficiently calculates the number of nice pairs in an array of integers by leveraging mathematical properties of numbers and their reversals. By transforming the problem into counting occurrences of differences and using combinatorial math, the solution achieves a clean and efficient approach to the problem.

This solution exemplifies the effective use of data structures such as hash maps to store and quickly access counts, as well as the implementation of modular arithmetic to handle large numbers, making it robust for competitive programming and algorithm design challenges.

[`Link to LeetCode Lab`](https://leetcode.com/problems/count-nice-pairs-in-an-array/description/)

---
{{< youtube qUNprFiUKyw >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
