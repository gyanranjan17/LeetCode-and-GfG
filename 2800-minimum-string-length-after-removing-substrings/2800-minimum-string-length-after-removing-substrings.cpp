class Solution {
public:
 int min(const std::string& s) {
    std::string result;
    
    for (char c : s) {
        result.push_back(c);
        
        int n = result.length();
        
        if (n >= 2 && result[n - 2] == 'A' && result[n - 1] == 'B') {
            result.pop_back();
            result.pop_back();
        } else if (n >= 2 && result[n - 2] == 'C' && result[n - 1] == 'D') {
            result.pop_back();
            result.pop_back();
        }
    }
    
    return result.length();
}
    int minLength(string s) {
        return min(s);
    }
};