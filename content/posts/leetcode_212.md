
+++
authors = ["Yasir"]
title = "Leetcode 212: Word Search II"
date = "2024-03-29"
description = "Solution to Leetcode 212"
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/word-search-ii/description/)

---

**Code:**

{{< highlight html >}}
class Node {
public:
    char val;
    bool isWord;
    string word;
    vector<Node*> next;
    Node(char val, bool isWord) {
        this->val = val;
        this->isWord = isWord;
        next.resize(26, NULL);
    }
};

class Solution {
public:
    int m, n;
    vector<vector<char>> grid;
    Node* root;
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        this->m = board.size(), this->n = board[0].size();
        this->grid = board;
        root = new Node(' ', false);
        Node* node;
        for(string w: words) {
            node = root;
            for(char x: w) {
                int c = x - 'a';
                if(node->next[c] == NULL)
                    node->next[c] = new Node(x, false);
                node = node->next[c];
            }
            node->word = w;
            node->isWord = true;
        }
        
        vector<string> ans;
        for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            dfs(ans, root, i, j);
        
        return ans;
    }
    
    void dfs(vector<string> &ans, Node* node, int i, int j) {
    
        char c = grid[i][j];
        
        if(c == '#' || node->next[c - 'a'] == NULL)
            return;
        
        node = node->next[c-'a'];
        if(node->isWord) {
            ans.push_back(node->word);
            node->isWord = false;
        }
        grid[i][j] = '#';
        int dir[] = {0, 1, 0, -1, 0};
        for(int k = 0;k < 4; k++) {
            int x = i + dir[k], y = j + dir[k + 1];
            if(x < 0 || y < 0 || x == m || y == n)
                continue;
            dfs(ans, node, x, y);
        }
        grid[i][j] = c;
    }
};
{{< /highlight >}}

