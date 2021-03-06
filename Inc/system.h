#ifndef _SYSTEM_H
#define _SYSTEM_H

#include "stm32l0xx_hal.h"

#define DATE_SHOW_VALUE		2500
#define SLEEP_MODE_VALUE 	5000
#define LO_PRESS_TIME	100
#define HI_PRESS_TIME 1000
#define CHRG_WAIT_TIME	50

typedef enum
{
	SYS_TIME			 = 0x01,
	SYS_DATE	 		 = 0x02,
	SYS_SETTINGS	 = 0x03,
	SYS_SET_HOUR	= 0x04,
	SYS_SET_MIN = 0x05,
	SYS_SET_WEEK = 0x06,
	SYS_SET_DAY = 0x07,
	SYS_SET_MONTH = 0x08,
	SYS_SET_YEAR = 0x09,
	SYS_BAT 	= 0x0A,
	SYS_SET_BRIGHT = 0x0B
}eSystemState;

typedef enum
{
	SELECT_DEFAULT		= 0x00,
	SELECT_TIME		  	= 0x01,
	SELECT_DATE				= 0x02,
	SELECT_BRIGHT			= 0x03,
	SELECT_BAT 				= 0x04,
	SELECT_EXIT 			= 0x05,
}eSettingsState;

#define FIRST_SETTING SELECT_TIME
#define LAST_SETTING 	SELECT_EXIT


void System_Init(void);
void System_Process(void);
void System_SetState(eSystemState State);
void System_SetSettingsState(eSettingsState State);
void System_EnterStandBy(void);

RTC_TimeTypeDef *System_GetRTCTime(void);
RTC_DateTypeDef *System_GetRTCDate(void);

eSystemState		System_GetState(void);
eSettingsState	System_GetSettingsState(void);

#endif
