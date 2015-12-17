/******************************************************************************
 * (C) Copyright 2006, Artur Lipowski
 *
 * No guarantees, warrantees, or promises, implied or otherwise.
 * May be used for hobby or commercial purposes provided copyright
 * notice remains intact.
 *
 ******************************************************************************/

#include <stddef.h>
#include <sst_timer.h>

#include "main.h"
#include "hw.h"
#include "mk_con.h"

SST_TaskID_T led_1s_tid;
SST_TaskID_T btn_task_id;

#if SST_MAX_EV_QUEUE_LEN == 0
SST_EVENTQ_DEFINE(led_1s_queue, 2);
SST_EVENTQ_DEFINE(btn_queue, 2);
#endif /* SST_MAX_EV_QUEUE_LEN == 0 */

#if defined(SST_USE_LAZY_TIMER) && SST_USE_LAZY_TIMER != 0
SST_TICKER_DEFINE(ticker_10ms, 1, NULL, NULL);
#else
SST_TICKER_DEFINE(ticker_10ms, 1);
#endif /* defined(SST_USE_LAZY_TIMER) && SST_USE_LAZY_TIMER != 0 */


void led_1s_func(SST_Event_T e)
{
    LED_TOGGLE(LED0);
}


void SST_Start(void)
{
    ioinit();
    MKC_Init();

#if SST_MAX_EV_QUEUE_LEN == 0
    led_1s_tid = SST_CreateTask(LED_1S_TASK_PRIO, led_1s_func, &led_1s_queue);
    btn_task_id = SST_CreateTask(KBD_TASK_PRIO, MKC_Task_Func, &btn_queue);
#else
    led_1s_tid = SST_CreateTask(LED_1S_TASK_PRIO, led_1s_func);
    btn_task_id = SST_CreateTask(KBD_TASK_PRIO, MKC_Task_Func);
#endif

#if defined(SST_USE_SIGNAL_MASK) && SST_USE_SIGNAL_MASK != 0
//    SST_SetSignalMask(timer_10ms_tid, LED_MASK);
#endif

    (void) SST_MakeTimedTask(led_1s_tid, 100, true, &ticker_10ms);

    SST_INT_UNLOCK();
}


int main(void)
{
    SST_Run();
}

