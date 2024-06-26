#******************************************************************************
#
# Makefile - Rules for building the Data logger quickstart example.
#
# Copyright (c) 2011-2015 Texas Instruments Incorporated.  All rights reserved.
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
# This is part of revision 2.1.1.71 of the EK-LM4F232 Firmware Package.
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
# The default rule, which causes the Data logger quickstart example to be built.
#
all: ${COMPILER}
all: ${COMPILER}/qs-logger.axf

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
# Rules for building the Data logger quickstart example.
#
${COMPILER}/qs-logger.axf: ${COMPILER}/acquire.o
${COMPILER}/qs-logger.axf: ${COMPILER}/buttons.o
${COMPILER}/qs-logger.axf: ${COMPILER}/cfal96x64x16.o
${COMPILER}/qs-logger.axf: ${COMPILER}/clocksetwidget.o
${COMPILER}/qs-logger.axf: ${COMPILER}/fat_usbmsc.o
${COMPILER}/qs-logger.axf: ${COMPILER}/ff.o
${COMPILER}/qs-logger.axf: ${COMPILER}/flashstore.o
${COMPILER}/qs-logger.axf: ${COMPILER}/images.o
${COMPILER}/qs-logger.axf: ${COMPILER}/menus.o
${COMPILER}/qs-logger.axf: ${COMPILER}/qs-logger.o
${COMPILER}/qs-logger.axf: ${COMPILER}/slidemenuwidget.o
${COMPILER}/qs-logger.axf: ${COMPILER}/startup_${COMPILER}.o
${COMPILER}/qs-logger.axf: ${COMPILER}/stripchartmanager.o
${COMPILER}/qs-logger.axf: ${COMPILER}/stripchartwidget.o
${COMPILER}/qs-logger.axf: ${COMPILER}/uartstdio.o
${COMPILER}/qs-logger.axf: ${COMPILER}/usb_serial_structs.o
${COMPILER}/qs-logger.axf: ${COMPILER}/usbserial.o
${COMPILER}/qs-logger.axf: ${COMPILER}/usbstick.o
${COMPILER}/qs-logger.axf: ${COMPILER}/ustdlib.o
${COMPILER}/qs-logger.axf: ${ROOT}/usblib/${COMPILER}/libusb.a
${COMPILER}/qs-logger.axf: ${ROOT}/grlib/${COMPILER}/libgr.a
${COMPILER}/qs-logger.axf: ${ROOT}/driverlib/${COMPILER}/libdriver.a
${COMPILER}/qs-logger.axf: qs-logger.ld
SCATTERgcc_qs-logger=qs-logger.ld
ENTRY_qs-logger=ResetISR
CFLAGSgcc=-DTARGET_IS_TM4C123_RA1

#
# Include the automatically generated dependency files.
#
ifneq (${MAKECMDGOALS},clean)
-include ${wildcard ${COMPILER}/*.d} __dummy__
endif
