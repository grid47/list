
+++
authors = ["grid47"]
title = "Leetcode 949: Largest Time for Given Digits"
date = "2024-08-04"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 949: Largest Time for Given Digits in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","String","Enumeration"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "sn6r0ZV_2y4"
youtube_upload_date="2020-09-01"
youtube_thumbnail="https://i.ytimg.com/vi/sn6r0ZV_2y4/hqdefault.jpg?sqp=-oaymwEmCOADEOgC8quKqQMa8AEB-AHUBoAC4AOKAgwIABABGGEgZShHMA8=&rs=AOn4CLCRrVpzGGgx18QwTzZjGamfSnIVlw"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string largestTimeFromDigits(vector<int>& A) {
        sort(begin(A), end(A), greater<int>());
        do if ((A[0] < 2 || (A[0] == 2 && A[1] < 4)) && A[2] < 6)
            return to_string(A[0]) + to_string(A[1]) + ":" + to_string(A[2]) + to_string(A[3]);
        while(prev_permutation(begin(A), end(A)));
            
        return "";
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem asks to create the largest possible time (in the format "HH:MM") using four digits provided in an array `A`. The digits must be rearranged to form a valid time, where:
- The first two digits represent the hour (00 to 23).
- The last two digits represent the minutes (00 to 59).
If it's not possible to form a valid time, return an empty string.

### Approach

To solve the problem, we need to generate the largest possible valid time from the given digits. We can break down the solution into the following key steps:

1. **Sorting the Digits**: 
   We start by sorting the digits in descending order. This is because we want to try and form the largest valid time, starting with the largest possible hour and minute digits.

2. **Checking Validity**:
   After sorting, we generate permutations of the digits to check all possible ways to form a valid time. We use the `prev_permutation` function to generate permutations in descending order, starting with the largest possible arrangement. For each permutation, we check if the resulting time is valid:
   - The first digit (hour’s tens place) must be less than or equal to `2` (to make the hour valid).
   - If the first digit is `2`, the second digit (hour’s ones place) must be less than `4` (to ensure the hour is between 00 and 23).
   - The third digit (minute’s tens place) must be less than `6` (to ensure the minutes are between 00 and 59).

3. **Constructing the Time**:
   Once a valid permutation is found, we construct the time string in the "HH:MM" format and return it. If no valid permutation is found after checking all possible ones, we return an empty string.

### Code Breakdown (Step by Step)

1. **Sorting the Digits in Descending Order**:
   ```cpp
   sort(begin(A), end(A), greater<int>());
   ```
   - We begin by sorting the digits in descending order using `sort` and the `greater<int>` comparator. This allows us to try the largest possible combinations first.

2. **Generating Permutations**:
   ```cpp
   do if ((A[0] < 2 || (A[0] == 2 && A[1] < 4)) && A[2] < 6)
       return to_string(A[0]) + to_string(A[1]) + ":" + to_string(A[2]) + to_string(A[3]);
   while(prev_permutation(begin(A), end(A)));
   ```
   - We then use the `do-while` loop and `prev_permutation` to generate all permutations of the digits in descending order.
   - For each permutation, we check if the arrangement forms a valid time:
     - The first digit `A[0]` must be less than `2`, or if it's `2`, the second digit `A[1]` must be less than `4` to ensure the hour is between 00 and 23.
     - The third digit `A[2]` must be less than `6` to ensure the minutes are between 00 and 59.
   - If a valid time is found, we format the digits into a string "HH:MM" using `to_string` and return the result immediately.

3. **Returning an Empty String**:
   ```cpp
   return "";
   ```
   - If no valid time is found after checking all permutations, the function returns an empty string.

### Complexity

1. **Time Complexity**:
   - Sorting the array of digits takes \(O(4 \log 4) = O(1)\), since the array always contains exactly 4 elements.
   - The `prev_permutation` function generates all permutations of the 4 digits. Since there are 4 digits, the total number of permutations is \(4! = 24\). For each permutation, we perform constant-time checks to validate the time format.
   - Hence, the overall time complexity is \(O(24) = O(1)\), because the number of permutations is constant.

2. **Space Complexity**:
   - The space complexity is \(O(1)\) because we are only using a constant amount of extra space, namely the `A` array and a few integer variables for processing.

### Conclusion

This solution efficiently generates the largest possible valid time from four digits by sorting the digits in descending order and checking all permutations for validity. The use of `prev_permutation` ensures that we explore the largest possible time combinations first, which allows us to quickly find the largest valid time or determine that it's impossible to form a valid time. The solution has constant time and space complexity, making it optimal for the given problem.

[`Link to LeetCode Lab`](https://leetcode.com/problems/largest-time-for-given-digits/description/)

---
{{< youtube sn6r0ZV_2y4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
