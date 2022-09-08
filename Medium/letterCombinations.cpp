//
// Created by Brian_Tsui on 2022.09.08.
//


// letterCombinations


#include<iostream>
#include<vector>


using namespace std;


class Solution{
public:
    // 电话号码的字母组合

    // 存储电话号码到字母的映射
    const string numbers[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
    // 存储最终字母组合的数组
    vector<string> result;

    // 缓存字母组合
    string cache;
    // 递归组合
    void charCombinnation(string digits, int index) {
        // 如果递归结束,则将当前缓存的字母组合存入数组中
        if (index == digits.size()) {
            result.push_back(cache);
            return;
        }

        // 利用ASCII码计算当前数字在映射中的索引
        int digit = digits[index] - '0';
        // 取出当前数字的字母映射
        string letters = numbers[digit];
        // 循环,递归遍历所有可能的情况
        for (int i = 0; i < letters.size();i++) {
            cache.push_back(letters[i]);
            charCombinnation(digits, index + 1);
            cache.pop_back();
        }
    }

    // 电话号码的字母组合
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0){
            return result;
        }
        charCombinnation(digits, 0);
        // 返回所有的电话号码的字母组合
        return result;
    }




};


int main(){

    cout<<"Hello letterCombinations !"<<endl;

    return 0;
}