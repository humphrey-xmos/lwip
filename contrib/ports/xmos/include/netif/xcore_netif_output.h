// Copyright 2015-2025 XMOS LIMITED.
// This Software is subject to the terms of the XMOS Public Licence: Version 1.

#ifndef __XCORE_NETIF_H__
#define __XCORE_NETIF_H__


#if defined(__XC__) || defined(DOXYGEN)
/** Function called to assign transmit interface for the network stack.
 *
 * @param i_eth_tx  The Ethernet transmit interface to use
 * 
 * \note This function should be called before the network stack is initialized.
 * 
 * \todo Check how to handle dual-PHY configuration
 */
void xcore_netif_output_init(client interface ethernet_tx_if i_eth_tx);
#endif /* __XC__ || DOXYGEN__ */

/** Function called when a when a packet is to be sent.
 *
 * \param buffer    The data to send
 * \param n_bytes   Length of data to send
 * 
 * \note This function will likely be called from C, netif->linkoutput().
 */
void xcore_netif_low_level_output(char buffer[], int n_bytes);

#endif
