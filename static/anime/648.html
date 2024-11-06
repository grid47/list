class TrieNode {
    public:
    TrieNode* child[26];
    bool isEnd;

    TrieNode() {
        isEnd = false;
        for(int i = 0; i < 26; i++)
            child[i]= NULL;
    }
};

class Solution {
    TrieNode* root;
public:

    void insert(string w) {
        TrieNode* st = root;
        for(char c: w) {
            if(!st->child[c - 'a']) st->child[c - 'a'] = new TrieNode();
            st = st->child[c - 'a'];
        }
        st->isEnd = true;
    }

    string check(string w) {
        TrieNode* st = root;
        string s = "";
        for(char c: w) {
            if(st->child[c - 'a']) st = st->child[c - 'a'];
            else break;
            s += c;
            if(st->isEnd) return s;
        }
        return w;
    }

    string replaceWords(vector<string>& dictionary, string sentence) {
        root = new TrieNode();
        for(auto w: dictionary) insert(w);

        istringstream ss(sentence);
        string word = "", ans = "";

        for(; ss>>word;) {
            ans += check(word);
            ans += ' ';
        }

        ans.pop_back();
        return ans;

    }
};