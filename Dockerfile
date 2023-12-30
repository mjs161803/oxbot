FROM dustynv/ros:humble-desktop-l4t-r32.7.1

RUN apt-key adv --keyserver keys.gnupg.net --recv-key F6E65AC044F831AC80A06380C8B3A55A6F3EFCDE || sudo apt-key adv --keyserver hkp://keyserver.ubuntu.com:80 --recv-key F6E65AC044F831AC80A06380C8B3A55A6F3EFCDE && \
add-apt-repository "deb https://librealsense.intel.com/Debian/apt-repo bionic main" -u && \
apt-get -y install librealsense2-utils && \
apt-get -y install librealsense2-dev
