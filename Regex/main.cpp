#include <iostream>
#include <regex>
using namespace std;

int main() {
    string str = "jiangxindeng233jiangxin222jiang21";
    regex reg("([a-z]+)2");

    cout<<"正则表达式：([a-z]+)2"<<endl;
    for(sregex_iterator it(str.begin(),str.end(),reg),end;it != end;it++){
        cout<<"字符串："<<&*it->prefix().first<<" 匹配成功！"<<endl;
        cout<<"匹配字符子串个数："<<it->size()<<endl;
        cout<<"分别为：" << endl;

        for (size_t i = 0; i < it->size(); i++)
        {
            cout << "i:" << i << " " << (*it)[i] << endl;
        }

//        for(auto aa:*it)
//            cout<<aa.str()<<" ";

        cout<<endl;
        cout<<"字符串 "<<it->str()<<" 前的字符串为："<<it->prefix().str()<<endl;
        cout<<"字符串 "<<it->str()<<" 后的字符串为："<<it->suffix().str()<<endl;
        cout<<endl;
    }
    return 0;
}
