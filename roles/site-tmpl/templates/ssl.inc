listen 443 ssl;
ssl_certificate     /etc/nginx/ssl/{{ domain_name }}.com.crt;
ssl_certificate_key /etc/nginx/ssl/{{ domain_name }}.com.key;

ssl_protocols TLSv1.2 TLSv1.3;
ssl_prefer_server_ciphers off;
ssl_ciphers ECDHE-ECDSA-AES128-GCM-SHA256:ECDHE-RSA-AES128-GCM-SHA256:ECDHE-ECDSA-AES256-GCM-SHA384:ECDHE-RSA-AES256-GCM-SHA384:ECDHE-ECDSA-CHACHA20-POLY1305:ECDHE-RSA-CHACHA20-POLY1305:DHE-RSA-AES128-GCM-SHA256:DHE-RSA-AES256-GCM-SHA384;
# ECDHE-RSA-AES256-SHA
ssl_dhparam          /etc/nginx/ssl/dhparam.pem;
ssl_session_cache    shared:SSL:10m;
ssl_session_timeout  10m;

keepalive_timeout    70;

# OCSP stapling
ssl_stapling on;
ssl_stapling_verify on;
resolver 8.8.8.8;

# Set HSTS to 365 days
add_header Strict-Transport-Security "max-age=31536000; includeSubDomains; preload" always;
