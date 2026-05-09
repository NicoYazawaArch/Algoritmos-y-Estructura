#include <iostream>
using namespace std;
int main(){
    int numeros[5]={4,5,-2,8,0};
    cout<<numeros[-1]<<endl;
    cout<<numeros[5]<<endl;
    cout<<"------------------------------"<<endl;

    for(int i=0;i<5 ;i++){//se pueden poner i<=4 o i<5
    cout<<numeros[i]<<endl;

}
return 0;
}