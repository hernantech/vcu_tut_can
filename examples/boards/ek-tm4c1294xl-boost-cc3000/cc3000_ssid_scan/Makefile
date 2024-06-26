#******************************************************************************
#
# Makefile - Rules for building the CC3000 SSI Scanning Application.
#
# Copyright (c) 2014-2015 Texas Instruments Incorporated.  All rights reserved.
# Software License Agreement
# 
# Texas Instruments (TI) is supplying this software for use solely and
# exclusively on TI's microcontroller products. The software is owned by
# TI and/or its suppliers, and is protected under applicable copyright
# laws. You may not combine this software with "viral" open-source
# software in order to form a larger program.
# 
# THIS SOFTWARE IS PROVIDED "AS IS" AND WITH ALL FAULTS.
# NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT
# NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
# A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE. TI SHALL NOT, UNDER ANY
# CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR CONSEQUENTIAL
# DAMAGES, FOR ANY REASON WHATSOEVER.
# 
# This is part of revision 2.1.1.71 of the EK-TM4C1294XL Firmware Package.
#
#******************************************************************************

#
# Defines the part type that this project uses.
#
PART=TM4C1294NCPDT

#
# The base directory for TivaWare.
#
ROOT=../../../..

#
# Include the common make definitions.
#
include ${ROOT}/makedefs

#
# Where to find source files that do not live in this directory.
#
VPATH=../../../../cc3000
VPATH+=../../../../cc3000/src/host_driver/core_driver
VPATH+=../drivers
VPATH+=../../../../cc3000/drivers/ek-tm4c129
VPATH+=../../../../cc3000/src/host_driver
VPATH+=../../../../cc3000/src/host_driver/include
VPATH+=../../../../cc3000/src/spi
VPATH+=../../../../cc3000/src/
VPATH+=../../../../cc3000/src/uart
VPATH+=../../../../utils

#
# Where to find header files that do not live in the source directory.
#
IPATH=..
IPATH+=../../../..
IPATH+=../../../../cc3000
IPATH+=../../../../cc3000/src/host_driver/core_driver
IPATH+=../../../../cc3000/drivers/ek-tm4c129
IPATH+=../../../../cc3000/src/host_driver
IPATH+=../../../../cc3000/src/host_driver/include
IPATH+=../../../../cc3000/src/spi
IPATH+=../../../../cc3000/src/
IPATH+=../../../../cc3000/src/uart

#
# The default rule, which causes the CC3000 SSI Scanning Application to be built.
#
all: ${COMPILER}
all: ${COMPILER}/cc3000_ssid_scan.axf

#
# The rule to clean out all the build products.
#
clean:
	@rm -rf ${COMPILER} ${wildcard *~}

#
# The rule to create the target directory.
#
${COMPILER}:
	@mkdir -p ${COMPILER}

#
# Rules for building the CC3000 SSI Scanning Application.
#
${COMPILER}/cc3000_ssid_scan.axf: ${COMPILER}/board.o
${COMPILER}/cc3000_ssid_scan.axf: ${COMPILER}/cc3000_ssid_scan.o
${COMPILER}/cc3000_ssid_scan.axf: ${COMPILER}/cc3000lib.o
${COMPILER}/cc3000_ssid_scan.axf: ${COMPILER}/pinout.o
${COMPILER}/cc3000_ssid_scan.axf: ${COMPILER}/startup_${COMPILER}.o
${COMPILER}/cc3000_ssid_scan.axf: ${COMPILER}/uartstdio.o
${COMPILER}/cc3000_ssid_scan.axf: ${ROOT}/driverlib/${COMPILER}/libdriver.a
${COMPILER}/cc3000_ssid_scan.axf: cc3000_ssid_scan.ld
SCATTERgcc_cc3000_ssid_scan=cc3000_ssid_scan.ld
ENTRY_cc3000_ssid_scan=ResetISR
CFLAGSgcc=-DTARGET_IS_TM4C129_RA0 -DUART_BUFFERED -D_POSIX_SOURCE -DCC3000_TM4C129_SPI -DCC3000_USE_BOOSTERPACK2

#
# Include the automatically generated dependency files.
#
ifneq (${MAKECMDGOALS},clean)
-include ${wildcard ${COMPILER}/*.d} __dummy__
endif
