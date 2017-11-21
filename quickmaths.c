#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main() {
    int READ = 0;
    int WRITE = 1;
  
    int child[2];
    int parent[2];
    pipe(child);
    pipe(parent);
  
    srand(time(NULL));
  
    if (fork() == 0) {
		close(parent[WRITE]);
		close(child[READ]);
      	int receive;
     	read(parent[READ], &receive, sizeof(receive));
      	printf("child is going to perform quick maths on: [%d]\n", receive);
     	receive /= 2; 
      	write(child[WRITE], &receive, sizeof(receive));
    } 
    else {
		close(parent[READ]);
		close(child[WRITE]);
      	int send = rand() % 100;
      	write(parent[WRITE], &send, sizeof(send));
      	printf("parent sent: [%d]\n", send);
      	read(child[READ], &send, sizeof(send)); 
      	printf("parent read: [%d]\n", send);
  	}
}