FROM powerc/pistache:latest

MAINTAINER jordy

# Installation des bibliothèques

RUN  apt-get install odb libodb-2.4 libodb-mysql-2.4 --no-install-recommends -y \
    && apt-get install libmysql++3v5 libmysqlclient20 libmysqlcppconn7v5 --no-install-recommends -y \
    && apt-get install --fix-missing \
    # Installation des outils de build
    && apt-get install gcc --no-install-recommends -y \
    # Purge
    && apt-get clean autoclean \
    && rm /var/cache/apt/archives/* -dr


# Création des repertoires de code
RUN mkdir /home/cbanking
WORKDIR /home/cbanking

# Récupération des codes sources
ADD https://github.com/Tencent/rapidjson/archive/v1.1.0.tar.gz .
ADD https://github.com/jedisct1/libsodium/releases/download/1.0.16/libsodium-1.0.16.tar.gz .
ADD https://github.com/SergiusTheBest/plog/archive/1.1.3.tar.gz .
ADD https://github.com/BlackPowerC/cbanking_rest_api/archive/latest.tar.gz .
ADD https://github.com/BlackPowerC/googletest/archive/release-1.8.0.tar.gz .

# Décompression et néttoyage
RUN tar -xzf v1.1.0.tar.gz \
  && tar -xzf libsodium-1.0.16.tar.gz \ 
  && tar -xzf 1.1.3.tar.gz \
  && tar -xzf latest.tar.gz \
  && tar -xzf release-1.8.0.tar.gz

# Compilation de libsodium
WORKDIR /home/cbanking/libsodium-1.0.16
RUN ./configure \
    && make \
    && make install \
    && make clean

# Compilation de rapidjson
WORKDIR /home/cbanking/rapidjson-1.1.0
RUN cmake -G Unix\ Makefiles . \
  && make \
  && make install \
  && make clean

# Compilation de googletest
WORKDIR /home/cbanking/googletest-release-1.8.0
RUN cmake -G Unix\ Makefiles . \
  && make \
  && make install \
  && make clean

# installation de plog
WORKDIR /home/cbanking/plog-1.1.3
RUN cp -R include/plog /usr/local/include/

# installation de cbanking
WORKDIR /home/cbanking/cbanking_rest_api-latest
RUN cmake -G Unix\ Makefiles . && make

# Création d'un entrypoint
RUN printf "#!/bin/bash\n ./cbanking_rest_api 8181\n" > entrypoint.sh

# Cleanup
WORKDIR /home/cbanking
RUN apt-get autoremove --purge g++ make gcc cmake -y
RUN rm *.tar.gz googletest-release-1.8.0 rapidjson-1.1.0 libsodium-1.0.16

EXPOSE 8181

ENTRYPOINT ["./home/cbanking/cbanking_rest_api-latest/entrypoint.sh"]

CMD ["bash"]