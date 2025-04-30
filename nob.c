// SPDX-License-Identifier: GPL-3.0-or-later
// SPDX-FileCopyrightText: 2025 kurth4cker <kurth4cker@gmail.com>

#include <stdlib.h>

#define NOB_EXPERIMENTAL_DELETE_OLD
#define NOB_IMPLEMENTATION
#include "nob.h"

int
main(int argc, char **argv)
{
    NOB_GO_REBUILD_URSELF(argc, argv);

    Nob_Cmd *cmd = &(Nob_Cmd) { 0 };
    nob_cmd_append(cmd, "cc", "-std=c17", "-pedantic");
    nob_cmd_append(cmd, "-g", "-Werror");
    nob_cmd_append(cmd, "-Wall", "-Wextra");
    nob_cc_inputs(cmd, "pfork.c", "main.c");
    nob_cc_output(cmd, "pfork");
    if (!nob_cmd_run_sync_and_reset(cmd)) {
        exit(EXIT_FAILURE);
    }

    // TODO(#2): build documentation with scdoc
}
