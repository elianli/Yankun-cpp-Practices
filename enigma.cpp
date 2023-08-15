#include<iostream>
#include<string>
using namespace std;
int main(){
    string pgbd,rta,rtb,rtc,rfct,msg;
    int ct,ct2,rtact,rtbct,msglth;
    rtact=0;
    rtbct=0;
    char pgbdorg[26],pgbdfin[26],rtac[26],rtactmp[26],rtbc[26],rtbctmp[26],rtcc[26],rtcctmp[26],rfctorg[26],rfctfin[26],tmp;
    bool tmp2;
    cout<<"Please enter the Plugboard in the following order:"<<endl<<"For example, If you want A switch to B, C switch to D, enter ABCD. If you want F switch to U and Y switch to K enter FUYK. Order dosen't matter."<<endl;
    cin>>pgbd;
    cout<<"Please enter your Roter 1:"<<endl<<"You must enter 26 unique alphabets, and your first alphabet will be your initial setup"<<endl;
    cin>>rta;
    cout<<"Please enter your Roter 2:"<<endl<<"You must enter 26 unique alphabets, and your first alphabet will be your initial setup"<<endl;
    cin>>rtb;
    cout<<"Please enter your Roter 3:"<<endl<<"You must enter 26 unique alphabets, and your first alphabet will be your initial setup"<<endl;
    cin>>rtc;
    cout<<"Please enter your Reflector:"<<endl<<"Your must enter 13 unique pairs, which are into 26 unique alphabets. Like QWERTYUIOPASDFGHJKLZXCVBNM will be interpreted as Q to W, W to Q, E to R, R to E, etc."<<endl;
    cin>>rfct;
    cout<<"Please enter your message."<<endl;
    cin>>msg;
    msglth=msg.length();
    char msgorg[msglth],msgfin[msglth];
    for(ct=65;ct<=90;ct++){
        pgbdorg[ct-65]=ct;
        pgbdfin[ct-65]=ct;
    }
    for(ct=0;ct<pgbd.length();ct+=2){
        tmp2=false;
        tmp=pgbd[ct];
        for(ct2=0;ct2<26;ct2++){
            if(ct2+65==tmp){
                tmp2=true;
                break;
            }
        }
        if(!tmp2){
            continue;
        }
        else{
            pgbdfin[ct2]=pgbd[ct+1];
            pgbdfin[(pgbd[ct+1])-65]=tmp;
        }
    }
    for(ct=0;ct<26;ct++){
        rtac[ct]=rta[ct];
        rtbc[ct]=rtb[ct];
        rtcc[ct]=rtc[ct];
    }
    for(ct=65;ct<=90;ct++){
        rfctorg[ct-65]=ct;
        rfctfin[ct-65]=ct;
    }
    for(ct=0;ct<26;ct+=2){
        tmp=rfct[ct];
        rfctfin[tmp-65]=rfct[ct+1];
        rfctfin[(rfctfin[tmp-65])-65]=tmp;
    }
    for(ct=0;ct<msglth;ct++){
        msgorg[ct]=msg[ct];
    }
    for(ct=0;ct<msglth;ct++){
        for(ct2=0;true;ct2++){
            if(msgorg[ct]==pgbdorg[ct2]){
                tmp=pgbdfin[ct2];
                break;
            }
        }
        for(ct2=0;true;ct2++){
            if(tmp==rtac[ct2]){
                tmp=rtbc[ct2];
                break;
            }
        }
        for(ct2=0;true;ct2++){
            if(tmp==rtbc[ct2]){
                tmp=rtcc[ct2];
                break;
            }
        }
        for(ct2=0;true;ct2++){
            if(tmp==rfctorg[ct2]){
                tmp=rfctfin[ct2];
                break;
            }
        }
        for(ct2=0;true;ct2++){
            if(tmp==rtcc[ct2]){
                tmp=rtbc[ct2];
                break;
            }
        }
        for(ct2=0;true;ct2++){
            if(tmp==rtbc[ct2]){
                tmp=rtac[ct2];
                break;
            }
        }
        for(ct2=0;true;ct2++){
            if(tmp==pgbdfin[ct2]){
                tmp=pgbdorg[ct2];
                break;
            }
        }
        msgfin[ct]=tmp;
        for(ct2=0;ct2<26;ct2++){
            rtactmp[ct2]=rtac[ct2];
        }
        rtac[0]=rtactmp[25];
        for(ct2=1;ct2<26;ct2++){
            rtac[ct2]=rtactmp[ct2-1];
        }
        rtact++;
        if(rtact==26){
            rtact=0;
            for(ct2=0;ct2<26;ct2++){
                rtbctmp[ct2]=rtbc[ct2];
            }
            rtbc[0]=rtbctmp[25];
            for(ct2=1;ct2<26;ct2++){
                rtbc[ct2]=rtbctmp[ct2-1];
            }
            rtbct++;
            if(rtbct==26){
                rtbct=0;
                for(ct2=0;ct2<26;ct2++){
                    rtcctmp[ct2]=rtcc[ct2];
                }
                rtcc[0]=rtcctmp[25];
                for(ct2=1;ct2<26;ct2++){
                    rtcc[ct2]=rtcctmp[ct2-1];
                }
            }
        }
    }
    for(ct=0;ct<msglth;ct++){
        cout<<msgfin[ct];
    }
    return 0;
}