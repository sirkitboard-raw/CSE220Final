#include "lib.h"
#include "string.h"

char* fgets(int size, char *buffer) {
  return readstring(buffer, size);
}


int isDigit(char a) {
  if(a=='0' || a=='1' ||a=='2' ||a=='3' ||a=='4' ||a=='5' ||a=='6' ||a=='7' ||a=='8' ||a=='9') {
    return 1;
  }
  else return 0;
}

int toDigit(char a) {
  return a-48;
}

void printf(const char* fmt, ...) {
  int* adr = &fmt;
  char* temp;
  int i=0,j=0;
  int ctr=1;
  int spaceCtr;
  int leftFlag;

  for(i=0;i<strlen(fmt);i++) {
    spaceCtr = 0;
    leftFlag = 0;
    if(fmt[i]=='%') {
      if(fmt[i+1]=='%'){
        putchar('%');
        i++;
      }
      else {
        if(fmt[i+1]=='-') {
          leftFlag=1;
          i++;
        }
        while(isDigit(fmt[i+1])){
          spaceCtr*=10;
          spaceCtr+= toDigit(fmt[i+1]);
          i++;
        }
        if(spaceCtr!=0) {
          if(fmt[i+1]=='s') {
            temp = (*(adr+ctr));
            ctr++;
            i++;
            if(leftFlag==1) {
              for(j=0;j<strlen(temp);j++){
                putchar(temp[j]);
              }
              if(strlen(temp)>=spaceCtr);
              else {
                for(j=0;j<spaceCtr-strlen(temp);j++) {
                  putchar(' ');
                }
              }
            }
            else {
              if(strlen(temp)>=spaceCtr);
              else {
                for(j=0;j<spaceCtr-strlen(temp);j++) {
                  putchar(' ');
                }
              }
              for(j=0;j<strlen(temp);j++){
                putchar(temp[j]);
              }
            }
          }
          else return;
        }
        else if (fmt[i+1]=='s') {
          temp = (*(adr+ctr));
          ctr++;
          i++;
          for(j=0;j<strlen(temp);j++){
            putchar(temp[j]);
          }
        }
        else if(fmt[i+1]=='d') {
          putint(*(adr+ctr));
          ctr++;
          i++;
        }
        else if(fmt[i+1]=='x') {
          puthex(*(adr+ctr));
          ctr++;
          i++;
        }
        else if(fmt[i+1]=='o') {
          putoctal(*(adr+ctr));
          ctr++;
          i++;
        }
        else if(fmt[i+1]=='u') {
          putunsigned(*(adr+ctr));
          ctr++;
          i++;
        }
        else if(fmt[i+1]=='b') {
          putbinary(*(adr+ctr));
          ctr++;
          i++;
        }
        else if(fmt[i+1]=='c') {
          putchar(*(adr+ctr));
          ctr++;
          i++;
        }
      }
    }
    else {
      putchar(fmt[i]);
    }
  }
}
