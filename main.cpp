#include <iostream>
#include "stusys.h"

using namespace std;
int main() {
    auto* ss = new stusys();
    while(true){
        char command;
        cin>>command;
        switch(command){
            case 'I':
                ss->Insert();
            case 'F':
                ss->Find();
            case 'A':
                ss->Add();
            case 'D':
                ss->Delete();
            case 'P':
                ss->Print();
            case 'S':
                ss->Save();
            case 'X':
                cout<<"Bye"<<endl;
                return 0;
            default:
                cout<<"请输入一个有效的命令："<<endl;
        }
    }
}
