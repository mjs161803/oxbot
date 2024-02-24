#!/bin/bash

docker run --runtime nvidia -it --rm --network=host --privileged -v /dev/:/dev/ -v /home/oxbot_dev/git/oxbot:/root/oxbot mjs161803/oxbot:latest /bin/bash
