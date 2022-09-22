//
// Created by Brian_Tsui on 2022.09.19.
//


// groupAnagrams


#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<algorithm>

using namespace std;


class Solution {
public:
    // 字母异位词分组
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        // 建立哈希表
        // 使用排序后的字符作为Key
        // 将原字符作为Value
        unordered_map<string, vector<string>> result_map;
        // 遍历所有的字符串
        for(string &sub_str : strs)
        {
            // 暂时保存原来的字符串
            string temp = sub_str;
            // 字符串排序,排序之后得道Key
            sort(temp.begin(), temp.end());
            // 只要排序后一样，就将原来的字符加入当前键对应的值
            result_map[temp].push_back(sub_str);
        }
        // 保存最终的结果
        vector<vector<string>> result;
        // 遍历哈希表
        for(auto iter=result_map.begin();iter!=result_map.end();iter++)
        {
            // 记录键值对中的Value（Second）结果
            result.push_back(iter->second);
        }
        // 返回结果
        return result;
    }
};



int main(){

    vector<int> a={1,2,3,4,5};
    for(int b:a){
        cout<<"Test 0"<<b<<' ';
    }
    cout<<endl;

    vector<int>::iterator c;
    for(c=a.begin();c!=a.end();c++){
        cout<<"Test 1"<<*c<<' ';
    }
    cout<<endl;

    vector<int> d;
    for(auto iter=a.begin();iter!=a.end();iter++){
        cout<<"Test 2"<<*iter<<' ';
        d.push_back(*iter);
    }
    cout<<endl;
    for(int e:d){
        cout<<"Test 3"<<e<<' ';
    }
    cout<<endl;

    Solution *s = new Solution();



    cout<<"Hello groupAnagrams !"<<endl;

    return 0;
}