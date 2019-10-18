#include <kernel/install/install.h>
#include <libc/stdio.h>
#include <libc/stdlib.h>
#include <kernel/drivers/term/term.h>
#include <kernel/drivers/storage/ATA_PIO/ATA_PIO.h>
#include <kernel/drivers/storage/ATAPI_PIO/ATAPI_PIO.h>
#include <kernel/drivers/storage/FS/ISO9660/ISO9660.h>
#include <kernel/drivers/storage/FS/JOTAFS/JOTAFS.h>

void install() {
	printf("%s", "You're booting from a CD!\n"
		"This means that you got jotadOS booting, which is quite cool.\n"
		"However, you won't be able to do anything but install the OS onto the hard disk.\n\n"
		"Note that you should ONLY be running jotadOS in a virtual machine,\n"
		"as it's incompatible with any other operating system.\n\n");

	// Check the drive is there.
	struct ATA_INTERFACE* primarymaster = newATA(1, 0x1F0);
	if(JOTAFS_init(primarymaster) != 0) {
		printf("You must insert an HDD into the primary master ATA drive.\n"
		"Then, please reboot.\n");
		while(1) {}
	}

	// Check if the disk is already formatted with JOTAFS.
	struct JOTAFS_SUPERBLOCK* currentSB = JOTAFS_readSB();
	if(currentSB->signature == 0x000CACADEBACA000) {
		printf("jotadOS seems to be already installed on the hard disk.\n"
			"Proceed with caution.\n\n"
		);
	}
	jfree(currentSB);

	printf("%s", "Now, write \"yes\" without quotes to install jotadOS into the\n"
		"primary master ATA drive. Any other input will stop the installation.\n\n");

	printf("-> ");
	showCursor();
	char* installInput = readLine();
	if(strcmp("yes", installInput) != 0) {
		// Stop!
		printf("\nInstallation stopped.\n");
		printf("You can reboot the machine now.\n");
		while(1) {}
	}

	printf("\nHere we go!\n");

	// Copy MBR.
	printf("Copying MBR... ");
	char* stage1_p[] = {"BOOT", "HDDS1.BIN"};
	struct ISO9660_entity* stage1_e = ISO9660_get(stage1_p, 2);
	if(!stage1_e) {
		printf("[FAILED]\n"
		"Couldn't find HDDS1.BIN in the BOOT directory of the CD.\n"
		"Installation stopped.\n"
		);
		while(1) {}
	}
	uint8_t* stage1 = ISO9660_read(stage1_e);
	jfree(stage1_e);
	JOTAFS_writeMBR(stage1);
	printf("[OK]\n");

	// Format disk.
	printf("Formatting disk... ");
	JOTAFS_format();
	printf("[OK]\n");

	// Copy JBoot's second stage.
	printf("Copying JBoot's second stage... ");
	char* stage2_p[] = {"BOOT", "HDDS2.BIN"};
	struct ISO9660_entity* stage2_e = ISO9660_get(stage2_p, 2);
	if(!stage2_e) {
		printf("[FAILED]\n"
		"Couldn't find HDDS2.BIN in the BOOT directory of the CD.\n"
		"Installation stopped."
		);
		while(1) {}
	}
	uint8_t* stage2 = ISO9660_read(stage2_e);
	JOTAFS_newfile(stage2_e->length, stage2, 0, 0, 0);
	jfree(stage2_e);
	printf("[OK]\n");

	// Copy the kernel.
	printf("Copying the kernel... ");
	char* kernel_p[] = {"BOOT", "KERNEL.BIN"};
	struct ISO9660_entity* kernel_e = ISO9660_get(kernel_p, 2);
	if(!kernel_e) {
		printf("[FAILED]\n"
		"This error is impossible.\n"
		);
		while(1) {}
	}
	/*
		The kernel is actually too big to be read by ISO9660_read.
		We have to read it granularly.
	*/
	uint8_t* kernel = jmalloc(kernel_e->length + 2048);
	ATAPI_granularread(1+(kernel_e->length / 2048), kernel_e->LBA, kernel);
	JOTAFS_newfile(kernel_e->length, kernel, 0, 0, 0);
	jfree(kernel);
	jfree(kernel_e);
	printf("[OK]\n");

	printf("\nInstallation successful!\nYou can reboot now.");
	while(1) {}
}
