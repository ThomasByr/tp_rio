#pragma once
#include "io.h"

#include "receiver-slc.h"
#include "receiver-tcp.h"
#include "receiver-udp.h"
#include "sender-tcp.h"
#include "sender-udp.h"

int exe(const struct io_args *args);
