class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> ret;
        for (int i = 0; i < input.size(); i++) {
            char c = input[i];
            if (ispunct(c)) {
                for (auto a : diffWaysToCompute(input.substr(0, i)))
                    for (auto b : diffWaysToCompute(input.substr(i + 1)))
                        ret.push_back(c == '-' ? a - b : c == '+' ? a + b : a * b);
            }
        }
        return ret.size() ? ret : vector<int>{stoi(input)};
    }
};
