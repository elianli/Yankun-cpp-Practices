#include<iostream>
#include<cmath>
using namespace std;
float r2d(float x){
    return x*180/M_PI;
}
float d2r(float x){
    return x*M_PI/180;
}
int main(){
    int num,count;
    cin>>num;
    float vc,ac,xt,yt,vt,at;
    xt=0;
    yt=0;
    for(count=0;count<num;count++){
        cin>>vc>>ac;
        ac=d2r(ac);
        xt+=vc*cos(ac);
        yt+=vc*sin(ac);
    }
    vt=sqrt(pow(xt,2)+pow(yt,2));
    at=atan(yt/xt);
    at=r2d(at);
    cout<<vt<<endl<<at;
    return 0;
}