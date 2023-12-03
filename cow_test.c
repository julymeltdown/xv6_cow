#include "types.h"
#include "user.h"
#include "param.h"

char *shared = "::This is parent process";
int num_childs = 5;

void
child_process(int i)
{
    printf(1, "Child %d sees: %s\n", i, shared);
    printf(1, "Child %d modifies memory...\n", i);
    shared[0] = 'A' + i;
    printf(1, "Now child %d sees: %s\n", i, shared);
    sleep(100); // sleep
}

int
main(void)
{
    int pid;
    int i;

    for(i = 0; i < num_childs; i++){
        pid = fork();
        if(pid < 0){
            printf(1, "fork failed\n");
            exit();
        }

        if(pid == 0){  // child process
            child_process(i);
            exit();
        }
    }

    for(i = 0; i < num_childs; i++){
        wait();
    }

    printf(1, "Parent sees: %s\n", shared);
    printf(1, "Parent process exiting...\n");

    exit();
}
