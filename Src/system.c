#include "system.h"
//#include "graphic.h"
#include "flash.h"
#include "hcms2915.h"
#include "cmsis_os.h"

RTC_HandleTypeDef hrtc;

static RTC_TimeTypeDef	rtcTime;
static RTC_DateTypeDef	rtcDate;

static eSystemState			eCurrentSysState;
static eSettingsState		eCurrentSettingsState;

extern ADC_HandleTypeDef hadc;

void	System_GetDateTimeFromRTC(void);

void System_Init()
{	
	hrtc.Instance = RTC;
	hrtc.Init.HourFormat = RTC_HOURFORMAT_24;
	hrtc.Init.AsynchPrediv = 127;
	hrtc.Init.SynchPrediv = 255;
	hrtc.Init.OutPut = RTC_OUTPUT_DISABLE;
	hrtc.Init.OutPutPolarity = RTC_OUTPUT_POLARITY_HIGH;
	hrtc.Init.OutPutType = RTC_OUTPUT_TYPE_OPENDRAIN;
			
	if (HAL_RTC_Init(&hrtc) != HAL_OK)
	{
		_Error_Handler(__FILE__, __LINE__);
	}
		
	System_SetState(SYS_TIME);
	System_SetSettingsState(SELECT_TIME);
	
}

void System_Process()
{
	System_GetDateTimeFromRTC();
	
	GPIO_PinState pinState = HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_0);
	
	
}


void System_EnterStandBy()
{
	HCMS_On(1);
	osDelay(500);	
	HAL_PWR_DisableWakeUpPin(PWR_WAKEUP_PIN1);
	__HAL_PWR_CLEAR_FLAG(PWR_FLAG_WU);	
	HAL_PWR_EnableWakeUpPin(PWR_WAKEUP_PIN1);
	HAL_PWR_EnterSTANDBYMode();
}

 void	System_GetDateTimeFromRTC()
{
	HAL_RTC_GetTime(&hrtc,&rtcTime,RTC_FORMAT_BIN);
	HAL_RTC_GetDate(&hrtc,&rtcDate, RTC_FORMAT_BIN);
	
	
}

RTC_TimeTypeDef *System_GetRTCTime()
{
	return &rtcTime;
}

RTC_DateTypeDef *System_GetRTCDate()
{	
	return &rtcDate;	
}

void System_SetState(eSystemState State)
{
	eCurrentSysState = State;
}
eSystemState	System_GetState(void){return eCurrentSysState;}

void System_SetSettingsState(eSettingsState State)
{
	eCurrentSettingsState = State;
}
eSettingsState	System_GetSettingsState(void){return eCurrentSettingsState;}

