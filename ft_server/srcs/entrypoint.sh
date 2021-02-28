#!/bin/sh

service mysql start
echo "CREATE DATABASE IF NOT EXISTS wordpress;" \
	| mysql -u root --skip-password
echo "CREATE USER IF NOT EXISTS 'wordpress'@'localhost' IDENTIFIED BY 'wordpress';" \
	| mysql -u root --skip-password
echo "GRANT ALL PRIVILEGES ON wordpress.* TO 'wordpress'@'localhost' WITH GRANT OPTION;" \
	| mysql -u root --skip-password
if [ "$AUTOINDEX" == "off" ]; then
	sed -i "60s/.*/		#autoindex on;/g" /etc/nginx/sites-available/default
fi

service nginx start
service php7.3-fpm start
rm /tmp/*

bash
