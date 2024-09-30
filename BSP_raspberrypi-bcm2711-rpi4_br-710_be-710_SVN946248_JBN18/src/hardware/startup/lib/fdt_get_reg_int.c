/*
 * $QNXLicenseC:
 * Copyright 2016, QNX Software Systems.
 *
 * Licensed under the Apache License, Version 2.0 (the "License"). You
 * may not reproduce, modify or distribute this software except in
 * compliance with the License. You may obtain a copy of the License
 * at: http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" basis,
 * WITHOUT WARRANTIES OF ANY KIND, either express or implied.
 *
 * This file may contain contributions from others, either as
 * contributors under the License or as licensors under other terms.
 * Please review this entire file for other proprietary rights or license
 * notices, as well as the QNX Development Suite License Guide at
 * http://licensing.qnx.com/license-guide/ for other information.
 * $
 */

/**
 * @file	fdt_get_reg_int.c
 * @brief	Convinience functions on top of the standard FDT library.
 */

#include <limits.h>
#include "libfdt_private.h"

/**
 * Extracts a signed value for the given node from either a reg property or its
 * name.
 * If a reg proprety exists, the first value in that property is
 * used. Otherwise, if the name of the node is of the form 'str@num' then the
 * numeric part of the name is used.
 * @param	fdt		Device tree
 * @param	node	The node to extract a value for
 * @param	pp		Holds the extracted value upon successful return
 * @return	0 if successful, negative error code otherwise
 */
int fdt_get_reg_int(const void *fdt, int node, int *pp) {
	int				r;
	unsigned		val;

	r = fdt_get_reg_addr(fdt, node, &val);
	if(r >= 0) {
		if(val > INT_MAX) {
			r = -FDT_ERR_BADSTRUCTURE;
		} else {
			*pp = (int)val;
		}
	}
	return r;
}

#if defined(__QNXNTO__) && defined(__USESRCVERSION)
#include <sys/srcversion.h>
__SRCVERSION("$URL: http://svn.ott.qnx.com/product/branches/7.1.0/trunk/hardware/startup/lib/fdt_get_reg_int.c $ $Rev: 811485 $")
#endif
