/*
******************************************************************************
	application.cpp
	VCU1200_Base
	Erik Stafl
	1/23/2015

	Written for Tiva TM4C123BH6PGE
	Language: C++

	Copyright (c) 2013-2016 Stafl Systems, LLC.  All rights reserved.
******************************************************************************
*/

#include "application.h"

// Main Application Object
Application application;

// Reference to Board Object
extern VCU1200_Board board;

Application::Application()
{
}
//string Application::LED[14] = {"LED1", "LED2", "LED3","LED4","LED5","LED6","LED7","LED8","LED9","LED10","LED11","LED12","LED13","LED14"};

void Application::initialize()
{
	// Set CAN Termination Resistor Setting
	board.setCANTermination(CAN_1, CAN_1_TERMINATION);
	board.setCANTermination(CAN_2, CAN_2_TERMINATION);

	// Initialize Inputs for this Application
	initializeInputs();

	// Initialize CAN Receive
	initializeCANReceive();

	// Set Initial State to Startup
	changeState(STARTUP);
}

void Application::tick()
{
	// Process State Machine
	processState();

	//Blink the Lights With User Input
	calculateLEDS();

	// Send CAN Data
	sendCANData();

	// Increment Counters
	incrementCounters();
}

//blinkLights Action for the LightsOn State
void Application::calculateLEDS()
{
	if (state == SYSTEM_ON)
	{
/*		//ON
		float OFF_LEDS;
		for(int i = 0; i < potentiometer_command; i++)
		{
			setOutput(static_cast<OutputSignal>(LED[i]), ON);
		}
		//OFF LEDS
		OFF_LEDS = 14 - potentiometer_command;
		for(int i = 0; i < OFF_LEDS; i++)
		{
			setOutput(LED[i], OFF);
		}*/

		//potentiometer_command = getAnalogInput(POTENTIOMETER);
		if(potentiometer_command == 14)
		{
			setOutput(LED1, ON);
			setOutput(LED2, ON);
			setOutput(LED3, ON);
			setOutput(LED4, ON);
			setOutput(LED5, ON);
			setOutput(LED6, ON);
			setOutput(LED7, ON);
			setOutput(LED8, ON);
			setOutput(LED9, ON);
			setOutput(LED10, ON);
			setOutput(LED11, ON);
			setOutput(LED12, ON);
			setOutput(LED13, ON);
			setOutput(LED14, ON);
		}
		else if(potentiometer_command == 13)
		{
			setOutput(LED1, ON);
			setOutput(LED2, ON);
			setOutput(LED3, ON);
			setOutput(LED4, ON);
			setOutput(LED5, ON);
			setOutput(LED6, ON);
			setOutput(LED7, ON);
			setOutput(LED8, ON);
			setOutput(LED9, ON);
			setOutput(LED10, ON);
			setOutput(LED11, ON);
			setOutput(LED12, ON);
			setOutput(LED13, ON);
			setOutput(LED14, OFF);
		}
		else if(potentiometer_command == 12)
		{
			setOutput(LED1, ON);
			setOutput(LED2, ON);
			setOutput(LED3, ON);
			setOutput(LED4, ON);
			setOutput(LED5, ON);
			setOutput(LED6, ON);
			setOutput(LED7, ON);
			setOutput(LED8, ON);
			setOutput(LED9, ON);
			setOutput(LED10, ON);
			setOutput(LED11, ON);
			setOutput(LED12, ON);
			setOutput(LED13, OFF);
			setOutput(LED14, OFF);
		}
		else if(potentiometer_command == 11)
		{
			setOutput(LED1, ON);
			setOutput(LED2, ON);
			setOutput(LED3, ON);
			setOutput(LED4, ON);
			setOutput(LED5, ON);
			setOutput(LED6, ON);
			setOutput(LED7, ON);
			setOutput(LED8, ON);
			setOutput(LED9, ON);
			setOutput(LED10, ON);
			setOutput(LED11, ON);
			setOutput(LED12, OFF);
			setOutput(LED13, OFF);
			setOutput(LED14, OFF);
		}
		else if(potentiometer_command == 10)
		{
			setOutput(LED1, ON);
			setOutput(LED2, ON);
			setOutput(LED3, ON);
			setOutput(LED4, ON);
			setOutput(LED5, ON);
			setOutput(LED6, ON);
			setOutput(LED7, ON);
			setOutput(LED8, ON);
			setOutput(LED9, ON);
			setOutput(LED10, ON);
			setOutput(LED11, OFF);
			setOutput(LED12, OFF);
			setOutput(LED13, OFF);
			setOutput(LED14, OFF);
		}
		else if(potentiometer_command == 9)
		{
			setOutput(LED1, ON);
			setOutput(LED2, ON);
			setOutput(LED3, ON);
			setOutput(LED4, ON);
			setOutput(LED5, ON);
			setOutput(LED6, ON);
			setOutput(LED7, ON);
			setOutput(LED8, ON);
			setOutput(LED9, ON);
			setOutput(LED10, OFF);
			setOutput(LED11, OFF);
			setOutput(LED12, OFF);
			setOutput(LED13, OFF);
			setOutput(LED14, OFF);
		}
		else if(potentiometer_command == 8)
		{
			setOutput(LED1, ON);
			setOutput(LED2, ON);
			setOutput(LED3, ON);
			setOutput(LED4, ON);
			setOutput(LED5, ON);
			setOutput(LED6, ON);
			setOutput(LED7, ON);
			setOutput(LED8, ON);
			setOutput(LED9, OFF);
			setOutput(LED10, OFF);
			setOutput(LED11, OFF);
			setOutput(LED12, OFF);
			setOutput(LED13, OFF);
			setOutput(LED14, OFF);
		}
		else if(potentiometer_command == 7)
		{
			setOutput(LED1, ON);
			setOutput(LED2, ON);
			setOutput(LED3, ON);
			setOutput(LED4, ON);
			setOutput(LED5, ON);
			setOutput(LED6, ON);
			setOutput(LED7, ON);
			setOutput(LED8, OFF);
			setOutput(LED9, OFF);
			setOutput(LED10, OFF);
			setOutput(LED11, OFF);
			setOutput(LED12, OFF);
			setOutput(LED13, OFF);
			setOutput(LED14, OFF);
		}
		else if(potentiometer_command == 6)
		{
			setOutput(LED1, ON);
			setOutput(LED2, ON);
			setOutput(LED3, ON);
			setOutput(LED4, ON);
			setOutput(LED5, ON);
			setOutput(LED6, ON);
			setOutput(LED7, OFF);
			setOutput(LED8, OFF);
			setOutput(LED9, OFF);
			setOutput(LED10, OFF);
			setOutput(LED11, OFF);
			setOutput(LED12, OFF);
			setOutput(LED13, OFF);
			setOutput(LED14, OFF);
		}
		else if(potentiometer_command == 5)
		{
			setOutput(LED1, ON);
			setOutput(LED2, ON);
			setOutput(LED3, ON);
			setOutput(LED4, ON);
			setOutput(LED5, ON);
			setOutput(LED6, OFF);
			setOutput(LED7, OFF);
			setOutput(LED8, OFF);
			setOutput(LED9, OFF);
			setOutput(LED10, OFF);
			setOutput(LED11, OFF);
			setOutput(LED12, OFF);
			setOutput(LED13, OFF);
			setOutput(LED14, OFF);
		}
		else if(potentiometer_command == 4)
		{
			setOutput(LED1, ON);
			setOutput(LED2, ON);
			setOutput(LED3, ON);
			setOutput(LED4, ON);
			setOutput(LED5, OFF);
			setOutput(LED6, OFF);
			setOutput(LED7, OFF);
			setOutput(LED8, OFF);
			setOutput(LED9, OFF);
			setOutput(LED10, OFF);
			setOutput(LED11, OFF);
			setOutput(LED12, OFF);
			setOutput(LED13, OFF);
			setOutput(LED14, OFF);
		}
		else if(potentiometer_command == 3)
		{
			setOutput(LED1, ON);
			setOutput(LED2, ON);
			setOutput(LED3, ON);
			setOutput(LED4, OFF);
			setOutput(LED5, OFF);
			setOutput(LED6, OFF);
			setOutput(LED7, OFF);
			setOutput(LED8, OFF);
			setOutput(LED9, OFF);
			setOutput(LED10, OFF);
			setOutput(LED11, OFF);
			setOutput(LED12, OFF);
			setOutput(LED13, OFF);
			setOutput(LED14, OFF);
		}
		else if(potentiometer_command == 2)
		{
			setOutput(LED1, ON);
			setOutput(LED2, ON);
			setOutput(LED3, OFF);
			setOutput(LED4, OFF);
			setOutput(LED5, OFF);
			setOutput(LED6, OFF);
			setOutput(LED7, OFF);
			setOutput(LED8, OFF);
			setOutput(LED9, OFF);
			setOutput(LED10, OFF);
			setOutput(LED11, OFF);
			setOutput(LED12, OFF);
			setOutput(LED13, OFF);
			setOutput(LED14, OFF);
		}
		else if(potentiometer_command == 1)
		{
			setOutput(LED1, ON);
			setOutput(LED2, OFF);
			setOutput(LED3, OFF);
			setOutput(LED4, OFF);
			setOutput(LED5, OFF);
			setOutput(LED6, OFF);
			setOutput(LED7, OFF);
			setOutput(LED8, OFF);
			setOutput(LED9, OFF);
			setOutput(LED10, OFF);
			setOutput(LED11, OFF);
			setOutput(LED12, OFF);
			setOutput(LED13, OFF);
			setOutput(LED14, OFF);
		}
		else if(potentiometer_command == 0)
		{
			setOutput(LED1, OFF);
			setOutput(LED2, OFF);
			setOutput(LED3, OFF);
			setOutput(LED4, OFF);
			setOutput(LED5, OFF);
			setOutput(LED6, OFF);
			setOutput(LED7, OFF);
			setOutput(LED8, OFF);
			setOutput(LED9, OFF);
			setOutput(LED10, OFF);
			setOutput(LED11, OFF);
			setOutput(LED12, OFF);
			setOutput(LED13, OFF);
			setOutput(LED14, OFF);
		}
	}
}

