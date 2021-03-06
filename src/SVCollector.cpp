/*
 ============================================================================
 Name        : SVCollector.cpp
 Author      : Fritz Sedlazeck
 Version     :
 Copyright   : MIT license
 Description : A greedy framework to select samples based on initial observations.
 ============================================================================
 */

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <sstream>
#include <map>
#include <math.h>

#include "Select_samples.h"

int main(int argc, char **argv) {

	//TODO make some histograms.

	if (argc == 1) {
		std::cerr << "./SVCollector <option> my_svs_vcf_file output_ranked" << std::endl;
		std::cerr << "<option>: greedy, topN or random " << std::endl;
		std::cerr << "my_svs_vcf_file: A valid uncompressed multisample VCF file." << std::endl;
		std::cerr << "num_samples: The number of samples that should be ranked." << std::endl;
		std::cerr << "output_ranked: The file to write out the ranked list with additional information." << std::endl;
		return -1;
	} else {
		if (strcmp(argv[1], "greedy") == 0) {
			if (argc == 5) {
				select_greedy(std::string(argv[2]), atoi(argv[3]), std::string(argv[4]));
			} else {
				std::cerr << "Input VCF file" << std::endl;
				std::cerr << "Number of samples to select" << std::endl;
				std::cerr << "Output file" << std::endl;
			}
			exit(0);
		}
		if (strcmp(argv[1], "topN") == 0) {
			if (argc == 5) {
				select_topN(std::string(argv[2]), atoi(argv[3]), std::string(argv[4]));
			} else {
				std::cerr << "Input VCF file" << std::endl;
				std::cerr << "Number of samples to select" << std::endl;
				std::cerr << "Output file" << std::endl;
			}
			exit(0);
		}
		if (strcmp(argv[1], "random") == 0) {
			if (argc == 5) {
				select_random(std::string(argv[2]), atoi(argv[3]), std::string(argv[4]));
			} else {
				std::cerr << "Input VCF file" << std::endl;
				std::cerr << "Number of samples to select" << std::endl;
				std::cerr << "Output file" << std::endl;
			}
			exit(0);
		}
		if (strcmp(argv[1], "gen_matrix") == 0) {
			if (argc == 5) {
				generate_matrix(std::string(argv[2]), std::string(argv[3]), std::string(argv[4]));
			} else {
				std::cerr << "Input VCF file" << std::endl;
				std::cerr << "Output file" << std::endl;
			}
			exit(0);
		}

	}

	return 0;
}
