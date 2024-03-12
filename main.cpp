#include <iostream>
#include <string>

using namespace std;

void shifrlash(string T0, int a, int b);
void deshifrlash(string T1, int a, int b);

int main()
{
    bool k;
    int i,a,b;
    string T;

    cout<<"  ----------   Shifrlamoqchi bo'lsangiz 1 ni aks holda 0 ni kiriting    -----------   "<<endl;
    cin>>k;
    if(k){
        cout<<"a="; cin>>a;
        cout<<"b="; cin>>b;
        cout<<"     --------------  Matnni kiriting  -----------  "<<endl;
        cin.ignore();
        getline(cin,T);
        shifrlash(T,a,b);
    }
    else{
        cout<<"a="; cin>>a;
        cout<<"b="; cin>>b;
        cout<<"     -------------- Deshifr matnni kiriting  -----------  "<<endl;
        cin.ignore();
        getline(cin,T);
        deshifrlash(T,a,b);
    }
    return 0;
}
void shifrlash(string T0, int a, int b){
    int i,q;
    string T1="";
    for(i=0; i<T0.length(); i++){
        q=int(T0[i]);
        if(q==32){
            T1+=' ';
        }
        if(q>96 and q<123){
            q=q-97;
            T1+=char((a*q+b)%26+97);
        }
        else
        if(q>64 and q<91){
            q=q-65;
            T1+=char((a*q+b)%26+65);
        }
    }
    cout<<"T1= "<<T1<<endl;
}

void deshifrlash(string T1, int a, int b){

    int i,q;
    string T0="";
    q=26;
    for(i=1; i<q; i+=2){
        if(a*i%26==1){
            a=i;
            q=0;
        }
    }
    for(i=0; i<T1.length(); i++){
        q=int(T1[i]);
        if(q==32){
            T0+=' ';
        }
        if(q>96 and q<123){
            q=q-97;
            if(q-b>=0){
                T0+=char(a*(q-b)%26+97);
            }
            else{
                if(q-b<0){
                    T0+=char(26-a*(b-q)%26+97);
                }
            }
        }
        else
        if(q>64 and q<91){
            q=q-65;
            if(q-b>=0){
                T0+=char(a*(q-b)%26+65);
            }
            else{
                if(q-b<0){
                    T0+=char(26-a*(b-q)%26+65);
                }
            }
        }
    }
    cout<<"T0= "<<T0<<endl;
}
