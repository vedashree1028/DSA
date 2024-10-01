// infix to postfix::
#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
int prec(char c){
    if(c=='^')
    return 3;
    else if(c=='+'||c=='-')
    return 2;
    else if(c=='*'||c=='/')
    return 1;
    
return 0;
}
void infixtopostfix(char s[]){
    char postfix[1000];
    int postindex=0;
    int len = strlen(s);
    char stack[1000];
    int stacktop=-1;
    
    for(int i=0;i<len;i++){
        char c = s[i];
        if(c>='a' && c<='z' || c>='A' && c<='Z' || c>='0' && c<='9'){
            postfix[postindex]=c;
            postindex++;
        }
        
        else if(c=='('){
            ++stacktop;
            stack[stacktop]=c;
        }
        else if(c==')'){
            while(stacktop>=0 && stack[stacktop]!='('){
                
                postfix[postindex]=stack[stacktop];
                postindex++;
                stacktop--;
            }
            stacktop--;
        }
        else{
            while(stacktop>=0 && prec(c) <= prec(stack[stacktop])){
                postfix[postindex]=stack[stacktop];
                postindex++;
                stacktop--;
            }
            ++stacktop;
            stack[stacktop]=c;
        }
    }
    while(stacktop>=0){
            postfix[postindex]=stack[stacktop];
            postindex++;
            stacktop--;
    }
    postfix[postindex]='\0';
    cout<<"POSTFIX IS :"<<postfix<<endl;
}
int main(){
    char exp[]="(a+b)*(c+d)";
    
    infixtopostfix(exp);
    
    return 0;
}




















//infix to prefix::
#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
int prec(char c){
    if(c=='^')
    return 3;
    else if(c=='+'||c=='-')
    return 2;
    else if(c=='*'||c=='/')
    return 1;
    
return 0;
}
void infixtopostfix(char s[]){
    char postfix[1000];
    int postindex=0;
    int len = strlen(s);
    char stack[1000];
    int stacktop=-1;
    
    for(int i=0;i<len;i++){
        char c = s[i];
        if(c>='a' && c<='z' || c>='A' && c<='Z' || c>='0' && c<='9'){
            postfix[postindex]=c;
            postindex++;
        }
        
        else if(c=='('){
            c=')';
              while(stacktop>=0 && stack[stacktop]!='('){
                
                postfix[postindex]=stack[stacktop];
                postindex++;
                stacktop--;
            }
            stacktop--;
          //  ++stacktop;
          //  stack[stacktop]=c;
        }
        else if(c==')'){
            c='(';
             ++stacktop;
            stack[stacktop]=c;
         /*   while(stacktop>=0 && stack[stacktop]!='('){
                
                postfix[postindex]=stack[stacktop];
                postindex++;
                stacktop--;
            }
            stacktop--;*/
        }
        else{
            while(stacktop>=0 && prec(c) <= prec(stack[stacktop])){
                postfix[postindex]=stack[stacktop];
                postindex++;
                stacktop--;
            }
            ++stacktop;
            stack[stacktop]=c;
        }
    }
    while(stacktop>=0){
            postfix[postindex]=stack[stacktop];
            postindex++;
            stacktop--;
    }
   // postfix[postindex]='\0';
   // cout<<"POSTFIX IS :"<<postfix<<endl;
    char prefix[1000];
    int prefixindex=0;
    for(int i=postindex-1;i>=0;i--){
        prefix[prefixindex]=postfix[i];
        prefixindex++;
    }
    prefix[prefixindex]='\0';
    cout<<"PREFIX IS:"<<prefix<<endl;
}
void reverse(char a[]){
    int len = strlen(a);
    for(int i=0;i<len/2;i++){
        for(int j=len-1-i;j>=0;j--){
            if(j==len-1-i){
            char temp = a[i];
            a[i]=a[j];
            a[j]=temp;
            }
        }
    }
   // cout<<"reverse is :"<<a<<endl;
     infixtopostfix(a);
}
int main(){
    char exp[]="(a+b)*(c+d)";
     
     
     reverse(exp);
    
    return 0;
}
