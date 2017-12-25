//
// Created by 邱添爽 on 2017/12/25.
//

#include "stusys.h"
#include <iostream>
#include <fstream>
#include "student.h"
#include <vector>

using namespace std;
stusys::stusys()=default;

vector<string> split(const string &s, const string &seperator){
    vector<string> result;
    typedef string::size_type string_size;
    string_size i = 0;

    while(i != s.size()){
        //找到字符串中首个不等于分隔符的字母；
        int flag = 0;
        while(i != s.size() && flag == 0){
            flag = 1;
            for (char x : seperator)
                if(s[i] == x){ ++i;flag = 0;break;
                }
        }

        //找到又一个分隔符，将两个分隔符之间的字符串取出；
        flag = 0;
        string_size j = i;
        while(j != s.size() && flag == 0){
            for (char x : seperator)
                if(s[j] == x){
                    flag = 1;
                    break;
                }
            if(flag == 0)
                ++j;
        }
        if(i != j){
            result.push_back(s.substr(i, j-i));
            i = j;
        }
    }
    return result;
}

// 从一个文本文件中输入各记录来建立散列表。
void stusys::Insert() {
    cout<<"请输入文件路径:"<<endl<<">";
    string path;
    cin>>path;
    ifstream fin(path);
    string s;
    while( getline(fin,s) )
    {
        vector v = split(s, " ");
        student* st = new student(v.at(0), v.at(1), v.at(2), v.at(3));
        ResultCode resultCode = hs->Insert(st);
        if (resultCode != Success){
            cout<<"插入数据 "<<s<<" 时出现错误"<<endl;
        }
    }
    cout<<"插入完毕"<<endl;
}

// 搜索并显示给定学号的学生记录。
void stusys::Find() {
    string sid;
    cout<<"请输入一个学号："<<endl;
    cin>>sid;
    student* st = new student(sid);
    ResultCode resultCode = hs->Search(st);
}

// 插入一个记录。
void stusys::Add() {
    string Sid, Name, Sex, Native;
    cout<<"请输入学号："<<endl;
    cin>>Sid;
    cout<<"请输入姓名："<<endl;
    cin>>Name;
    cout<<"请输入性别："<<endl;
    cin>>Sex;
    cout<<"请输入籍贯："<<endl;
    cin>>Native;
    student* st = new student(Sid, Name, Sex, Native);
    switch (hs->Insert(st)){
        case Success:
            cout<<"插入成功！"<<endl;
            break;
        case Duplicate:
            cout<<"学号重复！"<<endl;
            break;
        case Overflow:
            cout<<"溢出！"<<endl;
            break;
        case NeverUsed:break;
        case NotPresent:break;
    }
}

// 删除一个记录。
void stusys::Delete() {
    cout<<"请输入要删除的学号："<<endl;
    string Sid;
    cin>>Sid;
    student* st = new student(Sid);
    switch (hs->Remove(st)){
        case Success:
            cout<<"删除成功！"<<endl;
            break;
        case NeverUsed:
            break;
        case NotPresent:
            cout<<"学号不存在！"<<endl;
            break;
        case Overflow:break;
        case Duplicate:break;
    }
}

// 屏幕显示学生情况记录表。
void stusys::Print() {
    cout<<hs->Display();
}

// 保存学生情况记录表。
void stusys::Save() {
    ofstream ofile;
    string path;
    cout<<"请输入文件路径："<<endl;
    cin>>path;
    ofile.open(path);
    ofile<<hs->Display();
    ofile.close();
    cout<<"保存成功！"<<endl;
}
