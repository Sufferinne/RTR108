#!/bin/sh

a=-5

while [ $a -lt 10 ]
do
   echo $a
   if [ $a -eq 8 ]
   then
      break
   fi
   a=`expr $a + 1`
done
