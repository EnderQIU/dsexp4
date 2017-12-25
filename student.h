//
// Created by 邱添爽 on 2017/12/25.
//

#ifndef DSEXP4_STUDENT_H
#define DSEXP4_STUDENT_H

#include <string>
using namespace std;
class student {
private:
    //学号、姓名、性别、籍贯。
    string sid;
    string name;
    string sex;
    string native;

    void setSid(string sid);
    void setName(string Name);
    void setSex(string Sex);
    void setNative(string Native);

public:
    student(string Sid);
    student(string Sid, string Name, string Sex, string Native);
    string getSid();
    string getName();
    string getSex();
    string getNative();
    string display();

    int getKey();
    void setKey(string Sid, string Name, string Sex, string native);
};


#endif //DSEXP4_STUDENT_H