void Application::changeState(SystemState new_state)
{
	switch (new_state)
	{
	case STARTUP:
		//Set Default Actions for this state
		setOutput(LED1, OFF);
		setOutput(LED2, OFF);
		setOutput(LED3, OFF);
		setOutput(LED4, OFF);
		setOutput(LED5, OFF);
		setOutput(LED6, OFF);
		setOutput(LED7, OFF);
		setOutput(LED8, OFF);
		setOutput(LED9, OFF);
		setOutput(LED10, OFF);
		setOutput(LED11, OFF);
		setOutput(LED12, OFF);
		setOutput(LED13, OFF);
		setOutput(LED14, OFF);


		// Bootloader is OK in this State
		board.setBootloaderSafe(true);

		// Override is OK in this State
		board.setOutputOverrideSafe(true);
		break;

	case SYSTEM_OFF:
		//Set Default Actions for this state
		setOutput(LED1, OFF);
		setOutput(LED2, OFF);
		setOutput(LED3, OFF);
		setOutput(LED4, OFF);
		setOutput(LED5, OFF);
		setOutput(LED6, OFF);
		setOutput(LED7, OFF);
		setOutput(LED8, OFF);
		setOutput(LED9, OFF);
		setOutput(LED10, OFF);
		setOutput(LED11, OFF);
		setOutput(LED12, OFF);
		setOutput(LED13, OFF);
		setOutput(LED14, OFF);


		setOutput(POTENTIOMETER_5V, OFF);

		// Bootloader is OK in this State
		board.setBootloaderSafe(true);

		// Override is OK in this State
		board.setOutputOverrideSafe(true);
		break;

	case SYSTEM_ON:
		//Analog Controlled Lights
		//Actions Defined in calculateLEDS function called in tick() function

		setOutput(POTENTIOMETER_5V, ON);


		// Bootloader is OK in this State
		board.setBootloaderSafe(true);

		// Override is OK in this State
		board.setOutputOverrideSafe(true);
		break;
	}
	// Update Current State
	state = new_state;

	// Reset State Counter every 1 second
	state_counter = 0;
}

