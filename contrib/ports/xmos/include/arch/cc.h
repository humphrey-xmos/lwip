

#ifndef __ARCH_CC_H__
#define __ARCH_CC_H__

#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <sys/time.h>

#include "debug_print.h"
#include "random.h"

#define BYTE_ORDER LITTLE_ENDIAN

#define LWIP_ERR_T int

#ifndef __XC__
#define PACK_STRUCT_STRUCT __attribute__((packed))
#endif

/* Plaform specific diagnostic output */
#define LWIP_PLATFORM_DIAG(x) \
  do {                        \
    debug_printf x ;        \
  } while (0)

#define LWIP_PLATFORM_ASSERT(x)                                               \
  do {                                                                        \
    debug_printf("Assert \"%s\" failed at line %d in %s\n", x, __LINE__, __FILE__); \
    while (1) {                                                               \
    };                                                                        \
  } while (0)

extern random_generator_t rng;

#define LWIP_RAND() random_get_random_number(&rng)

typedef uint32_t sys_prot_t;

#endif /* __ARCH_CC_H__ */
