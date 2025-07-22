// Copyright 2015-2025 XMOS LIMITED.
// This Software is subject to the terms of the XMOS Public Licence: Version 1.

#include "ethernet.h"
#include "debug_print.h"
#include "netif/xcore_netif_output.h"

enum xcore_netif_eth_e {
  XCORE_NETIF_ETH_NONE,
  XCORE_NETIF_ETH_MII,
  XCORE_NETIF_ETH_TX,
};

/*
 * Ethernet TX interface passed in from xtcp_lwip()
 * This interface is used to send packets over the Ethernet interface using xcore_netif_low_level_output().
 */
static client interface ethernet_tx_if unsafe xtcp_i_eth_tx;
static enum xcore_netif_eth_e xcore_netif_eth = XCORE_NETIF_ETH_NONE;

void xcore_netif_output_init(client interface ethernet_tx_if i_eth_tx) {
  unsafe {
    xtcp_i_eth_tx = i_eth_tx;
  }
  xcore_netif_eth = XCORE_NETIF_ETH_TX;
}

void xcore_netif_low_level_output(char buffer[], int n_bytes) {
  unsafe {
    if (xcore_netif_eth == XCORE_NETIF_ETH_TX) {
      // TODO - Check whether ETHERNET_ALL_INTERFACES is correct when we support dual-PHY
      ((client interface ethernet_tx_if)xtcp_i_eth_tx).send_packet(buffer, n_bytes, ETHERNET_ALL_INTERFACES);

    } else {
      debug_printf("netif output interface not set.\n");
      while(1) {}
    }
  }
}
