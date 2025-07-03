# This file is indended to be included in end-user CMakeLists.txt
# include(/path/to/Filelists.cmake)
# It assumes the variable LWIP_CONTRIB_DIR is defined pointing to the
# root path of lwIP/contrib sources.
#
# This file is NOT designed (on purpose) to be used as cmake
# subdir via add_subdirectory()
# The intention is to provide greater flexibility to users to
# create their own targets using the *_SRCS variables.

if(NOT ${CMAKE_VERSION} VERSION_LESS "3.10.0")
    include_guard(GLOBAL)
endif()

set(lwipcontribportxmos_SRCS
    ${LWIP_CONTRIB_DIR}/ports/xmos/port/configure.c
    ${LWIP_CONTRIB_DIR}/ports/xmos/port/ethernetif.c
    ${LWIP_CONTRIB_DIR}/ports/xmos/port/sys_arch.c
    ${LWIP_CONTRIB_DIR}/ports/xmos/port/xcore_netif_output.xc
)
