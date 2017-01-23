# μ time zone (library)

An embedded timezone library and ~3kB tzinfo database featuring nearly 
all current timezones present in the IANA timezone database. 
Designed for use on budget embedded systems with low program space.

The C header containing packed timezone information is generated from
the IANA timezone database.

## Tradeoffs

All historical timezone information has been pruned to save space.

A limited number of aliases are available. (by default restricted to the
same set that android uses) In cases where the alias is not available,
the standard time UTC offset and abbreviation (if present) will be
displayed.

This library is generally inflexible as it heavily relies on
assumptions pertaining to timezone offset increments, abbreviation
formatting, etc to make efficient use of bit packs.

## Limitations

The current utility library does not support parsing /
packing all possible syntax of the source IANA tz database. 
Instead a subset corresponding to the what is needed to correctly parse  
most zones is implemented.

## Links

[zic man page and IANA tz database format documentation](https://linux.die.net/man/8/zic)

[vendored files](./vendor)
