#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    int n = 9;
    vector<int> nums = {-5,-4,-3,-2,-1,1,2,3,5};



    sort(nums.begin(), nums.end());

    int count = 0;
    for(int k = 0; k < n; k++) {
        int i = k+1; int j = n-1;
        while(i < j)
        {
            if(nums[i] + nums[j] == -nums[k])
            {
                cout << nums[k] << " " << nums[i] << " " << nums[j] << endl;
                count++;
                i++;
            }
            else if(nums[i] + nums[j] > -nums[k])
            {
                j--;
            }
            else {
                i++;
            }
        }
    }
    cout << count << endl;

}
