/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.c
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "math.h"
#include "string.h"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "sd_hal_mpu6050.h"
/* USER CODE END Includes */
/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
I2C_HandleTypeDef hi2c1;
I2C_HandleTypeDef hi2c2;

UART_HandleTypeDef huart1;

/* USER CODE BEGIN PV */
SD_MPU6050 mpu;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_I2C1_Init(void);
static void MX_I2C2_Init(void);
static void MX_USART1_UART_Init(void);
/* USER CODE BEGIN PFP */
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
/**
 * @brief  The application entry point.
 * @retval int
 */
int main(void)
{
	/* USER CODE BEGIN 1 */
	SD_MPU6050_Result result, result2;
	int i2cs[2] = {&hi2c2,&hi2c1};
	int cont;
	char str[8],resp='a';
	int16_t acelerometro_x,acelerometro_y,acelerometro_z;
	int16_t giroscopio_x,giroscopio_y,giroscopio_z;
	/*
	float angle_pitch1, angle_roll1;
	float angle_pitch2, angle_roll2;
	long acelerometro1_x_aux,acelerometro1_y_aux,acelerometro1_z_aux;
	long giroscopio1_x_aux,giroscopio1_y_aux,giroscopio1_z_aux;
	long acelerometro2_x_aux,acelerometro2_y_aux,acelerometro2_z_aux;
	long giroscopio2_x_aux,giroscopio2_y_aux,giroscopio2_z_aux;
	 */
	//float angle_pitch_acc,angle_roll_acc,acc_total_vector;
	//float temperatura;
	//int16_t g_x[2][2],g_y[2][2],g_z[2][2];
	//double teta,psi,phi;
	//char t[4],ps[4],ph[4];

	HAL_Init();
	/* USER CODE BEGIN Init */
	/* USER CODE END Init */
	/* Configure the system clock */
	SystemClock_Config();
	/* USER CODE BEGIN SysInit */
	/* USER CODE END SysInit */
	/* Initialize all configured peripherals */
	MX_GPIO_Init();
	MX_I2C1_Init();
	MX_I2C2_Init();
	MX_USART1_UART_Init();
	HAL_Delay(10000);
	HAL_UART_Transmit(&huart1,(uint8_t *)"\nBem vindo(a) a FistFenzy versão beta. \nDigite i para começar.",64, 100);
	while(resp != 'i'){
		HAL_UART_Receive(&huart1,&resp,1,100);
	}
	/* USER CODE BEGIN 2 */
	/*
  HAL_UART_Transmit(&huart1,(uint8_t *)"Repouse sua mão sobre uma superficie plana e com a outra ligue o dispositivo",78, 100);


  for(cont = 0;cont<1000;++cont){
		  result  = SD_MPU6050_Init(&hi2c1,&mpu,SD_MPU6050_Device_0,SD_MPU6050_Accelerometer_2G,SD_MPU6050_Gyroscope_250s);
		  result2 = SD_MPU6050_Init(&hi2c2,&mpu,SD_MPU6050_Device_0,SD_MPU6050_Accelerometer_2G,SD_MPU6050_Gyroscope_250s);
		  SD_MPU6050_ReadAll(&hi2c2,&mpu);
		  acelerometro1_x_aux  += mpu.Accelerometer_X;
		  acelerometro1_y_aux  += mpu.Accelerometer_Y;
		  acelerometro1_z_aux  += mpu.Accelerometer_Z;
		  giroscopio1_x_aux    += mpu.Gyroscope_X;
		  giroscopio1_y_aux    += mpu.Gyroscope_Y;
		  giroscopio1_z_aux    += mpu.Gyroscope_Z;
		  SD_MPU6050_ReadAll(&hi2c1,&mpu);
		  acelerometro2_x_aux  += mpu.Accelerometer_X;
		  acelerometro2_y_aux  += mpu.Accelerometer_Y;
		  acelerometro2_z_aux  += mpu.Accelerometer_Z;
		  giroscopio2_x_aux    += mpu.Gyroscope_X;
		  giroscopio2_y_aux    += mpu.Gyroscope_Y;
		  giroscopio2_z_aux    += mpu.Gyroscope_Z;
		  if(!(cont%100))HAL_UART_Transmit(&huart1,(uint8_t *)".",3, 100);

  }
	  acelerometro1_x_aux  /= 1000;
	  acelerometro1_y_aux  /= 1000;
	  acelerometro1_z_aux  /= 1000;
	  giroscopio1_x_aux    /= 1000;
	  giroscopio1_y_aux    /= 1000;
	  giroscopio1_z_aux    /= 1000;
	  acelerometro2_x_aux  /= 1000;
	  acelerometro2_y_aux  /= 1000;
	  acelerometro2_z_aux  /= 1000;
	  giroscopio2_x_aux    /= 1000;
	  giroscopio2_y_aux    /= 1000;
	  giroscopio2_z_aux    /= 1000;
	  HAL_UART_Transmit(&huart1,(uint8_t *)"Concluido",11, 100);
	 */
	/* USER CODE END 2 */

	/* Infinite loop */
	/* USER CODE BEGIN WHILE */
	while (1)
	{
		for(cont = 0; cont < 2;++cont){
			result  = SD_MPU6050_Init(i2cs[cont],&mpu,SD_MPU6050_Device_0,SD_MPU6050_Accelerometer_2G,SD_MPU6050_Gyroscope_250s);
			SD_MPU6050_ReadAll(i2cs[cont],&mpu);
			acelerometro_x  = mpu.Accelerometer_X;
			acelerometro_y  = mpu.Accelerometer_Y;
			acelerometro_z  = mpu.Accelerometer_Z;
			giroscopio_x    = mpu.Gyroscope_X;
			giroscopio_y    = mpu.Gyroscope_Y;
			giroscopio_z    = mpu.Gyroscope_Z;
			if(cont == 0){
				HAL_UART_Transmit(&huart1,(uint8_t *)"\n ==== PALMA DA MÃO ==== ",28, 100);
			}else{
				HAL_UART_Transmit(&huart1,(uint8_t *)"\n ==== DEDO ",12, 100);
				itoa(cont,str ,10);
				HAL_UART_Transmit(&huart1,(uint8_t *)str, strlen(str),100);
				HAL_UART_Transmit(&huart1,(uint8_t *)" ==== ",8, 100);
			}
			itoa(acelerometro_x,str ,10);
			HAL_UART_Transmit(&huart1,(uint8_t *)"\n Ax = ",8, 100); HAL_UART_Transmit(&huart1,(uint8_t *)str,strlen(str),100);
			HAL_Delay(50);
			itoa(acelerometro_y,str,10);
			HAL_UART_Transmit(&huart1,(uint8_t *)" |Ay = ",7, 100);  HAL_UART_Transmit(&huart1,(uint8_t *)str, strlen(str),100);
			HAL_Delay(50);
			itoa(acelerometro_z,str,10);
			HAL_UART_Transmit(&huart1,(uint8_t *)" |Az = ",7, 100);  HAL_UART_Transmit(&huart1,(uint8_t *)str, strlen(str),100);
			HAL_Delay(50);
			itoa(giroscopio_x,str,10);
			HAL_UART_Transmit(&huart1,(uint8_t *)"\n Gx = ",8, 100); HAL_UART_Transmit(&huart1,(uint8_t *)str, strlen(str),100);
			HAL_Delay(50);
			itoa(giroscopio_y,str,10);
			HAL_UART_Transmit(&huart1,(uint8_t *)" |Gy = ",7, 100);  HAL_UART_Transmit(&huart1,(uint8_t *)str, strlen(str),100);
			HAL_Delay(50);
			itoa(giroscopio_z,str,10);
			HAL_UART_Transmit(&huart1,(uint8_t *)" |Gz = ",7, 100);  HAL_UART_Transmit(&huart1,(uint8_t *)str, strlen(str),100);
			HAL_Delay(50);
			HAL_Delay(1000);

		}
		/*
		result  = SD_MPU6050_Init(&hi2c1,&mpu,SD_MPU6050_Device_0,SD_MPU6050_Accelerometer_2G,SD_MPU6050_Gyroscope_250s);
		result2 = SD_MPU6050_Init(&hi2c2,&mpu,SD_MPU6050_Device_0,SD_MPU6050_Accelerometer_2G,SD_MPU6050_Gyroscope_250s);
		SD_MPU6050_ReadAll(&hi2c2,&mpu);

		SD_MPU6050_ReadAll(&hi2c1,&mpu);
		acelerometro_x  = mpu.Accelerometer_X;
		acelerometro_y  = mpu.Accelerometer_Y;
		acelerometro_z  = mpu.Accelerometer_Z;
		giroscopio_x    = mpu.Gyroscope_X;
		giroscopio_y    = mpu.Gyroscope_Y;
		giroscopio_z    = mpu.Gyroscope_Z;*/
		/*
	  //Gyro angle calculations . Note 0.0000611 = 1 / (250Hz x 65.5)
	  angle_pitch1 = giroscopio1_x * 0.0000611;
	  angle_roll1  = giroscopio1_x * 0.0000611;
	  //0.000001066 = 0.0000611 * (3.142(PI) / 180degr) The Arduino sin function is in radians
	  angle_pitch1 += angle_roll1 * sin(giroscopio1_z* 0.000001066);
	  angle_roll1 -= angle_pitch1 * sin(giroscopio1_z * 0.000001066);
	  acc_total_vector = sqrt((acelerometro1_x*acelerometro1_x)+(acelerometro1_y*acelerometro1_y)+(acelerometro1_z*acelerometro1_z));  //Calculate the total accelerometer vector
	 //57.296 = 1 / (3.142 / 180) The Arduino asin function is in radians
	  angle_pitch_acc = asin((float)acelerometro1_y/acc_total_vector)* 57.296;       //Calculate the pitch angle
	  angle_roll_acc = asin((float)acelerometro1_x/acc_total_vector)* -57.296;
		 */
		/*
	  itoa(acelerometro_x,str ,10);
	  HAL_UART_Transmit(&huart1,(uint8_t *)"\n Ax = ",8, 100); HAL_UART_Transmit(&huart1,(uint8_t *)str,strlen(str),100);
	  HAL_Delay(50);
	  itoa(acelerometro_y,str,10);
	  HAL_UART_Transmit(&huart1,(uint8_t *)" |Ay = ",7, 100);  HAL_UART_Transmit(&huart1,(uint8_t *)str, strlen(str),100);
	  HAL_Delay(50);
	  itoa(acelerometro_z,str,10);
	  HAL_UART_Transmit(&huart1,(uint8_t *)" |Az = ",7, 100);  HAL_UART_Transmit(&huart1,(uint8_t *)str, strlen(str),100);
	  HAL_Delay(50);
	  itoa(giroscopio_x,str,10);
	  HAL_UART_Transmit(&huart1,(uint8_t *)"\n Gx = ",8, 100); HAL_UART_Transmit(&huart1,(uint8_t *)str, strlen(str),100);
	  HAL_Delay(50);
	  itoa(giroscopio_y,str,10);
	  HAL_UART_Transmit(&huart1,(uint8_t *)" |Gy = ",7, 100);  HAL_UART_Transmit(&huart1,(uint8_t *)str, strlen(str),100);
	  HAL_Delay(50);
	  itoa(giroscopio_z,str,10);
	  HAL_UART_Transmit(&huart1,(uint8_t *)" |Gz = ",7, 100);  HAL_UART_Transmit(&huart1,(uint8_t *)str, strlen(str),100);
	  HAL_Delay(50);

	  /*
	  char buffer[16];
	  int i = 15;
		//  HAL_UART_Transmit(&huart1, (uint8_t*)buffer, sprintf(buffer, "%d", i), 500);
		//	HAL_UART_Transmit(&huart1,(uint8_t *)"TITULAR: Thierry\nAPARTAMENTO: 2\nEntrada Liberada\n\n",52, 100);
    	/* USER CODE END WHILE */
		/*
	for(dedo = 0;dedo < 1 ;++dedo){
		  	  for(cont = 0; cont<2;++cont){
				  SD_MPU6050_ReadAccelerometer(i2cs[dedo],&mpu);
				  g_x[dedo][cont] = mpu.Accelerometer_X - ajuste;
				  HAL_UART_Transmit(&huart1, (uint8_t*)buffer, sprintf(buffer, "%d\n", g_x), 500);
				  g_y[dedo][cont] = mpu.Accelerometer_Y - ajuste;
				  HAL_UART_Transmit(&huart1, (uint8_t*)buffer, sprintf(buffer, "%d\n", g_y), 500);
				  g_z[dedo][cont] = mpu.Accelerometer_Z - a;
				  HAL_UART_Transmit(&huart1, (uint8_t*)buffer, sprintf(buffer, "%d\n", g_z), 500);
		  	  }

			  HAL_Delay(125);
	  }
	  for(dedo = 0; dedo <1;++dedo){
		  teta = atan(g_x[dedo][0] / sqrt(pow(g_y[dedo][0], 2) + pow(g_z[dedo][0], 2))) * (180 / PI) - atan(g_x[dedo][1] / sqrt(pow(g_y[dedo][1], 2) + pow(g_z[dedo][1], 2))) * (180 / PI);
		  psi  = atan(g_y[dedo][0] / sqrt(pow(g_x[dedo][0], 2) + pow(g_z[dedo][0], 2))) * (180 / PI)  - atan(g_y[dedo][1] / sqrt(pow(g_x[dedo][1], 2) + pow(g_z[dedo][1], 2))) * (180 / PI);
		  phi  = atan(sqrt(pow(g_x[dedo][0],2)+pow(g_y[dedo][0],2))/g_z[dedo][0])*(180/PI) - atan(sqrt(pow(g_x[dedo][1],2)+pow(g_y[dedo][1],2))/g_z[dedo][1])*(180/PI);
		  ftoa(teta,&t,2);
		  ftoa(psi,&ps,2);
		  ftoa(phi,&ph,2);
	  }
	  //int_to_string(g_x, valueStr, 4);
	  //strcopy(msg, valueStr, 44, 47);
	  //Add this value to the message
	  //}
    /* USER CODE BEGIN 3 */
	}
	/* USER CODE END 3 */
}
/**
 * @brief System Clock Configuration
 * @retval None
 */
