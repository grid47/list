
+++
authors = ["grid47"]
title = "Leetcode 2070: Most Beautiful Item for Each Query"
date = "2024-04-14"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2070: Most Beautiful Item for Each Query in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "r1WymhQxLZA"
youtube_upload_date="2021-11-13"
youtube_thumbnail="https://i.ytimg.com/vi/r1WymhQxLZA/maxresdefault.jpg"
comments = true
+++



---
You are given a list of items, where each item has a price and a beauty score. You are also given a list of price queries. For each query, find the maximum beauty of an item with a price less than or equal to the query price. If no such item exists, return 0.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given an array `items` where each item is represented as [price, beauty]. You are also given an array `queries` where each query is a price. For each query, find the maximum beauty of items with price <= query.
- **Example:** `Input: items = [[3, 5], [5, 7], [2, 8], [8, 2]], queries = [3, 5, 7, 9]`
- **Constraints:**
	- 1 <= items.length, queries.length <= 10^5
	- items[i].length == 2
	- 1 <= price[i], beauty[i], queries[j] <= 10^9

{{< dots >}}
### Output Specifications 📤
- **Output:** Return an array where each element is the maximum beauty for each query.
- **Example:** `Output: [8, 7, 7, 7]`
- **Constraints:**
	- The length of the output should be the same as the length of the queries.

{{< dots >}}
### Core Logic 🔍
**Goal:** For each query, find the maximum beauty of an item whose price is less than or equal to the queried price.

- 1. Sort the items based on their price.
- 2. For each query, iterate through the sorted items and track the maximum beauty of items with a price <= query.
{{< dots >}}
### Problem Assumptions ✅
- The price and beauty of each item is non-negative.
- Queries can have repeated prices.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: items = [[3, 5], [5, 7], [2, 8], [8, 2]], queries = [3, 5, 7, 9]`  \
  **Explanation:** For query 3, the possible items are [3, 5] and [2, 8]. The maximum beauty is 8. Similarly, for query 5, the possible items are [3, 5], [5, 7], and [2, 8]. The maximum beauty is 7.

{{< dots >}}
## Approach 🚀
Sort the items based on price, and for each query, find the maximum beauty among items with a price less than or equal to the query.

### Initial Thoughts 💭
- Sorting the items will allow us to efficiently find the maximum beauty for each query.
- By iterating over the sorted items, we can check each query in an optimal way, ensuring that we can handle the large input sizes.
{{< dots >}}
### Edge Cases 🌐
- Handle cases where either items or queries are empty.
- Ensure that the solution can handle inputs with a length up to 10^5.
- Handle cases where no item is within the price range for a query, returning 0.
- Ensure that the solution respects the constraint 1 <= price[i], beauty[i], queries[j] <= 10^9.
{{< dots >}}
## Code 💻
```cpp
vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
    // ith item -> price, beauty
    // max beauty of an item? whoes price <= query[i]
    vector<int> ans(queries.size());

    vector<pair<int, int>> queriesPair;
    for(int i = 0; i < queries.size(); i++) {
        queriesPair.push_back({queries[i], i});
    }

    sort(queriesPair.begin(), queriesPair.end());
    sort(items.begin(), items.end());

    int itemIdx = 0, maxBeauty = 0;
    for(int i = 0; i < queriesPair.size(); i++) {
        int maxPriceAllowed = queriesPair[i].first;
        int queryOriginalIndex = queriesPair[i].second;

        while(itemIdx < items.size() && items[itemIdx][0] <= maxPriceAllowed) {
            maxBeauty = max(maxBeauty, items[itemIdx][1]);
            itemIdx++;
        }
        ans[queryOriginalIndex] = maxBeauty;
    }
    return ans;
}
```

This function calculates the maximum beauty of items for each price query. It sorts both items and queries, then iterates through the queries to find the maximum beauty that can be bought for each price limit.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
	```
	This is the function signature for `maximumBeauty`. It takes two inputs: `items`, a 2D vector where each item consists of a price and beauty value, and `queries`, a vector of price limits. It returns a vector of the maximum beauty for each query.

2. **Variable Declaration**
	```cpp
	    vector<int> ans(queries.size());
	```
	This line declares a vector `ans` to store the maximum beauty for each query. The size of `ans` is the same as the number of queries.

3. **Variable Declaration**
	```cpp
	    vector<pair<int, int>> queriesPair;
	```
	This line declares a vector of pairs `queriesPair`, where each pair consists of a query price and its original index. This helps keep track of the original query order after sorting.

4. **Loop**
	```cpp
	    for(int i = 0; i < queries.size(); i++) {
	```
	This loop iterates through the `queries` vector to build the `queriesPair` vector, where each element is a pair of a query price and its index.

5. **Adding Pair to Vector**
	```cpp
	        queriesPair.push_back({queries[i], i});
	```
	This line adds a pair consisting of the price limit (`queries[i]`) and its index (`i`) to the `queriesPair` vector.

6. **Sort**
	```cpp
	    sort(queriesPair.begin(), queriesPair.end());
	```
	This line sorts the `queriesPair` vector based on the query price in ascending order.

7. **Sort**
	```cpp
	    sort(items.begin(), items.end());
	```
	This line sorts the `items` vector based on the item price in ascending order.

8. **Empty Section**
	```cpp
	
	```
	This space can be used for additional logic or setup if required.

9. **Variable Declaration**
	```cpp
	    int itemIdx = 0, maxBeauty = 0;
	```
	This declares two variables: `itemIdx`, which keeps track of the index of the current item being considered, and `maxBeauty`, which keeps track of the highest beauty value found so far.

10. **Loop**
	```cpp
	    for(int i = 0; i < queriesPair.size(); i++) {
	```
	This loop iterates through the `queriesPair` vector to process each query and find the maximum beauty for that query.

11. **Assign Query Data**
	```cpp
	        int maxPriceAllowed = queriesPair[i].first;
	```
	This line retrieves the maximum price allowed for the current query from `queriesPair[i].first`.

12. **Assign Query Data**
	```cpp
	        int queryOriginalIndex = queriesPair[i].second;
	```
	This line retrieves the original index of the current query from `queriesPair[i].second`.

13. **Loop**
	```cpp
	        while(itemIdx < items.size() && items[itemIdx][0] <= maxPriceAllowed) {
	```
	This inner loop processes the `items` array, checking if the current item's price is less than or equal to the query price limit. If so, it updates the maximum beauty.

14. **Update Max Beauty**
	```cpp
	            maxBeauty = max(maxBeauty, items[itemIdx][1]);
	```
	This line updates `maxBeauty` with the higher beauty value between the current `maxBeauty` and the beauty of the current item.

15. **Increment Index**
	```cpp
	            itemIdx++;
	```
	This increments the `itemIdx` to check the next item in the list.

16. **Assign Result**
	```cpp
	        ans[queryOriginalIndex] = maxBeauty;
	```
	This line assigns the maximum beauty found for the current query to the `ans` vector at the original query index.

17. **Return**
	```cpp
	    return ans;
	```
	This line returns the `ans` vector containing the maximum beauty values for each query.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n + m log m)
- **Average Case:** O(n log n + m log m)
- **Worst Case:** O(n log n + m log m)

The time complexity is dominated by sorting the items and queries.

### Space Complexity 💾
- **Best Case:** O(n + m)
- **Worst Case:** O(n + m)

The space complexity is determined by the storage for items and queries.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/most-beautiful-item-for-each-query/description/)

---
{{< youtube r1WymhQxLZA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
