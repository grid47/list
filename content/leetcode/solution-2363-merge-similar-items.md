
+++
authors = ["grid47"]
title = "Leetcode 2363: Merge Similar Items"
date = "2024-03-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2363: Merge Similar Items in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Sorting","Ordered Set"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "KjqRqf4KZxE"
youtube_upload_date="2022-08-06"
youtube_thumbnail="https://i.ytimg.com/vi_webp/KjqRqf4KZxE/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) 
    {
        map<int,int> m;
        for(int i=0;i<items1.size();i++)
        {
            m[items1[i][0]]=items1[i][1];
        }
        for(int i=0;i<items2.size();i++)
        {
            if(m.find(items2[i][0])!=m.end())
            {
                m[items2[i][0]]+=items2[i][1];
            }
            else
            {
                m[items2[i][0]]=items2[i][1];
            }
        }
        vector<vector<int>> ans;
        for(auto it : m)
        {
            ans.push_back({it.first,it.second});
        }
        return ans;
        
    }
};
{{< /highlight >}}
---

### Problem Statement

The task here is to merge two lists of items, each represented by a 2D vector where each element is a pair of integers: the item ID and its weight. The objective is to combine items from both lists that have the same ID by summing up their weights. The result should be a single list of items sorted by their ID, with each item appearing only once and showing the combined weight.

### Approach

The solution leverages a `map` data structure to efficiently store and update item weights by their IDs, ensuring that each item appears only once in the final list. Here's the approach broken down into steps:

1. **Map Initialization with Items from the First List:**
   First, we loop through the items in `items1` and store each item in a map (`m`) where the key is the item ID, and the value is the item weight. This allows us to initialize the map with all items from the first list.

2. **Merging Weights for Items in the Second List:**
   Next, we iterate over `items2`. For each item in this list, we check if its ID already exists in the map:
   - If it does, we add the item's weight from `items2` to the weight already present in the map for that ID, effectively merging the weights.
   - If it doesn’t exist, we add a new entry to the map with the item's ID and weight.

3. **Building the Result Vector:**
   After processing both lists, the map contains each unique item ID with its total weight. We then iterate over the map and add each entry as a vector (ID and weight) to a result vector `ans`. Since `map` in C++ is naturally sorted by key, the items in `ans` will be in ascending order of IDs, as required.

4. **Returning the Result:**
   Finally, the result vector `ans` is returned, containing the merged items with combined weights.

### Code Breakdown (Step by Step)

#### Step 1: Initializing the Map with Items from the First List

```cpp
map<int, int> m;
for (int i = 0; i < items1.size(); i++) {
    m[items1[i][0]] = items1[i][1];
}
```

In this section, we initialize an empty map `m`. We then iterate over `items1`, and for each item, we insert it into the map with its ID as the key and its weight as the value. After this loop, `m` contains all items from `items1`, with each ID mapped to its corresponding weight.

#### Step 2: Merging Weights for Items in the Second List

```cpp
for (int i = 0; i < items2.size(); i++) {
    if (m.find(items2[i][0]) != m.end()) {
        m[items2[i][0]] += items2[i][1];
    } else {
        m[items2[i][0]] = items2[i][1];
    }
}
```

We now process `items2`. For each item in `items2`, we check if its ID is already present in the map `m`:
- If it is (`m.find(items2[i][0]) != m.end()`), we add the item’s weight from `items2` to the current weight stored in `m` for that ID.
- If it is not, we add a new entry to `m` with the item’s ID and weight from `items2`.

After this loop, `m` contains all unique IDs from both lists, with weights appropriately merged.

#### Step 3: Building the Result Vector

```cpp
vector<vector<int>> ans;
for (auto it : m) {
    ans.push_back({it.first, it.second});
}
```

Here, we create an empty vector `ans` to store the result. We iterate over the map `m`, where each element is a pair (item ID and combined weight). For each pair, we add a vector of two elements (the ID and weight) to `ans`. Since `map` maintains elements in sorted order by key, `ans` will also be sorted by ID.

#### Step 4: Returning the Result

```cpp
return ans;
```

The result vector `ans` is now complete, containing each unique item ID along with its merged weight in ascending order of IDs. We return `ans` as the output of the function.

### Complexity

#### Time Complexity:
- **Inserting Items in the Map:** For both `items1` and `items2`, we perform insertions and updates in the map `m`, which takes `O(log k)` time per operation (where `k` is the number of unique IDs) due to the balanced tree structure of the map. Since we process each item exactly once, this results in a total time complexity of `O((n + m) * log k)`, where `n` and `m` are the sizes of `items1` and `items2`, respectively.
  
- **Building the Result Vector:** We iterate over all entries in the map to build the result vector, which takes `O(k)` time, where `k` is the number of unique item IDs.

Therefore, the total time complexity is `O((n + m) * log k)`.

#### Space Complexity:
- **Map Storage:** We store up to `k` unique item IDs in the map, so the space complexity for the map is `O(k)`.
- **Result Vector:** We also store the merged items in the result vector `ans`, which has a space complexity of `O(k)`.

Thus, the overall space complexity is `O(k)`.

### Conclusion

The code efficiently merges two lists of items with weights using a map, which allows us to keep track of the items by their IDs and sum up weights for items with the same ID. By leveraging the sorted nature of maps in C++, the solution automatically arranges items by ascending order of IDs. This makes the solution both efficient and straightforward, with an overall time complexity of `O((n + m) * log k)` and a space complexity of `O(k)`. The solution is suitable for handling large lists with potentially overlapping items, providing an optimized way to combine item weights based on IDs.

[`Link to LeetCode Lab`](https://leetcode.com/problems/merge-similar-items/description/)

---
{{< youtube KjqRqf4KZxE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
