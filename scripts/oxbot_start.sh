#!/bin/bash

docker run --runtime nvidia -it --rm --network=host --privileged -v /dev/:/dev/ -v /home/oxbot_dev/git/oxbot:/root/oxbot -v /home/oxbot_dev/git/jetson-containers:/root/jetson-containers mjs161803/oxbot:ob2 /bin/bash
