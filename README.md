# Raspberry Pi Pico Setup

Install the sdk and picotool from AUR

```bash
# on archlinux with paru
paru -S pico-sdk picotool
```

Set up a udev rule for non-root access in BOOTSEL and RUN mode.

```bash
# lsusb and check it attrvendor and attrid are matching
sudo sh -c 'echo "SUBSYSTEM==\"usb\", ATTRS{idVendor}==\"2e8a\", ATTRS{idProduct}==\"0003\", MODE=\"0666\"
SUBSYSTEM==\"tty\", ATTRS{idVendor}==\"2e8a\", ATTRS{idProduct}==\"0003\", MODE=\"0666\"
SUBSYSTEM==\"tty\", ATTRS{idVendor}==\"2e8a\", ATTRS{idProduct}==\"000a\", MODE=\"0666\"
SUBSYSTEM==\"usb\", ATTRS{idVendor}==\"2e8a\", ATTRS{idProduct}==\"000a\", MODE=\"0666\"" > /etc/udev/rules.d/11-pico.rules'
```

We use `picotool` to upload to our device. If you want to upload to your
PICO, then execute the following command, or target, from your preferred
editor:

```
# Build and upload to the PICO
cmake --preset pico-starter; cmake --build build/starter --target rpi_upload_project
```

