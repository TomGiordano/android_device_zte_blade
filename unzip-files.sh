#!/bin/sh

# Copyright (C) 2010 The Android Open Source Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

DEVICE=blade

mkdir -p ../../../vendor/zte/$DEVICE/proprietary
unzip -j -o ../../../${DEVICE}_update.zip system/bin/qmuxd -d ../../../vendor/zte/$DEVICE/proprietary/
chmod 755 ../../../vendor/zte/$DEVICE/proprietary/qmuxd
unzip -j -o ../../../${DEVICE}_update.zip system/bin/akmd2 -d ../../../vendor/zte/$DEVICE/proprietary/
chmod 755 ../../../vendor/zte/$DEVICE/proprietary/akmd2
unzip -j -o ../../../${DEVICE}_update.zip system/bin/CKPD-daemon -d ../../../vendor/zte/$DEVICE/proprietary/
chmod 755 ../../../vendor/zte/$DEVICE/proprietary/CPKD-daemon
unzip -j -o ../../../${DEVICE}_update.zip system/bin/hci_qcomm_init -d ../../../vendor/zte/$DEVICE/proprietary/
chmod 755 ../../../vendor/zte/$DEVICE/proprietary/hci_qcomm_init

unzip -j -o ../../../${DEVICE}_update.zip system/etc/init.qcom.bt.sh -d ../../../vendor/zte/$DEVICE/proprietary/

#Wifi
unzip -j -o ../../../${DEVICE}_update.zip system/wifi/ar6000.ko -d ../../../vendor/zte/$DEVICE/proprietary/
unzip -j -o ../../../${DEVICE}_update.zip system/wifi/regcode -d ../../../vendor/zte/$DEVICE/proprietary/
unzip -j -o ../../../${DEVICE}_update.zip system/wifi/data.patch.hw2_0.bin -d ../../../vendor/zte/$DEVICE/proprietary/
unzip -j -o ../../../${DEVICE}_update.zip system/wifi/athwlan.bin.z77 -d ../../../vendor/zte/$DEVICE/proprietary/
unzip -j -o ../../../${DEVICE}_update.zip system/wifi/athtcmd_ram.bin -d ../../../vendor/zte/$DEVICE/proprietary/

# EGL
unzip -j -o ../../../${DEVICE}_update.zip system/lib/egl/libEGL_adreno200.so -d ../../../vendor/zte/$DEVICE/proprietary/
unzip -j -o ../../../${DEVICE}_update.zip system/lib/egl/libGLESv2_adreno200.so -d ../../../vendor/zte/$DEVICE/proprietary/
unzip -j -o ../../../${DEVICE}_update.zip system/lib/egl/libGLESv1_CM_adreno200.so -d ../../../vendor/zte/$DEVICE/proprietary/
unzip -j -o ../../../${DEVICE}_update.zip system/lib/egl/libq3dtools_adreno200.so -d ../../../vendor/zte/$DEVICE/proprietary/

