# Kokuban Kernel for Xiaomi 17 (NetHunter Edition)

<p align="center">
  <img src="https://img.shields.io/badge/NETHUNTER-%23B71C1C?style=for-the-badge&logo=kali-linux&logoColor=white&labelColor=000000" 
       alt="NetHunter" width="280">
</p>

<p align="center">
<a href="https://github.com/Picters/android_kernel_xiaomi_sm8850_nethunter/releases"><img src="https://img.shields.io/github/v/release/Picters/android_kernel_xiaomi_sm8850_nethunter?style=for-the-badge&logo=github&color=blue" alt="GitHub release"></a>
<img src="https://img.shields.io/badge/Fork%20of-YuzakiKokuban-orange.svg?style=for-the-badge&logo=github" alt="Fork notice">
</p>

> This is a fork maintained by **Picters**. All credit for the original kernel base goes to the upstream Kokuban project.

## Device

Xiaomi 17 Series (NetHunter Edition).

## What This Fork Changes

This fork adds **NetHunter-friendly** kernel configuration on top of the stable Kokuban base:

- Wi-Fi packet injection (monitor mode)
- Support for popular external USB Wi-Fi adapters (Atheros, Realtek, Ralink, MediaTek)
- Bluetooth USB dongles (including BLE attacks)
- USB RNDIS / Ethernet gadget attacks
- SDR / RTL-SDR subsystems
- Serial devices (Silicon Labs CP210x, CH341)
- USB Mass Storage and CAN bus support

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

## Disclaimer

Use at your own risk. Always backup your data.
