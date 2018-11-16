#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int main(){
  printf("Testing fork()\n");
  int f = fork();
  if(f){
    int k = fork();
    if(!k){
      printf("%d \n",getpid());
      sleep(rand()*15 + 5);
      printf("Finished \n");
    }
  }else{
    printf("%d \n",getpid());
     sleep(rand()*15 + 5);
  }
  
  return 0;
}
