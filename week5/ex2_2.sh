#The algorithm is executed both in foreground and background 100 times, but the numbers won't be repeated because of lock 
#!/bin/bash
i=0 
while [ $i -le 99 ] 
do
	if ln file.txt file.txt.lock
	then
		var1=$(grep -Eo '^[0-9]+$' file.txt.lock | tail -1)
		expr $var1 + 1 >> file.txt.lock
		rm file.txt.lock
	else
		i=$(($i-1))
	fi
	i=$(($i+1))
done
