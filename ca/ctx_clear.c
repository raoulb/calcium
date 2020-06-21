/*
    Copyright (C) 2020 Fredrik Johansson

    This file is part of Calcium.

    Calcium is free software: you can redistribute it and/or modify it under
    the terms of the GNU Lesser General Public License (LGPL) as published
    by the Free Software Foundation; either version 2.1 of the License, or
    (at your option) any later version.  See <http://www.gnu.org/licenses/>.
*/

#include "ca.h"

void
ca_ctx_clear(ca_ctx_t ctx)
{
    slong i;

    CA_INFO(ctx, ("%wd fields cached at time of destruction\n", ctx->fields_len));

    for (i = 0; i < ctx->fields_len; i++)
        ca_field_clear(ctx->fields + i, ctx);

    flint_free(ctx->fields);

    flint_free(ctx->mctx);

    flint_free(ctx->options);
}
