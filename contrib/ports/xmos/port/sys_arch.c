// Copyright 2025 XMOS LIMITED.
// This Software is subject to the terms of the XMOS Public Licence: Version 1.

#include <stdint.h>

/* xcore includes */
#include <xs1.h>
#include <xcore/hwtimer.h>

/* lwIP includes. */
#include "lwip/debug.h"
#include "lwip/def.h"
#include "lwip/sys.h"
#include "lwip/mem.h"
#include "lwip/stats.h"
#include "lwip/timeouts.h"


#if LWIP_TIMERS && !LWIP_TIMERS_CUSTOM

u32_t sys_now(void)
{
  // TODO - implement ms timer value for returning, this is currently not needed, as NO_SYS_NO_TIMERS=1
}

#else /* LWIP_TIMERS && !LWIP_TIMERS_CUSTOM */

/* Timers currently run on fixed timer periods, always called when time elapses. See xcore_timeout() 
 * In order to support LwIP native apps (mdns, mqtt, sntp, tftp) this would need to be implemented to receive timer scheduling requests. */
void sys_timeout(u32_t msecs, sys_timeout_handler handler, void *arg)
{
  (void) msecs;
  (void) handler;
  (void) arg;
}

#endif /* LWIP_TIMERS && !LWIP_TIMERS_CUSTOM */

#include "random.h"

// Used in ports/xmos/include/arch/cc.h
random_generator_t rng;

void xarch_init(void) {
  rng = random_create_generator_from_hw_seed();
}
