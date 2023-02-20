#include <iostream>
#include <bits/stdc++.h>
#include <vector> 
#include <map>

using namespace std;

// 暴力遍历
vector<int> twoSum(vector<int>& nums, int target){
        int i, j;
        for (i = 0; i < nums.size()-1; i++)
            for(j = i+1; j < nums.size();j++)
                if(nums[i]+nums[j] == target)
                    return {i,j};
        return {i,j};   
};

/*
哈希表法

已知目标和的值，从第一位数，找到有没有能与之和为目标值的数。

假设目标是为target，现在数为nums[i]，要找到complement = target - nums[i]。

如果temp_map中出现complement的次数以及temp_map[complement]的值与i不匹配，

这句话的意思是：

①第一个条件，temp_map中出现一次这个数

②第二个条件，出现的这个数还不能是nums[i]本身

两个条件都满足的话，输出的第一位数字是nums[i]的索引i，输出的第二位数字是complement的索引（这两个数字输出顺序任意）
*/
class Solution{
public:
    vector<int> twosum(vector<int>& nums, int target)
    {
        vector<int> targetnum(2);
        map<int, int> temp_map;
        for(int i = 0; i < nums.size(); i++)
        {
            temp_map[nums[i]] = i;
        }
        for(int i = 0; i < nums.size();  i++)
        {
            int complement = target - nums[i];
            if(temp_map.count(complement) && temp_map[complement] != i)
            {
                targetnum[0] = i;
                targetnum[1] = temp_map[complement];
                break;
            }
        }
        return targetnum;

    }
};

int main()
{
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    Solution test;
    cout << "[" << test.twosum(nums, target)[0] << "," << test.twosum(nums, target)[1] << "]" << endl;

    return 0;
}
