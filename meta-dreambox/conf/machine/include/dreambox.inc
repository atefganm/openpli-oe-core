# dreambox.inc
# We know about rtc
MACHINE_FEATURES_BACKFILL_CONSIDERED += "rtc"

EXTRA_IMAGEDEPENDS += "dreambox-secondstage-${MACHINE}"

MACHINE_ESSENTIAL_EXTRA_RDEPENDS += "\
	dreambox-boot-progress \
	dreambox-dvb-modules-${MACHINE} \
	${@bb.utils.contains_any("MACHINE", "dm8000 dm7020hd dm800sev2 dm500hdv2", "kernel-module-ecb", "", d)} \
	kernel-module-hmac \
	kernel-module-md4 \
	kernel-module-stv0299 \
	"

MACHINE_FEATURES += "alsa usbhost switchoff dreambox"

PREFERRED_PROVIDER_virtual/bootloader = "dreambox-secondstage-${MACHINE}"
PREFERRED_PROVIDER_virtual/kernel = "linux-dreambox"

PREFERRED_PROVIDER_virtual/blindscan-dvbs = "dreambox-blindscan-utils"
PREFERRED_PROVIDER_virtual/blindscan-dvbc = "dreambox-blindscan-utils"

KERNEL_IMAGETYPE = "vmlinux"
KERNEL_OUTPUT = "${KERNEL_IMAGETYPE}"
KERNEL_OUTPUT_DIR = "."
KERNEL_CONSOLE = "${@bb.utils.contains('MACHINE_FEATURES', 'usbconsole', 'ttyS0,115200', 'null', d)}"

DREAMBOX_BUILDIMAGE = "buildimage --arch ${MACHINE} ${EXTRA_BUILDCMD} \
	--erase-block-size ${DREAMBOX_ERASE_BLOCK_SIZE} \
	--flash-size ${DREAMBOX_FLASH_SIZE} \
	--sector-size ${DREAMBOX_SECTOR_SIZE}"
