#!/bin/sh

# Definesim funkciju seit
Hello () {
   echo "Hello World $1 $2"
   return 2
}

# Funkcijas izeja
Hello John Egbert

# Atgriezisana pie pedejas komandas
ret=$?

echo "Return value is $ret"
