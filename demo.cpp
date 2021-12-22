(1) To Check Actual Ram on Laptop
 -> grep MemTotal /proc/meminfo

 (2) To Check a Maximum Ram Size in Over laptop
 -> sudo dmidecode -t 16

 (3) To Check Type (DDR4)/Speed Ram
 -> sudo dmidecode -t 17

 (4) To check Ram capacity 
 -> sudo dmidecode -t memory | grep -Po '^\tMaximum Capacity: \K.*'

