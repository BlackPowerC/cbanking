FROM ubuntu:xenial

MAINTAINER jordy

# Mise à jour de la distro
RUN apt-get update

# Installation des bibliothèques
RUN apt-get install odb libodb-2.4 libodb-mysql-2.4 -y
RUN apt-get install libmysql++3v5 libmysqlclient20 libmysqlcppconn7v5 -y
RUN apt-get install --fix-missing

# Installation des outils de build
RUN apt-get install cmake make -y
RUN apt-get install gcc g++ -y

# Purge
RUN apt-get clean autoclean
RUN rm /var/cache/apt/archives/* -dr

# Création des repertoires de code
RUN mkdir /home/cbanking
WORKDIR /home/cbanking

# Récupération des codes sources
ADD http://172.17.0.1/~jordy/github/github.tar.gz .

# Décompression et néttoyage
RUN tar -xzf *.tar.gz
RUN rm *.tar.gz

# Compilation de googletest
WORKDIR /home/cbanking/googletest
RUN cmake -G Unix\ Makefiles .
RUN make
RUN make install
RUN make clean


# Compilation de libsodium
WORKDIR /home/cbanking/libsodium
RUN ./configure
RUN make
RUN make install
RUN make clean

###############
#RUN cd ../  ##
###############

# Compilation de pistache
WORKDIR /home/cbanking/pistache
RUN cmake -G Unix\ Makefiles .
RUN make
RUN make install
RUN make clean

###############
RUN cd ../   ##
###############

# Compilation de rapidjson
WORKDIR /home/cbanking/rapidjson
RUN cmake -G Unix\ Makefiles .
RUN make
RUN make install
RUN make clean

# installation de plog
WORKDIR /home/cbanking/plog
RUN cp -R include/plog /usr/local/include/

###############
#RUN cd ../  ##
###############

WORKDIR /home/cbanking

# installation de cbanking
ADD http://172.17.0.1/~jordy/cbanking.tar.gz .
RUN tar -xzf cbanking.tar.gz

ENTRYPOINT ["/home/cbanking/cbanking/cbanking"]