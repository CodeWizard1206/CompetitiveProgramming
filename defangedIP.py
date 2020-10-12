"""

Given a valid (IPv4) IP address, return a defanged version
of that IP address. A defanged IP adress replaces every
period "." with "[.]".

input: address = "1.1.1.1"
output: "1[.]1[.]1[.]1"

"""
ipAddr = str(raw_input())
print(ipAddr.replace(".","[.]"))
