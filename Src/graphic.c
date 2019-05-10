#include "graphic.h"
#include "system.h"
#include "hcms2915.h"
#include "cmsis_os.h"
#include "adc.h"
#include "flash.h"

static RTC_TimeTypeDef	*currentTime;
static RTC_DateTypeDef	*currentDate;
	
uint32_t	uSettingScrollCnt;

uint8_t	uChangeFlag;

osThreadId graphicsTaskHandle;

void Graphic_Init()
{
	uSettingScrollCnt = 0;
	uChangeFlag = 0;
}

void Graphic_Process()
{
	eSystemState	currensSysState = System_GetState();
	tADCBattery		adcBattery = ADC_Battery();
	

	
	currentTime = System_GetRTCTime();
	currentDate = System_GetRTCDate();
	
	char strOutBuf[8]; 
	
	HCMS_Clear(); 

	if(currentTime->SubSeconds < 0x7F)
		sprintf(strOutBuf, "Аленка", 12);
	else
		sprintf(strOutBuf, "Пеленка", 21);	

	HCMS_PutStr(strOutBuf);   

	return;
}
void	Graphic_ResetSettingsScroll()
{
	
}

void 	Graphic_ScrollChangeCallback()
{
	if(uChangeFlag){uChangeFlag = 0;return;}
	if(!uChangeFlag){uChangeFlag = 1;return;}
}
