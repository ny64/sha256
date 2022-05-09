# sha256

Default sha256 algorithm implemented in C++ just to understand length extension attacks better.

## Installation

There already is a [binary file](https://github.com/ny64/sha256/raw/master/sha256) you can download directly.
To compile it yourself you need a C++ compiler. Your installed version will most likely work.

```
git clone https://github.com/ny64/sha256.git
cd sha256 
g++ src/*.cpp -o sha256
```

## Usage

```
./sha256 "String1" "String2" ...
```

Returns list of hashes.
