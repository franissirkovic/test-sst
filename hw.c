/******************************************************************************
 * (C) Copyright 2006, Artur Lipowski
 *
 * No guarantees, warrantees, or promises, implied or otherwise.
 * May be used for hobby or commercial purposes provided copyright
 * notice remains intact.
 *
 ******************************************************************************/

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <strings.h>

#include "hw.h"
#include "main.h"


void* timer_thread(void* arg)
{
    SST_DECLARE_ISR;

    while (1)
    {
        usleep(10000);
        SST_ISR_ENTRY(SST_MIN_INT_PRIO+1);

        SST_TimerTick(&ticker_10ms);
        SST_ScheduleTask(btn_task_id);

        SST_ISR_EXIT();
    }
    return NULL;
}


/*******************************************************************************/
void ioinit(void)
{
    int err;
    pthread_t thread;

    printf("Started timer thread!\n");
    err = pthread_create(&thread, NULL, timer_thread, NULL);
}


void SST_OnIdle(void)
{
}
