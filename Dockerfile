FROM redbug26/cptc-docker:latest

LABEL Version="1.0" \
      Date="2019-Dec-24" \
      Docker_Version="19.12.24 (1)" \
      Maintainer="RedBug (@kyuran)" \
      Description="A basic Docker container to cross-compile win32 exe (with SDL)"

ENV TERM="xterm" DEBIAN_FRONTEND="noninteractive" TZ="Europe/London"

RUN apt-get update \
	&& apt-get install -y git php

COPY crazyamp /tmp/crazyamp

ENV PATH="/src/bin:/tmp/crazyamp/bin:${PATH}"

WORKDIR /src/