#RIL files
unzip -j -o ../../../${DEVICE}_update.zip system/lib/libgsl.so -d ../../../vendor/zte/$DEVICE/proprietary/
unzip -j -o ../../../${DEVICE}_update.zip system/lib/libril-qc-1.so -d ../../../vendor/zte/$DEVICE/proprietary/
unzip -j -o ../../../${DEVICE}_update.zip system/lib/libril-qcril-hook-oem.so -d ../../../vendor/zte/$DEVICE/proprietary/
unzip -j -o ../../../${DEVICE}_update.zip system/lib/libdiag.so -d ../../../vendor/zte/$DEVICE/proprietary/
unzip -j -o ../../../${DEVICE}_update.zip system/lib/liboncrpc.so -d ../../../vendor/zte/$DEVICE/proprietary/
unzip -j -o ../../../${DEVICE}_update.zip system/lib/libqmi.so -d ../../../vendor/zte/$DEVICE/proprietary/
unzip -j -o ../../../${DEVICE}_update.zip system/lib/libdsm.so -d ../../../vendor/zte/$DEVICE/proprietary/
unzip -j -o ../../../${DEVICE}_update.zip system/lib/libqueue.so -d ../../../vendor/zte/$DEVICE/proprietary/
unzip -j -o ../../../${DEVICE}_update.zip system/lib/libdll.so -d ../../../vendor/zte/$DEVICE/proprietary/
unzip -j -o ../../../${DEVICE}_update.zip system/lib/libcm.so -d ../../../vendor/zte/$DEVICE/proprietary/
unzip -j -o ../../../${DEVICE}_update.zip system/lib/libmmgsdilib.so -d ../../../vendor/zte/$DEVICE/proprietary/
unzip -j -o ../../../${DEVICE}_update.zip system/lib/libgsdi_exp.so -d ../../../vendor/zte/$DEVICE/proprietary/
unzip -j -o ../../../${DEVICE}_update.zip system/lib/libgstk_exp.so -d ../../../vendor/zte/$DEVICE/proprietary/
unzip -j -o ../../../${DEVICE}_update.zip system/lib/libwms.so -d ../../../vendor/zte/$DEVICE/proprietary/
unzip -j -o ../../../${DEVICE}_update.zip system/lib/libnv.so -d ../../../vendor/zte/$DEVICE/proprietary/
unzip -j -o ../../../${DEVICE}_update.zip system/lib/libwmsts.so -d ../../../vendor/zte/$DEVICE/proprietary/
unzip -j -o ../../../${DEVICE}_update.zip system/lib/libpbmlib.so -d ../../../vendor/zte/$DEVICE/proprietary/
unzip -j -o ../../../${DEVICE}_update.zip system/lib/libdss.so -d ../../../vendor/zte/$DEVICE/proprietary/
unzip -j -o ../../../${DEVICE}_update.zip system/lib/libauth.so -d ../../../vendor/zte/$DEVICE/proprietary/

unzip -j -o ../../../${DEVICE}_update.zip system/lib/hw/sensors.default.so -d ../../../vendor/zte/$DEVICE/proprietary/
unzip -j -o ../../../${DEVICE}_update.zip system/lib/libcamera.so -d ../../../vendor/zte/$DEVICE/proprietary/
unzip -j -o ../../../${DEVICE}_update.zip system/lib/libcamera_client.so -d ../../../vendor/zte/$DEVICE/proprietary/
unzip -j -o ../../../${DEVICE}_update.zip system/lib/liboemcamera.so -d ../../../vendor/zte/$DEVICE/proprietary/
unzip -j -o ../../../${DEVICE}_update.zip system/lib/libmmjpeg.so -d ../../../vendor/zte/$DEVICE/proprietary/
unzip -j -o ../../../${DEVICE}_update.zip system/lib/libmmipl.so -d ../../../vendor/zte/$DEVICE/proprietary/



(cat << EOF) | sed s/__DEVICE__/$DEVICE/g > ../../../vendor/zte/$DEVICE/$DEVICE-vendor-blobs.mk
# Copyright (C) 2010 The Android Open Source Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

# This file is generated by device/zte/__DEVICE__/unzip-files.sh - DO NOT EDIT

