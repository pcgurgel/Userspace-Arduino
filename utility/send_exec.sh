#!/bin/bash


# COMMAND LINE ARGUMENTS
# ./send_exec.sh arduinofile

# A bash script to upload an executable binary to beagleboard and return the output

IP="192.168.7.2"
USERNAME="root"
FILE=$1
EXECUTABLE=${FILE}.elf

scp build-userspace/${EXECUTABLE} ${USERNAME}@${IP}:~/${FILE}
ssh ${USERNAME}@${IP}
#ssh ${USERNAME}@${IP} -t "./"${EXECUTABLE}

return_result=$?

if [ ${return_result} = 130 ] ; then
    exit 0
fi

