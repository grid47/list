class Solution {
public:
    string toGoatLatin(string str) {
        stringstream iss(str), oss;
        set<char> s = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        string word;
        string a;
        while(iss >> word) {
            a.push_back('a');
            if(s.count(word[0])) {
                oss << ' ' << word << "ma" << a;
            } else {
                oss << ' ' << word.substr(1) << word[0]  << "ma" << a;                
            }
        }
        return oss.str().substr(1);
    }
};