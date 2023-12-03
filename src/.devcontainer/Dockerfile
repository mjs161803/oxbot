FROM ros:galactic
ARG adam_dev=adam_dev
ARG USER_UID=1000
ARG USER_GID=$USER_UID

# Create the user
RUN groupadd --gid $USER_GID $adam_dev \
    && useradd --uid $USER_UID --gid $USER_GID -m $adam_dev \
    #
    # [Optional] Add sudo support. Omit if you don't need to install software after connecting.
    && apt-get update \
    && apt-get install -y sudo \
    && echo $adam_dev ALL=\(root\) NOPASSWD:ALL > /etc/sudoers.d/$adam_dev \
    && chmod 0440 /etc/sudoers.d/$adam_dev
RUN apt-get update && apt-get upgrade -y
RUN apt-get install -y python3-pip
ENV SHELL /bin/bash

# ********************************************************
# * Anything else you want to do like clean up goes here *
# ********************************************************

# [Optional] Set the default user. Omit if you want to keep the default as root.
USER $adam_dev
CMD ["/bin/bash"]