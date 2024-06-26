#******************************************************************************
#
# Makefile - Rules for building the Mass Storage Class example.
#
# Copyright (c) 2012-2015 Texas Instruments Incorporated.  All rights reserved.
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
# This is part of revision 2.1.1.71 of the DK-TM4C123G Firmware Package.
#
#******************************************************************************

#
# Defines the part type that this project uses.
#
PART=TM4C123GH6PGE

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
VPATH+=../../../../third_party/fatfs/port
VPATH+=../../../../third_party/fatfs/src
VPATH+=../../../../utils

#
# Where to find header files that do not live in the source directory.
#
IPATH=..
IPATH+=../../../..
IPATH+=../../../../third_party

#
# The default rule, which causes the Mass Storage Class example to be built.
#
all: ${COMPILER}
all: ${COMPILER}/usb_dev_msc.axf

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
# Rules for building the Mass Storage Class example.
#
${COMPILER}/usb_dev_msc.axf: ${COMPILER}/cfal96x64x16.o
${COMPILER}/usb_dev_msc.axf: ${COMPILER}/mmc-dk-tm4c123g.o
${COMPILER}/usb_dev_msc.axf: ${COMPILER}/startup_${COMPILER}.o
${COMPILER}/usb_dev_msc.axf: ${COMPILER}/uartstdio.o
${COMPILER}/usb_dev_msc.axf: ${COMPILER}/usb_dev_msc.o
${COMPILER}/usb_dev_msc.axf: ${COMPILER}/usb_msc_structs.o
${COMPILER}/usb_dev_msc.axf: ${COMPILER}/usbdsdcard.o
${COMPILER}/usb_dev_msc.axf: ${ROOT}/usblib/${COMPILER}/libusb.a
${COMPILER}/usb_dev_msc.axf: ${ROOT}/grlib/${COMPILER}/libgr.a
${COMPILER}/usb_dev_msc.axf: ${ROOT}/driverlib/${COMPILER}/libdriver.a
${COMPILER}/usb_dev_msc.axf: usb_dev_msc.ld
SCATTERgcc_usb_dev_msc=usb_dev_msc.ld
ENTRY_usb_dev_msc=ResetISR
CFLAGSgcc=-DTARGET_IS_TM4C123_RB1

#
# Include the automatically generated dependency files.
#
ifneq (${MAKECMDGOALS},clean)
-include ${wildcard ${COMPILER}/*.d} __dummy__
endif
