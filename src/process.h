//
// Created by Steve Soltys on 3/16/15.
//

#ifndef _PROCESS_H_
#define _PROCESS_H_

#include <sched.h>
#include "list.h"

typedef struct process {
    pid_t id;
    int exit_status;
} process_t;

void run_commands(list_t *commands);

#endif //_PROCESS_H_
