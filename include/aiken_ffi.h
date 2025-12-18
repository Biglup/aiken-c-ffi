/**
* \file aiken_ffi.h
*
* \author angel.castillo
* \date   Dec 18, 2025
*
* \section LICENSE
*
* Copyright 2025 Biglup Labs
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/

#ifndef AIKEN_FFI_H
#define AIKEN_FFI_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Slot configuration for the Cardano network.
 */
typedef struct SlotConfig {
    /** Length of a slot in milliseconds */
    uint32_t slot_length;
    /** The slot number at zero_time */
    uint64_t zero_slot;
    /** Unix timestamp in milliseconds at slot zero */
    uint64_t zero_time;
} SlotConfig;

/**
 * Initial execution budget for Plutus script evaluation.
 */
typedef struct InitialBudget {
    /** Initial memory budget in units */
    int64_t mem;
    /** Initial CPU budget in units */
    int64_t cpu;
} InitialBudget;

/**
 * Evaluates phase two of Plutus script execution.
 *
 * \param tx_hex        Hex-encoded CBOR transaction data
 * \param inputs        Hex-encoded transaction inputs
 * \param outputs       Hex-encoded transaction outputs
 * \param cost_mdls     Hex-encoded cost models
 * \param initial_budget Initial execution budget
 * \param slot_config   Slot configuration
 *
 * \return Pointer to a JSON response string. The response contains:
 *         - status: "SUCCESS" or "ERROR"
 *         - error: Error message (if status is ERROR)
 *         - redeemer_cbor: Hex-encoded redeemer CBOR (if status is SUCCESS)
 *
 * \note The returned string must be freed using drop_char_pointer().
 */
const char* eval_phase_two(
    const char* tx_hex,
    const char* inputs,
    const char* outputs,
    const char* cost_mdls,
    InitialBudget initial_budget,
    SlotConfig* slot_config
);

/**
 * Applies parameters to a Plutus script.
 *
 * \param params        Hex-encoded parameters to apply
 * \param plutus_script Hex-encoded Plutus script
 *
 * \return Pointer to a JSON response string. The response contains:
 *         - status: "SUCCESS" or "ERROR"
 *         - error: Error message (if status is ERROR)
 *         - compiled_code: Hex-encoded script with applied parameters (if status is SUCCESS)
 *
 * \note The returned string must be freed using drop_char_pointer().
 */
const char* apply_params_to_plutus_script(
    const char* params,
    const char* plutus_script
);

/**
 * Frees a string pointer returned by library functions.
 *
 * \param pointer Pointer to a C string returned by eval_phase_two or apply_params_to_plutus_script
 */
void drop_char_pointer(const char* pointer);

#ifdef __cplusplus
}
#endif

#endif /* AIKEN_FFI_H */
