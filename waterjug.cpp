#include<bits/stdc++.h>
using namespace std;
int x;
int y;

int min(int w,int z){
    if(w<z){
        return w;
    }
    else{
        return z;
    }
}
void show(int x,int y){
    cout<<setw(12)<<x<<setw(12)<<y<<endl;
}

void s(int n){
    int xq=0,yq=0;
    int t;
    cout<<setw(15)<<"First Jug"<<setw(15)<<"Second Jug"<<endl;
    while (xq!= n && yq != n)
    {
        if(xq==0){
            xq=x;
            show(xq,yq);
        }
        else if(yq==y){
            yq=0;
            show(xq,yq);
        }
        else{
            t=min(y-yq,xq);
            yq=yq+t;
            xq=xq-t;
            show(xq,yq);
        }
    }
}

int main(){
int n;
cout<<"Enter the liters of water requires out of two jar:- ";
cin>>n;
cout<<"Enter the capacity of first jar :- ";
cin>>x;
cout<<"Enter the capacity of second jar:- ";
cin>>y;
if(n<x || n<y){
    if(n%(__gcd(x,y))==0){
        s(n);
    }
    else{
        cout<<"Tis is not possible !!!!!!!";
    }
}
else{
            cout<<"Tis is not possible !!!!!!!";
}
    return 0;
}