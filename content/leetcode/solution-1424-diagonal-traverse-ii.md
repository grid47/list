
+++
authors = ["grid47"]
title = "Leetcode 1424: Diagonal Traverse II"
date = "2024-06-17"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1424: Diagonal Traverse II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Sorting","Heap (Priority Queue)"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "k4YsQgeJBt0"
youtube_upload_date="2020-04-30"
youtube_thumbnail="https://i.ytimg.com/vi_webp/k4YsQgeJBt0/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int m = nums.size(), n = nums[0].size(), mx = 0;
        unordered_map<int, vector<int>> mp;

        for(int i = 0; i < nums.size(); i++)
        for(int j = 0; j < nums[i].size(); j++) {
            mp[i + j].push_back(nums[i][j]);
            mx = max(mx, i + j);
        }

        vector<int> ans;
        for(int i = 0; i <= mx; i++) {
            for(auto x = mp[i].rbegin(); x != mp[i].rend(); x++)
            ans.push_back(*x);
        }
        return ans;
    }
};

/*
    Primary attempt can redirect to two pointer simulation
    But right attempt is, queueing over a map which shares same diagonals
*/
{{< /highlight >}}
---

### Problem Statement

The problem at hand is to return the elements of a 2D vector in a diagonal order. The input is a vector of vectors, where each inner vector may have different lengths, representing rows of a matrix. The desired output is a single vector that contains the elements traversed in diagonal order, starting from the top-left corner and moving towards the bottom-right corner.

### Approach

To solve this problem, we can utilize the concept of grouping elements based on their diagonal indices. Here's how we can break down the approach:

1. **Mapping Diagonal Indices**:
   - Each element in the matrix can be identified by a diagonal index defined as the sum of its row index and column index (`i + j`).
   - For example, elements in the same diagonal will have the same sum value. For the diagonal containing `(0,0)`, `(0,1)`, `(1,0)`, and so forth, the sums would be `0`, `1`, and `2` respectively.

2. **Using a Map for Storage**:
   - We will use an unordered map to store vectors corresponding to each diagonal index. Each key will be the diagonal index, and the value will be a vector of elements found at that diagonal.

3. **Filling the Map**:
   - We will iterate through each element of the input matrix, calculate its diagonal index, and push the element into the respective vector in the map.

4. **Constructing the Result**:
   - Once the map is populated, we will traverse the map in order of diagonal indices and reverse the order of elements in each vector to achieve the desired bottom-to-top traversal for each diagonal.

5. **Returning the Result**:
   - Finally, we will concatenate all elements from the vectors in the correct order into a single output vector.

### Code Breakdown (Step by Step)

Now, let's examine the provided code step by step to understand how it implements the above approach:

1. **Class Declaration**:
   ```cpp
   class Solution {
   public:
   ```

   - We declare a class `Solution` which will contain our method for diagonal traversal.

2. **Function Declaration**:
   ```cpp
   vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
   ```

   - The method `findDiagonalOrder` takes a reference to a vector of vectors `nums` as input and returns a vector of integers.

3. **Variable Initialization**:
   ```cpp
   int m = nums.size(), n = nums[0].size(), mx = 0;
   unordered_map<int, vector<int>> mp;
   ```

   - We initialize `m` to represent the number of rows in the input matrix and `n` for the number of columns (assuming all rows have at least one column).
   - `mx` is used to track the maximum diagonal index encountered.
   - We declare an unordered map `mp` to store the elements by their diagonal index.

4. **Populating the Map**:
   ```cpp
   for(int i = 0; i < nums.size(); i++)
   for(int j = 0; j < nums[i].size(); j++) {
       mp[i + j].push_back(nums[i][j]);
       mx = max(mx, i + j);
   }
   ```

   - We iterate through each element of the `nums` matrix using two nested loops.
   - For each element `nums[i][j]`, we calculate its diagonal index (`i + j`) and append the element to the corresponding vector in `mp`.
   - We also update `mx` to ensure we know the highest diagonal index present.

5. **Constructing the Result Vector**:
   ```cpp
   vector<int> ans;
   for(int i = 0; i <= mx; i++) {
       for(auto x = mp[i].rbegin(); x != mp[i].rend(); x++)
           ans.push_back(*x);
   }
   ```

   - We declare a result vector `ans`.
   - We iterate from `0` to `mx` to process each diagonal index.
   - For each diagonal, we use a reverse iterator (`rbegin` and `rend`) to traverse the elements in reverse order and append them to `ans`.

6. **Return Statement**:
   ```cpp
   return ans;
   }
   ```

   - Finally, we return the populated `ans` vector.

### Complexity

- **Time Complexity**: The time complexity of this solution is \(O(N)\), where \(N\) is the total number of elements across all rows in the input vector. Each element is processed exactly once during the population of the map and once during the final traversal.

- **Space Complexity**: The space complexity is also \(O(N)\) due to the use of the map to store vectors of diagonal elements.

### Conclusion

The `findDiagonalOrder` function efficiently constructs a diagonal traversal of a 2D matrix represented as a vector of vectors. By grouping elements based on their diagonal indices and using a map for storage, the solution maintains clarity and efficiency. The use of reverse iteration ensures that elements are added to the result in the correct order, adhering to the problem requirements.

#### Key Takeaways:

- **Diagonal Traversal**: Understanding how to leverage the properties of indices in a matrix allows for efficient traversal strategies.
- **Data Structures**: The use of unordered maps and vectors showcases the flexibility of C++ STL containers in managing collections of elements with dynamic sizes.
- **Efficiency**: This method effectively combines the simplicity of nested loops with efficient data storage and retrieval, resulting in an optimal solution.

Overall, the provided solution not only solves the problem at hand but also illustrates essential concepts in programming, data structures, and algorithm design.

[`Link to LeetCode Lab`](https://leetcode.com/problems/diagonal-traverse-ii/description/)

---
{{< youtube k4YsQgeJBt0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
