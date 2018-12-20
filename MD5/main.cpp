//
//  main.cpp
//  MD5
//
//  Created by 周芙蓉 on 2018/11/26.
//  Copyright © 2018 周芙蓉. All rights reserved.
//

#include <iostream>
#include "MD5.hpp"
using namespace std;

void printMD5(const string& message) {
    cout << "md5(\"" << message << "\") = "
    << MD5(message).toStr() << endl;
}

int main() {
    
    string input[6] = {
        "","a","abc","message digest",
        "abcdefghijklmnopqrstuvwxyz",
        "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"};
    string output[6] = {
        "d41d8cd98f00b204e9800998ecf8427e", "0cc175b9c0f1b6a831c399e269772661",
        "900150983cd24fb0d6963f7d28e17f72", "f96b697d7cb7938d525a2f31aaf161d0",
        "c3fcd3d76192e4007dfb496cca67e13b", "f29939a25efabaef3b87e2cbfe641315"};
    bool flag =true;
    for (int i=0;i<6;i++)
    {
        cout<< "Original data :"<<input[i]<<"\n"
        <<"Calculate Result:"<<MD5(input[i]).toStr()<<"\n"
        <<"Excepted  Result:"<<output[i]<<endl;
        cout<<"\n";
        if(MD5(input[i]).toStr()!=output[i])
            flag=false;
    }
    if(flag==true)
    {
        cout<<"Tested Success!!! "<<endl;
    }
    else
    {
        cout<<"Tested Fial!"<<endl;
    }
    string s;
    cout<<"please write the message you want to encrypt"<<endl;
    cin>>s;
    printMD5(s);
    return 0;
}
