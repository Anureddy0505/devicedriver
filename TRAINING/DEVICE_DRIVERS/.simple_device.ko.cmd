cmd_/home/km/MIRAFRA/TRAINING/DEVICE_DRIVERS/simple_device.ko := ld -r -m elf_x86_64  -z max-page-size=0x200000 -z noexecstack   --build-id  -T ./scripts/module-common.lds -o /home/km/MIRAFRA/TRAINING/DEVICE_DRIVERS/simple_device.ko /home/km/MIRAFRA/TRAINING/DEVICE_DRIVERS/simple_device.o /home/km/MIRAFRA/TRAINING/DEVICE_DRIVERS/simple_device.mod.o;  true