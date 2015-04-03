#include<stdio.h>

int main()
{
 int corect = 1;
 char skobi[1000];
 int vuvedeno;
 scanf(" &[^\n]s",skobi);
 int length;
 for(length = 0; length<1000; length++)
 {
 vuvedeno = skobi[length];
 if(vuveden==0)
 {
 break;
 }
 }
 int a;
 int sam = 0;
 int med = 0;
 int big = 0;
 for(a=0; a<length; a++)
 {
 if(vuvedeno[a]=='(') {sam++;}
 if(vuvedeno[a]==')') {sam--;}
 if(vuvedeno[a]=='{') {med++;}
 if(vuvedeno[a]=='}') {med--;}
 if(vuvedeno[a]=='[') {big++;}
 if(vuvedeno[a]==']') {big--;}
 if(sam<0 || med<0 || big<0)
 {
 printf("No\n");
 corect = 0;
 break;
 }
 }

 if(corect == 1) printf("Yes\n");
 return 0;
}