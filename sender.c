#include<sys/ipc.h>
#include<sys/msg.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXSIZE 128
struct msgbuf
{
long mtype;
char mtext[MAXSIZE];
};
int main()
{
int msqid,i;
key_t key;
struct msgbuf sbuf,rcvbuffer;
size_t buflen;
key=1234;
if((msqid=msgget(key,IPC_CREAT|0666))<0)
{
perror(" msgget failed\n");
exit(1);
}
sbuf. mtype=1;
printf("Enter a message to add:\n");
scanf("%[^\n]",sbuf.mtext);
getchar();
buflen=strlen(sbuf.mtext);
if(msgsnd(msqid,&sbuf,buflen,0)<0)
{
perror("msg is not sent\n");
exit(1);
}
return 0;
}