void SystemClock_Config(void)
{
	RCC_OscInitTypeDef RCC_OscInitStruct = {0};
	RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

	/** Initializes the CPU, AHB and APB busses clocks
	 */
	RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
	RCC_OscInitStruct.HSIState = RCC_HSI_ON;
	RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
	RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
	if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
	{
		Error_Handler();
	}
	/** Initializes the CPU, AHB and APB busses clocks
	 */
	RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
			|RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
	RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
	RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
	RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

	if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
	{
		Error_Handler();
	}
}

/**
 * @brief I2C1 Initialization Function
 * @param None
 * @retval None
 */
static void MX_I2C1_Init(void)
{

	/* USER CODE BEGIN I2C1_Init 0 */

	/* USER CODE END I2C1_Init 0 */

	/* USER CODE BEGIN I2C1_Init 1 */

	/* USER CODE END I2C1_Init 1 */
	hi2c1.Instance = I2C1;
	hi2c1.Init.ClockSpeed = 100000;
	hi2c1.Init.DutyCycle = I2C_DUTYCYCLE_2;
	hi2c1.Init.OwnAddress1 = 0;
	hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
	hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
	hi2c1.Init.OwnAddress2 = 0;
	hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
	hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
	if (HAL_I2C_Init(&hi2c1) != HAL_OK)
	{
		Error_Handler();
	}
	/* USER CODE BEGIN I2C1_Init 2 */

	/* USER CODE END I2C1_Init 2 */

}

