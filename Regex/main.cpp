#include <iostream>
#include <regex>
using namespace std;

int main() {
    string str = "jiangxindeng233jiangxin222jiang21";
    regex reg("([a-z]+)2");

    cout<<"������ʽ��([a-z]+)2"<<endl;
    for(sregex_iterator it(str.begin(),str.end(),reg),end;it != end;it++){
        cout<<"�ַ�����"<<&*it->prefix().first<<" ƥ��ɹ���"<<endl;
        cout<<"ƥ���ַ��Ӵ�������"<<it->size()<<endl;
        cout<<"�ֱ�Ϊ��" << endl;

        for (size_t i = 0; i < it->size(); i++)
        {
            cout << "i:" << i << " " << (*it)[i] << endl;
        }

//        for(auto aa:*it)
//            cout<<aa.str()<<" ";

        cout<<endl;
        cout<<"�ַ��� "<<it->str()<<" ǰ���ַ���Ϊ��"<<it->prefix().str()<<endl;
        cout<<"�ַ��� "<<it->str()<<" ����ַ���Ϊ��"<<it->suffix().str()<<endl;
        cout<<endl;
    }
    return 0;
}
