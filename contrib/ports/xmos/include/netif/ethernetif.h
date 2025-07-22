// Copyright 2011-2025 XMOS LIMITED.
// This Software is subject to the terms of the XMOS Public Licence: Version 1.

#ifndef ETHERNETIF_H
#define ETHERNETIF_H

#include <stdint.h>

#include "xtcp.h"

#if defined(__XC__) || defined(__cplusplus)
extern "C" {
#endif

/* 
 * Due to rate of xcore timers (100MHz) we cannot time beyond ~40 seconds
 * so we use a divisor to reduce the timer period to below this.
 * Practically, the timer expires immediately if timeout value is greater then
 * UINT_MAX / 2, hence /4 here
 */
#define XNETIF_DHCP_DIVISOR 4

typedef enum {
  ARP_TIMEOUT,
  IP_REASS_TIMEOUT,
  TCP_TIMEOUT,
  IGMP_TIMEOUT,
  DHCP_COARSE_TIMEOUT,
  DHCP_FINE_TIMEOUT,
  // ACD_TMR_TIMEOUT,
  DNS_TIMEOUT,
  NUM_TIMEOUTS
} xtcp_lwip_timeout_type;

int xcore_ethernetif_init(const uint8_t* mac_address_phy, const xtcp_ipconfig_t* ipconfig);
void xcore_lwip_init_timers(uint32_t period[NUM_TIMEOUTS], uint32_t timeout[NUM_TIMEOUTS], uint32_t time_now);

void ethernetif_input(const uint8_t buffer[], int32_t n_bytes);

void xcore_net_link_up(void);
void xcore_net_link_down(void);

void xcore_timeout(xtcp_lwip_timeout_type timeout);

void print_netif_ipaddr(void);

#if defined(__XC__) || defined(__cplusplus)
}
#endif

#endif /* ETHERNETIF_H */
