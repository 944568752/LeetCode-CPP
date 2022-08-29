//
// Created by 94456 on 8/28/2022.
//


#include<iostream>
#include<vector>


using namespace std;


class Solution{
public:
    // 动态规划 - 最长回文子串
    string longestPalindrome(string s){
        // 给定字符串的长度
        int n=s.size();

        // 记录最长回文子串
        string longest_sub_str="";

        // 记录字符串遍历矩阵
        // 某个子串是回文:True
        // 某个子串不是回文:False
        vector<vector<bool>> sub_strings (n,vector<bool> (n,false));

        // 从后往前遍历每个子串
        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                // 如果子串的长度为1
                // 即子串中只包含一个字符
                // 那该子串一定是回文子串
                if(i==j){
                    // 记录该子串为回文子串
                    sub_strings[i][j]=true;
                    // 如果该子串的长度大于当前最长的回文子串长度
                    if(j-i+1>longest_sub_str.size()){
                        // 则取代之前的回文子串,成为当前最长的回文子串
                        longest_sub_str=s.substr(i,j-i+1);
                    }
                }
                // 子串长度为2
                // 且子串左右两端的字符相等
                else if(s[i]==s[j]&&j-i==1){
                    // 记录该子串为回文子串
                    sub_strings[i][j]=true;
                    // 如果该子串的长度大于当前最长的回文子串长度
                    if(j-i+1>longest_sub_str.size()){
                        // 则取代之前的回文子串,成为当前最长的回文子串
                        longest_sub_str=s.substr(i,j-i+1);
                    }
                }
                // 子串左右两端的字符相等
                // 子串去掉左右两端的字符,仍然是一个子串
                else if(s[i]==s[j]&&sub_strings[i+1][j-1]){
                    // 记录该子串为回文子串
                    sub_strings[i][j]=true;
                    // 如果该子串的长度大于当前最长的回文子串长度
                    if(j-i+1>longest_sub_str.size()){
                        // 则取代之前的回文子串,成为当前最长的回文子串
                        longest_sub_str=s.substr(i,j-i+1);
                    }
                }
            }
        }

        // 返回最长的回文子串长度
        return longest_sub_str;

    }
};


int main(){

    printf("Hello longestPalindrome ! \n");

    return 0;
}