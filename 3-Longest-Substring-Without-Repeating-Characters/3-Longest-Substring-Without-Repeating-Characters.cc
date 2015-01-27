// 122ms
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> hash_map;
        int total_length = s.size();
        int max_length = 0;
        int temp_length = 0;
        int find_pos = 0;
        int right_pos = 0;
        int left_pos = 0;
        for (; right_pos < total_length; right_pos++) {
            if (hash_map.find(s[right_pos]) != hash_map.end()) {
                find_pos = hash_map.find(s[right_pos])->second;
                while(left_pos <= find_pos) {
                    hash_map.erase(hash_map.find(s[left_pos]));
                    left_pos++;
                }
            }
            hash_map.insert(make_pair(s[right_pos], right_pos));
            temp_length = right_pos - left_pos + 1;
            max_length = max(max_length, temp_length);
        }
        return max_length;
    }
};