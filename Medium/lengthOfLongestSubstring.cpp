//
// Created by 94456 on 8/26/2022.
//


// lengthOfLongestSubstring



#include<iostream>
#include<vector>
#include<unordered_set>


using namespace std;


class Solution_0{
public:
    // 滑窗法

    // 无重复字符的最长子串
    int lengthOfLongestSubstring(string s) {
        // 如果字符串的长度为0,则无重复字符的最长子串为0
        if (s.size() == 0) {
            return 0;
        }
        // 如果字符串的长度为1,则无重复字符的最长子串为1
        if (s.size() == 1) {
            return 1;
        }

        // 记录字符串长度
        int n = s.size();

        // 子串的开头索引
        int left = 0;
        // 子串的结尾索引
        int right = 0;

        // 记录无重复子串的最大长度
        int sub_n = 0;

        // 字符串s由英文字母,数字,符号和空格组成
        // 在ASCII码中,一共有128个英文字母,数字,符号和空格
        // 因此初始化一个长128的vector来存放字符出现的次数
        vector<int> cache(128, 0);

        // 遍历整个字符串
        while (right < n) {
            // 取当前子字符串的结尾字符
            char c = s[right];
            // vector中该字符的出现的次数+1
            cache[c]++;
            // 子字符串的结尾索引后移一位
            right++;

            // 如果当前字符的出现次数大于1,说明子字符串中出现了重复
            while (cache[c] > 1) {
                // 循环,将子串开头索引的字符出现次数减一
                cache[s[left]]--;
                // 子串的开头索引向后移动一位
                left++;
            }

            // 如果当前子串的长度大于之前无重复字符的子串
            // 则更新无重复字符的最长子串长度
            sub_n = max(sub_n, right - left);

        }

        // 返回最长的子串长度
        return sub_n;
    }
};


class Solution{
public:
    // 滑动窗口-双指针

    // 无重复字符的最长子串
    int lengthOfLongestSubstring(string s){
        // 如果字符串的长度为0,则无重复字符的最长子串为0
        if (s.size() == 0) {
            return 0;
        }
        // 如果字符串的长度为1,则无重复字符的最长子串为1
        if (s.size() == 1) {
            return 1;
        }

        // 记录字符串长度
        int n = s.size();

        // 记录无重复子串的最大长度
        int sub_n = 0;

        // 子串的开头索引
        int left = 0;

        // 创建哈希表，存储当前子串
        unordered_set<char> cache;

        // 遍历整个字符串
        for(int i=0;i<n;i++){
            // 如果当前字符的出现次数大于1,说明子字符串中出现了重复
            while(cache.count(s[i])>0){
                // 循环,擦除子串开头索引的字符串出现次数
                cache.erase(s[left]);
                // 字符串的开头索引向后移动一位
                left++;

            }
            // 如果当前子串的长度大于之前无重复字符的子串
            // 则更新无重复字符的最长子串长度
            sub_n=max(sub_n,i-left+1);

            // 当前该字符的出现次数+1
            cache.insert(s[i]);

        }
        // 返回最长的子串长度
        return sub_n;

    }
};


int main(){

    printf("Hello lengthOfLongestSubstring !\n");


    // Meituan Test
    int m=0;
    int n=0;
    cin>>m>>n;

    string s;
    cin>>s;

    vector<int> sub_length (n,0);
    for(int i=0;i<n;i++){
        cin>>sub_length[i];
    }

    vector<string> sub (n);
    for(int i=0;i<n;i++){
        cin>>sub[i];
    }

    return 0;
}