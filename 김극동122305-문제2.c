#include<stdio.h>
#include<signal.h>
#include<unistd.h>
/* SISTSTP 기능 */
Void sigtstp_handler(int signo) {
Printf(“received %d\n”, signo);
Signal(SIGTSTP, SIG_IGN);  //시그널 실행이 안됨 중지
}
/* SIGINT 기능 */
Void sigquit_handler(int signo)
{  printf(‘’received %\d”, signo);
   Signal(SIGINT, SIG_INT);   // 시그널 수행
}
/* SIGQUIT 기능 */
Void sigquit_handler(int signo)
{  printf(‘’received %\d”, signo);
   Signal(SIGQUIT, SIG_DFL);   // 시그널 수행
}

Int main(void)
{    
if (signal(SIGTSTP, sigtstp_handler) == SIG_ERR) {
       printf(“\ncan not catch signal\n”);
}
if (signal(SIGINT, sigquit_handler) == SIG_ERR) {
       printf(“\ncan not catch signal\n”);
}
if (signal(SIGQUIT, sigquit_handler) == SIG_ERR) {
       printf(“\ncan not catch signal\n”);
}

While(1) sleep(1);
Return 0;
}
