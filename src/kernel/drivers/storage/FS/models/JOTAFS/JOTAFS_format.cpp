#include <kernel/drivers/storage/FS/models/JOTAFS/JOTAFS.hpp>

// TODO: THIS SHOULD NOT BE PART OF THE FILESYSTEM IMPLEMENTATION, BUT AN INDEPENDENT PROGRAM.
void JOTAFS_model::format() {
	SUPERBLOCK sb;
	sb.signature = 0x000CACADEBACA000;

	/*
		TODO: Once I have entropy, this should be a random number.
	*/
	sb.UUID = 0x0123456789ABCDEF;

	/*
		I have no idea what number of inodes to choose.
		Let's just say, for instance, that 1/32th of the
		total size will be dedicated to inodes.
		In that case, we get the number of inodes as the total sectors
		divided by 32, but multiplied by JOTAFS_INODES_PER_SECTOR.
	*/
	sb.n_inodes = (getMaxSector() * JOTAFS_INODES_PER_SECTOR) / 32;

	/*
		We'll set the first_free_inode to 1. The installer will later
		create the necessary inodes in order.
	*/
	sb.first_free_inode = 1;

	sb.last_free_inode = sb.n_inodes;
	sb.s_first_bitmap = inode2sector(sb.last_free_inode)+1;
	sb.first_non_full_bitmap = 0;


	/*
		It's time to calculate the number of blocks and bitmap sectors.

		Let n be the number of blocks, and m the number of bitmaps.
		This way, we know that:
		n = m * ATA_SECTOR_SIZE
		Also, we have the following requirement:
		n + m <= sectors_left

		Substitute:
		m * (ATA_SECTOR_SIZE + 1) <= sectors_left
		Therefore:
		m <= sectors_left / (ATA_SECTOR_SIZE + 1)
		Approximating:
		m = lower(sectors_left / (ATA_SECTOR_SIZE + 1))
	*/
	uint32_t sectors_left = getMaxSector() - sb.s_first_bitmap;
	uint32_t n_bitmaps = sectors_left / (ATA_SECTOR_SIZE + 1);
	sb.s_first_block = sb.s_first_bitmap + n_bitmaps;
	sb.n_blocks = n_bitmaps * ATA_SECTOR_SIZE;
	// That's done. At this point we have the right numbers.


	// Write it to disk.
	writeSB(sb);

	// It's time to initialize the inodes.
	for(uint32_t i=1; i<=sb.n_inodes; i++) {
		FREE_INODE inodes[JOTAFS_INODES_PER_SECTOR];
		for(uint8_t j=0; j<JOTAFS_INODES_PER_SECTOR; j++) {
			inodes[j].used = 0;
			if(i != sb.n_inodes) {
				inodes[j].next = i+j+1;
			} else {
				inodes[j].next = 0;
				break;
			}
		}

		// Do not use writeInode. If we want to copy 4, this is more efficient.
		ide.ATA_write(driveid, inode2sector(i), 1, (uint8_t*)inodes);
		i += JOTAFS_INODES_PER_SECTOR-1;
	}

	// Initialize the bitmaps.
	uint8_t emptySector[512] = {0};
	ide.ATA_write(driveid, bitmap2sector(0), getNumberOfBitmaps(), emptySector);
}