void Application::incrementCounters()
{
	state_counter++;
	// Parent Class Function
	CANReceiver::incrementCounters();
}



void Application::initializeCANReceive()
{
	// Temporary Mailbox for Setup
	tCANMsgObject can_rx_message;

	// Setup Receive Messages on CAN Interface

	// Messages from MiniMon
	can_rx_message.ui32MsgID = 0x300;
	can_rx_message.ui32MsgIDMask = 0x700;
	can_rx_message.ui32Flags = MSG_OBJ_RX_INT_ENABLE | MSG_OBJ_USE_ID_FILTER;
	board.can.can_1.initializeReceiveMessage(this, &can_rx_message);

}

bool Application::receiveCANMessage(CANPort can_port, tCANMsgObject* message, unsigned int mailbox)
{
	// True if Message has been Processed
	bool processed = false;

	//int16_t stemp;

	// 0-8 Userinput Lights to Turn on
	if (message->ui32MsgID == 0x300)
	{
		potentiometer_command = message->pui8MsgData[0];

		processed = true;
	}

	if (processed)
	{
		last_message_counter = 0;
		message_received = true;
	}

	return processed;
}

void Application::sendCANData()
{
	uint16_t utemp;
	//int16_t stemp;

	// CAN Message Object for Transmission
	CANMessage msg(CANMessage::ID_STANDARD, CANMessage::DATA_FRAME, 8);

	// Every 1 second
	if (board.getStartupCounter() % 100 == 0)
	{
		//MESSAGE # 1 Primary System Status (ID 0x200)
		msg.setID(0x200);
		msg.setLength(1);

		// Current Analog Voltage Input
		utemp = getAnalogInput(POTENTIOMETER);
		//msg.getData()[1] = utemp >> 8;
		msg.getData()[0] = utemp;

		// Send Message
		board.can.sendMessage(CAN_1, &msg);

/*		//MESSAGE #2 Program Status (ID 0x201)
		msg.setID(0x201);
		msg.setLength(2);

		// On/Off Input Status
		msg.getData()[1] = getInput(ON_OFF_SWTICH);
		// Command Reference
		msg.getData()[0] = current_command.command_reference;

		// Send Message
		board.can.sendMessage(CAN_1, &msg);*/

/*		//MESSAGE#3 XY Stage Commanded Position (ID 0x212)
		msg.setID(0x212);
		msg.setLength(8);

		// X Commanded Position
		msg.getData()[7] = x_axis.getCommandedPosition() >> 24;
		msg.getData()[6] = x_axis.getCommandedPosition() >> 16;
		msg.getData()[5] = x_axis.getCommandedPosition() >> 8;
		msg.getData()[4] = x_axis.getCommandedPosition();
		// Y Commanded Position
		msg.getData()[3] = y_axis.getCommandedPosition() >> 24;
		msg.getData()[2] = y_axis.getCommandedPosition() >> 16;
		msg.getData()[1] = y_axis.getCommandedPosition() >> 8;
		msg.getData()[0] = y_axis.getCommandedPosition();

		// Send Message
		board.can.sendMessage(CAN_1, &msg);*/

/*		//MESSAGE #4 Input States (ID 0x250)
		msg.setID(0x250);
		msg.setLength(6);

		// Reserved
		msg.getData()[5] = 0xFF;
		// Joystick Position
		msg.getData()[4] = joystick;
		// Turn Knob Position
		msg.getData()[3] = turn_knob;
		// Input States 3
		msg.getData()[2] = secondary_vcu.getInput(SecondaryVCU::FOOT_PEDAL_1);
		msg.getData()[2] |= secondary_vcu.getInput(SecondaryVCU::FOOT_PEDAL_2) 		<< 1;
		msg.getData()[2] |= secondary_vcu.getInput(SecondaryVCU::X_HLFP) 			<< 2;
		msg.getData()[2] |= secondary_vcu.getInput(SecondaryVCU::Y_HLFP) 			<< 3;
		msg.getData()[2] |= secondary_vcu.getInput(SecondaryVCU::LEFT_ELECTRODE_SW) << 4;
		msg.getData()[2] |= secondary_vcu.getInput(SecondaryVCU::RIGHT_ELECTRODE_SW) << 5;
		// Input States 2
		msg.getData()[1] = getInput(WELDER_GOOD);
		msg.getData()[1] |= getInput(WELDER_NG)										<< 1;
		msg.getData()[1] |= getInput(WELDER_END)									<< 2;
		msg.getData()[1] |= getInput(WELDER_CAUTION)								<< 3;
		msg.getData()[1] |= getInput(WELDER_COUNT_UP)								<< 4;
		msg.getData()[1] |= getInput(WELDER_READY)									<< 5;
		msg.getData()[1] |= getInput(START_BUTTONS)									<< 6;
		msg.getData()[1] |= secondary_vcu.getInput(SecondaryVCU::LIGHT_CURTAIN_IN)	<< 7;
		// Input States 1
		msg.getData()[0] = getInput(KEYSWITCH);
		msg.getData()[0] |= getInput(YELLOW_BUTTON)									<< 1;
		msg.getData()[0] |= getInput(BLUE_BUTTON)									<< 2;
		msg.getData()[0] |= getInput(E_STOP)										<< 3;
		msg.getData()[0] |= getInput(X_POS_LIMIT)									<< 4;
		msg.getData()[0] |= getInput(X_NEG_LIMIT)									<< 5;
		msg.getData()[0] |= getInput(Y_POS_LIMIT)									<< 6;
		msg.getData()[0] |= getInput(Y_NEG_LIMIT)									<< 7;

		// Send Message
		board.can.sendMessage(CAN_1, &msg);*/
	}
}


void Application::processState()
{
	switch (state)
	{
	case STARTUP:
		if (state_counter >= MIN_STATE_TIME)
		{
			changeState(SYSTEM_OFF);
		}
		break;

	case SYSTEM_OFF:
		if(state_counter >= MIN_STATE_TIME)
		{
			if(getInput(ON_OFF_SWITCH))
			{
				changeState(SYSTEM_ON);
			}
		}
		break;

	case SYSTEM_ON:
		if(state_counter >= MIN_STATE_TIME)
		{
			if(!getInput(ON_OFF_SWITCH))
			{
				changeState(SYSTEM_OFF);
			}
		}
		break;
	}
}
