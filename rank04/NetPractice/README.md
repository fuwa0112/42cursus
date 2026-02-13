*This project has been created as part of the 42 curriculum by thitoe.*

# NetPractice

## Description

NetPractice is a networking training project from the 42 curriculum.\
The objective of this project is to understand and correctly configure
small-scale IP networks.

The project focuses on solving networking configuration problems across
multiple levels. Each level requires identifying misconfigurations and
correcting them in order to allow proper communication between hosts,
routers, switches, and the Internet.

------------------------------------------------------------------------

## Instructions

### Running the training interface

1.  Download the `net_practice.tgz` archive from the project page.
2.  Extract it:
    ``` bash
    tar -xzf net_practice.tgz
    ```
3.  Open the `index.html` file in your web browser.
4.  Leave the login field empty to enter correction mode.
5.  Solve each level by fixing the network configuration.
6.  When a level is completed, export the configuration.

### Exporting configurations

For each level: - Use the export button in the interface. - Save the
exported configuration file. - Ensure the file corresponds to the
correct level.

### Submission requirements

You must place **10 exported configuration files (one per level)** at
the root of your Git repository.
The repository must contain: - 10 configuration files - This README.md
file
All files must be correctly exported and functional.

------------------------------------------------------------------------

## Resources

The following resources were used to understand networking concepts:

-   https://www.youtube.com/playlist?list=PLXXalsdlzX-J7AUuw2zSHit5nRUZ3eDdz
-   Chat GPT
-   Discord 42 channnel

Networking Concepts Covered

## Knowledge

The following networking concepts were studied and referenced while completing this project:

TCP/IP Addressing
TCP/IP addressing defines how devices are identified on a network using IP addresses. In IPv4, an address consists of a network portion and a host portion, allowing devices to communicate within the same network or across different networks through routing.

Subnet Masks
A subnet mask determines which part of an IP address represents the network and which part represents the host. It is essential for dividing large networks into smaller subnets and for calculating network ranges, usable host addresses, and broadcast addresses.

Default Gateway
A default gateway is the router that forwards traffic from a local network to external networks. When a host needs to communicate with a device outside its own subnet, it sends the packet to the configured default gateway.

Routers and Switches
A switch operates at Layer 2 (Data Link Layer) and forwards frames within the same local network using MAC addresses.
A router operates at Layer 3 (Network Layer) and forwards packets between different networks using IP addresses and routing tables.

OSI Layers (Layer 2 and Layer 3 Focus)
The OSI model is a conceptual framework that describes network communication in layers.

Layer 2 (Data Link Layer) handles frame delivery within a local network.
Layer 3 (Network Layer) manages logical addressing and routing between networks.

### AI Usage

AI was used in the following situations:
As a learning assistant when encountering unfamiliar terminology or networking concepts in NetPractice.
To help structure and improve the clarity of the README documentation.

AI was used strictly as a support tool for understanding and documentation.
All network configurations were solved manually and independently.

------------------------------------------------------------------------

## Conclusion

NetPractice provides practical hands-on experience in IP networking
fundamentals.\
It strengthens the ability to reason about routing decisions,
subnetting, and network design --- core skills required in system
administration and network engineering.