#******************************************************************************
#
# Makefile - Rules for building the boot_demo_uart example.
#
# Copyright (c) 2013-2015 Texas Instruments Incorporated.  All rights reserved.
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
# This is part of revision 2.1.1.71 of the DK-TM4C129X Firmware Package.
#
#******************************************************************************

#
# Defines the part type that this project uses.
#
PART=TM4C129XNCZAD

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
VPATH=../drivers

#
# Where to find header files that do not live in the source directory.
#
IPATH=..
IPATH+=../../../..

#
# The default rule, which causes the boot_demo_uart example to be built.
#
all: ${COMPILER}
all: ${COMPILER}/boot_demo_uart.axf

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
# Rules for building the boot_demo_uart example.
#
${COMPILER}/boot_demo_uart.axf: ${COMPILER}/boot_demo_uart.o
${COMPILER}/boot_demo_uart.axf: ${COMPILER}/frame.o
${COMPILER}/boot_demo_uart.axf: ${COMPILER}/kentec320x240x16_ssd2119.o
${COMPILER}/boot_demo_uart.axf: ${COMPILER}/pinout.o
${COMPILER}/boot_demo_uart.axf: ${COMPILER}/startup_${COMPILER}.o
${COMPILER}/boot_demo_uart.axf: ${COMPILER}/touch.o
${COMPILER}/boot_demo_uart.axf: ${ROOT}/grlib/${COMPILER}/libgr.a
${COMPILER}/boot_demo_uart.axf: ${ROOT}/driverlib/${COMPILER}/libdriver.a
${COMPILER}/boot_demo_uart.axf: boot_demo_uart.ld
SCATTERgcc_boot_demo_uart=boot_demo_uart.ld
ENTRY_boot_demo_uart=ResetISR
CFLAGSgcc=-DTARGET_IS_TM4C129_RA0

#
# Include the automatically generated dependency files.
#
ifneq (${MAKECMDGOALS},clean)
-include ${wildcard ${COMPILER}/*.d} __dummy__
endif
