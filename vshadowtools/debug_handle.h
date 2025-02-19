/*
 * Debug handle
 *
 * Copyright (C) 2011-2022, Joachim Metz <joachim.metz@gmail.com>
 *
 * Refer to AUTHORS for acknowledgements.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#if !defined( _DEBUG_HANDLE_H )
#define _DEBUG_HANDLE_H

#include <common.h>
#include <file_stream.h>
#include <types.h>

#include "vshadowtools_libbfio.h"
#include "vshadowtools_libcerror.h"
#include "vshadowtools_libvshadow.h"

#if defined( __cplusplus )
extern "C" {
#endif

typedef struct debug_handle debug_handle_t;

struct debug_handle
{
	/* The volume offset
	 */
	off64_t volume_offset;

	/* The libbfio input file IO handle
	 */
	libbfio_handle_t *input_file_io_handle;

	/* The libvshadow input volume
	 */
	libvshadow_volume_t *input_volume;

	/* Value to indicate the allocation info should be printed
	 */
	uint8_t show_allocation_information;

	/* The notification output stream
	 */
	FILE *notify_stream;

	/* Value to indicate if abort was signalled
	 */
	int abort;
};

int vshadowtools_system_string_copy_from_64_bit_in_decimal(
     const system_character_t *string,
     size_t string_size,
     uint64_t *value_64bit,
     libcerror_error_t **error );

int debug_handle_initialize(
     debug_handle_t **debug_handle,
     libcerror_error_t **error );

int debug_handle_free(
     debug_handle_t **debug_handle,
     libcerror_error_t **error );

int debug_handle_signal_abort(
     debug_handle_t *debug_handle,
     libcerror_error_t **error );

int debug_handle_set_volume_offset(
     debug_handle_t *debug_handle,
     const system_character_t *string,
     libcerror_error_t **error );

int debug_handle_open_input(
     debug_handle_t *debug_handle,
     const system_character_t *filename,
     libcerror_error_t **error );

int debug_handle_close(
     debug_handle_t *debug_handle,
     libcerror_error_t **error );

int debug_handle_test_read(
     debug_handle_t *debug_handle,
     libcerror_error_t **error );

#if defined( __cplusplus )
}
#endif

#endif /* !defined( _DEBUG_HANDLE_H ) */

