This code contains a bunch of functions, which use some calls which are not
available under CeGCC. So is meant to be compiled into a dll with MS eVC compiler.
The dll can be later imported by CeGCC compilable code.

To compile this you will need to find OEMINC.H, which non-standard header
available in some Gizmondo SDKs.

