# aiken-c-ffi

[![Build](https://github.com/Biglup/aiken-c-ffi/actions/workflows/build.yml/badge.svg)](https://github.com/Biglup/aiken-c-ffi/actions/workflows/build.yml)
[![Release](https://github.com/Biglup/aiken-c-ffi/actions/workflows/release.yml/badge.svg)](https://github.com/Biglup/aiken-c-ffi/actions/workflows/release.yml)

C FFI wrapper for [Aiken](https://aiken-lang.org/) smart contract language.

This is a fork of https://github.com/bloxbean/aiken-jna-wrapper

It exposes following functions
- Phase 2 transaction ExUnits evaluation

## Supported Operating Systems / Archs
- Apple MacOS (Intel and Apple Silicon)
- Linux (x86_64 arm64) (Ubuntu 22.04 or compatible ...)
- Windows 64bits (x86_64 arm64)

For another platform, please create a PR / request [here](https://github.com/Biglup/aiken-c-ffi/issues)

## Build

```shell
git clone https://github.com/Biglup/aiken-c-ffi.git
```

```shell
cargo test
cargo build --release
```

