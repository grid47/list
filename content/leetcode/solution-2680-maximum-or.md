
+++
authors = ["grid47"]
title = "Leetcode 2680: Maximum OR"
date = "2024-02-13"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2680: Maximum OR in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy","Bit Manipulation","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "XiaXIrEHFEY"
youtube_upload_date="2023-05-13"
youtube_thumbnail="https://i.ytimg.com/vi/XiaXIrEHFEY/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    long long maximumOr(vector<int>& nums, int k) 
    {
        //prefix or
        //suffix or
        vector<long long>prefixor;
        for(int i = 0 ; i < nums.size() ; i++)
        {
            if(i == 0) prefixor.push_back((1LL * nums[i]));
            else prefixor.push_back(((1LL*prefixor.back()) | (1LL*nums[i])));
        }    

        vector<long long>suffixor;
        for(int i = nums.size() - 1; i >= 0; i--)
        {
            if(i == (nums.size()-1))  suffixor.push_back((1LL * nums[i]));
            else suffixor.push_back(((1LL*suffixor.back()) | (1LL*nums[i])));
        }
        reverse(suffixor.begin(),suffixor.end());

        long long ans = 0;
        for(int i = 0 ; i < nums.size() ; i++)
        { 
            long long int left = 0;
            long long int self;
            long long int right = 0;
            if((i-1) >= 0)
            {
                left = prefixor[i-1];
            }
            self = (nums[i] * pow(2,k));
            if((i+1) <= nums.size()-1)
            {
                right = suffixor[i+1];
            }
            ans = max(ans , left | self | right);
        }
        return ans;
    }
};
{{< /highlight >}}
---

### Problem Statement

The given problem requires finding the maximum OR value achievable by performing the following operation on an element in an array `nums`. You can multiply any element `nums[i]` by `2^k` and perform an OR operation on it with the elements to its left and right. The goal is to compute the maximum possible OR value after performing the operation on any element in the array.

The task is to maximize the value of the OR operation involving the modified element and its neighbors, considering all possible positions in the array.

### Approach

This problem is essentially about combining the properties of the OR operation and efficiently modifying the elements in the array by multiplying them with a power of 2. The solution can be broken down into several key steps:

1. **Prefix OR Array**: First, calculate the prefix OR of the array. The prefix OR is a way to keep track of the OR operation on all elements to the left of a given index.
   
2. **Suffix OR Array**: Similarly, calculate the suffix OR of the array. This is similar to the prefix OR but tracks the OR operation for all elements to the right of the given index.

3. **Main Calculation**: Iterate through each element in the array. For each element:
   - Calculate the OR of the elements to its left (using the prefix OR array).
   - Modify the current element by multiplying it by `2^k` and compute the OR with the neighbors using the suffix OR array.
   - Calculate the maximum OR value obtained by this process.

### Code Breakdown (Step by Step)

#### Step 1: Calculate Prefix OR Array

```cpp
vector<long long> prefixor;
for (int i = 0; i < nums.size(); i++) {
    if (i == 0) 
        prefixor.push_back((1LL * nums[i]));
    else 
        prefixor.push_back(((1LL * prefixor.back()) | (1LL * nums[i])));
}
```

- **Line 1**: We initialize an empty vector `prefixor` to store the OR results for each prefix of the array.
- **Line 2-5**: We iterate through the array `nums`. If it's the first element, simply set `prefixor[0]` to the first element. For all other elements, calculate the prefix OR up to that index by taking the OR of the previous prefix OR value and the current element in the array.

#### Step 2: Calculate Suffix OR Array

```cpp
vector<long long> suffixor;
for (int i = nums.size() - 1; i >= 0; i--) {
    if (i == (nums.size() - 1))  
        suffixor.push_back((1LL * nums[i]));
    else 
        suffixor.push_back(((1LL * suffixor.back()) | (1LL * nums[i])));
}
reverse(suffixor.begin(), suffixor.end());
```

- **Line 1**: We initialize an empty vector `suffixor` to store the OR results for each suffix of the array.
- **Line 2-5**: We iterate through the array in reverse. For each element, we calculate the suffix OR from the rightmost element to the leftmost one.
- **Line 6**: After the iteration, we reverse the `suffixor` array to align it with the original order of the `nums` array.

#### Step 3: Calculate the Maximum OR Value

```cpp
long long ans = 0;
for (int i = 0; i < nums.size(); i++) {
    long long int left = 0;
    long long int self;
    long long int right = 0;

    if ((i - 1) >= 0) {
        left = prefixor[i - 1];
    }
    self = (nums[i] * pow(2, k));

    if ((i + 1) <= nums.size() - 1) {
        right = suffixor[i + 1];
    }

    ans = max(ans, left | self | right);
}
```

- **Line 1**: Initialize a variable `ans` to store the maximum OR value.
- **Line 2-10**: We iterate through the array and calculate the OR for each element:
  - **Left**: If the current element is not the first, set `left` as the prefix OR of the element just before it.
  - **Self**: Multiply the current element by `2^k` to simulate the modification, and store the result in `self`.
  - **Right**: If the current element is not the last, set `right` as the suffix OR of the element just after it.
  - For each element, compute the OR of `left`, `self`, and `right`, and update the maximum `ans`.

#### Step 4: Return the Result

```cpp
return ans;
```

- **Line 11**: After iterating through all elements, return the maximum OR value stored in `ans`.

### Complexity

#### Time Complexity:

1. **Prefix OR Calculation**: The prefix OR is calculated in **O(n)** time, where `n` is the size of the array.
2. **Suffix OR Calculation**: The suffix OR is calculated in **O(n)** time as well.
3. **Main Loop**: The main loop iterates through the array and performs constant-time operations (such as multiplications and OR operations) for each element. Thus, it takes **O(n)** time.

Therefore, the overall time complexity is **O(n)**, where `n` is the size of the input array.

#### Space Complexity:

- The space complexity is **O(n)** because we use two additional arrays (`prefixor` and `suffixor`), each of size `n`, to store the prefix and suffix OR values.

### Conclusion

The solution provided is efficient for solving the problem of maximizing the OR value after modifying each element in the array. It leverages the prefix and suffix OR arrays to reduce redundant calculations, making the solution run in **O(n)** time, which is optimal for this problem. The space complexity is **O(n)** due to the extra arrays used for storing the OR values. This approach is well-suited for large arrays and is highly efficient, balancing time complexity with space usage.

[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-or/description/)

---
{{< youtube XiaXIrEHFEY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
