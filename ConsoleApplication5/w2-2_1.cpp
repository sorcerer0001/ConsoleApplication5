/*
编程题＃2：文件结构“图”

*/

#include<iostream>

#include<vector>
#include<algorithm>
#include<string>
using namespace std;
class Dir{
public:
    string name;
    vector<Dir> dirs;
    vector<string> files;
};
Dir getResult(string name){
    Dir dir;
    string tmp;
    cin >> tmp;
    if(tmp == "#")
        return dir;
    dir.name = name;
    while(tmp != "*"&&tmp != "]"){
        if(tmp[0] == 'f')
            dir.files.push_back(tmp);
        else
            dir.dirs.push_back(getResult(tmp));
        cin >> tmp;
    }
    return dir;
}
void foutput(string name,int level){
    for(int i = 0;i < level;i++)
        cout << "|     ";
    cout << name << endl;
}
void doutput(Dir dir,int level){
    foutput(dir.name,level);
    int i;
    for(i = 0;i < dir.dirs.size();i++)
        doutput(dir.dirs[i],level+1);
    sort(dir.files.begin(),dir.files.end());
    for(i = 0;i < dir.files.size();i++)
        foutput(dir.files[i],level);
}
int main(){
    int countNum(1);
    Dir dir = getResult("ROOT");
    while(dir.name == "ROOT")
    {
        cout<<"DATA SET "<<countNum<<":"<<endl;
        doutput(dir,0);
        cout<<endl;
        countNum++;
        dir = getResult("ROOT");
    }
}
