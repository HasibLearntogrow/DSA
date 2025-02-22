#include<bits/stdc++.h>
using namespace std;
int Regin(int line){
 if(line==0){
    return 1;
 }else{
    return line+Regin(line-1);
 }

}
int main(){
    int line;
    cout<<"Enter number of cutting number:";
    cin>>line;
    int part=Regin(line);
    cout<<"NUmber of Region :"<<" "<<part<<" "<<"in "<<line<<" cuts"<<endl;

    return 0;
}