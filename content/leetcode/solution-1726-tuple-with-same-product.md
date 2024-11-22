
+++
authors = ["grid47"]
title = "Leetcode 1726: Tuple with Same Product"
date = "2024-05-18"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1726: Tuple with Same Product in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Counting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "asI_UBkXI0M"
youtube_upload_date="2021-03-29"
youtube_thumbnail="https://i.ytimg.com/vi/asI_UBkXI0M/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        map<int, int> mp;
        
        int n = nums.size(), res = 0;
        
        for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++) {
            int x = nums[i] * nums[j];
            if(mp.count(x)) res+=mp[x];
            mp[x]++;
        }
        return res * 8;
    }
};
{{< /highlight >}}
---

### Problem Statement

The goal is to count how many unique tuples \((a, b, c, d)\) exist such that the product of \(a\) and \(b\) is equal to the product of \(c\) and \(d\), where each tuple is formed from the elements of a given list of integers `nums`. The tuples must consist of distinct elements, and the order of elements within each tuple does not matter, meaning \((a, b, c, d)\) is considered the same as \((c, d, a, b)\). Each tuple can be derived from pairs of indices within the array.

### Approach

To achieve this, the algorithm can be broken down into the following steps:

1. **Create a Map**: Utilize a map to keep track of the products of pairs of numbers from the list. The keys in the map will be the products, and the values will be the count of how many times each product can be formed using pairs of indices.

2. **Nested Loops for Pair Generation**: Use two nested loops to generate all possible pairs of indices \( (i, j) \) where \( i < j \). Calculate the product for each pair.

3. **Count Products**: For each product calculated, check if it already exists in the map. If it does, it means that there are previously counted pairs that form the same product. Add this count to the result.

4. **Store Product Count**: Increment the count of the product in the map after checking for existing pairs.

5. **Calculate the Result**: Since each product can form tuples in different combinations, multiply the final count by 8 (since each valid product contributes to 8 different tuples: \((a, b, c, d)\), \((a, c, b, d)\), \((a, d, b, c)\), etc.).

### Code Breakdown (Step by Step)

Here’s a breakdown of the code provided:

1. **Class Definition**: The solution is defined within the `Solution` class.

   ```cpp
   class Solution {
   ```

2. **Public Method**: The `tupleSameProduct` method is defined, which takes a vector of integers as input and returns an integer.

   ```cpp
   public:
       int tupleSameProduct(vector<int>& nums) {
   ```

3. **Map Initialization**: A map `mp` is initialized to keep track of the products and their corresponding counts.

   ```cpp
   map<int, int> mp;
   ```

4. **Variable Initialization**: The size of the input vector `n` is stored, and `res` is initialized to hold the result.

   ```cpp
   int n = nums.size(), res = 0;
   ```

5. **Nested Loop Structure**: Two nested loops are used to iterate through the vector to form pairs of indices \( (i, j) \).

   ```cpp
   for(int i = 0; i < n; i++)
       for(int j = i + 1; j < n; j++) {
   ```

6. **Product Calculation**: Inside the inner loop, the product of the current pair is calculated.

   ```cpp
   int x = nums[i] * nums[j];
   ```

7. **Check and Count Existing Products**: If the product already exists in the map, it indicates that there are previously counted pairs that form the same product. Add the count of these pairs to the result.

   ```cpp
   if(mp.count(x)) res += mp[x];
   ```

8. **Update the Product Count**: Regardless of whether the product was previously found, increment the count for this product in the map.

   ```cpp
   mp[x]++;
   ```

9. **Return Result**: Finally, return the result multiplied by 8 to account for all unique combinations of the pairs.

   ```cpp
   return res * 8;
   }
   ```

### Complexity

- **Time Complexity**: The time complexity of this algorithm is \( O(n^2) \) because we are using two nested loops to generate all pairs of indices. For each pair, we perform constant-time operations (checking the map and incrementing counts).

- **Space Complexity**: The space complexity is \( O(k) \), where \( k \) is the number of unique products generated from the pairs. In the worst case, this could also be \( O(n^2) \), but generally, it will be much smaller as not all products will be unique.

### Conclusion

In summary, this solution effectively counts the number of tuples that can be formed based on the given conditions by leveraging a map to store products of pairs of integers from the input list. The use of nested loops allows for generating all possible pairs efficiently, while the map helps in quickly determining if a product has been seen before, thus counting the valid tuples appropriately.

This algorithm is optimal for the problem, running in quadratic time with respect to the size of the input array, making it suitable for moderate input sizes typically encountered in competitive programming. By multiplying the final count by 8, the solution correctly accounts for all unique arrangements of the indices forming the valid tuples. This method is clear and efficient, demonstrating an effective use of combinatorial counting and data structures in C++.

[`Link to LeetCode Lab`](https://leetcode.com/problems/tuple-with-same-product/description/)

---
{{< youtube asI_UBkXI0M >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
