
+++
authors = ["grid47"]
title = "Leetcode 1734: Decode XORed Permutation"
date = "2024-05-17"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1734: Decode XORed Permutation in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Bit Manipulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "uA9lPzogB7Y"
youtube_upload_date="2021-01-23"
youtube_thumbnail="https://i.ytimg.com/vi/uA9lPzogB7Y/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> decode(vector<int>& enc) {
        int n = enc.size() + 1;
        vector<int> ans(n, 0);
        
        int x = 0;
        for(int i = 1; i < n + 1; i++)
            x ^= i;
        
        ans[0] = x;
        for(int i = 1; i < enc.size(); i += 2)
            ans[0] ^= enc[i];
        
        for(int i = 1; i < n; i++)
            ans[i] = ans[i - 1] ^ enc[i - 1];
        
        return ans;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem requires us to decode a sequence of integers that have been encoded using a specific XOR operation. Given an encoded array `enc`, we need to reconstruct the original array `ans`, which is of size `n = enc.size() + 1`. The encoding process uses the properties of the XOR operation to obfuscate the original data, making it necessary to understand the underlying mechanics of XOR to reverse the operation effectively.

### Approach

To solve this problem, we can utilize the properties of the XOR operation, particularly the fact that:

1. \(a \oplus a = 0\) for any integer \(a\) (XORing a number with itself results in zero).
2. \(a \oplus 0 = a\) (XORing a number with zero results in the number itself).
3. XOR is commutative and associative, meaning the order in which you XOR numbers does not affect the result.

Using these properties, we can derive the original values from the encoded array in the following steps:

1. **Determine the Size of the Original Array**: The size of the original array is one more than the size of the encoded array.
2. **Calculate XOR of All Indices**: Compute the XOR of all indices from 1 to `n` to find a starting value for the first element of the decoded array.
3. **Adjust for Odd Indexed Elements**: XOR the first element with the values at odd indices from the encoded array.
4. **Iteratively Build the Original Array**: Using the decoded first element, calculate the remaining elements of the original array using the encoded array values.

### Code Breakdown (Step by Step)

Here’s a detailed breakdown of the code implementation:

1. **Class Definition**: The solution is encapsulated within a class named `Solution`.

   ```cpp
   class Solution {
   ```

2. **Public Method**: The method `decode` takes a vector of integers `enc` as input and returns the decoded original array.

   ```cpp
   public:
       vector<int> decode(vector<int>& enc) {
   ```

3. **Initialization**: We determine the size of the original array `n` by adding 1 to the size of the encoded array and initialize the result vector `ans` with zeros.

   ```cpp
   int n = enc.size() + 1;
   vector<int> ans(n, 0);
   ```

4. **Calculate XOR of Indices**: We initialize a variable `x` to hold the XOR of all indices from 1 to `n`. This is done using a simple loop.

   ```cpp
   int x = 0;
   for(int i = 1; i < n + 1; i++)
       x ^= i;
   ```

5. **Determine the First Element**: The first element of the original array is set to the calculated XOR value `x`. Next, we adjust this value by XORing it with the values found at odd indices in the encoded array.

   ```cpp
   ans[0] = x;
   for(int i = 1; i < enc.size(); i += 2)
       ans[0] ^= enc[i];
   ```

6. **Iteratively Build Remaining Elements**: We use another loop to build the rest of the `ans` array by applying the XOR operation with the corresponding values from the encoded array. This process effectively decodes each subsequent value.

   ```cpp
   for(int i = 1; i < n; i++)
       ans[i] = ans[i - 1] ^ enc[i - 1];
   ```

7. **Return the Result**: Finally, we return the decoded array.

   ```cpp
   return ans;
   }
   ```

### Complexity

- **Time Complexity**: The overall time complexity is \(O(n)\), where \(n\) is the size of the original array (or \(enc.size() + 1\)). This is due to the linear passes through the encoded array to compute XOR values.

- **Space Complexity**: The space complexity is also \(O(n)\), which accounts for the space needed to store the result vector `ans`.

### Conclusion

The provided solution effectively decodes the original array from the encoded input by utilizing the properties of the XOR operation. The approach leverages mathematical properties to reconstruct the original values systematically, ensuring that the solution is both efficient and straightforward. By carefully maintaining the relationships between the indices and the encoded values, the method achieves the desired outcome while minimizing complexity. This solution is robust and can be applied to similar problems involving encoded data that utilizes XOR for transformation, showcasing the versatility of the XOR operation in data manipulation tasks.

[`Link to LeetCode Lab`](https://leetcode.com/problems/decode-xored-permutation/description/)

---
{{< youtube uA9lPzogB7Y >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
