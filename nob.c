// SPDX-License-Identifier: GPL-3.0-or-later
// SPDX-FileCopyrightText: 2025 kurth4cker <kurth4cker@gmail.com>

#include <stdlib.h>

#define NOB_EXPERIMENTAL_DELETE_OLD
#define NOB_IMPLEMENTATION
#include "nob.h"

int
main(int argc, char **argv)
{
    NOB_GO_REBUILD_URSELF_PLUS(argc, argv, "nob.h");

    Nob_Cmd *cmd = &(Nob_Cmd) { 0 };
    nob_cmd_append(cmd, "cc", "-std=c17", "-pedantic");
    nob_cmd_append(cmd, "-g", "-Werror");
    nob_cmd_append(cmd, "-Wall", "-Wextra");
    nob_cc_inputs(cmd, "pfork.c", "main.c");
    nob_cc_output(cmd, "pfork");
    if (!nob_cmd_run_sync_and_reset(cmd)) {
        exit(EXIT_FAILURE);
    }

    if (nob_needs_rebuild1("pfork.1", "pfork.1.scd")) {
        Nob_File fin = nob_file_open_for_read("pfork.1.scd");
        Nob_File fout = nob_file_open_for_write("pfork.1");
        nob_cmd_append(cmd, "scdoc");
        if (fin.fd == NOB_INVALID_FD
            || fout.fd == NOB_INVALID_FD
            || !nob_cmd_run_sync_redirect_file_and_reset(cmd, (Nob_Cmd_Redirect_File) {
                .fin = &fin,
                .fout = &fout,
        })) {
            exit(EXIT_FAILURE);
        }
        nob_file_close(fin);
        nob_file_close(fout);
    }
}
