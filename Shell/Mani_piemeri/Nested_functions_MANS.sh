#!/bin/sh


# Calling one function from another
echo "Kads ir tavs milakais ediens?"
read EDIENS
number_one () {
   echo "Zvanam draugiem, lai uzzinat kur gatavo $EDIENS..."
   number_two
}

number_two () {
   echo "Draugi nezin kur gatavo $EDIENS."
}

# Calling function one.
number_one
