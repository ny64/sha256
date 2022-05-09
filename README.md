# sha256

Default sha256 algorithm implemented in C++ just to understand length extension attacks better.

## Installation

There already is a [binary file](https://github.com/ny64/sha256/raw/main/sha256) you can download directly.
To compile it yourself you need a C++ compiler. Your installed version will most likely work.

```
git clone https://github.com/ny64/sha256.git
cd sha256 
g++ src/*.cpp -o sha256
```

## Usage

```
./sha256 "String 1" "String 2" ...
```

Returns list of hashes like
```
9ab25acb49b0ee82a6f395549aff98255b89d7eb4dcb2cdc6100550867acb1a4
ee94765bb93df4b023a1e6aad1d82e2c6ae0b7635c6fb2673dc5457abf7070d0
...
```
