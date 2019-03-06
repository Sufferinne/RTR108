#!/bin/bash
#jaizmanto expression  lai ierobezotu randomu skaitli
a=`expr $RANDOM % 10`
b=5
echo "$a $b"


if [ $a == $b ]
then
   echo "a ir vienads ar  b"
elif [ $a -gt $b ]
then
   echo "a ir lielaks par b"
elif [ $a -lt $b ]
then
   echo "a ir mazaks par  b"
else
   echo "Nesaprotu kas seit notiek"
fi
