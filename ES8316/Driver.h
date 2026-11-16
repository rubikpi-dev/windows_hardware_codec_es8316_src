/*
 * SPDX-License-Identifier: BSD-3-Clause
 * Copyright (c) rubikpi-dev Authors. All Rights Reserved.
 * See ../LICENSES/BSD-3-Clause.txt.
 */

#pragma once

#include <ntddk.h>
#include <wdf.h>
#include <initguid.h>
#define RESHUB_USE_HELPER_ROUTINES
#include <reshub.h>

#include "Trace.h"
#include "Spb.h"
#include "Gpio.h"
#include "Es8316Regs.h"
#include "Es8316Ioctl.h"
#include "Mclk.h"
#include "PersistentStream.h"
#include "Device.h"
#include "Codec.h"

// E816
#define ES8316_POOL_TAG '618E'

EXTERN_C_START

DRIVER_INITIALIZE DriverEntry;
EVT_WDF_DRIVER_DEVICE_ADD Es8316EvtDeviceAdd;
EVT_WDF_OBJECT_CONTEXT_CLEANUP Es8316EvtDriverContextCleanup;

EXTERN_C_END
