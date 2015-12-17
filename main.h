#ifndef MAIN_H_
#define MAIN_H_

/******************************************************************************
 * (C) Copyright 2006, Artur Lipowski
 *
 * No guarantees, warrantees, or promises, implied or otherwise.
 * May be used for hobby or commercial purposes provided copyright
 * notice remains intact.
 *
 ******************************************************************************/

#include <sst_timer.h>

#define LED_1S_TASK_PRIO        (SST_MIN_TASK_PRIO + 5)
#define KBD_TASK_PRIO           (SST_MIN_TASK_PRIO + 6)

#if defined(SST_USE_SIGNAL_MASK) && SST_USE_SIGNAL_MASK != 0
#define KB_MASK     8
#endif

extern SST_TaskID_T led_1s_td;
extern SST_TaskID_T btn_task_id;


SST_TICKER_DECLARE(ticker_10ms);


#endif /*MAIN_H_*/
