#!/usr/bin/python
"Check what version the interpreter is"

import sys

REQ_VERSION = (3, 0, 0)
CUR_VERSION = sys.version_info

if CUR_VERSION <= REQ_VERSION:
    print('To use these tools, please use Python', REQ_VERSION[0])
