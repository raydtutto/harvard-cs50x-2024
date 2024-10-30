# Internet primer

Instructor: **[Doug Lloyd](https://github.com/dlloyd09)**

---

## IP Address

**IP** - _Internet Protocol_.

In order for your machine to uniquely identify itself on the Internet, it needs an address.
- This way, it can send information out and also receive information back to the correct location.

The addressing scheme used by computers is known as IP addressing.

As originally developed, the IP addressing scheme would effectively allocate a unique 32-bit address
to each device hoping to connect to the internet.

Instead of representing these 32-bit addresses as hexadecimal, we represent them as four clusters
of 8-bits using decimal notation.

> _IP-address **IPv4**:_ `w.x.y.z`
> 
> Each of `w`, `x`, `y`, and `z` can be a non-negative value in the range `[0, 255]`.
> 
> _Example:_ `123.45.67.89`, `140.247.223.81`

If each IP address is 32 bits, that means there are roughly _4 billion_ addresses to give out.

The population of the world is somewhere in excess of _7 billion_, and most folks in the western world
have more than 1 device capable of Internet connectivity.
- Some workarounds have allowed us to deal with this problem (for now).

In recent years, we’ve been slowly phasing out this old scheme (IPv4) and replacing it with a newer scheme
(IPv6) that assigns computers 128-bit addresses, instead of 32-bit addresses.
- Instead of `4,294,967,296` of addresses we get `340,282,366,920,938,463,463,374,607,431,768,211,456` addresses.

> _IP-address **IPv6**:_ `s:t:u:v:w:x:y:z`
>
> Each of `s`, `t`, `u`, `v`, `w`, `x`, `y`, and `z` is represented by `1` to `4` hexadecimal digits
> in the range `[0,ffff]`.
>
> _Example:_ `1234:5678:90ab:cdef:fedc:ba09:8765:4321`; `2001:4860:4860:0:0:0:0:8844`
> can be shortened to `2001:4860:4860::8844`

---

## DHCP

How do we get an IP address in the first place though?

Somewhere between your computer and the Internet at large exists a **_Dynamic Host Configuration Protocol_**
(DHCP) server, whose role is to assign _IP addresses_ to devices.

Prior to the widespread promulgation of DHCP, the task of assigning IP addresses fell to a system administrator,
who would need to manually assign such addresses.

`[User]` --> `[DHCP server]` --> `[Internet]`

---

## DNS

Odds are, you’ve never actually tried to visit a website by typing its IP address into your browser.

The **_Domain Name System_** (DNS) exists to help us translate _IP addresses_ to more memorable names that
are more human-comprehensible.

In this way, _**DNS**_ is somewhat like the yellow pages of the web.

**_IPv4_**:

| Host                                   | IPv4 Address      |
|----------------------------------------|-------------------|
| `info.host1.net`                       | `0.0.0.0`         |
| `info.host2.net`                       | `0.0.0.1`         |
|                                        |                   |
| `io-in-f138.1e100.net` or `google.com` | `74.125.202.138`  |
|                                        |                   |
| `info.hostn-1.net`                     | `255.255.255.254` |
| `info.hostn.net`                       | `255.255.255.255` |

**Google** has a lot of different servers and can't call all of them "google.com", so they have their internal system
for translating what server is connected to the IP address.

**_IPv6_**:

| Host                                 | IPv4 Address                              |
|--------------------------------------|-------------------------------------------|
| `info.host1.net`                     | `0:0:0:0:0:0:0:0`                         |
| `info.host2.net`                     | `0:0:0:0:0:0:0:1`                         |
|                                      |                                           |
| `lk-in-x93.1e100.net` or `google.ie` | `2a00:1450:4010:c09:0:0:0:93`             |
|                                      |                                           |
| `info.hostn-1.net`                   | `ffff:ffff:ffff:ffff:ffff:ffff:ffff:fffe` |
| `info.hostn.net`                     | `ffff:ffff:ffff:ffff:ffff:ffff:ffff:ffff` |

Much like there is no yellow pages of the world, there is really no DNS record of the entire internet.

Rather, large DNS server systems (like Google’s own) are more like aggregators, collecting smaller
sets of DNS information and pooling them together, updating frequently.

In that way, large DNS servers are like libraries that stock many different sets of local yellow page books.
In order to have the most up-to-date phone numbers for businesses, libraries must update the books
they have on hand.

DNS record sets are thus fairly _decentralized_.

`[User]` --> `[DHCP server]` `[DNS Server]` --> `[Internet]`

---

## Access Points

One of the ways we’ve dealt with the IPv4 addressing problem is to start assigning multiple people to the same IP address.

The IP address is assigned to a router, whose job it is to act as a traffic cop that allows data requests
from all the devices on your local network (your home or business, e.g.) to be processed through a single IP address.

Modern home networks consist of access points that combine a router, a modem, a switch, and other technologies
together into a single device.

Modern business networks or large-scale wide-area networks (WANs) still frequently have these as separate devices
to allow the size of their network to scale more easily.

`[User]` --> `[DHCP server]` `[DNS Server]` `[Access Point]` --> `[Internet]`

> This isn’t a course on networking, so this is far from the whole
story, but it’s enough to get us started.

At home or at work we have local, small networks, and these networks are woven together to create a large,
interconnected network—an Internet.
- If you think about each of these small networks being isolated communities with only a single road in or out,
the picture becomes a bit clearer.

