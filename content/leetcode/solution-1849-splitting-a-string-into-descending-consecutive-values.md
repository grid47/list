
+++
authors = ["grid47"]
title = "Leetcode 1849: Splitting a String Into Descending Consecutive Values"
date = "2024-05-06"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1849: Splitting a String Into Descending Consecutive Values in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Backtracking"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "eDtMmysldaw"
youtube_upload_date="2021-05-02"
youtube_thumbnail="https://i.ytimg.com/vi/eDtMmysldaw/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string s;
    bool splitString(string s) {
        this->s = s;
        double tmp = 0;
        for(int i = 0; i < s.size() - 1; i++) {
            tmp = tmp * 10 + (s[i] - '0');
            if(bt(i + 1, tmp)) return true;
        }
        return false;
    }
    
    bool bt(int idx, double prv) {

        if(idx == s.size()) return true;
        
        double tmp = 0;
        for(int i = idx; i < s.size(); i++) {
            tmp = tmp * 10 + (s[i] - '0');
            if(tmp - prv > -1) break;
            if(tmp - prv == -1) {
                if(bt(i + 1, tmp))
                    return true;
            }
        }
        return false;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem requires determining whether a given string representing a number can be split into a sequence of integers such that each subsequent integer is exactly one less than the previous one. For instance, if the input is `"54321"`, the string can be split into `5`, `4`, `3`, `2`, `1`. However, if the input is `"5432"`, it cannot be split into a valid sequence because there is no `1` to follow `2`. The task is to implement a method to check for such a valid split.

### Approach

To solve the problem, we will employ a backtracking technique:

1. **Initial Loop**: Iterate through the string and consider each possible prefix of the number. This prefix will serve as the starting number of our sequence.

2. **Backtracking Function**: For each prefix, we call a backtracking function that will attempt to find the next number in the sequence. The backtracking function will keep track of the current index in the string and the previous number found.

3. **Checking Subsequent Numbers**: In the backtracking function, we will form subsequent numbers from the current index onward and check if they are exactly one less than the previous number. If they are, we recursively continue the search.

4. **Base Case**: If we reach the end of the string, we will return true, indicating that we successfully found a valid sequence.

### Code Breakdown (Step by Step)

```cpp
class Solution {
public:
    string s;
```
- We define a class `Solution` with a public member variable `s` to hold the input string.

```cpp
    bool splitString(string s) {
        this->s = s;
```
- The method `splitString` is defined, taking a string `s` as an argument and storing it in the member variable `this->s`.

```cpp
        double tmp = 0;
        for(int i = 0; i < s.size() - 1; i++) {
```
- We initialize a temporary variable `tmp` to 0. We iterate through the string from the beginning up to the second-to-last character.

```cpp
            tmp = tmp * 10 + (s[i] - '0');
```
- In each iteration, we build the current number (`tmp`) by multiplying the previous value by 10 and adding the next digit. This effectively converts the character digits into a numeric value.

```cpp
            if(bt(i + 1, tmp)) return true;
```
- We call the backtracking function `bt`, passing the next index and the current number `tmp`. If this call returns true, it indicates that a valid sequence has been found, so we return true immediately.

```cpp
        return false;
    }
```
- If no valid split is found after checking all prefixes, we return false.

```cpp
    bool bt(int idx, double prv) {
```
- The backtracking function `bt` is defined, taking the current index and the previous number as parameters.

```cpp
        if(idx == s.size()) return true;
```
- If the current index equals the size of the string, we have successfully traversed the entire string, so we return true.

```cpp
        double tmp = 0;
        for(int i = idx; i < s.size(); i++) {
```
- We initialize another temporary variable `tmp` to build subsequent numbers. We iterate from the current index to the end of the string.

```cpp
            tmp = tmp * 10 + (s[i] - '0');
```
- Similar to before, we build `tmp` from the digits starting at the current index.

```cpp
            if(tmp - prv > -1) break;
```
- If the difference between `tmp` and `prv` is greater than -1, we break out of the loop because we can only form valid sequences if the next number is less than or equal to the previous number.

```cpp
            if(tmp - prv == -1) {
```
- If the difference between `tmp` and `prv` equals -1, we have found a valid next number in the sequence.

```cpp
                if(bt(i + 1, tmp))
                    return true;
            }
```
- We recursively call `bt` with the updated index and the current number as the previous number. If this call returns true, we propagate that result back up.

```cpp
        return false;
    }
```
- If we exhaust all possibilities without finding a valid split, we return false.

### Complexity

- **Time Complexity**: 
  - The time complexity of this solution can be considered as \( O(n^2) \) in the worst case, where \( n \) is the length of the string. This arises from the nested loop structure, where each possible starting number can potentially explore every subsequent number.

- **Space Complexity**: 
  - The space complexity is \( O(n) \) due to the recursion stack in the backtracking approach.

### Conclusion

The provided solution effectively determines whether a string can be split into a sequence of integers that decrement by one at each step. By leveraging a backtracking approach, the code systematically explores potential splits, ensuring that each subsequent number adheres to the specified condition.

This method is both clear and efficient, making it suitable for competitive programming and algorithmic challenges. It highlights the power of backtracking in solving problems that involve searching through combinations or sequences. Moreover, the implementation demonstrates how to handle strings and numerical conversions in C++, showcasing an important technique in algorithm design.

Overall, the `splitString` method encapsulates a logical flow for solving the problem while maintaining readability and efficiency, proving it to be an effective solution for this type of challenge.

[`Link to LeetCode Lab`](https://leetcode.com/problems/splitting-a-string-into-descending-consecutive-values/description/)

---
{{< youtube eDtMmysldaw >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
