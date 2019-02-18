
#include "tm_c.h"
#include "tm.h"

extern "C" {

int tm_run(
    size_t states,
    size_t alphabet_size,
    unsigned int num_iterations,
    unsigned int k,
    _Bool verbose,
    TMCompressionResultsData** out) {

    try {
        auto results = tm(states, alphabet_size, num_iterations, k, verbose);
        auto o = new CompressionResultsData {
            results.amplitude,
            results.normalized_compression,
            results.self_compression
        };

        *out = reinterpret_cast<TMCompressionResultsData*>(o);
    } catch (...) {
        return -1;
    }
    return 0;
}

size_t tm_results_size(TMCompressionResultsData* results) {
    return reinterpret_cast<CompressionResultsData*>(results)->amplitude.size();
}


unsigned int* tm_results_amplitude(TMCompressionResultsData* results) {
    return reinterpret_cast<CompressionResultsData*>(results)->amplitude.data();
}

double* tm_results_normalized_compression(TMCompressionResultsData* results) {
    return reinterpret_cast<CompressionResultsData*>(results)->normalized_compression.data();
}

double* tm_results_self_compression(TMCompressionResultsData* results) {
    return reinterpret_cast<CompressionResultsData*>(results)->self_compression.data();
}

void tm_results_free(TMCompressionResultsData* results) {
    delete reinterpret_cast<CompressionResultsData*>(results);
}

}