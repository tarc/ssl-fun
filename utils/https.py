# Taken from http://www.piware.de/2011/01/creating-an-https-server-in-python/
# credits to Martin Pitt

import BaseHTTPServer, SimpleHTTPServer
import ssl

httpd = BaseHTTPServer.HTTPServer(
        ('localhost', 4443),
        SimpleHTTPServer.SimpleHTTPRequestHandler)

httpd.socket = ssl.wrap_socket(
        httpd.socket,
        certfile='server.crt',
        keyfile='server.key',
        server_side=True)

httpd.serve_forever()
