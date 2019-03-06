#!/bin/sh

# dosim iespeju izveleties augli pasam
echo "Kads auglis tev patik - apple, banana, kiwi?"
read FRUIT

case "$FRUIT" in
   "apple") echo "Apple pie is quite tasty." 
   ;;
   "banana") echo "I like banana nut bread." 
   ;;
   "kiwi") echo "New Zealand is famous for kiwi." 
   ;;
esac
