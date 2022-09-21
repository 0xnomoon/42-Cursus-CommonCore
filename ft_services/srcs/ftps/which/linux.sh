#!/bin/bash

telegraf &
{ echo "www"; echo "www"; } | adduser www
chown -R www /home/www
chmod -R 775 /home/www 

/usr/sbin/pure-ftpd -Y 2 -p 21000:21003 -P 172.17.0.100 &
while pgrep pure-ftpd >/dev/null && pgrep telegraf >/dev/null; do
    sleep 1;
done
