#include <signal.h>
#include <stdio.h>
#include <unistd.h> 
void sighandler(int signo, siginfo_t *si)      // 시그널 핸들러
{
if(si->si_code == SI_QUEUE)       // si_code가 SI_QUEUE 인지를 확인한후 원하는 작업을 한다.  
{
printf("User RTS signal %d\n", si->si_pid);    // SI_QUEUE일 경우 RTS형식으로 전달된 시그널       
printf("Sig  Number %d\n",     si->si_signo);
  printf("User Data is %d\n",    si->si_value.sival_int);
        // 시그널이 큐잉되는지 확인하기 위한 코드
        getchar();
    }
    Else            // 아니면 표준 유닉스 시그널
    {
        // kill등을 이용해서 표준 유닉스 시그널을 보냈을 경우
        // 실행되는 루틴 
        printf("UNIX standard signal %d\n", signo); 
    }
int main()
{
    struct sigaction sigact;
    printf("My pid %d\n", getpid());
 
    sigemptyset(&sigact.sa_mask);
    sigact.sa_flags     = SA_SIGINFO;    // sa_flags를 SA_SIGINFO로 설정
    sigact.sa_restorer  = NULL; 
    sigact.sa_sigaction = sighandler;      // 시그널 핸들러

    /*
     * RTS시그널에 대한 핸들러를 설치한다.  
     */
    if (sigaction(SIGRTMIN, &sigact, 0) == 1)
    {
        printf("signal error\n");
        exit(0);
    }   
    while(1)
    {
        sleep(1);
    }   
}   
