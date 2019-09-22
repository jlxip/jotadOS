#ifndef ISO9660_H
#define ISO9660_H

#define ISO9660_ROOT_RECORD_OFFSET 156
#define ISO9660_DIR_RECORD_LENGTH 0
#define ISO9660_DIR_EAR_LBA 2
#define ISO9660_DIR_EAR_LENGTH 10
#define ISO9660_DIR_FILENAME_LENGTH 32
#define ISO9660_DIR_FILENAME 33

#include <common/types.h>

// It can be either a directory record or a file itself.
struct ISO9660_entity {
	uint16_t LBA;
	uint16_t length;
};

struct ISO9660_entity* ISO9660_get(char** dirs, uint8_t dirs_sz);
uint8_t* ISO9660_read(struct ISO9660_entity* entity);

#endif
