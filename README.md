Frothleikr
------------------

Frothleikr is a very small, simple, and lightweight binary serialization library.

No depedencies, simply build as C or C++. 

Small and simple - Frothleikr is a small and simple library that requires little effort to learn.

Lightweight and direct - Frothleikr has a "keep it lean and direct" mentality. Some serialization libraries use higher levels
of abstraction, which is fine, but it's not the intention of Frothleikr. Frothleikr gives you very direct control over how you
serialize your complex data, what to do with it, etc. With Frothleikr's mentality, heap allocation should never occur without it being clear to the programmer
that heap allocation will occur. The ability to get a handle on the raw bytes of serialized data shoud be possible. Frothleikr
allows you to be very explicit and clear about how your serialization process works. 

What It Does Do
-----------------

- Easily create portable in memory serializations of integer types with your choice of endianness 

- Easily create portable in memory serializations of IEEE754 floating point types with your choice of endianness

- Easily store your serialized data into memory buffers

What It Does NOT Do
--------------------

- Serialize to non-system memory targets. This means it doesn't handle file io, sending data through networks etc.
This shouldn't be a problem for you unless you're looking for a more high level library. Once your
data has been serialized in memory, it's a simple matter of just passing the bytes along to whatever your target is. 

- Immediately serialize complex types for you. You are expected to define behaviour for serializing complex types yourself. 

Building
-------------------

Get Cmake (if you don't already have it)

Use Cmake

Use whatever Cmake generated.

Profit

The library should be able to be compiled as C and C++.
No depedencies needed.
