#!/bin/bash
cut -d":" -f 1 |sed -n "n;p" | rev | sort -r | sed -n "$MY_LINE1,$MY_LINE2 p" | sed -z "s/\n/, /g" | sed -e "s/, $/.\n/"
