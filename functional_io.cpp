/*
******************************************************************************
	Functional IO Mapping Implementation
	eHarley Project
	Erik Stafl
	1/23/2015

	Written for Tiva TM4C123BH6PGE
	Language: C++

	Copyright (c) 2013-2016 Stafl Systems, LLC.  All rights reserved.
******************************************************************************
*/

#include "functional_io.h"

// Reference to Main Board Object in vcu.cpp
extern VCU1200_Board board;

// Input Polarity Settings
SignalPolarity input_polarities[NUM_INPUT_SIGNALS];

// Local Storage of Input Signal States (fdor Secondary VCU Inputs)
SignalState input_states[NUM_INPUT_SIGNALS];

// Local Storage of Output Signal States (for Secondary VCU Outputs)
SignalState output_states[NUM_OUTPUT_SIGNALS];

SignalState getInput(InputSignal input)
{
	/*switch (input)
	{
	case BUTTON1:
		return (board.getAnalogValue(VCU1200_Board::THERMISTOR_1) > 10000.0f ? ON : OFF);
	}*/

	// Continue to Normal Digital Inputs

	if (input_polarities[input] == ACTIVE_HIGH)
	{
		// Invert Raw Pin State
		return (SignalState)(!board.getInput(mapInput(input)));
	}
	else
	{
		// Use Raw Pin State
		return (SignalState)(board.getInput(mapInput(input)));
	}
}

// Return the Raw Voltage of the Analog Input
float getAnalogInput(AnalogSignal input)
{
	switch (input)
	{
	//Setup the Potentiometer as an Analog Input and Read then return Value
	case POTENTIOMETER:
		return board.getAnalogValue(VCU1200_Board::ANALOG_INPUT_1);

	default:
		// Program should never get here
		error("Unimplemented Input in getAnalogInput() call", "functional_io.cpp", __LINE__);
		return 0.0f;
	}
}

SignalState getOutput(OutputSignal output)
{
	// Get State of Corresponding Output Pin on Board
	return (SignalState)board.getOutput(mapOutput(output));
}

void initializeInputs()
{
	// Set Pins to to Pull Up Resistor, but still Active High

	board.setPinResistor(mapInput(ON_OFF_SWITCH), 		VCU1200_Board::PULL_DOWN);
	setInputPolarity(ON_OFF_SWITCH, 						ACTIVE_HIGH);
	/*	board.setPinResistor(mapInput(X_POS_LIMIT), VCU1200_Board::PULL_UP);
	setInputPolarity(X_POS_LIMIT, 					ACTIVE_HIGH);
	board.setPinResistor(mapInput(X_NEG_LIMIT), 	VCU1200_Board::PULL_UP);
	setInputPolarity(X_NEG_LIMIT, 					ACTIVE_HIGH);
	board.setPinResistor(mapInput(Y_POS_LIMIT), 	VCU1200_Board::PULL_UP);
	setInputPolarity(Y_POS_LIMIT, 					ACTIVE_HIGH);
	board.setPinResistor(mapInput(Y_NEG_LIMIT), 	VCU1200_Board::PULL_UP);
	setInputPolarity(Y_NEG_LIMIT, 					ACTIVE_HIGH);*/

	// Set Pins to Active Low (Pull Up Resistor)
/*	board.setPinResistor(mapInput(WELDER_GOOD), 	VCU1200_Board::PULL_UP);
	setInputPolarity(WELDER_GOOD,					ACTIVE_LOW);
	board.setPinResistor(mapInput(WELDER_NG), 		VCU1200_Board::PULL_UP);
	setInputPolarity(WELDER_NG,						ACTIVE_LOW);
	board.setPinResistor(mapInput(WELDER_END), 		VCU1200_Board::PULL_UP);
	setInputPolarity(WELDER_END,					ACTIVE_LOW);
	board.setPinResistor(mapInput(WELDER_CAUTION),	VCU1200_Board::PULL_UP);
	setInputPolarity(WELDER_CAUTION,				ACTIVE_LOW);
	board.setPinResistor(mapInput(WELDER_COUNT_UP),	VCU1200_Board::PULL_UP);
	setInputPolarity(WELDER_COUNT_UP,				ACTIVE_LOW);
	board.setPinResistor(mapInput(WELDER_READY),	VCU1200_Board::PULL_UP);
	setInputPolarity(WELDER_READY,					ACTIVE_LOW);
	board.setPinResistor(mapInput(START_BUTTONS),	VCU1200_Board::PULL_UP);
	setInputPolarity(START_BUTTONS,					ACTIVE_LOW);*/
}

VCU1200_Board::Input mapInput(InputSignal input)
{
	switch (input)
	{
	case ON_OFF_SWITCH:
		return VCU1200_Board::DIGITAL_INPUT_1;

	default:
		// Program should never get here
		error("Unimplemented Input Signal in mapInput() call", "functional_io.cpp", __LINE__);
		return VCU1200_Board::DIGITAL_INPUT_1;
	}
}

VCU1200_Board::Output mapOutput(OutputSignal output)
{
	switch (output)
	{
		case LED1:
			return VCU1200_Board::RELAY_DRIVER_1;

		case LED2:
			return VCU1200_Board::RELAY_DRIVER_2;

		case LED3:
			return VCU1200_Board::RELAY_DRIVER_3;

		case LED4:
			return VCU1200_Board::RELAY_DRIVER_4;

		case LED5:
			return VCU1200_Board::RELAY_DRIVER_5;

		case LED6:
			return VCU1200_Board::RELAY_DRIVER_6;

		case LED7:
			return VCU1200_Board::RELAY_DRIVER_7;

		case LED8:
			return VCU1200_Board::RELAY_DRIVER_8;

		case LED9:
			return VCU1200_Board::RELAY_DRIVER_9;

		case LED10:
			return VCU1200_Board::RELAY_DRIVER_10;

		case LED11:
			return VCU1200_Board::RELAY_DRIVER_11;

		case LED12:
			return VCU1200_Board::RELAY_DRIVER_12;

		case LED13:
			return VCU1200_Board::RELAY_DRIVER_13;

		case LED14:
			return VCU1200_Board::RELAY_DRIVER_14;

		case POTENTIOMETER_5V:
			return VCU1200_Board::ANALOG_5V_OUTPUT_1;

		default:
			// Program should never get here
			error("Unimplemented Output Signal in mapOutput() call", "functional_io.cpp", __LINE__);
			return VCU1200_Board::RELAY_DRIVER_1;
	}
}

void setInputPolarity(InputSignal input, SignalPolarity polarity)
{
	input_polarities[input] = polarity;
}

void setOutput(OutputSignal output, SignalState out_state)
{
	// Set Corresponding Pin on Board
	board.setOutput(mapOutput(output), (PinState)out_state);
}

