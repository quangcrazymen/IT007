#!/bin/sh
echo "Is it morning? Please answer yes or no"
read timeofday
case "$timeofday" in
    "yes") echo "Good Morning";;
    "no" ) echo "Good Afternoon";;
    "y" ) echo "Good Morning";;
    "n" ) echo "Good Afternoon";;
    * ) echo "Sorry, answer not recognised";;
esac
exit 0 