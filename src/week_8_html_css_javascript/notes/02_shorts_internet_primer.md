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

| Host                   | IPv4 Address      |
|------------------------|-------------------|
| `info.host1.net`       | `0.0.0.0`         |
| `info.host2.net`       | `0.0.0.1`         |
|                        |                   |
| `io-in-f138.1e100.net` | `74.125.202.138`  |
|                        |                   |
| `info.hostn-1.net`     | `255.255.255.254` |
| `info.hostn.net`       | `255.255.255.255` |