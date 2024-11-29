
+++
authors = ["grid47"]
title = "Leetcode 1418: Display Table of Food Orders in a Restaurant"
date = "2024-06-18"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1418: Display Table of Food Orders in a Restaurant in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","String","Sorting","Ordered Set"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
comments = true
+++



---
Given a list of customer orders in a restaurant, return a table where each row represents a table number and the columns represent the number of food items ordered at that table, sorted in lexicographical order.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input is a list of lists, where each sublist contains a customer name, table number, and food item.
- **Example:** `orders = [["John", "2", "Burger"], ["Jane", "1", "Pasta"], ["David", "3", "Pizza"], ["John", "2", "Pasta"], ["Jane", "3", "Pizza"]]`
- **Constraints:**
	- 1 <= orders.length <= 5 * 10^4
	- orders[i].length == 3
	- 1 <= customerName.length, foodItem.length <= 20
	- customerName and foodItem consist of lowercase and uppercase English letters and spaces.
	- tableNumber is an integer between 1 and 500

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is a 2D list representing the display table. The first row is a header, with subsequent rows showing the number of orders for each food item at each table.
- **Example:** `[["Table", "Burger", "Pasta", "Pizza"], ["1", "0", "1", "0"], ["2", "1", "1", "0"], ["3", "0", "0", "2"]]`
- **Constraints:**
	- The output is a 2D list.

{{< dots >}}
### Core Logic 🔍
**Goal:** To count the number of orders of each food item at each table and return them in a sorted manner.

- Iterate over the orders and store the counts of each food item per table using a map.
- Sort the food items alphabetically and tables in increasing order.
- Construct the output list with table numbers and their respective food item counts.
{{< dots >}}
### Problem Assumptions ✅
- All orders have a valid table number and food item.
{{< dots >}}
## Examples 🧩
- **Input:** `orders = [["David","3","Ceviche"],["Corina","10","Beef Burrito"], ["David","3","Fried Chicken"], ["Carla","5","Water"]]`  \
  **Explanation:** For table 3, David orders Ceviche and Fried Chicken, and for table 5, Carla orders Water.

{{< dots >}}
## Approach 🚀
Use a hash map to count the number of food items per table, then sort the food items and tables before constructing the result.

### Initial Thoughts 💭
- The problem involves organizing customer orders by table number.
- We need to sort the food items alphabetically and ensure the output is in table number order.
{{< dots >}}
### Edge Cases 🌐
- An empty orders array should return an empty table.
- Ensure performance is within acceptable limits for 50,000 orders.
- Handle cases where no orders exist for certain food items at specific tables.
- Handle edge cases such as no orders or orders for only one table.
{{< dots >}}
## Code 💻
```cpp
vector<vector<string>> displayTable(vector<vector<string>>& orders) {
    vector<unordered_map<string, int>> table(501);
    set<string> s;
    
    for(vector<string> &v : orders) {
        s.insert(v[2]);
        ++table[stoi(v[1])][v[2]];
    }
    
    vector<vector<string>> res;
    for(int t = 0; t < 501; t++) {
        if (t > 0 && table[t].empty()) {
continue;
        }
        res.push_back(vector<string>());
        res.back().push_back(t == 0 ? "Table" : to_string(t));
        for(auto it = begin(s); it != end(s); it++) {
            
            res.back().push_back(t == 0? *it : to_string(table[t][*it]));
            
        }
    }
    
    return res;
}
```

The function `displayTable` generates a table of the number of orders per table and food item. It processes a list of orders, calculates the count of each food item per table, and then constructs a result table showing the counts.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	vector<vector<string>> displayTable(vector<vector<string>>& orders) {
	```
	Defines the function `displayTable` which takes a vector of orders and returns a table with food item counts per table.

2. **Variable Initialization**
	```cpp
	    vector<unordered_map<string, int>> table(501);
	```
	Initializes a vector of unordered maps to track the count of each food item per table. The vector size is 501 to accommodate up to 500 tables.

3. **Variable Initialization**
	```cpp
	    set<string> s;
	```
	Initializes a set `s` to store the unique food items encountered in the orders.

4. **Loop Constructs**
	```cpp
	    for(vector<string> &v : orders) {
	```
	Begins a loop to iterate over the list of orders.

5. **Set Insertion**
	```cpp
	        s.insert(v[2]);
	```
	Inserts the food item (v[2]) from the current order into the set `s` to ensure uniqueness.

6. **Table Insert**
	```cpp
	        ++table[stoi(v[1])][v[2]];
	```
	Increments the count of the food item at the corresponding table index `stoi(v[1])` using the food item `v[2]`.

7. **Variable Initialization**
	```cpp
	    vector<vector<string>> res;
	```
	Initializes a 2D vector `res` to store the final table with counts.

8. **Loop Constructs**
	```cpp
	    for(int t = 0; t < 501; t++) {
	```
	Begins a loop to process each table from 0 to 500.

9. **Conditional Statement**
	```cpp
	        if (t > 0 && table[t].empty()) {
	```
	Checks if the current table index `t` is greater than 0 and if the table is empty (no food orders).

10. **Control Flow**
	```cpp
	continue;
	```
	Skips the current iteration if the table is empty.

11. **Vector Pushback**
	```cpp
	        res.push_back(vector<string>());
	```
	Adds a new row to the result table `res`.

12. **String Manipulation**
	```cpp
	        res.back().push_back(t == 0 ? "Table" : to_string(t));
	```
	Adds the table label to the first column of the result row. For table 0, it adds the string "Table", otherwise it adds the table number.

13. **Loop Constructs**
	```cpp
	        for(auto it = begin(s); it != end(s); it++) {
	```
	Begins a loop to iterate over all unique food items in the set `s`.

14. **Vector Pushback**
	```cpp
	            res.back().push_back(t == 0? *it : to_string(table[t][*it]));
	```
	Adds the count of the food item for the current table to the result row. For table 0, it adds the food item name, otherwise it adds the count from `table[t][*it]`.

15. **Return Statement**
	```cpp
	    return res;
	```
	Returns the result table `res` containing the counts of food items per table.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n), where n is the number of unique food items.
- **Average Case:** O(n log n + m), where m is the number of tables.
- **Worst Case:** O(n log n + m), where n is the number of orders and m is the number of tables.

The sorting and counting operations dominate the time complexity.

### Space Complexity 💾
- **Best Case:** O(n + m), when the food items and tables are limited.
- **Worst Case:** O(n + m), where n is the number of orders and m is the number of unique food items.

The space complexity depends on the number of orders and the distinct food items.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/display-table-of-food-orders-in-a-restaurant/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
