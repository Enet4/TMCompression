
#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <stddef.h>

/// Opaque type for the results of an evaluation.
typedef struct TMCompressionResultsData {} TMCompressionResultsData;

/** Retrieve the full number of turing machines evaluated, which equates
 * to the length of each metric vector.
 */
size_t tm_results_size(TMCompressionResultsData* results);

/** Obtain a pointer to the start of the vector containing the amplitudes. The
 * pointed data is only valid for the lifetime of the results object.
 */
unsigned int* tm_results_amplitude(TMCompressionResultsData* results);

/** Obtain a pointer to the start of the vector containing the normalized
 * compression values. The pointed data is only valid for the lifetime of the
 * results object.
 */
double* tm_results_normalized_compression(TMCompressionResultsData* results);

/** Obtain a pointer to the start of the vector containing the self
 * compression values. The pointed data is only valid for the lifetime of the
 * results object.
 */
double* tm_results_self_compression(TMCompressionResultsData* results);

/** Free the given results object from memory. */
void tm_results_free(TMCompressionResultsData* results);

/** Evaluate all relative turing machine programs with the given architecture.
 *
 * @param states
 * @param alphabet_size
 * @param num_iterations
 * @param k
 * @param verbose
 * @param out pointer to an opaque output containing the evaluation results, one per turing machine
 */
int tm_run(
    size_t states,
    size_t alphabet_size,
    unsigned int num_iterations,
    unsigned int k,
    _Bool verbose,
    TMCompressionResultsData** out);

#ifdef __cplusplus
}
#endif
