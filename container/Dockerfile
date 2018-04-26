FROM ubuntu:xenial

MAINTAINER jordy

# Mise à jour de la distro
RUN apt-get update

# Installation des bibliothèques
RUN apt-get install odb libodb-2.4 libodb-mysql-2.4 -y \
    && apt-get install libmysql++3v5 libmysqlclient20 libmysqlcppconn7v5 -y \
    && apt-get install --fix-missing \
    # Installation des outils de build
    && apt-get install cmake make -y \
    && apt-get install gcc g++ -y \
    # Purge
    && apt-get clean autoclean \
    && rm /var/cache/apt/archives/* -dr


# Création des repertoires de code
RUN mkdir /home/cbanking
WORKDIR /home/cbanking

# Récupération des codes sources
ADD http://172.17.0.1/~jordy/github/github.tar.gz .

# Décompression et néttoyage
RUN tar -xzf *.tar.gz

# Compilation de googletest
WORKDIR /home/cbanking/googletest
RUN cmake -G Unix\ Makefiles . \
  && make \
  && make install \
  && make clean


# Compilation de libsodium
WORKDIR /home/cbanking/libsodium
RUN ./configure \
    && make \
    && make install \
    && make clean

# Compilation de pistache
WORKDIR /home/cbanking/pistache
RUN cmake -G Unix\ Makefiles . \
  && make \
  && make install \
  && make clean

# Compilation de rapidjson
WORKDIR /home/cbanking/rapidjson
RUN cmake -G Unix\ Makefiles . \
  && make \
  && make install \
  && make clean

# installation de plog
WORKDIR /home/cbanking/plog
RUN cp -R include/plog /usr/local/include/

WORKDIR /home/cbanking

ENV HOST_NAME   http://localhost
ENV PORT        8181

# installation de cbanking
ADD http://172.17.0.1/~jordy/cbanking.tar.gz .
RUN tar -xzf cbanking.tar.gz
RUN rm *.tar.gz

VOLUME /home/cbanking/resources

RUN printf "#!/bin/bash\n./cbanking ${HOST_NAME} ${PORT}" > entrypoint.sh \
        && chmod +x entrypoint.sh

ENTRYPOINT ["./entrypoint.sh"]
