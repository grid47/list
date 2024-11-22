
+++
authors = ["grid47"]
title = "Leetcode 721: Accounts Merge"
date = "2024-08-26"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 721: Accounts Merge in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","String","Depth-First Search","Breadth-First Search","Union Find","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/721.webp"
youtube = "otzKJY8YhRg"
youtube_upload_date="2020-04-04"
youtube_thumbnail="https://i.ytimg.com/vi_webp/otzKJY8YhRg/maxresdefault.webp"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/721.webp" 
    alt="A set of accounts where identical accounts are merged, with each merge softly glowing as it’s processed."
    caption="Solution to LeetCode 721: Accounts Merge Problem"
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
    vector<vector<string>> accountsMerge(vector<vector<string>>& acc) {
        map<string, string> mp;
        map<string, set<string>> gph;
        for(auto ac: acc) {
            for(int i = 1; i < ac.size(); i++) {
                mp[ac[i]] = ac[0];
                gph[ac[i]].insert(ac[1]);
                gph[ac[1]].insert(ac[i]);
            }
        }
        
        set<string> seen;
        vector<vector<string>> ans;
        for(auto it: mp) {
            if(seen.count(it.first)) continue;
            vector<string> tmp;
            dfs(tmp, gph, seen, it.first);
            sort(tmp.begin(), tmp.end());
            tmp.insert(tmp.begin(), it.second);
            ans.push_back(tmp);
        }
        
        return ans;
    }
    
    void dfs(vector<string> &tmp, map<string, set<string>> &gph, set<string> &seen, string node) {
        tmp.push_back(node);
        seen.insert(node);
        for(auto it: gph[node]) {
            if(!seen.count(it)) {
                dfs(tmp, gph, seen, it);
            }
        }
        
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem asks us to **merge accounts** where multiple email addresses can belong to the same account, but may appear in different records. We are tasked with finding all the accounts that should be merged, where an account is merged if any two of its email addresses share a common domain. The final result should return the merged accounts, where each account is represented by a list of emails and the first email should represent the account holder's name.

### Approach

The solution follows a **graph-based approach** to represent the email addresses as nodes and the connections between them as edges. Here’s a step-by-step breakdown of how we can approach the problem:

1. **Graph Representation**: We model the problem as a graph, where each email address is a node. The edges between nodes represent that two email addresses belong to the same account. This is because an account can have multiple email addresses, and if one email address is linked to another, they belong to the same account.

2. **Union-Find or DFS**: To merge accounts, we need to group connected components in the graph. This can be done using a **Depth-First Search (DFS)** approach or **Union-Find**. We will use DFS here to explore the connected components (i.e., the accounts).

3. **Mapping Emails to Accounts**: We need to ensure that each email address is associated with the correct account holder's name. The first email in each list represents the account holder’s name.

4. **Final Sorting**: After collecting the connected components (i.e., all the email addresses that belong to the same account), we sort them lexicographically and insert the account holder's name as the first element in each merged account.

5. **Handling Already Seen Accounts**: To avoid revisiting email addresses we’ve already processed, we maintain a `seen` set, which ensures that we only visit each email once.

### Code Breakdown (Step by Step)

Let’s dive into the code to understand how it implements this approach:

1. **Data Structures**:
   - `mp`: A map to associate each email address with the account holder’s name.
   - `gph`: A map representing the graph where each email address points to a set of other email addresses connected to it.
   - `seen`: A set to track the email addresses that have already been visited.
   - `ans`: A vector of vectors where the final merged accounts will be stored.

2. **Building the Graph**:
   ```cpp
   for(auto ac: acc) {
       for(int i = 1; i < ac.size(); i++) {
           mp[ac[i]] = ac[0];
           gph[ac[i]].insert(ac[1]);
           gph[ac[1]].insert(ac[i]);
       }
   }
   ```
   - The first loop iterates through each account in `acc`, where each account is represented as a vector of strings (the first element is the name and the rest are the email addresses).
   - For each email address, we map it to the account holder’s name using the `mp` map.
   - We also build the graph by inserting edges between the current email and the next one, ensuring both directions (i.e., if `a` and `b` are connected, both `a` points to `b` and `b` points to `a`).

3. **DFS Traversal**:
   ```cpp
   void dfs(vector<string> &tmp, map<string, set<string>> &gph, set<string> &seen, string node) {
       tmp.push_back(node);
       seen.insert(node);
       for(auto it: gph[node]) {
           if(!seen.count(it)) {
               dfs(tmp, gph, seen, it);
           }
       }
   }
   ```
   - The `dfs` function performs a Depth-First Search on the graph starting from the given email address (`node`).
   - It adds the current email to the `tmp` vector, marks it as seen, and recursively visits all its neighbors (emails connected in the graph).
   - This traversal collects all the email addresses that belong to the same account.

4. **Building the Result**:
   ```cpp
   for(auto it: mp) {
       if(seen.count(it.first)) continue;
       vector<string> tmp;
       dfs(tmp, gph, seen, it.first);
       sort(tmp.begin(), tmp.end());
       tmp.insert(tmp.begin(), it.second);
       ans.push_back(tmp);
   }
   ```
   - The second loop processes each email address in `mp` (which is the list of all emails encountered).
   - If the email has already been seen, it skips to the next one.
   - Otherwise, it performs a DFS to collect all emails connected to the current email.
   - After the DFS traversal, the emails are sorted lexicographically, and the account holder's name (from `mp`) is inserted as the first element of the result.
   - Finally, the merged account is added to the result vector `ans`.

5. **Returning the Result**:
   ```cpp
   return ans;
   ```
   - After processing all emails and their connected components, the function returns the merged accounts.

### Complexity Analysis

- **Time Complexity**:
  - **Building the Graph**: We iterate over each account and each email in it. This takes **O(N * M)** time, where `N` is the number of accounts and `M` is the average number of emails per account.
  - **DFS Traversal**: We visit each email exactly once, so the DFS traversal takes **O(V + E)** time, where `V` is the number of emails and `E` is the number of edges (connections between emails). This is also **O(N * M)** in the worst case.
  - **Sorting the Result**: After the DFS traversal, we sort the emails in each account, which takes **O(K log K)** for each account, where `K` is the number of emails in the account. In the worst case, the time complexity of sorting all accounts is **O(N * M log M)**.
  
  The overall time complexity is **O(N * M + N * M log M)**.

- **Space Complexity**:
  - We use a map (`mp`) to store the account holder’s name for each email, which takes **O(V)** space, where `V` is the number of unique email addresses.
  - We use a graph (`gph`) to store the adjacency list representation, which also takes **O(V + E)** space.
  - The `seen` set takes **O(V)** space.
  - The final result `ans` takes **O(V)** space.

  The overall space complexity is **O(V + E)**.

### Conclusion

This solution efficiently merges accounts by modeling the problem as a graph and performing a Depth-First Search (DFS) to find connected components. The approach ensures that we group emails belonging to the same account and sort them lexicographically for the final result. The use of a graph with an adjacency list allows us to efficiently check for connections between emails. The time complexity of **O(N * M + N * M log M)** and space complexity of **O(V + E)** makes this solution scalable for large inputs, where `N` is the number of accounts and `M` is the average number of emails per account. This approach efficiently solves the problem of merging accounts with multiple email addresses.

[`Link to LeetCode Lab`](https://leetcode.com/problems/accounts-merge/description/)

---
{{< youtube otzKJY8YhRg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
