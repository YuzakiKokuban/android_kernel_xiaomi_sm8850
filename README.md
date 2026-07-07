# Kokuban Kernel for Xiaomi 17 (NetHunter Edition)

<p align="center">
  <img src="https://img.shields.io/badge/NETHUNTER%20KERNEL-%23B71C1C?style=for-the-badge&logo=kali-linux&logoColor=white&labelColor=000000"
       alt="NetHunter Kernel" width="280">
</p>

<p align="center">
<a href="https://github.com/Picters/android_kernel_xiaomi_sm8850_nethunter/releases"><img src="https://img.shields.io/github/v/release/Picters/android_kernel_xiaomi_sm8850_nethunter?style=for-the-badge&logo=github&color=blue" alt="GitHub release"></a>
<img src="https://img.shields.io/badge/Fork%20of-YuzakiKokuban-orange.svg?style=for-the-badge&logo=github" alt="Fork notice">
<img src="https://img.shields.io/badge/UNOFFICIAL-NetHunter-critical.svg?style=for-the-badge" alt="Unofficial">
</p>

> This is a fork maintained by **Picters**. All credit for the original kernel base goes to the upstream Kokuban project.

## ⚠️ Unofficial Build Notice

**This is NOT an official Kali NetHunter kernel.** Kali publishes ~250 device-specific kernels through the official [NetHunter kernel builder](https://www.kali.org/docs/nethunter/nethunter-kernel-2-config-1/) and [GitLab kernel repository](https://gitlab.com/kalilinux/nethunter/kernels), each built and tested through Kali's own pipeline for that specific device.

This kernel is a **standard GKI base with KernelSU/ReSukiSU patches**, into which we've manually enabled the closest equivalent set of kernel config options (Wi-Fi injection stack, USB HID/gadget, Bluetooth, SDR, CAN bus, NFS, netfilter) that NetHunter's userspace tooling expects. It is, as far as we know, **the closest unofficial approximation** to a real NetHunter kernel for this specific device/SoC — but it has not gone through Kali's own patch/test pipeline, and some NetHunter features may behave differently or not work at all compared to an officially supported device.

If your device has an official NetHunter kernel listed on [nethunter.kali.org/kernels.html](https://nethunter.kali.org/kernels.html), use that instead for full support.

## Device

Xiaomi 17 Series (NetHunter Edition, unofficial).

## What This Fork Changes

This fork adds **NetHunter-friendly** kernel configuration on top of the stable Kokuban base:

- Wi-Fi packet injection (monitor mode) via CFG80211/MAC80211
- Support for popular external USB Wi-Fi adapters (Atheros, Realtek, Ralink, MediaTek) — including out-of-tree RTL8812AU/RTL8188EU/RTL8814AU built as external kernel modules
- Bluetooth USB dongles (including virtual HCI for BLE-related tooling)
- USB HID gadget (BadUSB-style keyboard emulation), Mass Storage, ACM, ECM, RNDIS gadget
- USB_ACM support for serial devices like Proxmark3
- SDR / RTL-SDR subsystem with RTL2832, Si2168, and ZD1301 tuner drivers
- NFS client/server support
- nftables (NF_TABLES) alongside legacy iptables
- CAN bus support (SocketCAN + USB-CAN adapters)
- Serial devices (Silicon Labs CP210x, CH341)
- Force module unload for stuck monitor-mode Wi-Fi drivers

## Release Variants

- **LKM** — Clean kernel (use KernelSU Manager for root)
- **ReSuki** — With ReSukiSU + advanced features (recommended)

## Installation

1. Unlock bootloader
2. Flash kernel zip via TWRP / OrangeFox
3. (LKM only) Patch `init_boot.img` with KernelSU Manager
4. Reboot

Downloads → [Releases page](https://github.com/Picters/android_kernel_xiaomi_sm8850_nethunter/releases)

## Credits

- Base kernel & CI: [YuzakiKokuban](https://github.com/YuzakiKokuban)
- NetHunter enhancements: Picters
- Official Kali NetHunter project (config reference, not affiliated): [kali.org/docs/nethunter](https://www.kali.org/docs/nethunter/)

## Disclaimer

This is an **unofficial, community-maintained** build and is **not affiliated with or endorsed by Offensive Security / Kali Linux**. Use at your own risk. Always backup your data.
