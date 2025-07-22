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

# set(lwipcontribportxmos_SRCS
#     ${LWIP_CONTRIB_DIR}/ports/xmos/port/sys_arch.c
# )

set(lwipcontribportxmosnetifs_SRCS
    ${LWIP_CONTRIB_DIR}/ports/xmos/netif/ethernetif.c
    ${LWIP_CONTRIB_DIR}/ports/xmos/netif/xcore_netif_output.xc
)

# add_library(lwipcontribportxmos EXCLUDE_FROM_ALL ${lwipcontribportxmos_SRCS} ${lwipcontribportxmosnetifs_SRCS})
add_library(lwipcontribportxmos EXCLUDE_FROM_ALL ${lwipcontribportxmosnetifs_SRCS})
target_include_directories(lwipcontribportxmos PRIVATE ${LWIP_INCLUDE_DIRS} ${LWIP_MBEDTLS_INCLUDE_DIRS})
target_compile_options(lwipcontribportxmos PRIVATE ${LWIP_COMPILER_FLAGS})
target_compile_definitions(lwipcontribportxmos PRIVATE ${LWIP_DEFINITIONS} ${LWIP_MBEDTLS_DEFINITIONS})
# target_link_libraries(lwipcontribportxmos PUBLIC ${LWIP_MBEDTLS_LINK_LIBRARIES})
