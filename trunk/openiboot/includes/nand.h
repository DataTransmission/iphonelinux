#ifndef NAND_H
#define NAND_H

#include "openiboot.h"

#define ERROR_ARG 0x80010000
#define ERROR_NAND 0x80020000
#define ERROR_TIMEOUT 0x1F
#define ERROR_ECC 0x17
#define ERROR_BADBLOCK 0x1

typedef struct NANDDeviceType {
	uint32_t id;
	uint16_t blocksPerBank;
	uint16_t pagesPerBlock;
	uint16_t sectorsPerPage;
	uint16_t bytesPerSpare;
	uint8_t NANDSetting2;
	uint8_t NANDSetting1;
	uint8_t NANDSetting3;
	uint8_t NANDSetting4;
	uint32_t userSubBlksTotal;
	uint32_t unk3;
	uint32_t unk4;
} NANDDeviceType;

typedef struct NANDData {
	uint32_t field_0;
	uint16_t field_4;
	uint16_t sectorsPerPage;
	uint16_t pagesPerBlock;
	uint16_t pagesPerSubBlk;
	uint32_t pagesPerBank;
	uint32_t pagesTotal;
	uint16_t subBlksTotal;
	uint16_t userSubBlksTotal;
	uint32_t userPagesTotal;
	uint16_t blocksPerBank;
	uint16_t bytesPerPage;
	uint16_t bytesPerSpare;
	uint16_t field_22;
	uint32_t field_24;
	uint32_t DeviceID;
	uint16_t banksTotal;
	uint8_t field_2E;
	uint8_t field_2F;
} NANDData;

int nand_setup();
int nand_read(int bank, int page, uint8_t* buffer, uint8_t* spare, int doECC, int checkBadBlocks);
NANDData* nand_get_geometry();

#endif
