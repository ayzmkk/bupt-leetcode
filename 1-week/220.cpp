class Solution {
public:
    long getBucket(long i, long w) {
        return i >= 0 ? i / w : (i + w) / w -1;
    }
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (t < 0) return false;
        long w = (long) t + 1;
        unordered_map<long, long> bucket;
        for (int i = 0; i < nums.size(); i++) {
            long id = getBucket(nums[i], w);
            if (bucket.find(id) != bucket.end()) return true;
            if (bucket.find(id - 1) != bucket.end() && abs(nums[i] - bucket[id - 1]) < w) return true;
            if (bucket.find(id + 1) != bucket.end() && abs(nums[i] - bucket[id + 1]) < w) return true;
            bucket[id] = nums[i];   // 在下面一行之前，防止k = 0
            if (i >= k) bucket.erase(getBucket(nums[i - k], w));
        }
        return false;
    }
};
