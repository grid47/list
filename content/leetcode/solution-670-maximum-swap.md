
+++
authors = ["grid47"]
title = "Leetcode 670: Maximum Swap"
date = "2024-09-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 670: Maximum Swap in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/670.webp"
youtube = "arecn8VuQL0"
youtube_upload_date="2020-05-02"
youtube_thumbnail="https://i.ytimg.com/vi/arecn8VuQL0/maxresdefault.jpg"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/670.webp" 
    alt="A number where the maximum swap is performed, with each swap softly glowing as it occurs."
    caption="Solution to LeetCode 670: Maximum Swap Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maximumSwap(int num) {

        vector<int> idx(10, 0);

        string nm = to_string(num);
        for(int i = 0; i < nm.size(); i++) idx[nm[i] - '0'] = i;

        for(int i = 0; i < nm.size(); i++)
        for(int j = 9; j > nm[i] - '0'; j--) {
            if(idx[j] > i) {
                swap(nm[idx[j]], nm[i]);
                return stoi(nm);
            }
        }

        return num;
    }
};
{{< /highlight >}}
---

### Problem Statement:

The problem asks us to find the largest number possible by swapping at most one pair of digits in a given number `num`. You are to return the maximum number that can be obtained by performing a single swap of digits, or if no such swap can improve the number, return the original number.

### Approach:

To solve this problem, we need to find the first opportunity where swapping digits results in a larger number. The approach is as follows:
1. **Track the Last Occurrence of Each Digit**: We start by storing the last index where each digit (from 0 to 9) appears in the number. This allows us to determine which digit to swap with to maximize the number.
   
2. **Greedy Approach for Maximum Swap**: We iterate through the number from left to right. For each digit, we look for the largest possible digit (greater than the current digit) that occurs later in the number. If such a digit exists, we perform the swap to maximize the number and return the result.

3. **Single Swap**: Once we identify the digits that should be swapped, we perform the swap and return the number as an integer.

The main idea is to use a greedy approach, always attempting to make the largest possible swap when encountering a smaller digit.

### Code Breakdown (Step by Step):

#### Step 1: Create a Vector to Store the Last Occurrence of Each Digit
```cpp
vector<int> idx(10, 0);
```
- We initialize a vector `idx` of size 10 to store the last occurrence of each digit (0-9) in the number. The index of this vector represents the digit, and the value at each index represents the position of the last occurrence of that digit in the number.

#### Step 2: Convert the Number to a String
```cpp
string nm = to_string(num);
```
- We convert the integer `num` into a string `nm` to allow easy manipulation of the individual digits. This allows us to access each digit by index, which is more convenient for performing the swap.

#### Step 3: Populate the `idx` Vector with Last Occurrences of Each Digit
```cpp
for(int i = 0; i < nm.size(); i++) 
    idx[nm[i] - '0'] = i;
```
- We iterate over each digit in the string `nm`, converting it to its integer form by subtracting `'0'`. For each digit, we update the `idx` vector to record the last position of that digit in the number.

#### Step 4: Find the First Possible Swap for Maximum Number
```cpp
for(int i = 0; i < nm.size(); i++)
    for(int j = 9; j > nm[i] - '0'; j--) {
        if(idx[j] > i) {
            swap(nm[idx[j]], nm[i]);
            return stoi(nm);
        }
    }
```
- Now, we iterate through the string `nm` from left to right. For each digit `nm[i]`, we check if there is a larger digit (from 9 down to `nm[i] + 1`) that appears later in the number. This is done by checking the `idx` vector to see if the last occurrence of a larger digit is positioned after the current digit `i`.
- If we find such a digit, we perform the swap and return the number immediately after converting it back to an integer using `stoi(nm)`.

#### Step 5: Return the Original Number if No Swap is Needed
```cpp
return num;
```
- If no valid swap is found, meaning the number is already the largest possible number we can get by swapping at most one pair of digits, we return the original number.

### Complexity:

#### Time Complexity:
- **O(n)**: The time complexity is dominated by the two loops: the first loop iterates through the string `nm` to populate the `idx` vector, and the second nested loop checks for possible swaps. Both loops run in linear time, so the overall time complexity is O(n), where `n` is the length of the number (i.e., the number of digits in `num`).

#### Space Complexity:
- **O(1)**: The space complexity is constant. The `idx` vector has a fixed size of 10 (for the digits 0-9), and the string `nm` stores the digits of the number. Since the size of the `idx` vector does not depend on the size of the input and the space used for the string is proportional to the number of digits, the space complexity is O(1).

### Conclusion:

This solution efficiently solves the problem by using a greedy approach to maximize the number by performing a single swap. The key idea is to track the last occurrence of each digit, and then, for each digit in the number, try to swap it with the largest possible digit that appears later in the number. This approach ensures that the number is maximized with minimal computation.

The algorithm runs in linear time, O(n), making it suitable for numbers with a large number of digits. The space complexity is constant, O(1), as we only use a fixed-size vector and the space required for the string representation of the number.

By leveraging this approach, we ensure an optimal solution to the problem, achieving the maximum number with a single swap in an efficient and easy-to-understand manner.

[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-swap/description/)

---
{{< youtube arecn8VuQL0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
