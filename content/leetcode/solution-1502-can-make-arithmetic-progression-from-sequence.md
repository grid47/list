
+++
authors = ["grid47"]
title = "Leetcode 1502: Can Make Arithmetic Progression From Sequence"
date = "2024-06-09"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1502: Can Make Arithmetic Progression From Sequence in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Sorting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "crVb-Fubs0w"
youtube_upload_date="2020-07-05"
youtube_thumbnail="https://i.ytimg.com/vi_webp/crVb-Fubs0w/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        if (arr.size() <= 2) return true;
        int min = INT_MAX, max = INT_MIN;
        for (int num : arr) {
            min = std::min(min, num);
            max = std::max(max, num);
        }
        if ((max - min) % (arr.size() - 1) != 0) return false;
        int d = (max - min) / (arr.size() - 1);

        int i = 0;
        while (i < arr.size()) {
            if (arr[i] == min + i * d) i++;
            else if ((arr[i] - min) % d != 0) return false;
            else {
                int pos = (arr[i] - min) / d;
                if (pos < i || arr[pos] == arr[i]) return false;
                std::swap(arr[i], arr[pos]);
            }
        }
        return true;        
    }
};
{{< /highlight >}}
---

### Problem Statement

The task is to determine if a given array can be rearranged to form an arithmetic progression (AP). An arithmetic progression is a sequence of numbers in which the difference between consecutive terms is constant. Given an array of integers, we need to ascertain whether it's possible to rearrange these integers to form such a sequence.

### Approach

To solve this problem, we can break it down into several key steps:

1. **Handle Edge Cases**: If the array has two or fewer elements, it can always form an AP, so we return `true` immediately.
2. **Find Minimum and Maximum**: Determine the minimum and maximum values in the array to compute the required common difference `d` for the AP.
3. **Check Difference Condition**: Verify whether the difference between the maximum and minimum values is divisible by the number of terms minus one (i.e., `(max - min) % (n - 1) == 0`). If not, it's impossible to form an AP.
4. **Determine Common Difference**: Calculate the common difference `d` as `(max - min) / (n - 1)`.
5. **Rearrangement Verification**: Using a greedy approach, try to rearrange the elements such that they match the expected AP sequence derived from the minimum value and the common difference.

### Code Breakdown (Step by Step)

```cpp
class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        if (arr.size() <= 2) return true;
```
- We start by defining a class `Solution` and a method `canMakeArithmeticProgression`.
- If the size of the array `arr` is less than or equal to 2, we return `true`, as any two numbers can form an AP.

```cpp
        int min = INT_MAX, max = INT_MIN;
        for (int num : arr) {
            min = std::min(min, num);
            max = std::max(max, num);
        }
```
- We initialize two variables, `min` and `max`, to find the minimum and maximum values in the array.
- We iterate over each number in the array, updating `min` and `max` accordingly.

```cpp
        if ((max - min) % (arr.size() - 1) != 0) return false;
        int d = (max - min) / (arr.size() - 1);
```
- We check if the difference between `max` and `min` is divisible by the number of elements minus one. If not, we return `false`, as it indicates that a uniform difference `d` cannot be established.
- If it is divisible, we calculate the common difference `d`.

```cpp
        int i = 0;
        while (i < arr.size()) {
            if (arr[i] == min + i * d) i++;
```
- We initialize a pointer `i` to traverse the array.
- The while loop continues until all elements are processed. For each `i`, we check if the current element matches the expected value in the AP sequence (`min + i * d`). If it does, we move to the next index.

```cpp
            else if ((arr[i] - min) % d != 0) return false;
```
- If the current element does not match the expected value, we check if the difference from `min` is not a multiple of `d`. If this condition is met, we return `false`.

```cpp
            else {
                int pos = (arr[i] - min) / d;
                if (pos < i || arr[pos] == arr[i]) return false;
                std::swap(arr[i], arr[pos]);
            }
        }
```
- If the previous conditions are not met, we compute the expected position `pos` for the current element.
- We check whether `pos` is less than `i` or if the element at `pos` is already equal to `arr[i]`. If either condition is true, it means that the sequence cannot be rearranged into an AP, and we return `false`.
- If all checks are passed, we swap the current element with the element at its computed position to continue rearranging.

```cpp
        return true;        
    }
};
```
- If the loop completes without returning false, we return `true`, indicating that the array can be rearranged to form an AP.

### Complexity

#### Time Complexity
- The algorithm performs a single pass to find the minimum and maximum, which takes \(O(n)\).
- It processes the array again to verify the arrangement and potential swapping, which also takes \(O(n)\).
- Overall, the time complexity is \(O(n)\), where \(n\) is the number of elements in the array.

#### Space Complexity
- The space complexity is \(O(1)\) since we are using a constant amount of extra space regardless of the input size.

### Conclusion

This solution efficiently checks whether a given array can be rearranged to form an arithmetic progression by utilizing properties of the sequence and performing necessary checks and rearrangements in linear time. The combination of finding the minimum and maximum values, calculating the common difference, and verifying the arrangement provides a robust approach to solving this problem. 

**Key Takeaways**:
- **Early Return**: For small arrays, the solution can terminate early.
- **Modular Checks**: Utilizing modular arithmetic helps determine the feasibility of creating an AP.
- **Greedy Approach**: Swapping elements based on expected positions allows for in-place rearrangements without requiring additional data structures.

This method is efficient and easy to understand, making it suitable for problems involving arithmetic properties in sequences.

[`Link to LeetCode Lab`](https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/description/)

---
{{< youtube crVb-Fubs0w >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
