#include<sys/ipc.h>
#include<sys/msg.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXSIZE 128
struct msgbuf
{
long mtype;
char mtext[MAXSIZE];
};

int main()
{
int msqid;
key_t key;
size_t buflen;
struct msgbuf rcvbuffer;
key=1234;
if((msqid=msgget(key,0666))<0)
{
perror("msgq failed\n");
exit(1);
}
if(msgrcv(msqid,&rcvbuffer,MAXSIZE,1,0)<0)
{
perror("msgrcv failed\n");
exit(1);
}
printf("%s\n",rcvbuffer.mtext);
getchar();
msgctl(msqid, IPC_RMID, NULL);// to destroy msgq
return 0;
}
