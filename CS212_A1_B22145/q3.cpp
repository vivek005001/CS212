#include <iostream>
using namespace std;

int GCD(int a,int b){
      if (a == 0) {
        return b;
    }
    if (b == 0) {
        return a;
    }

    if(a%11==0 && b%11==0 ){
        return 11*GCD(a/11,b/11);
    }
    else if(a%11 == 0){
        if(a%2!=0 && b%11!=0){
           return GCD(a/11,2*b);
        }
        else if(a%2==0 && b%11!=0){
            return GCD(a/11,abs(a-b));
        }
    }
        else if(b%11 == 0){
        if(b%2!=0 && a%11!=0){
            return GCD(2*a,b/11);
        }
        else if(b%2==0 && a%11!=0){
            return GCD(abs(a-b),b/11);  
        }
    }
    else{
        return GCD(abs(a-b),min(a,b));

    }
    return 0;
}

int main(){
   int a ,b;
   cin>>a>>b;
   if (a==b){
    cout<<a<<endl;
   }
    else{
        int result = GCD(a,b);
        cout<<result<<endl;
    }

    return 0;
}

