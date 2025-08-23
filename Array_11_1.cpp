#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    unordered_map<int, int> m;
    for (int i = 0; i < nums.size(); ++i)
    {
        int x = nums[i];
        int y = target - x;
        if (m.count(y))
        {
            return {m[y], i};
        }
        m[x] = i;
    }
    return {};
}

int main() {
    vector<int> nums = {3,2,4};
    int target = 6;

    vector<int> result = twoSum(nums, target);

    cout << "Indices: " << result[0] << " " << result[1] << endl;

    return 0;
}
