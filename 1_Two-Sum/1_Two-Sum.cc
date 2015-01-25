// sort and scan, 18ms, O(NlogN)
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> copy_numbers = numbers;
        vector<int> ret;
        ret.resize(2);
        sort(copy_numbers.begin(), copy_numbers.end());
        int left = 0;
        int right = copy_numbers.size()-1;
        int sum = 0;
        while(left < right) {
            sum = copy_numbers[left] + copy_numbers[right];
            if (sum < target) {
                left++;
                continue;
            }
            if (sum > target) {
                right--;
                continue;
            }
            // find sum is target
            int find_count = 0;
            for (int i = 0; i < numbers.size(); i++) {
                if (numbers[i] == copy_numbers[left] || numbers[i] == copy_numbers[right] && find_count < 2) {
                    ret[find_count] = i+1;
                    find_count++;
                    if (find_count >= 2) {
                        return ret;
                    }
                }
            }
            break;
        }
        return ret;
    }
};

// Hash map, 48ms, O(N)
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        map<int, int> hash_map;
        for (int i = 0; i < numbers.size(); i++) {
            if (hash_map.find(numbers[i]) != hash_map.end()) {
                if (2*numbers[i] == target) {
                    ret.push_back(hash_map[numbers[i]]);
                    ret.push_back(i+1);
                    return ret;
                }
                continue;
            }
            hash_map.insert(make_pair(numbers[i], i+1));
        }
        for (auto it : hash_map) {
            if (hash_map.find(target - it.first) != hash_map.end()) {
                ret.push_back(it.second);
                ret.push_back(hash_map[target-it.first]);
                if (it.second > hash_map[target-it.first]) {
                    ret[0] = hash_map[target-it.first];
                    ret[1] = it.second;
                }
                return ret;
            }
        }
        return ret;
    }
}; 