/**
 * @brief I2C2 Initialization Function
 * @param None
 * @retval None
 */
static void MX_I2C2_Init(void)
{

	/* USER CODE BEGIN I2C2_Init 0 */

	/* USER CODE END I2C2_Init 0 */

	/* USER CODE BEGIN I2C2_Init 1 */

	/* USER CODE END I2C2_Init 1 */
	hi2c2.Instance = I2C2;
	hi2c2.Init.ClockSpeed = 100000;
	hi2c2.Init.DutyCycle = I2C_DUTYCYCLE_2;
	hi2c2.Init.OwnAddress1 = 0;
	hi2c2.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
	hi2c2.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
	hi2c2.Init.OwnAddress2 = 0;
	hi2c2.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
	hi2c2.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
	if (HAL_I2C_Init(&hi2c2) != HAL_OK)
	{
		Error_Handler();
	}
	/* USER CODE BEGIN I2C2_Init 2 */

	/* USER CODE END I2C2_Init 2 */

}

/**
 * @brief USART1 Initialization Function
 * @param None
 * @retval None
 */
static void MX_USART1_UART_Init(void)
{

	/* USER CODE BEGIN USART1_Init 0 */

	/* USER CODE END USART1_Init 0 */

	/* USER CODE BEGIN USART1_Init 1 */

	/* USER CODE END USART1_Init 1 */
	huart1.Instance = USART1;
	huart1.Init.BaudRate = 9600;
	huart1.Init.WordLength = UART_WORDLENGTH_8B;
	huart1.Init.StopBits = UART_STOPBITS_1;
	huart1.Init.Parity = UART_PARITY_NONE;
	huart1.Init.Mode = UART_MODE_TX_RX;
	huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	huart1.Init.OverSampling = UART_OVERSAMPLING_16;
	if (HAL_UART_Init(&huart1) != HAL_OK)
	{
		Error_Handler();
	}
	/* USER CODE BEGIN USART1_Init 2 */

	/* USER CODE END USART1_Init 2 */

}

/**
 * @brief GPIO Initialization Function
 * @param None
 * @retval None
 */
static void MX_GPIO_Init(void)
{

	/* GPIO Ports Clock Enable */
	__HAL_RCC_GPIOB_CLK_ENABLE();
	__HAL_RCC_GPIOA_CLK_ENABLE();

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
 * @brief  This function is executed in case of error occurrence.
 * @retval None
 */
void Error_Handler(void)
{
	/* USER CODE BEGIN Error_Handler_Debug */
	/* User can add his own implementation to report the HAL error return state */

	/* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
 * @brief  Reports the name of the source file and the source line number
 *         where the assert_param error has occurred.
 * @param  file: pointer to the source file name
 * @param  line: assert_param error line source number
 * @retval None
 */
void assert_failed(uint8_t *file, uint32_t line)
{ 
	/* USER CODE BEGIN 6 */
	/* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
	/* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