# All the blobs necessary for blade
PRODUCT_COPY_FILES += \\
    vendor/zte/__DEVICE__/proprietary/ar6000.ko:system/wifi/ar6000.ko \\
    vendor/zte/__DEVICE__/proprietary/regcode:system/wifi/regcode \\
    vendor/zte/__DEVICE__/proprietary/data.patch.hw2_0.bin:system/wifi/data.patch.hw2_0.bin \\
    vendor/zte/__DEVICE__/proprietary/athwlan.bin.z77:system/wifi/athwlan.bin.z77 \\
    vendor/zte/__DEVICE__/proprietary/athtcmd_ram.bin:system/wifi/athtcmd_ram.bin \\
    vendor/zte/__DEVICE__/proprietary/libEGL_adreno200.so:system/lib/egl/libEGL_adreno200.so \\
    vendor/zte/__DEVICE__/proprietary/libGLESv2_adreno200.so:system/lib/egl/libGLESv2_adreno200.so \\
    vendor/zte/__DEVICE__/proprietary/libGLESv1_CM_adreno200.so:system/lib/egl/libGLESv1_CM_adreno200.so \\
    vendor/zte/__DEVICE__/proprietary/libq3dtools_adreno200.so:system/lib/egl/libq3dtools_adreno200.so \\
    vendor/zte/__DEVICE__/proprietary/libgsl.so:system/lib//libgsl.so \\
    vendor/zte/__DEVICE__/proprietary/qmuxd:system/bin/qmuxd \\
    vendor/zte/__DEVICE__/proprietary/akmd2:system/bin/akmd2 \\
    vendor/zte/__DEVICE__/proprietary/CKPD-daemon:system/bin/CKPD-daemon \\
    vendor/zte/__DEVICE__/proprietary/libril-qc-1.so:system/lib/libril-qc-1.so \\
    vendor/zte/__DEVICE__/proprietary/libril-qcril-hook-oem.so:system/lib/libril-qcril-hook-oem.so \\
    vendor/zte/__DEVICE__/proprietary/libdiag.so:system/lib/libdiag.so \\
    vendor/zte/__DEVICE__/proprietary/init.qcom.bt.sh:system/etc/init.qcom.bt.sh \\
    vendor/zte/__DEVICE__/proprietary/liboncrpc.so:system/lib/liboncrpc.so \\
    vendor/zte/__DEVICE__/proprietary/libqmi.so:system/lib/libqmi.so \\
    vendor/zte/__DEVICE__/proprietary/libdsm.so:system/lib/libdsm.so \\
    vendor/zte/__DEVICE__/proprietary/libqueue.so:system/lib/libqueue.so \\
    vendor/zte/__DEVICE__/proprietary/libdll.so:system/lib/libdll.so \\
    vendor/zte/__DEVICE__/proprietary/libcm.so:system/lib/libcm.so \\
    vendor/zte/__DEVICE__/proprietary/libmmgsdilib.so:system/lib/libmmgsdilib.so \\
    vendor/zte/__DEVICE__/proprietary/libgsdi_exp.so:system/lib/libgsdi_exp.so \\
    vendor/zte/__DEVICE__/proprietary/libgstk_exp.so:system/lib/libgstk_exp.so \\
    vendor/zte/__DEVICE__/proprietary/libwms.so:system/lib/libwms.so \\
    vendor/zte/__DEVICE__/proprietary/libnv.so:system/lib/libnv.so \\
    vendor/zte/__DEVICE__/proprietary/libwmsts.so:system/lib/libwmsts.so \\
    vendor/zte/__DEVICE__/proprietary/libpbmlib.so:system/lib/libpbmlib.so \\
    vendor/zte/__DEVICE__/proprietary/libdss.so:system/lib/libdss.so \\
    vendor/zte/__DEVICE__/proprietary/libauth.so:system/lib/libauth.so \\
    vendor/zte/__DEVICE__/proprietary/sensors.default.so:system/lib/hw/sensors.default.so \\
    vendor/zte/__DEVICE__/proprietary/libcamera.so:obj/lib/libcamera.so \\
    vendor/zte/__DEVICE__/proprietary/libcamera.so:system/lib/libcamera.so \\
    vendor/zte/__DEVICE__/proprietary/libcamera_client.so:obj/lib/libcamera_client.so \\
    vendor/zte/__DEVICE__/proprietary/libcamera_client.so:system/lib/libcamera_client.so \\
    vendor/zte/__DEVICE__/proprietary/liboemcamera.so:system/lib/liboemcamera.so \\
    vendor/zte/__DEVICE__/proprietary/libmmjpeg.so:system/lib/libmmjpeg.so \\
    vendor/zte/__DEVICE__/proprietary/libmmipl.so:system/lib/libmmipl.so \\
    vendor/zte/__DEVICE__/proprietary/hci_qcomm_init:system/bin/hci_qcomm_init

EOF

./setup-makefiles.sh
