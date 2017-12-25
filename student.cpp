//
// Created by 邱添爽 on 2017/12/25.
//

#include "student.h"
#include <string>

using namespace std;
student::student(string Sid) {
    this->setSid(Sid);
}

student::student(string Sid, string Name, string Sex, string Native) {
    this->setSid(Sid);
    this->setName(Name);
    this->setSex(Sex);
    this->setNative(Native);
}

string student::getSid() {
    return this->sid;
}

void student::setSid(string sid) {
    this->sid = sid;
}

string student::getName() {
    return this->name;
}

void student::setName(string Name) {
    this->name = Name;
}

string student::getSex() {
    return this->sex;
}

void student::setSex(string Sex) {
    this->sex = Sex;
}

string student::getNative() {
    return this->native;
}

void student::setNative(string Native) {
    this->native = Native;
}

void student::setKey(string Sid, string Name, string Sex, string Native) {
    this->setSid(Sid);
    this->setName(Name);
    this->setSex(Sex);
    this->setNative(Native);
}

int student::getKey() {
    string _sid = this->getSid();
    int __sid = (int) _sid.c_str();
    return __sid;
}

string student::display() {
    return getSid()+" "+getName()+" "+getSex()+" "+getNative();
}
