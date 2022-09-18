//
// Created by Brian_Tsui on 2022.09.17.
//


// combinationSum


#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;


class Solution{
public:
    void Recall(vector<int> candidates,int index,int target,vector<int> &temp,vector<vector<int>> &result){
        // 如果当前回溯深度等于n,即已经查找到数组最后一个数
        if(index == candidates.size()){
            // 回溯结束
            return;
        }
        // 如果已经得到目标数值
        if(target == 0){
            // 记录当前组合
            result.emplace_back(temp);
            // 返回上一级回溯
            return;
        }
        // 继续回溯查找
        // 跳过当前值,直接回溯下一个数字
        Recall(candidates,index + 1,target,temp,result);
        // 选择当前值进行回溯,即:candidates[index]
        // 如果当前数字组合不能满足要求
        if(target-candidates[index] >= 0){
            // 增加数字进行回溯查找
            // 记录当前数字
            temp.push_back(candidates[index]);
            // 继续回溯，目标为target-candidates[index]
            // 由于每个数字可以被无限制重复选取，因此搜索的下标仍为temp而不是temp+1
            Recall(candidates,index,target-candidates[index],temp,result);
            // 如果向后回溯过程中凑成功达到目标值，则将temp中的结果记录到result中
            // 但是如果回溯中没有找到可以实现目标的解,说明当前candidates[index]不适合
            // 此时需要需要恢复temp，pop candidates[index]
            temp.pop_back();
        }
    }
    // 对于组合数很大的问题,使用回溯法(深度优先搜索)来搜索可行解
    vector<vector<int>> combinationSum(vector<int> &candidates,int target){
        // 缓存每一次的解
        vector<int> temp;
        // 记录所有结果
        vector<vector<int>> result;
        //从数组第0个元素开始回溯查找，每次找到的解保存在temp,所有的解保存在result
        Recall(candidates,0, target,temp,result);
        return result;
    }
};


int main(){

    vector<int> candidates={2,3,6,7};
    int target=7;

    Solution *s=new Solution();

    vector<vector<int>> result;
    result=s->combinationSum(candidates,target);

    for(int i=0;i<result.size();i++){
        for(int j=0;j<result[i].size();j++){
            cout<<result[i][j]<<' ';
        }
        cout<<endl;
    }


    cout<<"Hello combinationSum !"<<endl;

    return 0;
}