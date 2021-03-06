#ifndef  _POSIX_C_SOURCE
# define _POSIX_C_SOURCE 200809L
#endif

#include <stdio.h>
#include "fev_tmsvc_modules.h"

// The resolution is million seconds for this API
int fev_tmmod_timeout(ftimer_node* node, struct timespec* now) {
    long int diff_sec  = now->tv_sec  - node->start.tv_sec;
    long int diff_nsec = now->tv_nsec - node->start.tv_nsec;

    // if the timer will be started in the future, exit with no-timeout
    if (diff_sec < 0) {
        return 0;
    }

    if (diff_sec == 0 && diff_nsec < 0) {
        return 0;
    }

    long int diff_ms = diff_sec * MS_PER_SECOND + (diff_nsec / NS_PER_MS);

    if (diff_ms >= node->expiration) {
        return 1;
    } else {
        return 0;
    }
}

extern fev_tmsvc_ops_t sl_ops;

// global opt table
// every type of timer module should register in this table
fev_tmsvc_ops_t* tmsvc_ops_tbl[] = {
    &sl_ops,   // for FEV_TMSVC_SINGLE_LINKED
    NULL       // reserve for FEV_TMSVC_TIMER_WHEEL
};
