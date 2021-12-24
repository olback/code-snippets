#!/bin/sh

RUSTFLAGS="-Ctarget-cpu=native -Clto=yes -Cembed-bitcode=yes -Copt-level=3 -Ccodegen-units=2" cargo run --release

