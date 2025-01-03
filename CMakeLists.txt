# Copyright (c) 2020 ARM Limited. All rights reserved.
# SPDX-License-Identifier: Apache-2.0

add_library(nu-bme680 STATIC EXCLUDE_FROM_ALL)

target_include_directories(nu-bme680
    PUBLIC
        BME680
        BME680_driver
)

target_sources(nu-bme680
    PRIVATE
        BME680/mbed_bme680.cpp
        BME680_driver/bme680.c
)

target_link_libraries(nu-bme680 PUBLIC mbed-core-flags)
