#ifndef __MAIN_H__
#define __MAIN_H__

/* Includes ------------------------------------------------------------------*/

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private define ------------------------------------------------------------*/

#define BAT_ADC_IN_Pin GPIO_PIN_2
#define BAT_ADC_IN_GPIO_Port GPIOA
#define LCD_EN_Pin GPIO_PIN_4
#define LCD_EN_GPIO_Port GPIOA
#define BAT_STAT_Pin GPIO_PIN_8
#define BAT_STAT_GPIO_Port GPIOA
#define LCD_RS_Pin GPIO_PIN_11 
#define LCD_RS_GPIO_Port GPIOA
#define LCD_RESET_Pin GPIO_PIN_8
#define LCD_RESET_GPIO_Port GPIOB

 
#ifdef __cplusplus
 extern "C" {
#endif
void _Error_Handler(char *, int);

#define Error_Handler() _Error_Handler(__FILE__, __LINE__)
#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H__ */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
