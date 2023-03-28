/*
 * Hash information that's independent from the crypto implementation.
 *
 * (See the corresponding header file for usage notes.)
 */
/*
 *  Copyright The Mbed TLS Contributors
 *  SPDX-License-Identifier: Apache-2.0
 *
 *  Licensed under the Apache License, Version 2.0 (the "License"); you may
 *  not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 *  WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */

#include "hash_info.h"
#include "mbedtls/error.h"

typedef struct {
    psa_algorithm_t psa_alg;
    mbedtls_md_type_t md_type;
    unsigned char size;
    unsigned char block_size;
} hash_entry;

static const hash_entry hash_table[] = {
#if defined(MBEDTLS_MD_CAN_MD5)
    { PSA_ALG_MD5, MBEDTLS_MD_MD5, 16, 64 },
#endif
#if defined(MBEDTLS_MD_CAN_RIPEMD160)
    { PSA_ALG_RIPEMD160, MBEDTLS_MD_RIPEMD160, 20, 64 },
#endif
#if defined(MBEDTLS_MD_CAN_SHA1)
    { PSA_ALG_SHA_1, MBEDTLS_MD_SHA1, 20, 64 },
#endif
#if defined(MBEDTLS_MD_CAN_SHA224)
    { PSA_ALG_SHA_224, MBEDTLS_MD_SHA224, 28, 64 },
#endif
#if defined(MBEDTLS_MD_CAN_SHA256)
    { PSA_ALG_SHA_256, MBEDTLS_MD_SHA256, 32, 64 },
#endif
#if defined(MBEDTLS_MD_CAN_SHA384)
    { PSA_ALG_SHA_384, MBEDTLS_MD_SHA384, 48, 128 },
#endif
#if defined(MBEDTLS_MD_CAN_SHA512)
    { PSA_ALG_SHA_512, MBEDTLS_MD_SHA512, 64, 128 },
#endif
    { PSA_ALG_NONE, MBEDTLS_MD_NONE, 0, 0 },
};
