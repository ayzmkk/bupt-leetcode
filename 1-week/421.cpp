struct TrieNode {
    bool isKey;
    TrieNode* children[2];
    TrieNode(): isKey(false) {
        memset(children, NULL, sizeof(children));
    }
};
class Solution {
public:
    TrieNode* buildTrie(vector<int>& nums) {
        TrieNode* root = new TrieNode();
        for (auto num : nums) {
            TrieNode* cur = root;
            for (int i = 31; i >= 0; i--) {
                int index = (num >> i) & 1;
                if (!cur->children[index]) {
                    cur->children[index] = new TrieNode();
                }
                cur = cur->children[index];
            }
        }
        return root;
    }
    int helper(TrieNode* root, int num) {
        TrieNode* cur = root;
        int ret = 0;
        for (int i = 31; i >= 0; i--) {
            int index = ((num >> i) & 1) ? 0: 1;
            if (cur->children[index]) {
                ret <<= 1;
                ret |= 1;
                cur = cur->children[index];
            }
            else {
                ret <<= 1;
                ret |= 0;
                cur = cur->children[index ? 0 : 1];
            }
        }
        return ret;
    }
    int findMaximumXOR(vector<int>& nums) {
        TrieNode* root = buildTrie(nums);
        int ret = 0;
        for (auto i : nums) {
            ret = max(ret, helper(root, i));
        }
        return ret;
    }
};
