
+++
authors = ["grid47"]
title = "Leetcode 2708: Maximum Strength of a Group"
date = "2024-02-10"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2708: Maximum Strength of a Group in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Backtracking","Greedy","Bit Manipulation","Sorting","Enumeration"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "Kqv0-lRVYwM"
youtube_upload_date="2023-05-27"
youtube_thumbnail="https://i.ytimg.com/vi_webp/Kqv0-lRVYwM/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        
        bool zero = false, allneg = true, allzero = true, pos = false;
        
        int ncnt = 0, pcnt = 0;
        
        long long ans = 1, neg = 1;
        int mxn = -10;
        int n = nums.size();
        
        for(int i = 0; i < n; i++) {
            if(nums[i] > 0) {
                pcnt++;
                pos = true;
                allzero = false;
                allneg = false;
                ans *= nums[i];
            } else if(nums[i] == 0) {
                zero = true;
            } else {
                ncnt++;
                allzero = false;                
                mxn= max(mxn, nums[i]);
                neg *= nums[i];
            }
        }
        
        if(allzero) return 0;
        
        if(ncnt > 0 && (ncnt %2)) {
            if(pcnt == 0 && ncnt == 1) return zero? 0: neg; 
            neg = neg / mxn;
        }
        

        if(pcnt == 0) {
            return neg;
        }
        
        return ans * neg;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem asks you to find the maximum product of a subset of an array `nums` where the subset contains at least one number. The subset can include both positive and negative numbers, and it can also include zeros. You need to return the maximum strength, which is defined as the product of the selected subset. 

### Approach

To solve this problem, we need to carefully consider the impact of positive numbers, negative numbers, and zero on the product of the subset. Here is a breakdown of the key observations:

1. **Handling Positive Numbers**:
   - Positive numbers will always increase the product, so we should always include all positive numbers in the product.

2. **Handling Negative Numbers**:
   - Negative numbers, when taken in even quantities, will result in a positive product. However, if there is an odd count of negative numbers, the product will be negative. Therefore, we need to either exclude the smallest negative number (if we have an odd number of them) or include all negative numbers (if we have an even number of them).

3. **Handling Zeros**:
   - Zeros do not affect the product (i.e., multiplying by zero results in zero), but they can be useful when there are only negative numbers in the array and we cannot form a positive product. In such cases, including a zero might allow us to get a non-negative product.

4. **Final Strategy**:
   - Multiply all positive numbers.
   - For negative numbers, if their count is odd, exclude the smallest (least negative) one to make the product positive.
   - If the count of negative numbers is even, include all of them.
   - If there are zero values, we can use one zero if necessary to avoid a negative product when there are no positive numbers.

### Code Breakdown (Step by Step)

#### 1. Initializing Variables

```cpp
bool zero = false, allneg = true, allzero = true, pos = false;
int ncnt = 0, pcnt = 0;
long long ans = 1, neg = 1;
int mxn = -10;
int n = nums.size();
```

- **`zero`**: Tracks whether there's a zero in the array.
- **`allneg`**: Tracks whether all the numbers are negative (used later to check if there are any positive numbers).
- **`allzero`**: Tracks whether the array consists only of zeros.
- **`pos`**: Indicates whether there are any positive numbers in the array.
- **`ncnt`**: The count of negative numbers.
- **`pcnt`**: The count of positive numbers.
- **`ans`**: The variable that will store the final result, initialized to `1` because we're multiplying numbers.
- **`neg`**: The product of negative numbers, initialized to `1`.
- **`mxn`**: Tracks the maximum negative number (the least negative) to handle cases where we need to exclude it.
- **`n`**: The size of the input array.

#### 2. Loop through the Array

```cpp
for(int i = 0; i < n; i++) {
    if(nums[i] > 0) {
        pcnt++;
        pos = true;
        allzero = false;
        allneg = false;
        ans *= nums[i];
    } else if(nums[i] == 0) {
        zero = true;
    } else {
        ncnt++;
        allzero = false;
        mxn = max(mxn, nums[i]);
        neg *= nums[i];
    }
}
```

- This loop iterates over the entire array and performs the following:
  - If the number is positive (`nums[i] > 0`), it increments the `pcnt` counter, sets the `pos` flag to true, and includes this number in the product (`ans`).
  - If the number is zero (`nums[i] == 0`), it sets the `zero` flag to true.
  - If the number is negative (`nums[i] < 0`), it increments the `ncnt` counter, updates `mxn` with the least negative number, and multiplies `neg` by this number.

#### 3. All Zeros Case

```cpp
if(allzero) return 0;
```

- If all numbers in the array are zero, the result is `0` because no non-zero product can be formed.

#### 4. Handling Negative Numbers

```cpp
if(ncnt > 0 && (ncnt % 2)) {
    if(pcnt == 0 && ncnt == 1) return zero ? 0 : neg; 
    neg = neg / mxn;
}
```

- If there are negative numbers and their count is odd (`ncnt % 2`), we must exclude the smallest negative number (i.e., the least negative) to make the product positive.
- If there are no positive numbers and only one negative number, then we return `0` if there's a zero in the array. Otherwise, the result is just the negative number itself (`neg`).
- Otherwise, we divide `neg` by the least negative number (`mxn`), effectively removing it from the product to make the product positive.

#### 5. Handling No Positive Numbers

```cpp
if(pcnt == 0) {
    return neg;
}
```

- If there are no positive numbers (`pcnt == 0`), the result is simply the product of negative numbers (`neg`).

#### 6. Final Calculation

```cpp
return ans * neg;
```

- If there are positive numbers, we return the product of positive numbers (`ans`) multiplied by the product of negative numbers (`neg`).

### Complexity

#### Time Complexity

The time complexity of this algorithm is **O(n)**, where `n` is the size of the input array. We loop through the array once, performing constant time operations for each element, resulting in a linear time complexity.

#### Space Complexity

The space complexity is **O(1)**, as we only use a constant amount of extra space for the variables, regardless of the size of the input array.

### Conclusion

This solution efficiently computes the maximum product of a subset of the input array by considering the effects of positive and negative numbers on the product. It handles the cases for negative numbers, positive numbers, and zeros by carefully excluding or including elements to maximize the product. The time complexity is linear, making it efficient for large inputs.

[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-strength-of-a-group/description/)

---
{{< youtube Kqv0-lRVYwM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
