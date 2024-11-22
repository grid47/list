
+++
authors = ["grid47"]
title = "Leetcode 1512: Number of Good Pairs"
date = "2024-06-08"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1512: Number of Good Pairs in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Math","Counting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "BqhDFUo1rjs"
youtube_upload_date="2023-10-03"
youtube_thumbnail="https://i.ytimg.com/vi_webp/BqhDFUo1rjs/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int numIdenticalPairs(vector<int>& A) {
        int res = 0;
        unordered_map<int, int> count;
        for (int a: A) {
            res += count[a]++;
        }
        return res;   
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem requires us to determine the number of good pairs in an array of integers. A pair of indices \( (i, j) \) is considered good if \( i < j \) and \( A[i] = A[j] \). The goal is to count all such pairs in the given array.

### Approach

To solve this problem, we can leverage a hash map (or unordered map) to efficiently count the occurrences of each integer in the array. As we iterate through the array, we can calculate the number of good pairs that can be formed with the current number based on how many times it has appeared before. 

Here’s a step-by-step breakdown of the approach:

1. **Count Occurrences**: Use an unordered map to count how many times each integer appears in the array as we iterate through it.

2. **Calculate Good Pairs**: For each integer, the number of good pairs that can be formed with the current integer is equal to the count of that integer already seen (since any previous occurrence can form a pair with the current index).

3. **Update Count**: After calculating the good pairs for the current integer, update its count in the unordered map.

4. **Return Result**: At the end of the iteration, return the total count of good pairs.

### Code Breakdown (Step by Step)

Here’s a detailed breakdown of the code implementation:

```cpp
class Solution {
public:
```
- We define a class `Solution` with a public method `numIdenticalPairs`.

```cpp
    int numIdenticalPairs(vector<int>& A) {
```
- The method `numIdenticalPairs` takes a vector of integers `A` as input, which represents the array of numbers.

```cpp
        int res = 0;
        unordered_map<int, int> count;
```
- We initialize a variable `res` to store the result (the total number of good pairs) and an unordered map `count` to keep track of how many times each integer has appeared.

```cpp
        for (int a: A) {
```
- We begin a loop that iterates over each integer `a` in the array `A`.

```cpp
            res += count[a]++;
```
- For each integer `a`, we add the current count of `a` (which is the number of times it has appeared before this index) to `res`. The `++` operator increments the count of `a` in the map after accessing it, ensuring that the count reflects the total occurrences after this iteration.

```cpp
        }
```
- The loop continues until all integers in the array have been processed.

```cpp
        return res;   
    }
};
```
- Finally, we return the total number of good pairs stored in `res`.

### Complexity

#### Time Complexity
- The time complexity of this solution is \(O(n)\), where \(n\) is the number of elements in the array `A`. This is because we make a single pass through the array, and each map operation (insert or find) is average \(O(1)\).

#### Space Complexity
- The space complexity is \(O(k)\), where \(k\) is the number of unique integers in the array `A`. This is due to the storage requirements of the unordered map used to count the occurrences.

### Conclusion

This solution effectively counts the number of good pairs in an array by utilizing a hash map to keep track of occurrences of each integer. 

**Key Insights**:
- **Efficiency**: By using an unordered map, we achieve linear time complexity, making this solution efficient even for larger arrays.
- **Real-World Application**: This type of counting problem can frequently arise in competitive programming and algorithm challenges, showcasing the importance of understanding hash maps and their applications in counting frequencies.

Overall, the approach is straightforward yet powerful, demonstrating how a simple counting mechanism can solve problems efficiently. The code is concise, easy to understand, and leverages C++ STL features effectively, making it suitable for quick implementations in various programming contests.

[`Link to LeetCode Lab`](https://leetcode.com/problems/number-of-good-pairs/description/)

---
{{< youtube BqhDFUo1rjs >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
