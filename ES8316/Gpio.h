/*
 * SPDX-License-Identifier: BSD-3-Clause
 * Copyright (c) rubikpi-dev Authors. All Rights Reserved.
 * See ../LICENSES/BSD-3-Clause.txt.
 */

#pragma once

#include <wdm.h>
#include <wdf.h>

NTSTATUS
GpioOpenPin(
    _In_ WDFDEVICE FxDevice,
    _In_ LARGE_INTEGER ConnectionId,
    _In_ ACCESS_MASK DesiredAccess,
    _Out_ WDFIOTARGET *Target
    );

NTSTATUS
GpioWritePin(
    _In_ WDFIOTARGET Target,
    _In_ BOOLEAN High
    );

NTSTATUS
GpioReadPin(
    _In_ WDFIOTARGET Target,
    _Out_ BOOLEAN *High
    );

VOID
GpioClosePin(
    _Inout_ WDFIOTARGET *Target
    );
