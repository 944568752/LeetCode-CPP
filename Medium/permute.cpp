//
// Created by Brian_Tsui on 2022.09.18.
//


// Permute


#include<iostream>
#include<vector>


using namespace std;


class Solution{
public:
    // 全排列

    // 使用回溯法遍历所有可能的排列方式
    void Recall(vector<int> &nums, vector<int> &temp, vector<vector<int>> &result, vector<bool> &use_flag){
        // 如果当前缓存的结果长度等于给定的数组长度
        if(temp.size()==nums.size()){
            // 则回溯结束
            // 记录当前缓存的结果
            result.push_back(temp);
        }
        // 从0开始遍历给定的数组
        for(int i=0;i<nums.size();i++){
            // 如果当前数字已经被使用
            if(use_flag[i]==true){
                // 则跳过该数字
                continue;
            }
            // 如果当前数字未被使用
            // 将当前数字设置为已使用
            use_flag[i]=true;
            // 将当前数字加入缓存中
            temp.push_back(nums[i]);
            // 回溯搜索接下来的排列
            Recall(nums, temp, result, use_flag);
            // 搜索完毕后将该数字移出缓存
            temp.pop_back();
            // 取消该数字的使用记录
            use_flag[i]=false;
        }
    }

    // 全排列
    vector<vector<int>> permute(vector<int> &nums){
        // 记录所有结果
        vector<vector<int>> result;
        // 临时保存一组结果
        vector<int> temp;
        // 记录数组中的数是否被使用
        vector<bool> use_flag(nums.size(),false);
        // 如果给定数组的长度为1
        if(nums.size()==1){
            // 则最终结果只有一种可能
            temp.push_back(nums[0]);
            result.push_back(temp);
        }
        else{
            // 如果给定数组的长度大于1
            // 则开始回溯所有可能的排列方式
            Recall(nums, temp, result, use_flag);
        }
        return result;
    }
};


int main(){

    Solution *s=new Solution();

    vector<int> a={1,2,3};

    vector<vector<int>> b=s->permute(a);

    for(int i=0;i<b.size();i++){
        for(int j=0;j<b[i].size();j++){
            cout<<b[i][j]<<' ';
        }
        cout<<endl;
    }


    cout<<"Hello permute !"<<endl;

    return 0;
}