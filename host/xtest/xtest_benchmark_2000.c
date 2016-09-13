/*
 * Copyright (c) 2015, Linaro Limited
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License Version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "xtest_test.h"
#include "xtest_helpers.h"

#include <sha_perf.h>
#include <util.h>

#define SHA_PERF_COUNT 5000	/* Number of measurements */	
#define SHA_PERF_WARMUP 2 /* Start with a 2-second busy loop  */
#define SHA_PERF_LOOPS 1 /* Inner loops */
#define SHA_PERF_RANDOM_IN 1 /* Get input data from /dev/urandom */
#define SHA_PERF_VERBOSITY 0



static void xtest_tee_benchmark_2001(ADBG_Case_t *Case_p);
static void xtest_tee_benchmark_2002(ADBG_Case_t *Case_p);

static void xtest_tee_benchmark_2001(ADBG_Case_t *c)
{
	UNUSED(c);

	int algo = TA_SHA_SHA1;	/* Algorithm */
	size_t size = 1024;	/* Buffer size */
	int offset = 0;          /* Buffer offset wrt. alloc'ed address */

	sha_perf_run_test(algo, size, SHA_PERF_COUNT, 
								SHA_PERF_LOOPS, SHA_PERF_RANDOM_IN, offset, 
								SHA_PERF_WARMUP, SHA_PERF_VERBOSITY);

}

static void xtest_tee_benchmark_2002(ADBG_Case_t *c)
{
	UNUSED(c);

	int algo = TA_SHA_SHA256;	/* Algorithm */
	size_t size = 4096;	/* Buffer size */
	int offset = 0;          /* Buffer offset wrt. alloc'ed address */

	sha_perf_run_test(algo, size, SHA_PERF_COUNT, 
								SHA_PERF_LOOPS, SHA_PERF_RANDOM_IN, offset, 
								SHA_PERF_WARMUP, SHA_PERF_VERBOSITY);

}

ADBG_CASE_DEFINE(XTEST_TEE_BENCHMARK_2001, xtest_tee_benchmark_2001,
		/* Title */
		"TEE SHA Performance test (TA_SHA_SHA1)",
		/* Short description */
		"Hashing 1024 bytes buffer with SHA1 algo, offset = 0",
		/* Requirement IDs */ "",
		/* How to implement */ ""
		);

ADBG_CASE_DEFINE(XTEST_TEE_BENCHMARK_2002, xtest_tee_benchmark_2002,
		/* Title */
		"TEE SHA Performance test (TA_SHA_SHA226)",
		/* Short description */
		"Hashing 4096 bytes buffer with SHA256 algo, offset = 0",
		/* Requirement IDs */ "",
		/* How to implement */ ""
		);
