#since the algorithm is executed both in foreground and background 100 times, some numbers will be repeated, for example: 12 12 13 etc. 
#!/bin/bash
for i in {1..100}
do
if [ -e file.txt ]
then touch file.txt
fi
#critical region
number=$(tail -n 1 file.txt)
echo $((number+1)) >>file.txt
done
