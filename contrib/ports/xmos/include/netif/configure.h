// Copyright 2025 XMOS LIMITED.
// This Software is subject to the terms of the XMOS Public Licence: Version 1.

#ifndef CONFIGURE_H
#define CONFIGURE_H

#include <stdint.h>

/* 
 * Configure callback called during TCP/IP stack set-up. 
 * Function defined as weak, define this function in the client application to add custom configuration.
 */
void xnetif_configure(void);

#endif /* CONFIGURE_H */
