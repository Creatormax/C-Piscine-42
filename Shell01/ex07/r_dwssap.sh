cat /etc/passwd | awk '! /#/ && NR%2==0' | cut -d : -f 1 | rev | sort -r | awk -v l1=$FT_LINE1 -v l2=$FT_LINE2 'NR==l1, NR == l2'| tr "\n" "," | sed 's/,$/./' | sed 's/,/, /g' | tr -d "\n"
