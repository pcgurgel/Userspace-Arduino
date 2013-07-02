#!/bin/bash

# SETTING UP SSH KEYS FOR YOUR BOARD (Required for password-less login)
# cd ~/.ssh
# ssh-keygen -t dsa
# ssh-copy-id -i ~/.ssh/id_dsa.pub $USERNAME@$IP
# ssh $USERNAME@$IP

# COMMAND LINE ARGUMENTS
# ./send_exec.sh source.c

# A bash script to helloworld.bin to beagleboard and return the output
IP="192.168.7.2"
USERNAME="root"
FILE=$1
EXECUTABLE=$FILE.bin
echo $FILE 
echo $EXECUTABLE
arm-angstrom-linux-gnueabi-gcc $FILE -o $EXECUTABLE

 echo "ls
 put "$EXECUTABLE"
 exit" > commands.tmp

  sftp -b commands.tmp $USERNAME@$IP
  ssh $USERNAME@$IP -t "./"$EXECUTABLE



# IGNORE THIS

# Installing GNU Netcat from source
# wget http://kaz.dl.sourceforge.net/project/netcat/netcat/0.7.1/netcat-0.7.1.tar.gz
# tar xzvf netcat-0.7.1.tar.gz 
# cd netcat-0.7.1/
# ./configure 
# make
# make check
# sudo make install
# make clean
# sudo apt-get install sshpass
