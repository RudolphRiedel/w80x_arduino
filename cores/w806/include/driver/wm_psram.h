#ifndef __WM_PSRAM_H__
#define __WM_PSRAM_H__

#include "wm_hal.h"

#define PSRAM_ADDR_START          0x30000000

#define PSRAM	((PSRAM_TypeDef *)PSRAM_BASE)

typedef struct
{
	uint32_t Div;
	uint32_t Mode;
	
} PSRAM_InitTypeDef;

typedef struct
{
	PSRAM_TypeDef                   *Instance;
	PSRAM_InitTypeDef               Init;
	
} PSRAM_HandleTypeDef;

#define PSRAM_MODE_SPI		(PSRAM_CR_SPI_EN)
#define PSRAM_MODE_QSPI		(PSRAM_CR_QUAD_EN)

#define IS_PSRAM_INSTANCE(INSTANCE)	((INSTANCE) == PSRAM)
#define IS_PSRAM_DIV(DIV)			(((DIV) > 2) && ((DIV) <= 0x0F))
#define IS_PSRAM_MODE(MODE)			(((MODE) == PSRAM_MODE_SPI) || ((MODE == PSRAM_MODE_QSPI)))

#ifdef __cplusplus
extern "C"{
#endif

HAL_StatusTypeDef HAL_PSRAM_Init(PSRAM_HandleTypeDef *hpsram);
HAL_StatusTypeDef HAL_PSRAM_DeInit(PSRAM_HandleTypeDef *hpsram);
void HAL_PSRAM_MspInit(PSRAM_HandleTypeDef *hpsram);
void HAL_PSRAM_MspDeInit(PSRAM_HandleTypeDef *hpsram);

#ifdef __cplusplus
}
#endif

#endif
