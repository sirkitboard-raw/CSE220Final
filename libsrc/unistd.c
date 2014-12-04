#include "unistd.h"
#include "lib.h"
#include "string.h"

int exec(const char* path) {
  char buffer[EXEC_BUFFER_SIZE];
  int ret;
  int fp = open(path,0,0);
  if(!(fp<0)) {
    read(fp, &buffer, EXEC_BUFFER_SIZE);
    ret = load(buffer);
    return ret;
  }
  return -1;
}

int fputint(int fd, int a) {
  char buffer[10];
  int ctr = 0;
  int i=0;
  int temp;
  if(a==0) {
    fputc(fd,'0');
    return 1;
  }
  else if (a<0) {
    fputc(fd,'-');
    a*=-1;
    ctr++;
  }
  while(a!=0) {
    temp = a%10;
    if(temp==0) buffer[ctr] = '0';
    else if (temp==1) buffer[ctr] = '1';
    else if (temp==2) buffer[ctr] = '2';
    else if (temp==3) buffer[ctr] = '3';
    else if (temp==4) buffer[ctr] = '4';
    else if (temp==5) buffer[ctr] = '5';
    else if (temp==6) buffer[ctr] = '6';
    else if (temp==7) buffer[ctr] = '7';
    else if (temp==8) buffer[ctr] = '8';
    else if (temp==9) buffer[ctr] = '9';
    a/=10;
    ctr++;
  }
  for(i=ctr-1;i>=0;i--) {
    fputc(fd,buffer[i]);
  }
  return ctr;
}

int fputhex(int fd, int a) {
  char buffer[8];
  int ctr = 0;
  int i=0;
  int temp;
  if(a==0) {
    fputc(fd,'0');
    return 1;
  }
  else if (a<0) {
    fputc(fd,'-');
    a*=-1;
    ctr++;
  }
  while(a!=0) {
    temp = a%16;
    if(temp==0) buffer[ctr] = '0';
    else if (temp==1) buffer[ctr] = '1';
    else if (temp==2) buffer[ctr] = '2';
    else if (temp==3) buffer[ctr] = '3';
    else if (temp==4) buffer[ctr] = '4';
    else if (temp==5) buffer[ctr] = '5';
    else if (temp==6) buffer[ctr] = '6';
    else if (temp==7) buffer[ctr] = '7';
    else if (temp==8) buffer[ctr] = '8';
    else if (temp==9) buffer[ctr] = '9';
    else if (temp==10) buffer[ctr] = 'A';
    else if (temp==11) buffer[ctr] = 'B';
    else if (temp==12) buffer[ctr] = 'C';
    else if (temp==13) buffer[ctr] = 'D';
    else if (temp==14) buffer[ctr] = 'E';
    else if (temp==15) buffer[ctr] = 'F';
    a/=16;
    ctr++;
  }
  for(i=ctr-1;i>=0;i--) {
    fputc(fd,buffer[i]);
  }
  return ctr;
}

int fputoct(int fd, int a) {
  char buffer[11];
  int ctr = 0;
  int i=0;
  int temp;
  if(a==0) {
    fputc(fd,'0');
    return 1;
  }
  else if (a<0) {
    fputc(fd,'-');
    a*=-1;
    ctr++;
  }
  while(a!=0) {
    temp = a%8;
    if(temp==0) buffer[ctr] = '0';
    else if (temp==1) buffer[ctr] = '1';
    else if (temp==2) buffer[ctr] = '2';
    else if (temp==3) buffer[ctr] = '3';
    else if (temp==4) buffer[ctr] = '4';
    else if (temp==5) buffer[ctr] = '5';
    else if (temp==6) buffer[ctr] = '6';
    else if (temp==7) buffer[ctr] = '7';
    a/=8;
    ctr++;
  }
  for(i=ctr-1;i>=0;i--) {
    fputc(fd,buffer[i]);
  }
  return ctr;
}

int fputunsigned(int fd, int b) {
  unsigned int a = b;
  char buffer[10];
  int ctr = 0;
  int i=0;
  int temp;
  if(a==0) {
    fputc(fd,'0');
    return 1;
  }
  while(a!=0) {
    temp = a%10;
    if(temp==0) buffer[ctr] = '0';
    else if (temp==1) buffer[ctr] = '1';
    else if (temp==2) buffer[ctr] = '2';
    else if (temp==3) buffer[ctr] = '3';
    else if (temp==4) buffer[ctr] = '4';
    else if (temp==5) buffer[ctr] = '5';
    else if (temp==6) buffer[ctr] = '6';
    else if (temp==7) buffer[ctr] = '7';
    else if (temp==8) buffer[ctr] = '8';
    else if (temp==9) buffer[ctr] = '9';
    a/=10;
    ctr++;
  }
  for(i=ctr-1;i>=0;i--) {
    fputc(fd,buffer[i]);
  }
  return ctr;
}

int fputbin(int fd, int a) {
  int i=0;
  int temp;
  for(i=0;i<32;i++) {
    temp = a & 0x7FFFFFFF;
    if(temp == 0x00000000) fputc(fd,'0');
    else fputc(fd,'1');
    a = a << 1;
  }
  return 32;
}

int fprintf(int fd, const char *fmt, ...) {
  int* adr = &fmt;
  char* temp;
  int i=0,j=0;
  int ctr=1;
  int spaceCtr;
  int leftFlag;
  int charCtr = 0;
  for(i=0;i<strlen(fmt);i++) {
    spaceCtr = 0;
    leftFlag = 0;
    if(fmt[i]=='%') {
      if(fmt[i+1]=='%'){
        fputc(fd,'%');
        charCtr++;
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
                fputc(fd,temp[j]);
                charCtr++;
              }
              if(strlen(temp)>=spaceCtr);
              else {
                for(j=0;j<spaceCtr-strlen(temp);j++) {
                  fputc(fd,' ');
                  charCtr++;
                }
              }
            }
            else {
              if(strlen(temp)>=spaceCtr);
              else {
                for(j=0;j<spaceCtr-strlen(temp);j++) {
                  fputc(fd,' ');
                  charCtr++;
                }
              }
              for(j=0;j<strlen(temp);j++){
                fputc(fd,temp[j]);
                charCtr++;
              }
            }
          }
          else return charCtr;
        }
        else if (fmt[i+1]=='s') {
          temp = (*(adr+ctr));
          ctr++;
          i++;
          for(j=0;j<strlen(temp);j++){
            fputc(fd,temp[j]);
            charCtr++;
          }
        }
        else if(fmt[i+1]=='d') {
          charCtr+=fputint(fd,*(adr+ctr));
          ctr++;
          i++;
        }
        else if(fmt[i+1]=='x') {
          charCtr+=fputhex(fd,*(adr+ctr));
          ctr++;
          i++;
        }
        else if(fmt[i+1]=='o') {
          charCtr+=fputoct(fd,*(adr+ctr));
          ctr++;
          i++;
        }
        else if(fmt[i+1]=='u') {
          charCtr+=fputunsigned(fd,*(adr+ctr));
          ctr++;
          i++;
        }
        else if(fmt[i+1]=='b') {
          charCtr+=fputbin(fd,*(adr+ctr));
          ctr++;
          i++;
        }
        else if(fmt[i+1]=='c') {
          charCtr+=fputc(fd,*(adr+ctr));
          ctr++;
          i++;
        }
      }
    }
    else {
      fputc(fd,fmt[i]);
      charCtr++;
    }
  }
  return charCtr;
}
