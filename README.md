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

If you're like me and want to develop in an IDE we can setup automatic upload without re-attaching!
Just specify a custom executable where the working directory is the build dir of the project.
Make sure to use picotool >= 1.1 for that.

```bash
/usr/bin/picotool load rpiPICOStarter.uf2 -f
```