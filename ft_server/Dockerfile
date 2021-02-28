FROM	debian:buster

COPY	srcs tmp

# install LEMP and others
RUN		apt-get update
RUN		apt-get -y upgrade
RUN		apt-get install -y \
		nginx \
		mariadb-server \
		mariadb-client \
		php-mysql \
		php-mbstring \
		openssl \
		vim \
		wget \
		php7.3-fpm

# ssl certificate and server
RUN		openssl req -newkey rsa:4096 -days 365 -nodes -x509 -subj "/C=KR/ST=Seoul/L=Seoul/O=42Seoul/OU=Wonchoi/CN=localhost" -keyout /etc/ssl/private/localhost.dev.key -out etc/ssl/certs/localhost.dev.crt
RUN		chmod 600 /etc/ssl/certs/localhost.dev.crt /etc/ssl/private/localhost.dev.key
RUN		mv /tmp/default /etc/nginx/sites-available/default

# install wordpress and setting
RUN		wget https://wordpress.org/latest.tar.gz && \
		tar -xvf latest.tar.gz -C /var/www/html/ && \
		rm -rf latest.tar.gz
RUN		mv /tmp/wp-config.php /var/www/html/wordpress/
RUN 	chown -R www-data:www-data /var/www/html/wordpress && chmod -R 755 /var/www/*

# install phpmyadmin and setting
RUN		wget https://files.phpmyadmin.net/phpMyAdmin/4.9.5/phpMyAdmin-4.9.5-all-languages.tar.gz
RUN		tar -xvf phpMyAdmin-4.9.5-all-languages.tar.gz && \
		mv phpMyAdmin-4.9.5-all-languages /var/www/html/phpmyadmin && \
		mv /tmp/config.inc.php /var/www/html/phpmyadmin/ && \
		rm -rf phpMyAdmin-4.9.5-all-languages.tar.gz

# port
EXPOSE	80 443

# autoindex
ENV		AUTOINDEX on

# service start and create User data
ENTRYPOINT	bash /tmp/entrypoint.sh
