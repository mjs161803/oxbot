#!/bin/bash

docker run --runtime nvidia -it --rm --network=host --privileged -v /dev/bus/usb:/dev/bus/usb -v /home/oxbot_dev/git/oxbot:/root/oxbot mjs161803/oxbot:latest /bin/bash
