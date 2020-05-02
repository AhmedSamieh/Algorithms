/*
[0,1,2,4,5,6,7] if n[tail] > n[head]
[1,2,4,5,6,7,0] n[tail] < n[head] and n[tail-1] > n[head+1]
[7,0,1,2,4,5,6] n[tail] < n[head] and n[tail-1] > n[head+1]
[5,6,7,0,1,2,4] n[tail] == n[head]
[5,6,0,1,2,4] n[tail] < n[head] and n[tail-1] > n[head+1]
[4,5,6,0,1,2] n[tail] < n[head] and n[tail-1] > n[head+1]
*/
class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int tail = nums.size() - 1;
        int head = 0;
        int smallest = nums[0];

        while (nums[tail] < nums[head]) {
            smallest = nums[tail--];
            ++head;
        }

        return min(nums[head], smallest);
    }
};