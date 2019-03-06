#!/bin/sh

a=5

until [ $a -lt 5 ]
do
   echo $a
   a=`expr $a + 1`
done
