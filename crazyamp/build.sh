#!/bin/bash

PROJECT=crazyamp

# Don't modify code after this line

cd /tmp/$PROJECT

CFLAGS="--fomit-frame-pointer --allow-unsafe-read"
CODELOC=0x400

cd song
find . -type f -name "*.s" -exec sh -c 'sdasz80 -o -l -s ../obj/`basename -s .s "{}"`.rel {}' \;
cd ..

cd src
find . -type f -name "*.s" -exec sh -c 'sdasz80 -o -l -s ../obj/`basename -s .s "{}"`.rel {}' \;
cd ..

cd src
find . -type f -name "*.c" -exec sdcc -c -mz80 ${CFLAGS} -I ../include/ {} -o ../obj/ \;
cd ..

sdcc -mz80 ${CFLAGS} -o crazyamp.ihx --code-loc $CODELOC --data-loc 0 --no-std-crt0 obj/*.rel

hex2bin -p 00 crazyamp.ihx > crazyamp.log

LOADADDR=`sed -n 's/^Lowest address  = 0000\([0-9]*\).*$/\1/p' <crazyamp.log`
RUNADDR=`sed -n 's/^ *0000\([0-9A-F]*\) *_main  *.*$/\1/p' <crazyamp.map`

echo "-- Binary summary"
echo "Load addr: 0x"$LOADADDR
echo "Execute addr: 0x"$RUNADDR
echo "Code loc: " $CODELOC

# create the disk
iDSK ${PROJECT}.dsk -n >> main.log 2>> main.log

# import the game
iDSK ${PROJECT}.dsk -i crazyamp.bin -c $LOADADDR -e $RUNADDR -t 1 >> main.log 2>> main.log

# display the disk
echo
echo "-- Disk dump"

iDSK -l ${PROJECT}.dsk 

du -b crazyamp.bin

cp crazyamp.dsk /src
cp crazyamp.bin /src

# clean all the stuff
#make clean

# MiSTER
#scp ${PROJECT}.dsk root@192.168.1.116:/media/fat/Amstrad/

# RG350
#scp ${PROJECT}.dsk root@10.1.1.2:/media/sdcard/roms/amstrad/


