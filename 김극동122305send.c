김극동 122305_send.c RTS 발생시키는 코드
#include <signal.h>
#include <stdio.h>
/*
 * argv[1]은 보내고자 하는 프로세스의 PID  
 * argv[2]는 보내고자 하는 값이다.   
 * SIGUSR1을 RTS로 전송한다. 
 */  
int main(int argc, char **argv)
{
    union sigval sv;

    sv.sival_int = atoi(argv[2]);
    sigqueue(atoi(argv[1]), SIGRTMIN, sv);
}
#include<stdio.h>
#include<signal.h>
#include<unistd.h>
/*  ctrl+z 기능 */
Void sigtstp_handler(int signo) {
Printf(“received %d\n”, signo);
Signal(SIGTSTP, SIG_IGN);  //시그널 실행이 안됨 중지
}
Int main(void)
{    
if (signal(SIGTSTP, sigtstp_handler) == SIG_ERR) {
       printf(“\ncan not catch signal\n”);
}

While(1) sleep(1);
Return 0;
}
