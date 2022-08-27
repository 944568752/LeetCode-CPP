//
// Created by 94456 on 8/27/2022.
//


#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

string s_combine(vector<string> s){
    string res = "";
    for(int i = 0; i < s.size(); i++){
        res += s[i];
    }
    return res;
}
void process(string s_big, int i, vector<string> s_small, int& res){
    if(i == s_small.size()){
        return;
    }
    for(int j = i; j < s_small.size(); j++){
        swap(s_small[i], s_small[j]);
        string temp = s_combine(s_small);
        if(temp == s_big)
            res++;
        swap(s_small[i], s_small[j]);
    }
    return;
}
int main(){
    int n,m;
    cin>>n>>m;
    string s_big;
    vector<string> s_small;
    cin>>s_big;
    for(int i = 0; i < m; i++){
        int temp;
        cin>>temp;
    }
    for(int i = 0; i < m; i++){
        string str_temp;
        cin>>str_temp;
        s_small.push_back(str_temp);
    }

    int res = 0;
    process(s_big, 0, s_small, res);

    cout<<res<<endl;
    return 0;
}