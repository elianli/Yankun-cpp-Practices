#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int a,b,f,g,h,i,j,k,l,n;
    i=0;
    cout<<"Please enter the number of students."<<endl;
    cin>>a;
    cout<<"Please enter the number of subjects for each student."<<endl;
    cin>>b;
    float c[a],o[a],m;
    char e[a];
    for(g=0;g<a;g++){
        for(f=0;f<b;f++){
            cout<<"Please enter the grade of student number "<<g+1<<" on the subject number "<<f+1<<endl;
            cin>>h;
            i+=h;
            if(f==b-1){
                c[g]=i/1.0/b;
                i=0;
            }
        }
    }
    for(k=0;k<a;k++){
        if(c[k]>=90){
            e[k]='A';
        }
        else if(c[k]>=80){
            e[k]='B';
        }
        else if(c[k]>=70){
            e[k]='C';
        }
        else if (c[k]>=60){
            e[k]='D';
        }
        else{
            e[k]='F';
        }
    }
    for(j=0;j<a;j++){
        cout<<"The average score of the student number "<<j+1<<" is "<<c[j]<<'.'<<endl<<"His/Her Alphabetic Grade is "<<e[j]<<'.'<<endl;
    }
    m=0;
    for(l=0;l<a;l++){
        m+=c[l];
    }
    m/=a;
    cout<<"The average score of the whole class is "<<m<<'.'<<endl;
    for(n=0;n<a;n++){
        o[n]=c[n];
    }
    return 0;
}