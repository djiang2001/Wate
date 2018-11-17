#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int main(){
  printf("Parent fork()\n");
  int f = fork();
  int status;
  int pid = wait(&status);

  if(!f){
    printf("Child Process: %d Running\n",getpid());//child
    int rando = rand()%15+5;
    sleep(rando);
    printf("Child %d finished after %d seconds\n",getpid(), rando);
    return rando;
  }
   printf("Parent wait for child %d for %d seconds \n", pid, WEXITSTATUS(status));
  printf("Parent fork()\n");
  int g = fork();
  int status1;
  int pid1 = wait(&status1);
  if(!g){
    printf("Child Process: %d Running\n",getpid());//child
    int rando = rand()%15+5;
    sleep(rando);
    printf("Child finished after %d seconds\n", rando);
    return rando;
  }
   printf("Parent wait for child %d for %d seconds \n", pid1, WEXITSTATUS(status1));
 
  printf("Parent done \n");
  return 0;
}
