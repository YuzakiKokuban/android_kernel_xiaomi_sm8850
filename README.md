# Kokuban Kernel for Xiaomi 17 (NetHunter Edition)

<p align="center">
<img src="https://raw.githubusercontent.com/YuzakiKokuban/Kokuban_Kernel_CI_Center/main/docs/kokuban_logo.png" alt="Logo" width="150">
</p>

<p align="center">
<a href="https://github.com/Picters/android_kernel_xiaomi_sm8850_nethunter/releases"><img src="https://img.shields.io/github/v/release/Picters/android_kernel_xiaomi_sm8850_nethunter?style=for-the-badge&logo=github&color=blue" alt="GitHub release"></a>
<img src="https://img.shields.io/badge/Fork%20of-YuzakiKokuban-orange.svg?style=for-the-badge&logo=github" alt="Fork notice">
</p>

> This is a fork maintained by **Picters**. All credit for the original kernel base, tuning, and release infrastructure goes to the upstream Kokuban project. This fork adds a set of driver-level configuration changes on top of the original base to support external hardware commonly used with **Kali NetHunter**.

## Device

Xiaomi 17 Series (NetHunter Edition).

## What This Fork Changes

The upstream Kokuban kernel is built for stability and day-to-day performance. This fork keeps that base intact and layers on additional kernel configuration to enable external USB/wireless hardware that upstream does not enable by default, primarily for use with Kali NetHunter.

No scheduler, governor, or security-hardening changes from upstream have been altered beyond what upstream's own build pipeline already toggles per release mode.

## NetHunter Hardware Support Added

The following was enabled in `arch/arm64/configs/gki_defconfig` on top of the upstream config:

**Wi-Fi adapters (monitor mode / packet injection capable)**
- `CONFIG_CFG80211`, `CONFIG_CFG80211_WEXT`, `CONFIG_MAC80211` — core wireless stack required by the drivers below.
- `CONFIG_ATH9K_HTC` — Atheros AR9271-based USB adapters (e.g. Alfa AWUS036NHA, TP-Link TL-WN722N v1).
- `CONFIG_RTL8187` — Realtek RTL8187L-based USB adapters (e.g. older Alfa AWUS036H).

**USB Mass Storage & File Systems**
- `CONFIG_USB_CONFIGFS_MASS_STORAGE`, `CONFIG_USB_STORAGE`, `CONFIG_USB_UAS` — Enables core USB mass storage and USB Attached SCSI (UAS) capabilities for mounting high-speed external drives.
- `CONFIG_NTFS3_FS`, `CONFIG_EXFAT_FS`, `CONFIG_VFAT_FS` — Adds robust, native read/write filesystem support for modern USB flash drives and external hard disks.

**Serial / debug hardware**
- `CONFIG_USB_SERIAL_CP210X` — Silicon Labs CP210x USB-to-serial devices, commonly used by GPS dongles, HackRF companion boards, and Arduino-based tools.

**CAN bus (automotive hacking)**
- `CONFIG_CAN_GS_USB` — Geschwister Schneider / CANtact-compatible USB-CAN adapters, used with SocketCAN tooling.

**USB networking**
- `CONFIG_USB_NET_CDC_SUBSET` — USB Ethernet devices under the CDC subset class.
- `CONFIG_USB_NET_RNDIS_HOST` — RNDIS-based USB tethering/network devices.
- `CONFIG_NET_SLIP` — SLIP (Serial Line IP) tunneling over serial links.

**Diagnostics**
- `CONFIG_PACKET_DIAG` — raw `AF_PACKET` socket introspection (used by tools that inspect low-level network sockets, e.g. via `ss`).

**Media / SDR framework**
- `CONFIG_MEDIA_DIGITAL_TV_SUPPORT` — enables the DVB/digital-TV subsystem framework required by RTL-SDR-adjacent tuner drivers. Note: this enables the framework only; a matching tuner driver (e.g. `CONFIG_DVB_USB_RTL28XXU`) is required separately for actual RTL-SDR dongle detection.

## Release Variants

* **LKM (Loadable Kernel Module)**
  * No built-in root solution; intended for users who prefer a cleaner kernel environment.
  * If root access is required, patch and flash the device `init_boot` image manually through the KernelSU Manager App.

* **ReSuki (ReSukiSU)**
  * Ships with ReSukiSU integration and supports advanced capabilities such as `SUSFS` and `KPM`.
  * Recommended for users who need module extensibility, root hiding, or other advanced workflows.

> This project does not maintain the legacy built-in `KSU/MKSU` branch model, consistent with upstream.

## Installation

1. **Unlock the Bootloader** — make sure the device bootloader is already unlocked.
2. **Prepare a Recovery Environment** — a recent version of `TWRP` or `OrangeFox Recovery` is recommended.
3. **Flash the Kernel** — download the appropriate package from the [Releases page](https://github.com/Picters/android_kernel_xiaomi_sm8850_nethunter/releases) and flash the kernel `zip` through Recovery.
4. **LKM Builds Only: Patch `init_boot`** — back up your current `init_boot.img`, patch it with the KernelSU Manager App, then flash the patched image back to the `init_boot` partition using Fastboot or Recovery.
5. **Reboot the Device** — restart and verify the kernel is running as expected.

## Downloads

All builds from this fork are published on the [Releases page](https://github.com/Picters/android_kernel_xiaomi_sm8850_nethunter/releases).

## Credits

- Original kernel, base tuning, and CI infrastructure: [YuzakiKokuban](https://github.com/YuzakiKokuban)
- NetHunter driver configuration additions: Picters

## Disclaimer

Flashing custom kernels carries inherent risk. Back up your personal data before proceeding. Neither the original author nor the maintainer of this fork is responsible for any device damage or data loss resulting from the use of this kernel.
