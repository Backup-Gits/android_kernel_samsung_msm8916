#!/bin/bash
# cleaning before a build
rm -rf $(pwd)/output
rm -rf $(pwd)/kernel-out
make clean
make mrproper

# Built info
S_VERSION=v1
S_DATE=$(date +%Y%m%d)

# Build the zImage
export ARCH=arm
export CROSS_COMPILE=$(pwd)/dragon/gcc-linaro-4.9.4-2017.01-x86_64_arm-eabi/bin/arm-eabi-
mkdir -p output kernel-out/pack/rd kernel-out/zip/dragon/modules kernel-out/zip/dragon/kernel
make -C $(pwd) O=output msm8916_sec_defconfig VARIANT_DEFCONFIG=msm8916_sec_j5xlte_eur_defconfig SELINUX_DEFCONFIG=selinux_defconfig
make -j`grep processor /proc/cpuinfo|wc -l` -C $(pwd) O=output

# copy the built zImage
cp output/arch/arm/boot/zImage $(pwd)/kernel-out/pack/zImage

# DTS packing
./tools/dtbTool -v -s 2048 -o ./kernel-out/pack/dts ./output/arch/arm/boot/dts/

# Packing the ramdisk
cp -r dragon/ramdisk/J5FN/* kernel-out/pack/rd
cd $(pwd)/kernel-out/pack/rd
mkdir -p data dev oem proc sys system
# set all directories to 0755 by default
find -type d -exec chmod 755 {} \;
# set all files to 0644 by default
find -type f -exec chmod 644 {} \;
# scripts should be 0750
find -name "*.rc" -exec chmod 750 {} \;
find -name "*.sh" -exec chmod 750 {} \;
# init and everything in /sbin should be 0750
chmod -Rf 750 init sbin
chmod 771 data
find | fakeroot cpio -o -H newc | gzip -9 > ../kernel-ramdisk.gz
cd ../../../

# Generating a bootable image
./dragon/mkbootimg --kernel ./kernel-out/pack/zImage \
				--ramdisk ./kernel-out/pack/kernel-ramdisk.gz \
				--cmdline "console=null androidboot.hardware=qcom user_debug=23 msm_rtb.filter=0x3F ehci-hcd.park=3 androidboot.bootdevice=7824900.sdhci" \
				--base 80000000 \
				--pagesize 2048 \
				--kernel_offset 00008000 \
				--ramdisk_offset 02000000 \
				--tags_offset 01e00000 \
				--dt ./kernel-out/pack/dts \
				--output $(pwd)/kernel-out/zip/dragon/kernel/boot.img

# ENFORCE the new generated image
echo -n "SEANDROIDENFORCE" >> $(pwd)/kernel-out/zip/dragon/kernel/boot.img

# Pack everything into a zip
cp -r $(pwd)/dragon/META-INF $(pwd)/kernel-out/zip/
cp -r $(pwd)/dragon/libsecure $(pwd)/kernel-out/zip/dragon/modules/
cp -r $(pwd)/dragon/libsecure_jni $(pwd)/kernel-out/zip/dragon/modules/
cp -r $(pwd)/dragon/wlan $(pwd)/kernel-out/zip/dragon/modules/
cd kernel-out/zip
zip -r -9 - * > ../"DRAGON-SMJ510FN-$S_VERSION-$S_DATE.zip"
cd ../../

# END
