#!/bin/bash


# COMMAND LINE ARGUMENTS
# ./send_exec.sh arduinofile.ino

# A bash script to helloworld.bin to beagleboard and return the output

IP="192.168.7.2"
USERNAME="root"
FILE=$1
# FILE=${FILE%%\.*}
# EXECUTABLE=$FILE.elf

# make

# echo "ls
#  put build-userspace/"$EXECUTABLE"
#  exit" > commands.tmp

sftp -b commands.tmp $USERNAME@$IP
ssh $USERNAME@$IP #-t "./"$EXECUTABLE



