
+++
authors = ["grid47"]
title = "Leetcode 1436: Destination City"
date = "2024-06-16"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1436: Destination City in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "Hi8vMnnTZHE"
youtube_upload_date="2023-12-15"
youtube_thumbnail="https://i.ytimg.com/vi/Hi8vMnnTZHE/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        map<string, string> mp;
        for(auto s: paths)
            mp[s[0]] = s[1];
        
        string ans = paths[0][0];
        while(mp.count(ans)) {
            ans = mp[ans];
        }
        return ans;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem at hand is to determine the destination city in a directed graph represented by a series of paths between cities. Each path is represented as a directed edge from one city to another, and the task is to find the city that cannot be the starting point of any path. This destination city is the endpoint that no other city points to.

### Approach

To solve this problem, we will utilize a map (or dictionary) to represent the paths from one city to another. The solution involves the following steps:

1. **Input Parsing**: We will read the list of paths and store them in a map where each key is a starting city, and its corresponding value is the destination city.
2. **Identify the Destination City**: We will start with an arbitrary city (the starting point of the first path) and keep traversing the paths using the map until we reach a city that does not have any outgoing paths.
3. **Return the Result**: The last city reached in this traversal is our destination city.

### Code Breakdown (Step by Step)

Let's break down the code to understand its functionality and flow:

1. **Class Declaration**:
   ```cpp
   class Solution {
   public:
   ```

   - We define a class `Solution` that will contain the method to find the destination city.

2. **Function Declaration**:
   ```cpp
   string destCity(vector<vector<string>>& paths) {
   ```

   - The function `destCity` takes a vector of vectors, `paths`, where each inner vector contains two strings: a starting city and a destination city.

3. **Map Initialization**:
   ```cpp
   map<string, string> mp;
   for(auto s: paths)
       mp[s[0]] = s[1];
   ```

   - We declare a map `mp` to store the paths. The loop iterates through each path in the `paths` vector, where `s[0]` is the starting city, and `s[1]` is the destination city. This creates a mapping of starting cities to their corresponding destination cities.

4. **Starting City Initialization**:
   ```cpp
   string ans = paths[0][0];
   ```

   - We initialize the string `ans` with the first starting city, which is `paths[0][0]`. This city will be used as the starting point for our traversal.

5. **Finding the Destination City**:
   ```cpp
   while(mp.count(ans)) {
       ans = mp[ans];
   }
   ```

   - This while loop checks if the current city `ans` exists in the map `mp`. If it does, we update `ans` to the destination city corresponding to `ans`. This continues until we reach a city that does not have any outgoing paths (i.e., it is not a key in the map).

6. **Return the Result**:
   ```cpp
   return ans;
   }
   ```

   - Finally, once the loop terminates, we return `ans`, which now contains the name of the destination city.

### Complexity

- **Time Complexity**: The time complexity of this solution is \(O(n)\), where \(n\) is the number of paths in the input. We traverse the list of paths once to build the map and then potentially traverse the paths again to find the destination city, but each traversal is linear in nature.

- **Space Complexity**: The space complexity is also \(O(n)\) due to the storage requirements for the map that holds the paths.

### Conclusion

The provided code efficiently determines the destination city using a map to represent the paths between cities. The approach ensures that we traverse the paths in linear time, making it suitable for large inputs.

#### Key Takeaways:

1. **Data Structures**: Utilizing a map to represent relationships (in this case, city paths) is a powerful approach for problems involving directed graphs or one-to-one mappings.
  
2. **Linear Traversal**: The method employs a straightforward linear traversal of the paths, demonstrating that sometimes the simplest approach can yield efficient solutions.

3. **Problem Solving**: The solution exemplifies how to approach graph-related problems using fundamental programming concepts such as loops, conditionals, and data structures.

Overall, this solution serves as a clear illustration of how to navigate directed paths and find terminal nodes in a graph-like structure, making it applicable to a range of similar problems in computational graph theory.

[`Link to LeetCode Lab`](https://leetcode.com/problems/destination-city/description/)

---
{{< youtube Hi8vMnnTZHE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
