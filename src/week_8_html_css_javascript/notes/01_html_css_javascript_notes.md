# Week 8: HTML, CSS, JavaScript

Instructor: **[David J. Malan](https://github.com/dmalan)**

---

## The Internet

- _Markup_ languages: `HTML`, `CSS`
- _Programming_ language: `JavaScript`

The `ARPANET`, a project from the US Department of Defence, connected the first points on the internet to one another.

<img src="img/01.png" alt="ARPANET 1969">

A **router** - a device that connects two or more packet-switched networks or subnetworks.

---

## TCP/IP

**TCP/IP** - a pair of protocols:
- **IP** - Internet Protocol - every device has an IP address, you can share IP address. Standardize the data
in a packet, specifies the source and destination addresses. _Not guarantee delivery._
  - `#.#.#.#` - IPv4 format. Numeric dot-decimal notation (each between 0 and 255), 4 bytes or 32 bits.
  - `#.#.#.#.#.#.#.#` - IPv6 format. Alphanumeric hexadecimal notation. 128 bits.
- **TCP** "guarantees" the delivery of a packet. Make the sequence of packets.

Digital representation of a packet:

<img src="img/02.png" alt="Example Internet Datagram Header">

- Source address
- Destination address

Each package has a type indicator that identifies what is inside (message, video, archive, etc).

---

## Ports

Port number 
- `80` HTTP (Hypertext Transfer Protocol)
- `443` HTTPS (HTPSecure)
- ...

<img src="img/03.png" alt="TCP Header Format">


---

## DNS

Domain Name System Servers are another type of servers, naming system, specifies the IP address for the domain name.

DNS may fit the model of a dictionary with keys and values or a hash table:


| Fully Qualified Domain Name | IP Address |
|-----------------------------|------------|
| harvard.edu                 | #.#.#.#    |

---

## DHCP

Dynamic Host Configuration Protocol answers the question - _"What is my DNS server and router?"_, 
_"What IP address should I use?"_

---

## HTTP

Hypertext Transfer Protocol that governs how web browsers and web servers speak.

HTTPS uses encryption.

- `www` - World Wide Web, host name;
- `.com` - top level domain;
- `https` securely accessing the server;
- `https://www.example.com/` - root of a website, default folder;
- `https://www.example.com/path.html` - most servers hide `.html`;
- `https://www.example.com/folder/` - folder.

### Request server information

- `GET` - getting info;
- `POST` - sending info;
- ...

### `GET` example

Browser to server:

- `GET` / `HTTP` / `2`
- Host: `www.harvard.edu`
  - Key: host
  - Value: address
- ...

Server to browser:
- `HTTP`/ `2` `200`
- Content-Type: text/html
- ...

You can see the entire info through commandline:

```commandline
curl -I https://www.harvard.edu
```

- `curl` means connect to URL, command-line program simulates being a browser. Gets the package info only
without images.

```commandline
HTTP/2 200 
server: nginx
date: Fri, 25 Oct 2024 11:00:21 GMT
content-type: text/html; charset=UTF-8
vary: Accept-Encoding
x-hacker: If you're reading this, you should visit wpvip.com/careers and apply to join the fun, mention this header.
host-header: a9130478a60e5f9135f765b23f26593b
link: <https://www.harvard.edu/>; rel=shortlink
x-rq: ams5 111 254 443
accept-ranges: bytes
x-cache: HIT
cache-control: max-age=300, must-revalidate
```

---

## Developer tools

In the browser's private mode you have no history, no cookies, no sessions.

Let's open `network` in `developers tools`.

Without `www` we get this:
- Notice where was `HTTP/2 200` is now `HTTP/2 301`;

```commandline
curl -I https://harvard.edu
HTTP/2 301 
server: nginx
date: Fri, 25 Oct 2024 11:14:07 GMT
content-type: text/html; charset=utf-8
location: https://www.harvard.edu/
x-rq: ams5 111 254 443
x-cache: HIT
```


### Response codes

The most common codes:

- `200` OK

`3...` Redirects user to other places:
- `301` Moved Permanently - redirects to the default address
- `302` Found
- `304` Not Modified
- `304` Temporary Redirect

`4...` means troubles with user's request:
- `401` Unauthorized
- `403` Forbidden
- `404` Not Found
- `418` I'm a Teapot - joke

`5...` segfault (segmentation fault):
- `500` Internal Server Error
- `503` Service Unavailable

```commandline
$ curl -I http://safetyschool.org/
HTTP/1.1 301 Moved Permanently
Server: Sun-ONE-Web-Server/6.1
Date: Fri, 25 Oct 2024 11:32:44 GMT
Content-length: 122
Content-type: text/html
Location: http://www.yale.edu
Connection: close
```

---

## HTML

Markup text-based language. HTML is presenting information. Doesn't have functions and logic.

Has two vocabulary words:
- `tags`
- `attributes`

HTML sample:

```html
<!DOCTYPE html>

<html lang="en">
    <head>
        <title>
            hello, title
        </title>
    </head>
    <body>
        hello, body
    </body>
</html>
```

Command `http-server` zero-configuration command-line static HTTP server:

```commandline
http-server
Starting up http-server, serving ./

http-server settings: 
CORS: true
Cache: -1 seconds
Connection Timeout: 120 seconds
Directory Listings: visible
AutoIndex: not visible
Serve GZIP Files: false
Serve Brotli Files: false
Default File Extension: none

Available on:
  https://name-somenumbers-8080.app.github.dev
Hit CTRL-C to stop the server
```

When we follow the link, we get a directory listing:

```
Index of /
(-rw-------)	25-Oct-2024 14:44	166B	hello.html

http-server server running @ localhost:8080
```

Click on `hello.html` to see your site.

- `<html>` - html tag, start tag or open tag means start of something for browser;
- `<html lang="en">`
  - `lang` is an attribute. Everything after the tag name is an attribute;
  - `"en"` value of an attribute;
  - we have a key/value pair again.
- `</html>` - close tag or end tag:
  - forward slash `/` before the tag name means the end.

`html tag` has inside two elements inside:
- `<head>` head element;
  - `<title>` start of a page title;
- `<body>` body element.

