#******************************************************************************
#
# Makefile - Rules for building the NFC P2P Demo App.
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
# This is part of revision 2.1.1.71 of the EK-TM4C123GXL Firmware Package.
#
#******************************************************************************

#
# Defines the part type that this project uses.
#
PART=TM4C123GH6PM

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
VPATH=./
VPATH+=../
VPATH+=../drivers
VPATH+=../../../../nfclib
VPATH+=../../../../utils

#
# Where to find header files that do not live in the source directory.
#
IPATH=.
IPATH+=..
IPATH+=../../../..

#
# The default rule, which causes the NFC P2P Demo App to be built.
#
all: ${COMPILER}
all: ${COMPILER}/nfc_p2p_demo.axf

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
# Rules for building the NFC P2P Demo App.
#
${COMPILER}/nfc_p2p_demo.axf: ${COMPILER}/buttons.o
${COMPILER}/nfc_p2p_demo.axf: ${COMPILER}/iso14443a.o
${COMPILER}/nfc_p2p_demo.axf: ${COMPILER}/llcp.o
${COMPILER}/nfc_p2p_demo.axf: ${COMPILER}/nfc.o
${COMPILER}/nfc_p2p_demo.axf: ${COMPILER}/nfc_dep.o
${COMPILER}/nfc_p2p_demo.axf: ${COMPILER}/nfc_f.o
${COMPILER}/nfc_p2p_demo.axf: ${COMPILER}/nfc_p2p.o
${COMPILER}/nfc_p2p_demo.axf: ${COMPILER}/nfc_p2p_demo.o
${COMPILER}/nfc_p2p_demo.axf: ${COMPILER}/nfc_p2p_demo_debug.o
${COMPILER}/nfc_p2p_demo.axf: ${COMPILER}/ringbuf.o
${COMPILER}/nfc_p2p_demo.axf: ${COMPILER}/snep.o
${COMPILER}/nfc_p2p_demo.axf: ${COMPILER}/ssitrf79x0.o
${COMPILER}/nfc_p2p_demo.axf: ${COMPILER}/startup_${COMPILER}.o
${COMPILER}/nfc_p2p_demo.axf: ${COMPILER}/trf79x0.o
${COMPILER}/nfc_p2p_demo.axf: ${COMPILER}/uartstdio.o
${COMPILER}/nfc_p2p_demo.axf: ${COMPILER}/ustdlib.o
${COMPILER}/nfc_p2p_demo.axf: ${COMPILER}/ustdlib.o
${COMPILER}/nfc_p2p_demo.axf: ${ROOT}/driverlib/${COMPILER}/libdriver.a
${COMPILER}/nfc_p2p_demo.axf: nfc_p2p_demo.ld
SCATTERgcc_nfc_p2p_demo=nfc_p2p_demo.ld
ENTRY_nfc_p2p_demo=ResetISR
CFLAGSgcc=-DTARGET_IS_TM4C123_RB1 -DUART_BUFFERED

#
# Include the automatically generated dependency files.
#
ifneq (${MAKECMDGOALS},clean)
-include ${wildcard ${COMPILER}/*.d} __dummy__
endif
