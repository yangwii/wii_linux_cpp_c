#include<string>
#include<iostream>
using namespace std;

/*
去哪儿笔试题：一个字符串中有数字和字母，把数字与数字间的字符串重复数字遍，
注意：第一次出现数字是重复前面的字符
例如：str="love2big2gae4fff" 输出后的结果为：“lovelovebigbiggaegaegaegaefff”
*/

string Decode(string str){
    string result;
    int size = str.size();
    if(size <= 0){
        return result;
    }//if
    // 重复元素区间
    int start = 0,end = 0;
    // 重复次数
    int count = 0;
    for(int i = 0;i < size;++i){
        // 数字
        if(str[i] >= '0' && str[i] <= '9'){
            count = count * 10 + str[i] - '0';
            if(i == size || (str[i+1] < '0' || str[i+1] > '9')){
                for(int j = 0;j < count;++j){
                    result += str.substr(start,end-start);
                }//for
                // 重新设定
                start = i + 1;
                end = i + 1;
                count = 0;
            }//if
        }//if
        // 字符
        else{
            ++end;
        }
    }//for
    return result;
}

int main(){
    string str("love2big2gae4fff1");
    cout<<Decode(str)<<endl;
    return 0;
}