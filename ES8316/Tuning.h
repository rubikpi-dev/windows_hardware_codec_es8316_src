/*
 * SPDX-License-Identifier: BSD-3-Clause
 * Copyright (c) rubikpi-dev Authors. All Rights Reserved.
 * See ../LICENSES/BSD-3-Clause.txt.
 */

#pragma once

#define ES8316_TUNING_FIELDS(X) \
    X(HpEnableDelayMs,       10,   0,  1000) \
    X(HpMuteDelayMs,         10,   0,  1000) \
    X(DacRampRate,            4,   0,     4)

static __inline ULONG
Es8316BoundTuningValue(ULONG value, ULONG defaultValue, ULONG minimum, ULONG maximum)
{
    return (value < minimum || value > maximum) ? defaultValue : value;
}
